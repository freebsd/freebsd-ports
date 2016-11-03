--- src/mod_cgi.c.orig 2016-11-02 13:53:21 UTC
+++ src/mod_cgi.c
@@ -36,7 +36,7 @@
 #include <stdio.h>
 #include <fcntl.h>

-#if defined(O_CLOEXEC) && (!defined(__FreeBSD__) || defined(F_DUPFD_CLOEXEC))
+#if defined(O_CLOEXEC) && __FreeBSD_version >= 1000032
 #define pipe_cloexec(pipefd) pipe2((pipefd), O_CLOEXEC)
 #elif defined FD_CLOEXEC
 #define pipe_cloexec(pipefd) \
