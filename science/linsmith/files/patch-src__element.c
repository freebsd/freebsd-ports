--- src/element.c.orig	2011-06-23 01:10:42.000000000 +0900
+++ src/element.c	2012-10-21 04:47:51.000000000 +0900
@@ -306,6 +306,7 @@
 }
 
 
+void
 clear_element_lnlist(chart_lnlist *lnlst)
 {
   GList *l;
