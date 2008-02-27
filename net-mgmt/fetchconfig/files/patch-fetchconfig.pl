--- ./fetchconfig.pl.orig	2007-07-20 19:05:39.000000000 +0200
+++ ./fetchconfig.pl	2008-02-27 22:58:14.000000000 +0100
@@ -21,6 +21,8 @@
 # $Id: fetchconfig.pl,v 1.7 2007/07/20 17:05:39 evertonm Exp $
 
 use strict;
+use FindBin;
+use lib "$FindBin::Bin/../lib";
 use fetchconfig::Logger;
 use fetchconfig::Constants;
 use fetchconfig::model::Detector;
@@ -64,7 +66,7 @@
 if (@device_file_list < 1) {
     $log->error("at least one device list file is required");
     &usage;
-    die;
+    exit 0;
 }
 
 fetchconfig::model::Detector->init($log);
