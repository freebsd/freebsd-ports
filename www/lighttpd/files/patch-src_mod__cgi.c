--- src/mod_cgi.c.orig	2016-10-31 13:16:40 UTC
+++ src/mod_cgi.c
@@ -35,8 +35,9 @@
 
 #include <stdio.h>
 #include <fcntl.h>
+#include <sys/param.h>
 
-#if defined(O_CLOEXEC) && (!defined(__FreeBSD__) || defined(F_DUPFD_CLOEXEC))
+#if defined(O_CLOEXEC) && (!defined(__FreeBSD__) || __FreeBSD_version >= 1000032) 
 #define pipe_cloexec(pipefd) pipe2((pipefd), O_CLOEXEC)
 #elif defined FD_CLOEXEC
 #define pipe_cloexec(pipefd) \
