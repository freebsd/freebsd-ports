--- sfsauthd/sfsdeclog.C.orig	Wed Jan  1 17:52:31 2003
+++ sfsauthd/sfsdeclog.C	Wed Jan  1 17:52:51 2003
@@ -43,7 +43,7 @@
 }
 
 void
-writewait (int fd)
+writewait (unsigned int fd)
 {
   fd_set fds;
   assert (fd < FD_SETSIZE);
