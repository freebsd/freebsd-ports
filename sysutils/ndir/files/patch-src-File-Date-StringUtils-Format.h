--- src/File-Date-StringUtils/Format.h.orig	Sat Apr 10 01:41:38 2004
+++ src/File-Date-StringUtils/Format.h	Mon Sep 26 16:09:59 2005
@@ -65,6 +65,6 @@
     text-containing string to be output on a terminal 
    */
   std::string clean( std::string s);
-
+  std::string getLengthString( int length);
 
 #endif
