--- libs/simdvec/src/test/java/org/elasticsearch/simdvec/AbstractVectorTestCase.java.orig	2026-10-28 20:24:18 UTC
+++ libs/simdvec/src/test/java/org/elasticsearch/simdvec/AbstractVectorTestCase.java
@@ -51,7 +51,7 @@ public abstract class AbstractVectorTestCase extends E
 
         if (jdkVersion >= 21
             && (arch.equals("aarch64") && (osName.startsWith("Mac") || osName.equals("Linux"))
-                || arch.equals("amd64") && osName.equals("Linux"))) {
+                || arch.equals("amd64") && (osName.equals("Linux") || osName.equals("FreeBSD")))) {
             assertThat(factory, isPresent());
             return true;
         } else {
