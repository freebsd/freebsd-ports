--- base/debug/elf_reader.cc.orig	2021-07-19 18:45:05 UTC
+++ base/debug/elf_reader.cc
@@ -39,7 +39,9 @@ using Nhdr = Elf64_Nhdr;
 using Word = Elf64_Word;
 #endif
 
+#if !defined(OS_BSD)
 constexpr char kGnuNoteName[] = "GNU";
+#endif
 
 // Returns a pointer to the header of the ELF binary mapped into memory, or a
 // null pointer if the header is invalid. Here and below |elf_mapped_base| is a
@@ -76,6 +78,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
     bool found = false;
     while (current_section < section_end) {
       current_note = reinterpret_cast<const Nhdr*>(current_section);
+#if !defined(OS_BSD)
       if (current_note->n_type == NT_GNU_BUILD_ID) {
         StringPiece note_name(current_section + sizeof(Nhdr),
                               current_note->n_namesz);
@@ -85,6 +88,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
           break;
         }
       }
+#endif
 
       size_t section_size = bits::AlignUp(current_note->n_namesz, 4) +
                             bits::AlignUp(current_note->n_descsz, 4) +
