--- libs/native/src/test/java/org/elasticsearch/nativeaccess/PosixCLibraryTests.java.orig	2026-10-28 20:24:18 UTC
+++ libs/native/src/test/java/org/elasticsearch/nativeaccess/PosixCLibraryTests.java
@@ -37,11 +37,11 @@ public class PosixCLibraryTests extends ESTestCase {
     @Before
     public void setup() {
         nativeAccess = NativeAccess.instance();
-        if (Constants.LINUX || Constants.MAC_OS_X) {
+        if (Constants.LINUX || Constants.MAC_OS_X || Constants.FREE_BSD) {
             clib = NativeLibraryProvider.instance().getLibrary(PosixCLibrary.class);
             assertNotNull(clib);
         } else {
-            assumeFalse("posix only available on Mac/Linux", Constants.WINDOWS);
+            assumeFalse("posix only available on Mac/Linux/FreeBSD", Constants.WINDOWS);
         }
     }
 
