--- lib/user_exit.c.orig	2026-06-21 09:49:29 UTC
+++ lib/user_exit.c
@@ -13,6 +13,7 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <signal.h>
+#include <stdio.h>
 
 int sigterm_signaled=0;
 
