--- src/common/read_config.h.orig	2018-10-23 14:45:36 UTC
+++ src/common/read_config.h
@@ -140,8 +140,10 @@ extern uint16_t drop_priv_flag;
 #define DEFAULT_CHECKPOINT_TYPE     "checkpoint/none"
 #if defined HAVE_REAL_CRAY/* ALPS requires cluster-unique job container IDs */
 #  define DEFAULT_PROCTRACK_TYPE    "proctrack/sgi_job"
-#else
+#elif defined __linux__
 #  define DEFAULT_PROCTRACK_TYPE    "proctrack/cgroup"
+#else
+#  define DEFAULT_PROCTRACK_TYPE    "proctrack/pgid"
 #endif
 #define DEFAULT_PREEMPT_TYPE        "preempt/none"
 #define DEFAULT_PRIORITY_DECAY      604800 /* 7 days */
