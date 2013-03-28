--- ./librbl/rbl.c.orig	2012-10-25 07:12:31.000000000 +0900
+++ ./librbl/rbl.c	2013-03-21 02:26:41.000000000 +0900
@@ -312,6 +312,7 @@
 
 	free(tmp);
 #endif /* HAVE_RES_SETSERVERS */
+	return 0;
 }
 
 /*
