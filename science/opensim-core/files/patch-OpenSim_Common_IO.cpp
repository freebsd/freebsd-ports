--- OpenSim/Common/IO.cpp.orig	2018-11-15 09:02:08 UTC
+++ OpenSim/Common/IO.cpp
@@ -33,7 +33,7 @@
 #include <climits>
 
 #include "IO.h"
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
     #include <sys/stat.h>
     #include <sys/types.h>
 #elif defined(_MSC_VER)
@@ -476,7 +476,7 @@ int IO::
 makeDir(const string &aDirName)
 {
 
-#if defined __linux__ || defined __APPLE__
+#if defined __linux__ || defined __APPLE__ || defined __FreeBSD__
     return mkdir(aDirName.c_str(),S_IRWXU);
 #else
     return _mkdir(aDirName.c_str());
@@ -491,7 +491,7 @@ int IO::
 chDir(const string &aDirName)
 {
 
-#if defined __linux__ || defined __APPLE__
+#if defined __linux__ || defined __APPLE__ || defined __FreeBSD__
     return chdir(aDirName.c_str()); 
 #else
     return _chdir(aDirName.c_str());
@@ -507,7 +507,7 @@ string IO::
 getCwd()
 {
     char buffer[PATH_MAX];
-#if defined __linux__ || defined __APPLE__
+#if defined __linux__ || defined __APPLE__ || defined __FreeBSD__
     auto ptr = getcwd(buffer, PATH_MAX); (void)ptr;
 #else
     _getcwd(buffer, PATH_MAX);
