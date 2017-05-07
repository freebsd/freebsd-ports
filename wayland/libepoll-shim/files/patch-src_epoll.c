--- src/epoll.c.orig	2016-08-12 13:15:11 UTC
+++ src/epoll.c
@@ -9,7 +9,7 @@
 #include <poll.h>
 #include <signal.h>
 
-#if 0
+#if 1
 int epoll_create(int size)
 {
 	return epoll_create1(0);
