--- lib/pkgversion.rb.orig	Mon Mar 29 07:35:38 2004
+++ lib/pkgversion.rb	Mon Mar 29 07:36:10 2004
@@ -62,4 +62,4 @@
     # ignore padded 0's
-    n1.gsub!(/(^|\D)0+(\d)/, "\\1\\2")
-    n2.gsub!(/(^|\D)0+(\d)/, "\\1\\2")
+    n1 = n1.gsub(/(^|\D)0+(\d)/, "\\1\\2")
+    n2 = n2.gsub(/(^|\D)0+(\d)/, "\\1\\2")
 
