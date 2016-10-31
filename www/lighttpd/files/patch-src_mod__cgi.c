--- src/mod_cgi.c.orig	2016-10-16 10:48:26 UTC
+++ src/mod_cgi.c
@@ -32,13 +32,14 @@
 #include <signal.h>
 #include <ctype.h>
 #include <assert.h>
+#include <sys/param.h>
 
 #include <stdio.h>
 #include <fcntl.h>
 
-#ifdef O_CLOEXEC
+#if defined(O_CLOEXEC) && __FreeBSD_version >= 1000032
 #define pipe_cloexec(pipefd) pipe2((pipefd), O_CLOEXEC)
-#elif defined FD_CLOEXEC
+#elif defined(FD_CLOEXEC)
 #define pipe_cloexec(pipefd) \
   (   0 == pipe(pipefd) \
    && 0 == fcntl(pipefd[0], F_SETFD, FD_CLOEXEC) \
