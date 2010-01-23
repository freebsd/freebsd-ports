--- libpurple/protocols/zephyr/Zinternal.c.orig	2010-01-21 11:30:42.000000000 -0800
+++ libpurple/protocols/zephyr/Zinternal.c	2010-01-21 11:30:50.000000000 -0800
@@ -30,7 +30,6 @@
 #else
 #include <arpa/inet.h>
 #include <sys/socket.h>
-#include <utmp.h>
 #endif
 
 int __Zephyr_fd = -1;
