diff -urN -x .svn ../../vendor/vpopmail/vqmaillocal.c ./vqmaillocal.c
--- ../../vendor/vpopmail/vqmaillocal.c	Mon Oct  2 13:08:46 2006
+++ ./vqmaillocal.c	Wed Oct  4 15:44:20 2006
@@ -672,7 +672,7 @@
      exit(-1);
   }
 
-  wait(&wstat);
+  waitpid(child,&wstat,0);
 
 }
 
