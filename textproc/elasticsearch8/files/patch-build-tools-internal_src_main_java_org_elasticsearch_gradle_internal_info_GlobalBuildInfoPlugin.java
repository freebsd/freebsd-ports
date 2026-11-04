--- build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/info/GlobalBuildInfoPlugin.java.orig	2026-10-28 21:29:53 UTC
+++ build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/info/GlobalBuildInfoPlugin.java
@@ -22,6 +22,7 @@ import org.elasticsearch.gradle.internal.conventions.u
 import org.elasticsearch.gradle.internal.conventions.info.GitInfo;
 import org.elasticsearch.gradle.internal.conventions.info.ParallelDetector;
 import org.elasticsearch.gradle.internal.conventions.util.Util;
+import org.elasticsearch.gradle.internal.util.HttpUtils;
 import org.elasticsearch.gradle.util.GradleUtils;
 import org.gradle.api.Action;
 import org.gradle.api.GradleException;
@@ -53,10 +54,8 @@ import java.io.IOException;
 import java.io.File;
 import java.io.FileInputStream;
 import java.io.IOException;
-import java.io.InputStream;
 import java.io.InputStreamReader;
 import java.io.UncheckedIOException;
-import java.net.URI;
 import java.nio.file.Files;
 import java.util.List;
 import java.util.Locale;
@@ -215,14 +214,36 @@ public class GlobalBuildInfoPlugin implements Plugin<P
     }
 
     private List<DevelopmentBranch> getDevelopmentBranches() {
-        String branchesFileLocation = project.getProviders()
+        String configuredBranchesFileLocation = project.getProviders()
             .gradleProperty(BRANCHES_FILE_LOCATION_PROPERTY)
             .getOrElse(DEFAULT_BRANCHES_FILE_URL);
+        String branchesFileLocation = configuredBranchesFileLocation;
+        if (project.getGradle().getStartParameter().isOffline() && isHttpLocation(configuredBranchesFileLocation)) {
+            File localBranchesFile = new File(Util.locateElasticsearchWorkspace(project.getGradle()), "branches.json");
+            if (localBranchesFile.exists()) {
+                LOGGER.warn(
+                    "Gradle is running in offline mode; using local branches.json at [{}] instead of downloading from [{}].",
+                    localBranchesFile,
+                    configuredBranchesFileLocation
+                );
+                branchesFileLocation = localBranchesFile.getAbsolutePath();
+            } else {
+                throw new GradleException(
+                    "Gradle is running in offline mode, but branches.json location ["
+                        + configuredBranchesFileLocation
+                        + "] is an http(s) URL and no local branches.json was found at ["
+                        + localBranchesFile
+                        + "]. Either disable offline mode, set -P"
+                        + BRANCHES_FILE_LOCATION_PROPERTY
+                        + "=<local file path>, or create branches.json at the workspace root."
+                );
+            }
+        }
         LOGGER.info("Reading branches.json from {}", branchesFileLocation);
         byte[] branchesBytes;
-        if (branchesFileLocation.startsWith("http")) {
-            try (InputStream in = URI.create(branchesFileLocation).toURL().openStream()) {
-                branchesBytes = in.readAllBytes();
+        if (isHttpLocation(branchesFileLocation)) {
+            try {
+                branchesBytes = HttpUtils.readHttpBytesWithRetry(branchesFileLocation);
             } catch (IOException e) {
                 throw new UncheckedIOException("Failed to download branches.json from: " + branchesFileLocation, e);
             }
@@ -236,6 +257,10 @@ public class GlobalBuildInfoPlugin implements Plugin<P
 
         var branchesFileParser = new BranchesFileParser(new ObjectMapper());
         return branchesFileParser.parse(branchesBytes);
+    }
+
+    private static boolean isHttpLocation(String branchesFileLocation) {
+        return branchesFileLocation.startsWith("http://") || branchesFileLocation.startsWith("https://");
     }
 
     private void logGlobalBuildInfo(BuildParameterExtension buildParams) {
