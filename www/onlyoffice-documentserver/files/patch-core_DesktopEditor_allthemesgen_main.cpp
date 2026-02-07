--- core/DesktopEditor/allthemesgen/main.cpp.orig	2021-12-18 19:29:47 UTC
+++ core/DesktopEditor/allthemesgen/main.cpp
@@ -48,7 +48,7 @@
 #undef CreateDirectory
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined (__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -179,7 +179,7 @@ namespace NSX2T
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined (__FreeBSD__)
         pid_t pid = fork(); // create child process
         int status;
 
