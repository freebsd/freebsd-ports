--- rebuildspamdb.pl.orig	2010-12-09 22:50:45.000000000 -0600
+++ rebuildspamdb.pl	2010-12-10 14:54:49.000000000 -0600
@@ -51,7 +51,7 @@
  # the last one is the one used if all else fails 
  $base = cwd(); 
  unless (-e "$base/assp.cfg") { 
-   foreach ('.','/usr/local/assp','/home/assp','/etc/assp','/usr/assp','/applications/assp','/assp','.') {
+   foreach ('.','/usr/local/assp','/home/assp','/etc/assp','/usr/assp','/applications/assp','/assp','/var/db/assp') {
     if (-e "$_/assp.cfg") {
       $base=$_; 
       last ; 
