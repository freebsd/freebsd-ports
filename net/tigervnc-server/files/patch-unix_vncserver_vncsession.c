diff --git unix/vncserver/vncsession.c unix/vncserver/vncsession.c
index 3e0c98f0..cdac9d1a 100644
--- unix/vncserver/vncsession.c
+++ unix/vncserver/vncsession.c
@@ -339,7 +339,7 @@ static void
 redir_stdio(const char *homedir, const char *display)
 {
     int fd;
-    char hostname[HOST_NAME_MAX+1];
+    char hostname[_SC_HOST_NAME_MAX+1];
     char logfile[PATH_MAX];
 
     fd = open("/dev/null", O_RDONLY);
