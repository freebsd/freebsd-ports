--- mod_sequester.c.orig	Tue Sep 30 19:22:29 2003
+++ mod_sequester.c	Tue Jan 15 22:28:22 2002
@@ -9,7 +9,7 @@
  *
 
  *
- * $Id: mod_sequester.c,v 1.7 2000/06/19 17:51:30 coar Exp $
+ * $Id: mod_sequester.c,v 1.8 2001/06/15 14:14:03 coar Exp $
  *
  * Abstract:
  *+
@@ -350,7 +350,7 @@
     switch (dconf->pos) {
     case WINDOW_ATBEGINNING:
 	msg = ap_pstrcat(r->pool, "The resource will become available at ",
-			 ap_ht_time(r->pool, begin, TIMEFMT ".", 1), NULL);
+			 ap_ht_time(r->pool, end, TIMEFMT ".", 1), NULL);
 	break;
     case WINDOW_ATEND:
 	msg = ap_pstrcat(r->pool, "The resource became unavailable at ",
