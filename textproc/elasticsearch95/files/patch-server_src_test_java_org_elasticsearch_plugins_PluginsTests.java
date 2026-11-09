--- server/src/test/java/org/elasticsearch/plugins/PluginsTests.java.orig	2026-10-28 21:29:53 UTC
+++ server/src/test/java/org/elasticsearch/plugins/PluginsTests.java
@@ -34,6 +34,7 @@ public class PluginsTests extends ESTestCase {
         assertEquals("windows-x86", Platforms.platformName("Windows Server 2008", "x86"));
         assertEquals("windows-x86_64", Platforms.platformName("Windows 8.1", "amd64"));
         assertEquals("sunos-x86_64", Platforms.platformName("SunOS", "amd64"));
+        assertEquals("freebsd-x86_64", Platforms.platformName("FreeBSD", "amd64"));
     }
 
 }
