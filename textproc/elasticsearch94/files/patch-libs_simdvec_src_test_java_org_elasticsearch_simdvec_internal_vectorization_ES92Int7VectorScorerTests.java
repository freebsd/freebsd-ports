--- libs/simdvec/src/test/java/org/elasticsearch/simdvec/internal/vectorization/ES92Int7VectorScorerTests.java.orig	2026-10-28 20:24:18 UTC
+++ libs/simdvec/src/test/java/org/elasticsearch/simdvec/internal/vectorization/ES92Int7VectorScorerTests.java
@@ -31,7 +31,7 @@ public class ES92Int7VectorScorerTests extends BaseVec
         var osName = System.getProperty("os.name");
         return (jdkVersion >= 22
             && (arch.equals("aarch64") && (osName.startsWith("Mac") || osName.equals("Linux"))
-                || arch.equals("amd64") && osName.equals("Linux")));
+                || arch.equals("amd64") && (osName.equals("Linux") || osName.equals("FreeBSD"))));
     }
 
     public void testInt7DotProduct() throws Exception {
