--- imap/smap.c.orig	Tue Nov 22 02:17:31 2005
+++ imap/smap.c	Sun Dec 31 13:25:19 2006
@@ -3496,7 +3496,7 @@
 						}
 						argvec[i]=0;
 
-						i=sendmsg(tmpname, argvec,
+						i=ci_sendmsg(tmpname, argvec,
 							  &senderr);
 						free(argvec);
 						if (i)
