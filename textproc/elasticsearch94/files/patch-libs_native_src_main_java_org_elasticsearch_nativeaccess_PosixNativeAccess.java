--- libs/native/src/main/java/org/elasticsearch/nativeaccess/PosixNativeAccess.java.orig	2026-10-28 20:24:18 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/PosixNativeAccess.java
@@ -149,7 +149,15 @@ public abstract class PosixNativeAccess extends Abstra
         if (libc.close(fd) != 0) {
             logger.warn("Failed to close file [" + path + "] after getting stats: " + libc.strerror(libc.errno()));
         }
-        return OptionalLong.of(stats.st_blocks() * 512);
+
+        long bytesUsed = stats.st_blocks() * 512;
+
+        // On FreeBSD, st_blocks returns the actual blocks used
+        if (isFreebsdAmd64()) {
+            bytesUsed = stats.st_size();
+        }
+
+        return OptionalLong.of(bytesUsed);
     }
 
     @SuppressForbidden(reason = "Using mkdirs")
@@ -208,7 +216,8 @@ public abstract class PosixNativeAccess extends Abstra
     }
 
     static boolean isNativeVectorLibSupported() {
-        return Runtime.version().feature() >= 21 && (isMacOrLinuxAarch64() || isLinuxAmd64()) && checkEnableSystemProperty();
+        return Runtime.version().feature() >= 21 && (isMacOrLinuxAarch64() || isLinuxAmd64() || isFreebsdAmd64()) &&
+            checkEnableSystemProperty();
     }
 
     /**
@@ -223,6 +232,12 @@ public abstract class PosixNativeAccess extends Abstra
     static boolean isMacOrLinuxAarch64() {
         String name = System.getProperty("os.name");
         return (name.startsWith("Mac") || name.startsWith("Linux")) && System.getProperty("os.arch").equals("aarch64");
+    }
+
+    /** Returns true if the OS is FreeBSD, and the architecture is x64. */
+    static boolean isFreebsdAmd64() {
+        String name = System.getProperty("os.name");
+        return (name.startsWith("FreeBSD")) && System.getProperty("os.arch").equals("amd64");
     }
 
     /** -Dorg.elasticsearch.nativeaccess.enableVectorLibrary=false to disable.*/
