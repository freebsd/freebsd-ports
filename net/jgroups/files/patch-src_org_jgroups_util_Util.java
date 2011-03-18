--- src/org/jgroups/util/Util.java.orig	2011-03-18 10:35:16.000000000 +0100
+++ src/org/jgroups/util/Util.java	2011-03-18 10:36:44.000000000 +0100
@@ -3323,6 +3323,10 @@
     }
 
 
+    public static boolean checkForFreeBSD() {
+        return checkForPresence("os.name", "freebsd");
+    }
+
     public static boolean checkForLinux() {
         return checkForPresence("os.name", "linux");
     }
