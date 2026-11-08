--- libs/native/src/test/java/org/elasticsearch/nativeaccess/VectorSimilarityFunctionsTests.java.orig	2026-10-28 21:29:53 UTC
+++ libs/native/src/test/java/org/elasticsearch/nativeaccess/VectorSimilarityFunctionsTests.java
@@ -47,7 +47,7 @@ public class VectorSimilarityFunctionsTests extends ES
 
         if (jdkVersion >= 21
             && ((arch.equals("aarch64") && (osName.startsWith("Mac") || osName.equals("Linux")))
-                || (arch.equals("amd64") && osName.equals("Linux")))) {
+                || (arch.equals("amd64") && (osName.equals("Linux") || osName.equals("FreeBSD"))))) {
             assertThat(vectorSimilarityFunctions, isPresent());
             return true;
         } else {
