--- base/memory/madv_free_discardable_memory_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -292,6 +292,10 @@ void MadvFreeDiscardableMemoryPosix::SetKeepMemoryForT
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
+// XXX mincore
+#if defined(OS_BSD)
+  return false;
+#else
 #if defined(OS_APPLE)
   std::vector<char> vec(allocated_pages_);
 #else
@@ -307,6 +311,7 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
       return false;
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
