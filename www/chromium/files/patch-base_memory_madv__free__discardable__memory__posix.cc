--- base/memory/madv_free_discardable_memory_posix.cc.orig	2020-03-03 18:53:47 UTC
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -267,7 +267,7 @@ void MadvFreeDiscardableMemoryPosix::SetKeepMemoryForT
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(OS_BSD)
   std::vector<char> vec(allocated_pages_);
 #else
   std::vector<unsigned char> vec(allocated_pages_);
