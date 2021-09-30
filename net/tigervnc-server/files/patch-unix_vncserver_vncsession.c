--- unix/vncserver/vncsession.c.orig	2020-09-08 12:16:08 UTC
+++ unix/vncserver/vncsession.c
@@ -339,7 +339,7 @@ static void
 redir_stdio(const char *homedir, const char *display)
 {
     int fd;
-    char hostname[HOST_NAME_MAX+1];
+    char hostname[_POSIX_HOST_NAME_MAX+1];
     char logfile[PATH_MAX];
 
     fd = open("/dev/null", O_RDONLY);
