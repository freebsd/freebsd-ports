libc does not export PT_NOTE for FreeBSD.

FreeBSD's kernel only executes binaries whose program headers are in the
first page, so the relocated program header table produced by
Elf::append() makes `deno compile` output fail with ENOEXEC.  For
executables, append the payload as a non-allocated .note.sui section and
read it back from the executable file at runtime.  Shared libraries
(desktop mode's libdenort.so) keep the upstream layout, which rtld handles.

--- cargo-crates/libsui-0.16.4/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/libsui-0.16.4/lib.rs
@@ -1270,6 +1270,25 @@ impl<'a> Elf<'a> {
             return Err(Error::InvalidObject("Invalid program header table"));
         }
 
+        // The FreeBSD kernel refuses to execute binaries whose program
+        // headers are not within the first page.  For anything it loads
+        // itself (ET_EXEC, or a PIE with PT_INTERP), leave the program headers
+        // in place and append the note as a non-allocated section, which the
+        // runtime reads back from the executable file.  Shared libraries are
+        // mapped by rtld, which copes with relocated program headers.
+        const ELFOSABI_FREEBSD: u8 = 9;
+        const ET_EXEC: u16 = 2;
+        const PT_INTERP: u32 = 3;
+        if data[7] == ELFOSABI_FREEBSD
+            && (r16(&data[0x10..0x12]) == ET_EXEC
+                || (0..e_phnum).any(|i| {
+                    let off = e_phoff + i * e_phentsize;
+                    r32(&data[off..off + 4]) == PT_INTERP
+                }))
+        {
+            return self.append_note_section(name, sectdata, writer);
+        }
+
         // Scan existing program headers: find the highest mapped virtual
         // address (so the note lands above everything), the PT_PHDR entry, and
         // the first PT_LOAD's `p_vaddr - p_offset` bias.
@@ -1505,12 +1524,120 @@ impl<'a> Elf<'a> {
         writer.write_all(&out)?;
         Ok(())
     }
+
+    /// Append `sectdata` as a non-allocated `.note.sui` section, touching
+    /// only the section header table.
+    fn append_note_section<W: Write>(
+        &self,
+        name: &str,
+        sectdata: &[u8],
+        writer: &mut W,
+    ) -> Result<(), Error> {
+        const SHENTSIZE64: usize = 64;
+        const SHT_NOTE: u32 = 7;
+
+        let data = self.data;
+        let le = data[5] == 1;
+        let r16 = |b: &[u8]| -> u16 {
+            let a = [b[0], b[1]];
+            if le {
+                u16::from_le_bytes(a)
+            } else {
+                u16::from_be_bytes(a)
+            }
+        };
+        let r64 = |b: &[u8]| -> u64 {
+            let mut a = [0u8; 8];
+            a.copy_from_slice(&b[..8]);
+            if le {
+                u64::from_le_bytes(a)
+            } else {
+                u64::from_be_bytes(a)
+            }
+        };
+        let w16 = |b: &mut [u8], v: u16| {
+            let a = if le { v.to_le_bytes() } else { v.to_be_bytes() };
+            b[..2].copy_from_slice(&a);
+        };
+        let w32 = |b: &mut [u8], v: u32| {
+            let a = if le { v.to_le_bytes() } else { v.to_be_bytes() };
+            b[..4].copy_from_slice(&a);
+        };
+        let w64 = |b: &mut [u8], v: u64| {
+            let a = if le { v.to_le_bytes() } else { v.to_be_bytes() };
+            b[..8].copy_from_slice(&a);
+        };
+
+        let e_shoff = r64(&data[0x28..0x30]) as usize;
+        let e_shentsize = r16(&data[0x3a..0x3c]) as usize;
+        let e_shnum = r16(&data[0x3c..0x3e]) as usize;
+        let e_shstrndx = r16(&data[0x3e..0x40]) as usize;
+        if e_shoff == 0
+            || e_shentsize < SHENTSIZE64
+            || e_shnum == 0
+            || e_shnum >= 0xff00
+            || e_shstrndx == 0
+            || e_shstrndx >= e_shnum
+            || e_shoff
+                .checked_add(e_shnum * e_shentsize)
+                .map(|end| end > data.len())
+                .unwrap_or(true)
+        {
+            return Err(Error::InvalidObject("Invalid section header table"));
+        }
+        let hdr = &data[e_shoff + e_shstrndx * e_shentsize..];
+        let shstr_off = r64(&hdr[24..32]) as usize;
+        let shstr_size = r64(&hdr[32..40]) as usize;
+        if shstr_off
+            .checked_add(shstr_size)
+            .map(|end| end > data.len())
+            .unwrap_or(true)
+        {
+            return Err(Error::InvalidObject("Invalid section name table"));
+        }
+
+        let note = build_elf_note_payload(name, sectdata);
+        let mut out = data.to_vec();
+        let note_off = align_up(out.len(), 4);
+        out.resize(note_off, 0);
+        out.extend_from_slice(&note);
+
+        let mut new_shstr = data[shstr_off..shstr_off + shstr_size].to_vec();
+        let note_name_index = new_shstr.len() as u32;
+        new_shstr.extend_from_slice(b".note.sui\0");
+        let shstr_new_off = out.len();
+        out.extend_from_slice(&new_shstr);
+        let sht_new_off = align_up(out.len(), 8);
+        out.resize(sht_new_off, 0);
+
+        let mut sht = data[e_shoff..e_shoff + e_shnum * e_shentsize].to_vec();
+        {
+            let e = &mut sht[e_shstrndx * e_shentsize..];
+            w64(&mut e[24..32], shstr_new_off as u64);
+            w64(&mut e[32..40], new_shstr.len() as u64);
+        }
+        let mut note_sh = vec![0u8; e_shentsize];
+        w32(&mut note_sh[0..4], note_name_index); // sh_name
+        w32(&mut note_sh[4..8], SHT_NOTE); // sh_type
+        w64(&mut note_sh[24..32], note_off as u64); // sh_offset
+        w64(&mut note_sh[32..40], note.len() as u64); // sh_size
+        w64(&mut note_sh[48..56], 4); // sh_addralign
+        sht.extend_from_slice(&note_sh);
+        out.extend_from_slice(&sht);
+
+        w64(&mut out[0x28..0x30], sht_new_off as u64);
+        w16(&mut out[0x3c..0x3e], (e_shnum + 1) as u16);
+
+        writer.write_all(&out)?;
+        Ok(())
+    }
 }
 
 #[cfg(all(unix, not(target_vendor = "apple")))]
 mod elf {
-    use libc::{dl_iterate_phdr, dl_phdr_info, Elf64_Phdr, PT_NOTE};
+    use libc::{dl_iterate_phdr, dl_phdr_info, Elf64_Phdr};
     use std::os::raw::{c_int, c_void};
+    const PT_NOTE: u32 = 4;
 
     unsafe extern "C" fn sui_dl_iterate_phdr_callback(
         info: *mut dl_phdr_info,
@@ -1564,7 +1691,61 @@ mod elf {
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
+    /// Find a section appended by `Elf::append_note_section`, which is not
+    /// mapped into memory, by reading the executable file.
+    #[cfg(target_os = "freebsd")]
+    fn find_section_in_exe_file(name: &str) -> std::io::Result<Option<&'static [u8]>> {
+        use std::os::unix::fs::FileExt;
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
+            let segment = read(r64(&sh[24..32]), r64(&sh[32..40]) as usize)?;
+            let Some(found) = find_in_note_segment(&segment, 4, name) else {
+                continue;
+            };
+            let start = found.as_ptr() as usize - segment.as_ptr() as usize;
+            let len = found.len();
+            // Leaked deliberately: callers expect data that lives for the
+            // rest of the process, like the mapped notes found above.
+            let segment: &'static [u8] = Box::leak(segment.into_boxed_slice());
+            return Ok(Some(&segment[start..start + len]));
+        }
+        Ok(None)
     }
 
     fn find_section_in_phdr_info(
