--- base/debug/elf_reader.cc.orig	2020-03-03 18:52:59 UTC
+++ base/debug/elf_reader.cc
@@ -98,6 +98,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
     bool found = false;
     while (current_section < section_end) {
       current_note = reinterpret_cast<const Nhdr*>(current_section);
+#if !defined(OS_BSD)
       if (current_note->n_type == NT_GNU_BUILD_ID) {
         StringPiece note_name(current_section + sizeof(Nhdr),
                               current_note->n_namesz);
@@ -107,6 +108,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
           break;
         }
       }
+#endif
 
       size_t section_size = bits::Align(current_note->n_namesz, 4) +
                             bits::Align(current_note->n_descsz, 4) +
