--- lib/MIME/Words.pm.orig	Sat Nov 11 01:45:12 2000
+++ lib/MIME/Words.pm	Thu Jun  6 10:15:15 2002
@@ -186,7 +186,7 @@
     $@ = '';           ### error-return
 
     ### Collapse boundaries between adjacent encoded words:
-    $encstr =~ s{(\?\=)\r?\n[ \t](\=\?)}{$1$2}gs;
+    $encstr =~ s{(\?\=)\s*(\=\?)}{$1$2}gs;
     pos($encstr) = 0;
     ### print STDOUT "ENC = [", $encstr, "]\n";
 
