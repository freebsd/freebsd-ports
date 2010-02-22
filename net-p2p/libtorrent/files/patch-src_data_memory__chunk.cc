*** src/data/memory_chunk.cc.orig	Wed Feb 10 09:55:42 2010
--- src/data/memory_chunk.cc	Wed Feb 10 09:56:26 2010
***************
*** 78,87 ****
--- 78,90 ----
  void
  MemoryChunk::unmap() {
    if (!is_valid())
      throw internal_error("MemoryChunk::unmap() called on an invalid object");
  
+    if (msync(m_ptr, m_end - m_ptr,MS_INVALIDATE) != 0)
+        throw internal_error("MemoryChunk::unmap() - msync() system call failed");
+ 
    if (munmap(m_ptr, m_end - m_ptr) != 0)
      throw internal_error("MemoryChunk::unmap() system call failed: " + std::string(rak::error_number::current().c_str()));
  }  
  
  void


