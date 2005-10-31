--- src/file.cpp.orig	Mon Oct 17 10:22:04 2005
+++ src/file.cpp	Sun Oct 23 21:21:21 2005
@@ -514,7 +514,7 @@
     if( noSort)
       flags |= GLOB_NOSORT;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
     if( !quote) // n/a on OS X
       flags |= GLOB_NOESCAPE;
 
