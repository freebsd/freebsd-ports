--- fetchconfig.pl.orig	2018-03-05 16:07:31 UTC
+++ fetchconfig.pl
@@ -21,6 +21,8 @@
 # $Id: fetchconfig.pl,v 1.8 2012/11/27 21:42:28 evertonm Exp $
 
 use strict;
+use FindBin;
+use lib "$FindBin::Bin/../lib";
 use fetchconfig::Logger;
 use fetchconfig::Constants;
 use fetchconfig::model::Detector;
@@ -63,7 +65,7 @@ foreach my $opt (@ARGV) {
     }
     $log->error("unexpected argument: $opt");
     &usage;
-    die;
+    exit 0;
 }
 
 if ((@device_file_list < 1) && (@line_list < 1)){
