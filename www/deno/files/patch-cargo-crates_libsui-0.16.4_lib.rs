FreeBSD's kernel only executes binaries whose program headers are in the
first page, so the relocated program header table produced by
Elf::append() makes `deno compile` output fail with ENOEXEC.  For
executables, keep the program headers and add the payload only as a
non-allocated .note.sui section, which find_section() maps from the
executable file at runtime.  Shared libraries (desktop mode's
libdenort.so) keep the upstream layout, which rtld handles.  Also define
PT_NOTE locally, as libc does not export it for FreeBSD.

--- cargo-crates/libsui-0.16.4/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/libsui-0.16.4/lib.rs
@@ -1187,6 +1187,11 @@ impl<'a> Elf<'a> {
     ///   3. Repoint `e_phoff`/`e_phnum` (and `PT_PHDR`, if present) at the new
     ///      table. The section header table is never touched, so relocations,
     ///      `.relr.dyn`, and everything else survive unchanged.
+    ///
+    /// FreeBSD executables are the exception: the kernel refuses to run them
+    /// unless the program headers lie within the first page, so they keep
+    /// their program headers and the note is only added as a non-allocated
+    /// section, which `find_section` reads back from the executable file.
     pub fn append<W: Write>(
         &self,
         name: &str,
@@ -1196,10 +1201,13 @@ impl<'a> Elf<'a> {
         const PAGE: usize = 0x1000;
         // Program/segment header type and flag constants (ELF64).
         const PT_LOAD: u32 = 1;
+        const PT_INTERP: u32 = 3;
         const PT_NOTE: u32 = 4;
         const PT_PHDR: u32 = 6;
         const PF_R: u32 = 4;
         const PHENTSIZE64: usize = 56;
+        const ET_EXEC: u16 = 2;
+        const ELFOSABI_FREEBSD: u8 = 9;
 
         let data = self.data;
         if data.len() < 64 || data[0..4] != *b"\x7fELF" {
@@ -1275,6 +1283,7 @@ impl<'a> Elf<'a> {
         // the first PT_LOAD's `p_vaddr - p_offset` bias.
         let mut max_vaddr_end = 0u64;
         let mut pt_phdr_index = None;
+        let mut has_interp = false;
         let mut first_load_bias: Option<i64> = None;
         for i in 0..e_phnum {
             let off = e_phoff + i * e_phentsize;
@@ -1291,6 +1300,7 @@ impl<'a> Elf<'a> {
                         first_load_bias = Some(p_vaddr as i64 - p_offset as i64);
                     }
                 }
+                PT_INTERP => has_interp = true,
                 PT_PHDR => pt_phdr_index = Some(i),
                 _ => {}
             }
@@ -1300,6 +1310,14 @@ impl<'a> Elf<'a> {
         }
         let first_load_bias = first_load_bias.unwrap_or(0);
 
+        // The FreeBSD kernel only executes binaries whose program headers lie
+        // within the first page (see sys/kern/imgact_elf.c), so leave them in
+        // place for anything it loads itself (ET_EXEC, or a PIE with
+        // PT_INTERP). Shared libraries are mapped by rtld, which copes with a
+        // relocated program header table.
+        let keep_phdrs =
+            data[7] == ELFOSABI_FREEBSD && (r16(&data[0x10..0x12]) == ET_EXEC || has_interp);
+
         let note = build_elf_note_payload(name, sectdata);
 
         // Layout of the appended region, all within one new PT_LOAD:
@@ -1385,8 +1403,14 @@ impl<'a> Elf<'a> {
         ));
 
         let mut out = data.to_vec();
-        out.resize(new_phoff, 0);
-        out.extend_from_slice(&table);
+        let note_file_off = if keep_phdrs {
+            // Only the section added below refers to the note.
+            align_up(out.len(), 4)
+        } else {
+            out.resize(new_phoff, 0);
+            out.extend_from_slice(&table);
+            note_file_off
+        };
         out.resize(note_file_off, 0);
         out.extend_from_slice(&note);
 
@@ -1431,13 +1455,19 @@ impl<'a> Elf<'a> {
                 .unwrap_or(false)
         });
 
+        if keep_phdrs && shstr_range.is_none() {
+            return Err(Error::InvalidObject("No section header table for the note"));
+        }
+
         if let Some((shstr_off, shstr_size)) = shstr_range {
             // Relocate and grow .shstrtab so it carries the new section names.
             let mut new_shstr = data[shstr_off..shstr_off + shstr_size].to_vec();
             let note_name_index = new_shstr.len() as u32;
             new_shstr.extend_from_slice(b".note.sui\0");
             let phdr_name_index = new_shstr.len() as u32;
-            new_shstr.extend_from_slice(b".sui.phdrs\0");
+            if !keep_phdrs {
+                new_shstr.extend_from_slice(b".sui.phdrs\0");
+            }
 
             // .shstrtab and the section header table are non-allocated
             // metadata: place them past the note, outside the new PT_LOAD.
@@ -1467,24 +1497,30 @@ impl<'a> Elf<'a> {
             // of the note: BFD `strip` parses SHT_NOTE contents, so folding the
             // (non-note) program header bytes into `.note.sui` corrupts the note
             // on strip and loses it.
-            let mut phdr_sh = vec![0u8; e_shentsize];
-            w32(&mut phdr_sh[0..4], phdr_name_index); // sh_name
-            w32(&mut phdr_sh[4..8], SHT_PROGBITS); // sh_type
-            w64(&mut phdr_sh[8..16], SHF_ALLOC); // sh_flags
-            w64(&mut phdr_sh[16..24], load_vaddr); // sh_addr
-            w64(&mut phdr_sh[24..32], new_phoff as u64); // sh_offset
-            w64(&mut phdr_sh[32..40], (note_file_off - new_phoff) as u64); // sh_size
-            w64(&mut phdr_sh[48..56], PAGE as u64); // sh_addralign
-            sht.extend_from_slice(&phdr_sh);
+            if !keep_phdrs {
+                let mut phdr_sh = vec![0u8; e_shentsize];
+                w32(&mut phdr_sh[0..4], phdr_name_index); // sh_name
+                w32(&mut phdr_sh[4..8], SHT_PROGBITS); // sh_type
+                w64(&mut phdr_sh[8..16], SHF_ALLOC); // sh_flags
+                w64(&mut phdr_sh[16..24], load_vaddr); // sh_addr
+                w64(&mut phdr_sh[24..32], new_phoff as u64); // sh_offset
+                w64(&mut phdr_sh[32..40], (note_file_off - new_phoff) as u64); // sh_size
+                w64(&mut phdr_sh[48..56], PAGE as u64); // sh_addralign
+                sht.extend_from_slice(&phdr_sh);
+            }
 
             // The allocated SHT_NOTE section keeps the note reachable through the
             // section table (what BFD-based tools rebuild from); the runtime
-            // reads it through its PT_NOTE program header regardless.
+            // reads it through its PT_NOTE program header regardless. Without
+            // a PT_NOTE (`keep_phdrs`), the section is not mapped and the
+            // runtime reads it from the file instead.
             let mut note_sh = vec![0u8; e_shentsize];
             w32(&mut note_sh[0..4], note_name_index); // sh_name
             w32(&mut note_sh[4..8], SHT_NOTE); // sh_type
-            w64(&mut note_sh[8..16], SHF_ALLOC); // sh_flags
-            w64(&mut note_sh[16..24], note_vaddr); // sh_addr
+            if !keep_phdrs {
+                w64(&mut note_sh[8..16], SHF_ALLOC); // sh_flags
+                w64(&mut note_sh[16..24], note_vaddr); // sh_addr
+            }
             w64(&mut note_sh[24..32], note_file_off as u64); // sh_offset
             w64(&mut note_sh[32..40], note.len() as u64); // sh_size
             w64(&mut note_sh[48..56], 4); // sh_addralign
@@ -1492,13 +1528,15 @@ impl<'a> Elf<'a> {
             out.extend_from_slice(&sht);
 
             new_shoff = sht_new_off as u64;
-            new_shnum = (e_shnum + 2) as u16;
+            new_shnum = (e_shnum + if keep_phdrs { 1 } else { 2 }) as u16;
         }
 
         // Point the ELF header at the relocated, enlarged program header table
         // (and section header table, if one was added).
-        w64(&mut out[0x20..0x28], new_phoff as u64);
-        w16(&mut out[0x38..0x3a], new_phnum as u16);
+        if !keep_phdrs {
+            w64(&mut out[0x20..0x28], new_phoff as u64);
+            w16(&mut out[0x38..0x3a], new_phnum as u16);
+        }
         w64(&mut out[0x28..0x30], new_shoff);
         w16(&mut out[0x3c..0x3e], new_shnum);
 
@@ -1509,9 +1547,12 @@ mod elf {
 
 #[cfg(all(unix, not(target_vendor = "apple")))]
 mod elf {
-    use libc::{dl_iterate_phdr, dl_phdr_info, Elf64_Phdr, PT_NOTE};
+    use libc::{dl_iterate_phdr, dl_phdr_info, Elf64_Phdr};
     use std::os::raw::{c_int, c_void};
 
+    // Not exported by the libc crate on every platform (e.g. FreeBSD).
+    const PT_NOTE: u32 = 4;
+
     unsafe extern "C" fn sui_dl_iterate_phdr_callback(
         info: *mut dl_phdr_info,
         _size: usize,
@@ -1564,7 +1605,90 @@ mod elf {
             );
         }
 
-        find_section_in_phdr_info(&main_program_info, name)
+        let section = find_section_in_phdr_info(&main_program_info, name);
+        #[cfg(target_os = "freebsd")]
+        if matches!(section, Ok(None)) {
+            return find_section_in_exe_file(name);
+        }
+        section
+    }
+
+    /// Find a section that `Elf::append` stored without a `PT_LOAD` (see
+    /// `keep_phdrs`) by mapping it from the executable file.
+    #[cfg(target_os = "freebsd")]
+    fn find_section_in_exe_file(name: &str) -> std::io::Result<Option<&'static [u8]>> {
+        use std::os::unix::fs::FileExt;
+        use std::os::unix::io::AsRawFd;
+        const SHT_NOTE: u32 = 7;
+        const SHF_ALLOC: u64 = 2;
+
+        let file = std::fs::File::open(std::env::current_exe()?)?;
+        let read = |offset: u64, len: usize| -> std::io::Result<Vec<u8>> {
+            let mut buf = vec![0u8; len];
+            file.read_exact_at(&mut buf, offset)?;
+            Ok(buf)
+        };
+        let r16 = |b: &[u8]| u16::from_ne_bytes([b[0], b[1]]);
+        let r32 = |b: &[u8]| u32::from_ne_bytes([b[0], b[1], b[2], b[3]]);
+        let r64 = |b: &[u8]| {
+            let mut a = [0u8; 8];
+            a.copy_from_slice(&b[..8]);
+            u64::from_ne_bytes(a)
+        };
+
+        let ehdr = read(0, 64)?;
+        let e_shoff = r64(&ehdr[0x28..0x30]);
+        let e_shentsize = r16(&ehdr[0x3a..0x3c]) as usize;
+        let e_shnum = r16(&ehdr[0x3c..0x3e]) as usize;
+        if e_shoff == 0 || e_shentsize < 64 || e_shnum == 0 {
+            return Ok(None);
+        }
+        let sht = read(e_shoff, e_shnum * e_shentsize)?;
+        // The appended note is the last non-allocated SHT_NOTE section.
+        for sh in sht.chunks_exact(e_shentsize).rev() {
+            if r32(&sh[4..8]) != SHT_NOTE || r64(&sh[8..16]) & SHF_ALLOC != 0 {
+                continue;
+            }
+            let offset = r64(&sh[24..32]) as usize;
+            let len = r64(&sh[32..40]) as usize;
+            if len == 0 {
+                continue;
+            }
+            // Map the section rather than reading it, so that, as with a
+            // PT_LOAD, the (potentially large) payload is paged in on demand.
+            // SAFETY: sysconf is always safe to call for _SC_PAGESIZE.
+            let page = unsafe { libc::sysconf(libc::_SC_PAGESIZE) } as usize;
+            let map_offset = offset & !(page - 1);
+            let map_len = len + (offset - map_offset);
+            // SAFETY: a fresh read-only private mapping of the file; the
+            // kernel validates the range.
+            let ptr = unsafe {
+                libc::mmap(
+                    std::ptr::null_mut(),
+                    map_len,
+                    libc::PROT_READ,
+                    libc::MAP_PRIVATE,
+                    file.as_raw_fd(),
+                    map_offset as libc::off_t,
+                )
+            };
+            if ptr == libc::MAP_FAILED {
+                return Err(std::io::Error::last_os_error());
+            }
+            // SAFETY: the mapping covers `offset..offset + len` of the file.
+            let segment: &'static [u8] = unsafe {
+                std::slice::from_raw_parts((ptr as *const u8).add(offset - map_offset), len)
+            };
+            if let Some(section_data) = find_in_note_segment(segment, 4, name) {
+                // The mapping is kept for the rest of the process, like the
+                // mapped notes `find_section_in_phdr_info` returns.
+                return Ok(Some(section_data));
+            }
+            // SAFETY: `ptr`/`map_len` describe the mapping created above, and
+            // nothing borrows from it.
+            unsafe { libc::munmap(ptr, map_len) };
+        }
+        Ok(None)
     }
 
     fn find_section_in_phdr_info(
