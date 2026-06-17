--- src/ucm/util/reloc.c.orig	2026-06-17 21:33:49 UTC
+++ src/ucm/util/reloc.c
@@ -28,12 +28,9 @@
 #include <fcntl.h>
 #include <link.h>
 #include <limits.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
 
-#if HAVE_DECL_GETAUXVAL
-#include <sys/auxv.h>
-#endif
-
-
 /* Ensure this macro is defined (from <link.h>) - otherwise, cppcheck might
    fail with an "unknown macro" warning */
 #ifndef ElfW
@@ -97,8 +94,15 @@ ucm_reloc_get_pointer(ElfW(Addr) base, const ElfW(Phdr
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
@@ -118,84 +122,10 @@ static ucs_status_t ucm_reloc_get_aux_phsize(int *phsi
 
 static ucs_status_t ucm_reloc_get_aux_phsize(int *phsize_p)
 {
-#define UCM_RELOC_AUXV_BUF_LEN 16
-    static const char *proc_auxv_filename = "/proc/self/auxv";
-    static int phsize = 0;
-    ucm_auxv_t buffer[UCM_RELOC_AUXV_BUF_LEN];
-    ucm_auxv_t *auxv;
-    unsigned count;
-    ssize_t nread;
-    int found;
-    int fd;
-
-    /* Can avoid lock here - worst case we'll read the file more than once */
-    if (phsize != 0) {
-        *phsize_p = phsize;
-        return UCS_OK;
-    }
-
-#if HAVE_DECL_GETAUXVAL
-    phsize = getauxval(AT_PHENT);
-    if (phsize > 0) {
-        *phsize_p = phsize;
-        return UCS_OK;
-    }
-#endif
-
-    fd = open(proc_auxv_filename, O_RDONLY);
-    if (fd < 0) {
-        ucm_error("failed to open '%s' for reading: %m", proc_auxv_filename);
-        return UCS_ERR_IO_ERROR;
-    }
-
-    if (RUNNING_ON_VALGRIND) {
-        /* Work around a bug caused by valgrind's fake /proc/self/auxv -
-         * every time this file is opened when running with valgrind, a
-         * a duplicate of the same fd is returned, so all share the same
-         * file offset.
-         */
-        ucm_reloc_file_lock(fd, F_WRLCK);
-        lseek(fd, 0, SEEK_SET);
-    }
-
-    /* Use small buffer on the stack, avoid using malloc() */
-    found = 0;
-    do {
-        nread = read(fd, buffer, sizeof(buffer));
-        if (nread < 0) {
-            ucm_error("failed to read %lu bytes from %s (ret=%ld): %m",
-                      sizeof(buffer), proc_auxv_filename, nread);
-            break;
-        }
-
-        count = nread / sizeof(buffer[0]);
-        for (auxv = buffer; (auxv < (buffer + count)) && (auxv->type != AT_NULL);
-             ++auxv)
-        {
-            if ((auxv->type == AT_PHENT) && (auxv->value > 0)) {
-                found  = 1;
-                phsize = auxv->value;
-                ucm_debug("read phent from %s: %d", proc_auxv_filename, phsize);
-                if (phsize == 0) {
-                    ucm_error("phsize is 0");
-                }
-                break;
-            }
-        }
-    } while ((count > 0) && !found);
-
-    if (RUNNING_ON_VALGRIND) {
-        ucm_reloc_file_lock(fd, F_UNLCK);
-    }
-    close(fd);
-
-    if (!found) {
-        ucm_error("AT_PHENT entry not found in %s", proc_auxv_filename);
-        return UCS_ERR_NO_ELEM;
-    }
-
-    *phsize_p = phsize;
-    return UCS_OK;
+    /* TODO: Implement full FreeBSD RTLD binary patching engine support.
+     * Enforcing UCS_ERR_UNSUPPORTED stubs out libucm for this iteration 
+     * to prevent early-init memory interposition conflicts. */
+    return UCS_ERR_UNSUPPORTED;
 }
 
 ElfW(Rela) *ucm_reloc_find_sym(void *table, size_t table_size, const char *symbol,
@@ -353,7 +283,8 @@ static ucs_status_t ucm_reloc_dl_info_get(const struct
         if (phdr->p_type == PT_LOAD) {
             /* Found loadable section - update address range */
             dl_info->start = ucs_min(dl_info->start, dlpi_addr + phdr->p_vaddr);
-            dl_info->end   = ucs_max(dl_info->end, phdr->p_vaddr + phdr->p_memsz);
+            dl_info->end   = ucs_max(dl_info->end, dlpi_addr + phdr->p_vaddr +
+                                                   phdr->p_memsz);
             found_pt_load  = 1;
         } else if (phdr->p_type == PT_DYNAMIC) {
             /* Found dynamic section */
@@ -673,10 +604,13 @@ static int ucm_dlclose(void *handle)
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
 
