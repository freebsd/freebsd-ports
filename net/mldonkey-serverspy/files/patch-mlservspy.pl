--- mlservspy.pl.orig	Mon Feb 24 16:16:22 2003
+++ mlservspy.pl	Mon Feb 24 16:16:35 2003
@@ -36,7 +36,7 @@
     ARGCOUNT => ARGCOUNT_ONE,
 },
 'path' => {
-    DEFAULT => "/lab/mlservspy/",
+    DEFAULT => "$ENV{'HOME'}/.mldonkey-serverspy/",
     ARGCOUNT => ARGCOUNT_ONE,    
 },
 'image_file' => {
