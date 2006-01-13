--- mainwindow.ui.pm.orig	Fri Jan 13 13:55:25 2006
+++ mainwindow.ui.pm	Fri Jan 13 13:55:36 2006
@@ -344,7 +344,7 @@
   if ($total_selected)
   {
     my $capacity = $dvdr_total_sectors - $dvdr_spare_sectors;
-    $compression = sprintf "%d", $capacity * 100 / ($total_selected + 0.0);
+    $compression = sprintf "%d", $capacity * 200 / ($total_selected + 0.0);
     $compression = 100 if ($compression > 100);
   }
   else
