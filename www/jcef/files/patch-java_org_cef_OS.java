--- java/org/cef/OS.java.orig	2026-09-08 14:07:06 UTC
+++ java/org/cef/OS.java
@@ -23,6 +23,7 @@ public class OS {
         return getOSType() == OSType.OSMacintosh;
     }
 
+// Handle FreeBSD like Linux
     public static final boolean isLinux() {
         return getOSType() == OSType.OSLinux;
     }
@@ -32,6 +33,8 @@ public class OS {
             String os = System.getProperty("os.name").toLowerCase();
             if (os.startsWith("windows"))
                 osType = OSType.OSWindows;
+            else if (os.startsWith("freebsd"))
+                osType = OSType.OSLinux;
             else if (os.startsWith("linux"))
                 osType = OSType.OSLinux;
             else if (os.startsWith("mac"))
