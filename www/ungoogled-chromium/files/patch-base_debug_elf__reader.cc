--- base/debug/elf_reader.cc.orig	2026-11-17 11:49:09 UTC
+++ base/debug/elf_reader.cc
@@ -45,6 +45,10 @@ constexpr char kGnuNoteName[] = "GNU";
 // Support up to 32 bytes (for blake3 & SHA256).
 constexpr size_t kMaxBuildIdByteLength = 32;
 
+#ifndef NT_GNU_BUILD_ID
+#define NT_GNU_BUILD_ID 3
+#endif
+
 // Returns a pointer to the header of the ELF binary mapped into memory, or a
 // null pointer if the header is invalid. Here and below |elf_mapped_base| is a
 // pointer to the start of the ELF image.
