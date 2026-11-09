--- build-conventions/src/main/java/org/elasticsearch/gradle/internal/conventions/info/ParallelDetector.java.orig	2026-10-28 21:58:41 UTC
+++ build-conventions/src/main/java/org/elasticsearch/gradle/internal/conventions/info/ParallelDetector.java
@@ -83,6 +83,15 @@ public class ParallelDetector {
                 if (result.getResult().get().getExitValue() == 0 && stdout.isEmpty() == false) {
                     _defaultParallel = Integer.parseInt(stdout);
                 }
+            } else if (isFreeBSD(project.getProviders())) {
+                var result = project.getProviders().exec(execSpec -> {
+                    execSpec.commandLine("sysctl", "-n", "kern.smp.cores");
+                    execSpec.setIgnoreExitValue(true);
+                });
+                String stdout = result.getStandardOutput().getAsText().get().trim();
+                if (result.getResult().get().getExitValue() == 0 && stdout.isEmpty() == false) {
+                    _defaultParallel = Integer.parseInt(stdout);
+                }
             }
 
             if (_defaultParallel == null || _defaultParallel < 1) {
@@ -96,6 +105,10 @@ public class ParallelDetector {
 
     private static boolean isMac(ProviderFactory providers) {
         return providers.systemProperty("os.name").getOrElse("").startsWith("Mac");
+    }
+
+    private static boolean isFreeBSD(ProviderFactory providers) {
+        return providers.systemProperty("os.name").getOrElse("").startsWith("FreeBSD");
     }
 
     private static boolean isMontereyOrNewer(ProviderFactory providers) {
