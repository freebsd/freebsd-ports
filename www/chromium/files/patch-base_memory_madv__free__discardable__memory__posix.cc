--- base/memory/madv_free_discardable_memory_posix.cc.orig	2021-04-14 18:40:48 UTC
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -292,7 +292,7 @@ void MadvFreeDiscardableMemoryPosix::SetKeepMemoryForT
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
   std::vector<char> vec(allocated_pages_);
 #else
   std::vector<unsigned char> vec(allocated_pages_);
