--- Makefile.PL.orig	2010-08-08 12:25:18.234910310 +0200
+++ Makefile.PL	2010-08-08 12:25:31.618794295 +0200
@@ -50,7 +50,7 @@
 }
 
 cc_lib_links('crypto');
-cc_optimize_flags('-g -Wall -Werror');
+cc_optimize_flags('-g -Wall');
 
 auto_install();
 WriteAll();
