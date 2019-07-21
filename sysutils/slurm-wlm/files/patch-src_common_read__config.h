--- src/common/read_config.h.orig	2019-05-28 17:23:14 UTC
+++ src/common/read_config.h
@@ -113,7 +113,7 @@ extern uint16_t drop_priv_flag;
 #define DEFAULT_KILL_TREE           0
 #define DEFAULT_KILL_WAIT           30
 #define DEFAULT_LAUNCH_TYPE         "launch/slurm"
-#define DEFAULT_MAIL_PROG           "/bin/mail"
+#define DEFAULT_MAIL_PROG           "/usr/bin/mail"
 #define DEFAULT_MAIL_PROG_ALT       "/usr/bin/mail"
 #define DEFAULT_MAX_ARRAY_SIZE      1001
 #define DEFAULT_MAX_JOB_COUNT       10000
@@ -129,7 +129,11 @@ extern uint16_t drop_priv_flag;
 #define DEFAULT_MSG_TIMEOUT         10
 #define DEFAULT_POWER_PLUGIN        ""
 #define DEFAULT_CHECKPOINT_TYPE     "checkpoint/none"
-#define DEFAULT_PROCTRACK_TYPE      "proctrack/cgroup"
+#if defined __linux__
+#  define DEFAULT_PROCTRACK_TYPE    "proctrack/cgroup"
+#else
+#  define DEFAULT_PROCTRACK_TYPE    "proctrack/pgid"
+#endif
 #define DEFAULT_PREEMPT_TYPE        "preempt/none"
 #define DEFAULT_PRIORITY_DECAY      604800 /* 7 days */
 #define DEFAULT_PRIORITY_CALC_PERIOD 300 /* in seconds */
