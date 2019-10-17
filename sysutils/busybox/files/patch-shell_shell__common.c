--- shell/shell_common.c.orig	2019-06-10 09:09:31 UTC
+++ shell/shell_common.c
@@ -328,7 +328,9 @@ struct limits {
 static const struct limits limits_tbl[] = {
 	{ RLIMIT_CORE,		9,	"core file size (blocks)" }, // -c
 	{ RLIMIT_DATA,		10,	"data seg size (kb)" },      // -d
+#ifdef RLIMIT_NICE
 	{ RLIMIT_NICE,		0,	"scheduling priority" },     // -e
+#endif
 	{ RLIMIT_FSIZE,		9,	"file size (blocks)" },      // -f
 #define LIMIT_F_IDX     3
 #ifdef RLIMIT_SIGPENDING
