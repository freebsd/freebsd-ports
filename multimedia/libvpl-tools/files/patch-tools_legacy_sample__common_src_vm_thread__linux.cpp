--- tools/legacy/sample_common/src/vm/thread_linux.cpp.orig	2026-06-25 23:06:43 UTC
+++ tools/legacy/sample_common/src/vm/thread_linux.cpp
@@ -283,12 +283,16 @@ mfxStatus msdk_thread_get_schedtype(const char* str, m
     else if (msdk_match(str, "other")) {
         type = SCHED_OTHER;
     }
+#ifdef SCHED_BATCH
     else if (msdk_match(str, "batch")) {
         type = SCHED_BATCH;
     }
+#endif
+#ifdef SCHED_IDLE
     else if (msdk_match(str, "idle")) {
         type = SCHED_IDLE;
     }
+#endif
     else {
         return MFX_ERR_UNSUPPORTED;
     }
