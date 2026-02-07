--- unbuffered_file.cc.orig	2014-11-08 22:56:14.000000000 +0800
+++ unbuffered_file.cc	2014-11-08 22:56:25.000000000 +0800
@@ -13,7 +13,7 @@
 #include "unbuffered_file.hh"
 
 
-#ifdef __APPLE__
+#if defined(__APPLE_) || defined(__FreeBSD__)
 #define lseek64 lseek
 #endif
 
@@ -24,7 +24,7 @@
 
   int flags = ( mode == WriteOnly ? ( O_WRONLY | O_CREAT | O_TRUNC ) :
                                     O_RDONLY );
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
   flags |= O_LARGEFILE;
 #endif
   fd = open( fileName, flags, 0666 );
