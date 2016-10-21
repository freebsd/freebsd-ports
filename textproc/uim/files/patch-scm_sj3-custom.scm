--- scm/sj3-custom.scm.orig	2013-06-30 04:26:09 UTC
+++ scm/sj3-custom.scm
@@ -339,7 +339,7 @@
   (N_ "SJ3 user name")
   (N_ "long description will be here."))
 
-(define-custom 'sj3-unix-domain-socket-path "/var/sj3/run/sj3serv.socket"
+(define-custom 'sj3-unix-domain-socket-path "/var/run/sj3/socket"
   '(sj3-advanced sj3server)
   '(string ".*")
   (N_ "SJ3 server socket path")
