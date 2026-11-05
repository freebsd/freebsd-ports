--- libs/native/src/main/java/org/elasticsearch/nativeaccess/jdk/JdkNativeLibraryProvider.java.orig	2026-10-28 20:24:18 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/jdk/JdkNativeLibraryProvider.java
@@ -9,6 +9,7 @@ package org.elasticsearch.nativeaccess.jdk;
 
 package org.elasticsearch.nativeaccess.jdk;
 
+import org.elasticsearch.nativeaccess.lib.FreebsdCLibrary;
 import org.elasticsearch.nativeaccess.lib.JavaLibrary;
 import org.elasticsearch.nativeaccess.lib.Kernel32Library;
 import org.elasticsearch.nativeaccess.lib.LinuxCLibrary;
@@ -39,7 +40,9 @@ public class JdkNativeLibraryProvider extends NativeLi
                 ZstdLibrary.class,
                 JdkZstdLibrary::new,
                 VectorLibrary.class,
-                JdkVectorLibrary::new
+                JdkVectorLibrary::new,
+                FreebsdCLibrary.class,
+                JdkFreebsdCLibrary::new
             )
         );
     }
