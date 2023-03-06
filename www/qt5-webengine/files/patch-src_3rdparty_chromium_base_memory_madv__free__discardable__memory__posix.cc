--- src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc
@@ -296,7 +296,7 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
   std::vector<char> vec(allocated_pages_);
 #else
   std::vector<unsigned char> vec(allocated_pages_);
