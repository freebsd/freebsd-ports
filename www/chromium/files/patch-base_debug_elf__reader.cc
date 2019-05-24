--- base/debug/elf_reader.cc.orig	2019-04-30 22:22:28 UTC
+++ base/debug/elf_reader.cc
@@ -82,6 +82,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
         reinterpret_cast<const Nhdr*>(elf_base + header.p_offset);
     bool found = false;
     while (current_note < section_end) {
+#if !defined(OS_BSD)
       if (current_note->n_type == NT_GNU_BUILD_ID) {
         const char* note_name =
             reinterpret_cast<const char*>(current_note) + sizeof(Nhdr);
@@ -91,6 +92,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
           break;
         }
       }
+#endif
 
       current_note = reinterpret_cast<const Nhdr*>(
           reinterpret_cast<const char*>(current_note) + sizeof(Nhdr) +
