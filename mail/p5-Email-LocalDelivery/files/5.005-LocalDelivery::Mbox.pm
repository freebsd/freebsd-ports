--- LocalDelivery/Mbox.pm.orig	Sun Dec 19 00:06:35 2004
+++ LocalDelivery/Mbox.pm	Sun Dec 19 00:09:40 2004
@@ -26,10 +26,10 @@
     my $dir = dirname($file);
     return if ! -d $dir and not mkpath($dir);
 
-    open my $fh, ">> $file" or return;
-    $class->getlock($fh) || return;
-    seek $fh, 0, 2;
-    return $fh;
+    open FH, ">> $file" or return;
+    $class->getlock(\*FH) || return;
+    seek FH, 0, 2;
+    return \*FH;
 }
 
 sub _close_fh {
