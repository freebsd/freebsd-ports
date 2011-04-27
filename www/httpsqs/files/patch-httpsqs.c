--- httpsqs.c.orig	2011-04-14 00:46:09.000000000 -0500
+++ httpsqs.c	2011-04-23 03:19:34.920926265 -0500
@@ -30,6 +30,7 @@ This is free software, and you are welco
 #include <signal.h>
 #include <stdbool.h>
 #include <pthread.h>
+#include <sys/wait.h>
 
 #include <err.h>
 #include <event.h>
@@ -656,7 +657,7 @@ int main(int argc, char *argv[], char *e
 	char httpsqs_path_file[1024] = { 0 }; // httpsqs_path_file 为 httpsqs 程序的绝对路径
 	struct evbuffer *httpsqs_prename_buf; /* 原命令行参数 */
     httpsqs_prename_buf = evbuffer_new();
-	readlink("/proc/self/exe", httpsqs_path_file, sizeof(httpsqs_path_file));
+	//readlink("/proc/self/exe", httpsqs_path_file, sizeof(httpsqs_path_file));
 	evbuffer_add_printf(httpsqs_prename_buf, "%s", httpsqs_path_file);
 	for (httpsqs_prename_num = 1; httpsqs_prename_num < argc; httpsqs_prename_num++) {
 		evbuffer_add_printf(httpsqs_prename_buf, " %s", argv[httpsqs_prename_num]);
