--- plugins/check_load.c.orig	2020-02-24 15:17:13 UTC
+++ plugins/check_load.c
@@ -111,7 +111,7 @@ main (int argc, char **argv)
 	int len;
 #endif
 
-	setlocale (LC_ALL, "");
+	setlocale (LC_ALL, ""); setlocale(LC_NUMERIC, "C");
 	bindtextdomain (PACKAGE, LOCALEDIR);
 	textdomain (PACKAGE);
 	setlocale(LC_NUMERIC, "POSIX");
@@ -351,6 +351,7 @@ int cmpstringp(const void *p1, const void *p2) {
 	pid_t kthread_ppid = 0;
 	int procvsz = 0;
 	int procrss = 0;
+	int procjid = 0;
 	float procpcpu = 0;
 	char procstat[8];
 #ifdef PS_USES_PROCETIME
