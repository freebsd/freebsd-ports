--- libs/native/src/main/java/org/elasticsearch/nativeaccess/jdk/JdkNativeLibraryProvider.java.orig	2026-10-28 21:58:41 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/jdk/JdkNativeLibraryProvider.java
@@ -9,6 +9,7 @@ package org.elasticsearch.nativeaccess.jdk;
 
 package org.elasticsearch.nativeaccess.jdk;
 
+import org.elasticsearch.nativeaccess.lib.FreebsdCLibrary;
 import org.elasticsearch.nativeaccess.lib.JavaLibrary;
 import org.elasticsearch.nativeaccess.lib.Kernel32Library;
 import org.elasticsearch.nativeaccess.lib.LinuxCLibrary;
@@ -36,7 +37,9 @@ public class JdkNativeLibraryProvider extends NativeLi
                 VectorLibrary.class,
                 JdkVectorLibrary::new,
                 ParquetRsLibrary.class,
-                JdkParquetRsLibrary::new
+                JdkParquetRsLibrary::new,
+                FreebsdCLibrary.class,
+                JdkFreebsdCLibrary::new
             )
         );
     }
