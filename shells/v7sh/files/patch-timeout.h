diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ timeout.h.orig timeout.h
--- timeout.h.orig	Fri Jun  4 02:51:02 2004
+++ timeout.h	Sat Jun 19 18:42:25 2004
@@ -7,4 +7,5 @@
  *
  */
 
+/*	seconds elapsing before log-off	*/
 #define TIMEOUT 0
