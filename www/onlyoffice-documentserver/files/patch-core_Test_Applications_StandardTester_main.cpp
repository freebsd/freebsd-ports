--- core/Test/Applications/StandardTester/main.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/Test/Applications/StandardTester/main.cpp
@@ -13,7 +13,7 @@
 
 #include "../../../OfficeUtils/src/OfficeUtils.h"
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -178,7 +178,7 @@ namespace NSX2T
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
         pid_t pid = fork(); // create child process
         int status;
 
