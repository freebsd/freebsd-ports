--- src/3rdparty/chromium/base/debug/elf_reader_linux.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/debug/elf_reader_linux.cc
@@ -41,8 +41,10 @@ Optional<std::string> ElfSegmentBuildIDNoteAsString(co
   const void* section_end = segment.data() + segment.size_bytes();
   const Nhdr* note_header = reinterpret_cast<const Nhdr*>(segment.data());
   while (note_header < section_end) {
+#if !defined(OS_BSD)
     if (note_header->n_type == NT_GNU_BUILD_ID)
       break;
+#endif
     note_header = reinterpret_cast<const Nhdr*>(
         reinterpret_cast<const char*>(note_header) + sizeof(Nhdr) +
         bits::Align(note_header->n_namesz, 4) +
