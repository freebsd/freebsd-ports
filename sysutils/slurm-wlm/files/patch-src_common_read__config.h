--- src/common/read_config.h.orig	2020-01-18 14:09:19 UTC
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
