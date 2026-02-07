--- src/data/memory_chunk.cc.orig	2025-09-05 08:47:37 UTC
+++ src/data/memory_chunk.cc
@@ -49,6 +49,9 @@ MemoryChunk::unmap() {
   if (!is_valid())
     throw internal_error("MemoryChunk::unmap() called on an invalid object");
 
+  if (msync(m_ptr, m_end - m_ptr,MS_INVALIDATE) != 0)
+    throw internal_error("MemoryChunk::unmap() - msync() system call failed");
+
   if (munmap(m_ptr, m_end - m_ptr) != 0)
     throw internal_error("MemoryChunk::unmap() system call failed: " + std::string(rak::error_number::current().c_str()));
 }
