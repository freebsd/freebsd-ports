
$FreeBSD$

--- libxslt/extra.c.orig	Wed Aug 15 05:55:12 2001
+++ libxslt/extra.c	Mon Aug 27 13:24:28 2001
@@ -235,7 +235,12 @@
      * Calling localtime() has the side-effect of setting timezone.
      * After we know the timezone, we can adjust for it
      */
-    lmt = gmt - timezone;
+    /*
+     * May be on some stupid Linux localtime() have such side-effect,
+     * but FreeBSD DOESN'T HAVE such side-ffect, so we should use
+     * local_tm. 
+     */ 
+    lmt = gmt - local_tm->tm_gmtoff;
 
     /*
      * FIXME: it's been too long since I did manual memory management.
