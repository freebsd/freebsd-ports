--- src/ucm/util/reloc.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/util/reloc.c
@@ -97,8 +97,15 @@ ucm_reloc_get_pointer(ElfW(Addr) base, const ElfW(Phdr
 {
     uintptr_t entry = ucm_reloc_get_entry(base, dphdr, tag);
 
-#if defined(__riscv)
-    /* On RISC-V these are not pointers but offsets */
+#if defined(__FreeBSD__) || defined(__riscv)
+    /*
+     * On FreeBSD, the dynamic-section pointer entries we consume here
+     * (DT_SYMTAB, DT_STRTAB, DT_JMPREL, DT_RELA, ...) are observed through
+     * dl_iterate_phdr() as object-relative virtual addresses for shared
+     * objects, so they must be rebased by dlpi_addr before dereference.
+     *
+     * RISC-V already required the same treatment.
+     */
     return UCS_PTR_BYTE_OFFSET(base, entry);
 #else
     return (void *)entry;
@@ -353,7 +360,8 @@ static ucs_status_t ucm_reloc_dl_info_get(const struct
         if (phdr->p_type == PT_LOAD) {
             /* Found loadable section - update address range */
             dl_info->start = ucs_min(dl_info->start, dlpi_addr + phdr->p_vaddr);
-            dl_info->end   = ucs_max(dl_info->end, phdr->p_vaddr + phdr->p_memsz);
+            dl_info->end   = ucs_max(dl_info->end, dlpi_addr + phdr->p_vaddr +
+                                                   phdr->p_memsz);
             found_pt_load  = 1;
         } else if (phdr->p_type == PT_DYNAMIC) {
             /* Found dynamic section */
@@ -673,10 +681,13 @@ static int ucm_dlclose(void *handle)
          * cached information anyway, and it may be re-added on the next call to
          * ucm_reloc_apply_patch().
          */
-        dl_name = ucm_reloc_get_dl_name(lm_entry->l_name, lm_entry->l_addr,
+        ElfW(Addr) dlpi_addr;
+        dlpi_addr = (ElfW(Addr))(uintptr_t)lm_entry->l_addr;
+
+        dl_name = ucm_reloc_get_dl_name(lm_entry->l_name, dlpi_addr,
                                         dl_name_buffer, sizeof(dl_name_buffer));
         pthread_mutex_lock(&ucm_reloc_patch_list_lock);
-        ucm_reloc_dl_info_cleanup(lm_entry->l_addr, dl_name);
+        ucm_reloc_dl_info_cleanup(dlpi_addr, dl_name);
         pthread_mutex_unlock(&ucm_reloc_patch_list_lock);
     }
 
