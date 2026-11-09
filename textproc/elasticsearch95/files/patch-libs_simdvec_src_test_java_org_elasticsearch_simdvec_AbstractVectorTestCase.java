--- libs/simdvec/src/test/java/org/elasticsearch/simdvec/AbstractVectorTestCase.java.orig	2026-10-28 21:58:41 UTC
+++ libs/simdvec/src/test/java/org/elasticsearch/simdvec/AbstractVectorTestCase.java
@@ -43,7 +43,7 @@ public abstract class AbstractVectorTestCase extends E
         // native support requires JDK 22+ (for heap segment support and native vec lib loading)
         if (Runtime.version().feature() >= 22
             && (arch.equals("aarch64") && (osName.startsWith("Mac") || osName.equals("Linux"))
-                || arch.equals("amd64") && osName.equals("Linux"))) {
+                || arch.equals("amd64") && (osName.equals("Linux") || osName.equals("FreeBSD")))) {
             assertTrue(factory.usesNative());
         } else {
             // not an arch with native support, so shouldn't be native
