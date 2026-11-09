--- qa/packaging/src/test/java/org/elasticsearch/packaging/test/PluginCliTests.java.orig	2026-10-28 21:29:53 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/test/PluginCliTests.java
@@ -76,6 +76,7 @@ public class PluginCliTests extends PackagingTestCase 
         Files.move(pluginsDir, stashedPluginsDir);
         Path linkedPlugins = createTempDir("symlinked-plugins");
         Platforms.onLinux(() -> sh.run("chown elasticsearch:elasticsearch " + linkedPlugins.toString()));
+        Platforms.onFreeBSD(() -> sh.run("chown elasticsearch:elasticsearch " + linkedPlugins.toString()));
         Files.createSymbolicLink(pluginsDir, linkedPlugins);
         // Packaged installation don't get autoconfigured yet
         assertWithExamplePlugin(installResult -> {
