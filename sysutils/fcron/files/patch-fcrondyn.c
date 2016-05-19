Fix use of size_t in context where ssize_t (error value included) is
more correct.

--- fcrondyn.c.orig	2014-05-10 17:03:59 UTC
+++ fcrondyn.c
@@ -482,7 +482,7 @@ talk_fcron(char *cmd_str, int fd)
     long int *cmd = NULL;
     int cmd_len = 0;
     char buf[LINE_LEN];
-    size_t read_len = 0;
+    ssize_t read_len = 0;
     char existing_connection = (fd < 0) ? 0 : 1;
     fd_set read_set;            /* needed to use select to check if some data is waiting */
     struct timeval tv;
@@ -578,7 +578,7 @@ talk_fcron(char *cmd_str, int fd)
     }
 
 
-    while ((read_len = (size_t) recv(fd, buf, sizeof(buf) - 1, 0)) >= 0
+    while ((read_len = (ssize_t) recv(fd, buf, sizeof(buf) - 1, 0)) >= 0
            || errno == EINTR) {
 
         if (errno == EINTR && debug_opt)
