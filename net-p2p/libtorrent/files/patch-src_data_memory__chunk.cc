--- src/data/memory_chunk.cc.orig	2010-02-10 09:55:42 UTC
+++ src/data/memory_chunk.cc
@@ -86,6 +86,9 @@
   if (!is_valid())
     throw internal_error("MemoryChunk::unmap() called on an invalid object");
 
+  if (msync(m_ptr, m_end - m_ptr,MS_INVALIDATE) != 0)
+    throw internal_error("MemoryChunk::unmap() - msync() system call failed");
+
   if (munmap(m_ptr, m_end - m_ptr) != 0)
     throw internal_error("MemoryChunk::unmap() system call failed: " + std::string(rak::error_number::current().c_str()));
 }  
