--- src/xfeutils.cpp.orig	2010-08-24 07:44:57.000000000 +0000
+++ src/xfeutils.cpp	2010-08-24 07:45:25.000000000 +0000
@@ -512,7 +512,7 @@
 
 
 // Replacement of the stat function
-inline FXint statrep(const FXchar* filename, struct stat* buf)
+FXint statrep(const FXchar* filename, struct stat* buf)
 {
 #if defined(linux)
 
@@ -546,7 +546,7 @@
 
 
 // Replacement of the lstat function
-inline FXint lstatrep(const FXchar* filename, struct stat* buf)
+FXint lstatrep(const FXchar* filename, struct stat* buf)
 {
 #if defined(linux)
 
