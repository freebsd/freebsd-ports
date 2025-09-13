--- base/memory/madv_free_discardable_memory_posix.cc.orig	2025-09-11 13:19:19 UTC
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -298,6 +298,10 @@ void MadvFreeDiscardableMemoryPosix::SetKeepMemoryForT
 
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
     }
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
