--- core/DesktopEditor/doctrenderer/docbuilder_p.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/doctrenderer/docbuilder_p.h
@@ -50,7 +50,7 @@
 #include "embed/NativeControlEmbed.h"
 #include "embed/MemoryStreamEmbed.h"
 #include "embed/GraphicsEmbed.h"
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -536,7 +536,7 @@ namespace NSDoctRenderer
 
     #endif
 
-    #ifdef LINUX
+    #if defined(LINUX) || defined(__FreeBSD__)
             pid_t pid = fork(); // create child process
             int status;
 
@@ -848,7 +848,7 @@ namespace NSDoctRenderer
 
     #endif
 
-    #ifdef LINUX
+    #if defined(LINUX) || defined(__FreeBSD__)
             pid_t pid = fork(); // create child process
             int status;
 
