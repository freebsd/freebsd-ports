--- startsrv.sh.orig	Sat Nov 17 16:28:07 2001
+++ startsrv.sh	Sat Nov 17 16:28:19 2001
@@ -19,7 +19,7 @@
 
 default_options='-b 9600 -w 8 -p none'
 default_sock_prot='ug=rw,o='
-default_sock_owner='root.wheel'
+default_sock_owner='root:wheel'
 default_log_prot='u=rw,g=r,o='
 
 for host
