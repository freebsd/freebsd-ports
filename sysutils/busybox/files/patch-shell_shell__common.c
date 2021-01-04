--- shell/shell_common.c.orig	2021-01-01 13:30:58 UTC
+++ shell/shell_common.c
@@ -327,7 +327,9 @@ struct limits {
 static const struct limits limits_tbl[] = {
 	{ RLIMIT_CORE,		9,	}, // -c
 	{ RLIMIT_DATA,		10,	}, // -d
+#ifdef RLIMIT_NICE
 	{ RLIMIT_NICE,		0,	}, // -e
+#endif
 	{ RLIMIT_FSIZE,		9,	}, // -f
 #define LIMIT_F_IDX     3
 #ifdef RLIMIT_SIGPENDING
