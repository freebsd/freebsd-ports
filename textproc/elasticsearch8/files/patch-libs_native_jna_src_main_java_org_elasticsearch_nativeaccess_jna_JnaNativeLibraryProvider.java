--- libs/native/jna/src/main/java/org/elasticsearch/nativeaccess/jna/JnaNativeLibraryProvider.java.orig	2026-10-28 21:29:53 UTC
+++ libs/native/jna/src/main/java/org/elasticsearch/nativeaccess/jna/JnaNativeLibraryProvider.java
@@ -10,6 +10,7 @@ import org.elasticsearch.core.SuppressForbidden;
 package org.elasticsearch.nativeaccess.jna;
 
 import org.elasticsearch.core.SuppressForbidden;
+import org.elasticsearch.nativeaccess.lib.FreebsdCLibrary;
 import org.elasticsearch.nativeaccess.lib.JavaLibrary;
 import org.elasticsearch.nativeaccess.lib.Kernel32Library;
 import org.elasticsearch.nativeaccess.lib.LinuxCLibrary;
@@ -42,6 +43,8 @@ public class JnaNativeLibraryProvider extends NativeLi
                 JnaLinuxCLibrary::new,
                 MacCLibrary.class,
                 JnaMacCLibrary::new,
+                FreebsdCLibrary.class,
+                JnaFreebsdCLibrary::new,
                 Kernel32Library.class,
                 JnaKernel32Library::new,
                 ZstdLibrary.class,
