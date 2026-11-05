--- x-pack/plugin/core/src/main/java/org/elasticsearch/xpack/core/XPackSettings.java.orig	2026-10-28 21:29:53 UTC
+++ x-pack/plugin/core/src/main/java/org/elasticsearch/xpack/core/XPackSettings.java
@@ -83,7 +83,13 @@ public class XPackSettings {
     /** Setting for enabling or disabling graph. Defaults to true. */
     public static final Setting<Boolean> GRAPH_ENABLED = Setting.boolSetting("xpack.graph.enabled", true, Setting.Property.NodeScope);
 
-    public static final Set<String> ML_NATIVE_CODE_PLATFORMS = Set.of("darwin-aarch64", "linux-aarch64", "linux-x86_64", "windows-x86_64");
+    public static final Set<String> ML_NATIVE_CODE_PLATFORMS = Set.of(
+        "darwin-aarch64",
+        "freebsd-x86_64",
+        "linux-aarch64",
+        "linux-x86_64",
+        "windows-x86_64"
+    );
 
     /** Setting for enabling or disabling machine learning. Defaults to true on platforms that have the ML native code available. */
     public static final Setting<Boolean> MACHINE_LEARNING_ENABLED = Setting.boolSetting(
