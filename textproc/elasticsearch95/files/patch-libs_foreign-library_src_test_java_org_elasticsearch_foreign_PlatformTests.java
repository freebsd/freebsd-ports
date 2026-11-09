--- libs/foreign-library/src/test/java/org/elasticsearch/foreign/PlatformTests.java.orig	2026-10-28 21:58:41 UTC
+++ libs/foreign-library/src/test/java/org/elasticsearch/foreign/PlatformTests.java
@@ -53,6 +53,14 @@ public class PlatformTests extends TestCase {
         assertEquals(Platform.WINDOWS_X64, Platform.resolve("Windows Server 2019", "x86_64"));
     }
 
+    public void testFreebsdX64AmdVariant() {
+        assertEquals(Platform.FREEBSD_X64, Platform.resolve("FreeBSD", "amd64"));
+    }
+
+    public void testFreebsdX64X86Variant() {
+        assertEquals(Platform.FREEBSD_X64, Platform.resolve("FreeBSD", "x86_64"));
+    }
+
     public void testUnknownOsThrows() {
         try {
             Platform.resolve("SunOS", "amd64");
