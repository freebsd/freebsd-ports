--- src/gui/wxMApp.cpp.orig	Tue Aug  5 01:04:21 2003
+++ src/gui/wxMApp.cpp	Sun Oct  5 03:06:51 2003
@@ -911,7 +911,7 @@
             // now load the message catalogs
 #ifdef OS_UNIX
             String localePath;
-            localePath << M_BASEDIR << "/locale";
+            localePath << M_PREFIX << "/share/locale";
 #elif defined(OS_WIN)
             // the program directory is not initialized yet so we can't do much
             // more than looking in the current directory...
