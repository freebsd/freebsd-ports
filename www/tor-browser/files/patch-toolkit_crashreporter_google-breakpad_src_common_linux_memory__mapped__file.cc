commit d47074b830ce057d758b8d1e9200829824666cd5
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    disable linux-only code in crashreporter on FreeBSD
    
    The crashreporter itself is not active here anyway, but parts
    of the code are still compiled for interface reasons. We skip
    the parts which are linux-only.

diff --git toolkit/crashreporter/google-breakpad/src/common/linux/memory_mapped_file.cc toolkit/crashreporter/google-breakpad/src/common/linux/memory_mapped_file.cc
index c18ddb01f8bc..98506221e3ba 100644
--- toolkit/crashreporter/google-breakpad/src/common/linux/memory_mapped_file.cc
+++ toolkit/crashreporter/google-breakpad/src/common/linux/memory_mapped_file.cc
@@ -58,6 +58,9 @@ MemoryMappedFile::~MemoryMappedFile() {
 
 bool MemoryMappedFile::Map(const char* path, size_t offset) {
   Unmap();
+#if defined(__FreeBSD__)
+    return false;
+#else
 
   int fd = sys_open(path, O_RDONLY, 0);
   if (fd == -1) {
@@ -97,13 +100,16 @@ bool MemoryMappedFile::Map(const char* path, size_t offset) {
 
   content_.Set(data, file_len - offset);
   return true;
+#endif
 }
 
 void MemoryMappedFile::Unmap() {
+#if !defined(__FreeBSD__)
   if (content_.data()) {
     sys_munmap(const_cast<uint8_t*>(content_.data()), content_.length());
     content_.Set(NULL, 0);
   }
+#endif
 }
 
 }  // namespace google_breakpad
