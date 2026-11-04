--- libs/native/src/main21/java/org/elasticsearch/nativeaccess/jdk/JdkNativeLibraryProvider.java.orig	2026-10-28 21:29:53 UTC
+++ libs/native/src/main21/java/org/elasticsearch/nativeaccess/jdk/JdkNativeLibraryProvider.java
@@ -9,6 +9,7 @@ package org.elasticsearch.nativeaccess.jdk;
 
 package org.elasticsearch.nativeaccess.jdk;
 
+import org.elasticsearch.nativeaccess.lib.FreebsdCLibrary;
 import org.elasticsearch.nativeaccess.lib.JavaLibrary;
 import org.elasticsearch.nativeaccess.lib.Kernel32Library;
 import org.elasticsearch.nativeaccess.lib.LinuxCLibrary;
@@ -34,6 +35,8 @@ public class JdkNativeLibraryProvider extends NativeLi
                 JdkLinuxCLibrary::new,
                 MacCLibrary.class,
                 JdkMacCLibrary::new,
+                FreebsdCLibrary.class,
+                JdkFreebsdCLibrary::new,
                 Kernel32Library.class,
                 JdkKernel32Library::new,
                 ZstdLibrary.class,
