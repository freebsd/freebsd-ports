--- src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc
@@ -299,6 +299,10 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
+// XXX mincore
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
 #if BUILDFLAG(IS_APPLE)
   std::vector<char> vec(allocated_pages_);
 #else
@@ -314,6 +318,7 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
       return false;
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
