--- libs/native/src/test/java/org/elasticsearch/nativeaccess/VectorSimilarityFunctionsTests.java.orig	2026-10-28 20:24:18 UTC
+++ libs/native/src/test/java/org/elasticsearch/nativeaccess/VectorSimilarityFunctionsTests.java
@@ -83,7 +83,7 @@ public abstract class VectorSimilarityFunctionsTests e
 
         if (jdkVersion >= 21
             && ((arch.equals("aarch64") && (osName.startsWith("Mac") || osName.equals("Linux")))
-                || (arch.equals("amd64") && osName.equals("Linux")))) {
+                || (arch.equals("amd64") && (osName.equals("Linux") || osName.equals("FreeBSD"))))) {
             assertThat(vectorSimilarityFunctions, isPresent());
             return true;
         } else {
