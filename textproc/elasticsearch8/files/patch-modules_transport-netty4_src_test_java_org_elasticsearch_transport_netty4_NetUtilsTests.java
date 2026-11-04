--- modules/transport-netty4/src/test/java/org/elasticsearch/transport/netty4/NetUtilsTests.java.orig	2026-10-28 21:29:53 UTC
+++ modules/transport-netty4/src/test/java/org/elasticsearch/transport/netty4/NetUtilsTests.java
@@ -27,7 +27,7 @@ public class NetUtilsTests extends ESTestCase {
             ModuleLayer.boot().modules().stream().map(Module::getName).anyMatch(nm -> nm.equals("jdk.net"))
         );
 
-        assumeTrue("Platform possibly not supported", IOUtils.LINUX || IOUtils.MAC_OS_X);
+        assumeTrue("Platform possibly not supported", IOUtils.LINUX || IOUtils.MAC_OS_X || IOUtils.FREEBSD);
         try (var channel = networkChannel()) {
             var options = channel.supportedOptions();
             assertThat(options, hasItem(NetUtils.getTcpKeepIdleSocketOption()));
