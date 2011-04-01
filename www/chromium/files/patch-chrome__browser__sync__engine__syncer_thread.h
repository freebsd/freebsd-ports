--- chrome/browser/sync/engine/syncer_thread.h.orig	2011-01-06 10:01:41.000000000 +0100
+++ chrome/browser/sync/engine/syncer_thread.h	2011-01-09 20:25:21.000000000 +0100
@@ -26,7 +26,7 @@
 #include "chrome/browser/sync/syncable/model_type.h"
 #include "chrome/common/deprecated/event_sys-inl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/browser/sync/engine/idle_query_linux.h"
 #endif
 
@@ -329,7 +329,7 @@
       NudgeSource source,
       const syncable::ModelTypeBitSet& model_types);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // On Linux, we need this information in order to query idle time.
   scoped_ptr<IdleQueryLinux> idle_query_;
 #endif
