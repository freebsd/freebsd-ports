--- src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc.orig	2020-04-08 09:41:36 UTC
+++ src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc
@@ -271,7 +271,7 @@ void MadvFreeDiscardableMemoryPosix::SetKeepMemoryForT
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(OS_BSD)
   std::vector<char> vec(allocated_pages_);
 #else
   std::vector<unsigned char> vec(allocated_pages_);
