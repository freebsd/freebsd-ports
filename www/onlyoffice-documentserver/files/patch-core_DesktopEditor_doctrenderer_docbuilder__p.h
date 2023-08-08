--- core/DesktopEditor/doctrenderer/docbuilder_p.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/doctrenderer/docbuilder_p.h
@@ -47,7 +47,7 @@
 #include "embed/NativeControlEmbed.h"
 #include "embed/GraphicsEmbed.h"
 #include "embed/Default.h"
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -785,7 +785,7 @@ namespace NSDoctRenderer
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 			pid_t pid = fork(); // create child process
 			int status;
 
@@ -1103,7 +1103,7 @@ namespace NSDoctRenderer
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 			pid_t pid = fork(); // create child process
 			int status;
 
