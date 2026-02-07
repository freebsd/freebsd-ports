diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ name.h.orig name.h
--- name.h.orig	Fri Jun  4 02:51:02 2004
+++ name.h	Sat Jun 19 18:42:24 2004
@@ -18,7 +18,7 @@
 struct namnod {
 	NAMPTR	namlft;
 	NAMPTR	namrgt;
-	STRING	namid;
+	CSTRING	namid;
 	STRING	namval;
 	STRING	namenv;
 	INT	namflg;
