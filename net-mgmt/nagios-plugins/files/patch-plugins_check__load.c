--- plugins/check_load.c.orig	2019-12-09 11:57:36 UTC
+++ plugins/check_load.c
@@ -351,6 +351,7 @@ int cmpstringp(const void *p1, const void *p2) {
 	pid_t kthread_ppid = 0;
 	int procvsz = 0;
 	int procrss = 0;
+	int procjid = 0;
 	float procpcpu = 0;
 	char procstat[8];
 #ifdef PS_USES_PROCETIME
