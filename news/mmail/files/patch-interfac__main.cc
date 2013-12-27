--- ./interfac/main.cc.orig	2007-07-16 19:19:36.000000000 +0200
+++ ./interfac/main.cc	2013-12-27 11:18:04.000000000 +0100
@@ -12,7 +12,7 @@
 #include "interfac.h"
 
 #ifdef USE_NEWHANDLER
-# include <new.h>
+# include <new>
 #endif
 
 #include <locale.h>
@@ -40,7 +40,7 @@
 	srand((unsigned) starttime);
 
 #ifdef USE_NEWHANDLER
-	set_new_handler(memError);
+	std::set_new_handler(memError);
 #endif
 	origdir = mygetcwd();
 }
