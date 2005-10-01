Index: src/custom.c
===================================================================
RCS file: /cvsroot/mpd/mpd/src/custom.c,v
retrieving revision 1.1.2.1
retrieving revision 1.1.2.2
diff -u -r1.1.2.1 -r1.1.2.2
--- src/custom.c	26 Apr 2004 13:17:17 -0000	1.1.2.1
+++ src/custom.c	10 Jan 2005 23:14:03 -0000	1.1.2.2
@@ -141,16 +141,19 @@
   if (!bund)
     return;
 
-  va_start(args, fmt);
   if (l == NULL) {
     for (k = 0; k < bund->n_links; k++) {
-      if (bund && bund->links[k])
+      if (bund && bund->links[k]) {
+	va_start(args, fmt);
 	RecordLinkUpDownReason2(bund->links[k], up, key, fmt, args);
+	va_end(args);
+      }
     }
   } else {
+    va_start(args, fmt);
     RecordLinkUpDownReason2(l, up, key, fmt, args);
+    va_end(args);
   }
-  va_end(args);
 }
 
 static void
