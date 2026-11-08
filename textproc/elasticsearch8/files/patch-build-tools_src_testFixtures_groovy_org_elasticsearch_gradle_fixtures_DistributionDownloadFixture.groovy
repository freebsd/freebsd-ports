--- build-tools/src/testFixtures/groovy/org/elasticsearch/gradle/fixtures/DistributionDownloadFixture.groovy.orig	2026-10-28 21:29:53 UTC
+++ build-tools/src/testFixtures/groovy/org/elasticsearch/gradle/fixtures/DistributionDownloadFixture.groovy
@@ -64,7 +64,8 @@ class DistributionDownloadFixture {
 
     private static String urlPath(String version,ElasticsearchDistribution.Platform platform) {
         String fileType = ((platform == ElasticsearchDistribution.Platform.LINUX ||
-                platform == ElasticsearchDistribution.Platform.DARWIN)) ? "tar.gz" : "zip"
+                platform == ElasticsearchDistribution.Platform.DARWIN ||
+                platform == ElasticsearchDistribution.Platform.FREEBSD)) ? "tar.gz" : "zip"
         "/downloads/elasticsearch/elasticsearch-${version}-${platform}-${Architecture.current().classifier}.$fileType"
     }
 
