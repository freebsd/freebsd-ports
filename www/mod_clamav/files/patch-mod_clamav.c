--- mod_clamav.c.orig	Wed Apr 21 18:29:42 2004
+++ mod_clamav.c	Wed Apr 21 18:30:07 2004
@@ -310,6 +310,7 @@
     int			rc = 1, i, l;
     char		*ct;
     const char		*action;
+    clamav_safeuri *p;
 
     /* requests with only headers can be bypassed			*/
     if (f->r->header_only) {
@@ -339,7 +340,7 @@
     }
 
     /* check safe uri */
-    clamav_safeuri *p = (clamav_safeuri *)(rec->safeuris->elts);
+    p = (clamav_safeuri *)(rec->safeuris->elts);
     for (i = 0; i < rec->safeuris->nelts; i++) {
 	switch (p[i].matchtype) {
 	    case MATCH_SAFE_URI:
