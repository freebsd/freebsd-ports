--- ./chrome/browser/zygote_host_linux.h.orig	2010-12-16 02:11:58.000000000 +0100
+++ ./chrome/browser/zygote_host_linux.h	2010-12-20 20:15:08.000000000 +0100
@@ -51,6 +51,9 @@
     kCmdReap = 1,                  // Reap a renderer child.
     kCmdGetTerminationStatus = 2,  // Check what happend to a child process.
     kCmdGetSandboxStatus = 3,      // Read a bitmask of kSandbox*
+#if defined(OS_FREEBSD)
+    kCmdEnd = 5,                   // Kill zygote for SOCK_DGRAM.
+#endif
   };
 
   // These form a bitmask which describes the conditions of the sandbox that
