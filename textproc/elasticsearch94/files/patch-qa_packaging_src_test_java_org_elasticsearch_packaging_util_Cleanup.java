--- qa/packaging/src/test/java/org/elasticsearch/packaging/util/Cleanup.java.orig	2026-10-28 21:29:53 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/util/Cleanup.java
@@ -42,6 +42,36 @@ public class Cleanup {
         "/usr/lib/sysctl.d/elasticsearch.conf"
     );
 
+    private static final List<String> ELASTICSEARCH_FILES_FREEBSD = Arrays.asList(
+        "/usr/local/share/elasticsearch",
+        "/usr/local/etc/elasticsearch/elasticsearch.keystore",
+        "/usr/local/etc/elasticsearch",
+        "/usr/local/lib/elasticsearch",
+        "/usr/local/libexec/elasticsearch",
+        "/var/log/elasticsearch",
+        "/var/run/elasticsearch",
+        "/var/db/elasticsearch",
+        "/usr/local/share/doc/elasticsearch",
+        "/usr/local/etc/rc.d/elasticsearch"
+    );
+
+    private static final List<String> ELASTICSEARCH_FILES_FREEBSD_PORTS = Arrays.asList(
+        "%%DATADIR%%",
+        "%%ETCDIR%%/elasticsearch.keystore",
+        "%%ETCDIR%%",
+        "%%PREFIX%%/lib/elasticsearch",
+        "%%PREFIX%%/libexec/elasticsearch",
+        "/var/log/elasticsearch",
+        "/var/run/elasticsearch",
+        "/var/db/elasticsearch",
+        "%%DOCSDIR%%",
+        "%%PREFIX%%/etc/rc.d/elasticsearch"
+    );
+
+    private static final List<String> ELASTICSEARCH_FILES_FREEBSD_FINAL = Boolean.parseBoolean(
+        System.getProperty("freebsd.build.fromPorts", "false")
+    ) ? ELASTICSEARCH_FILES_FREEBSD_PORTS : ELASTICSEARCH_FILES_FREEBSD;
+
     // todo
     private static final List<String> ELASTICSEARCH_FILES_WINDOWS = Collections.emptyList();
 
@@ -54,6 +84,11 @@ public class Cleanup {
             sh.runIgnoreExitCode("ps aux | grep -i 'org.elasticsearch.bootstrap.Elasticsearch' | awk {'print $2'} | xargs kill -9");
         });
 
+        Platforms.onFreeBSD(() -> {
+            sh.runIgnoreExitCode("pkill -u elasticsearch");
+            sh.runIgnoreExitCode("ps aux | grep -i 'org.elasticsearch.bootstrap.Elasticsearch' | awk {'print $2'} | xargs kill -9");
+        });
+
         Platforms.onWindows(() -> {
             // the view of processes returned by Get-Process doesn't expose command line arguments, so we use WMI here
             sh.runIgnoreExitCode(
@@ -64,17 +99,24 @@ public class Cleanup {
         });
 
         Platforms.onLinux(Cleanup::purgePackagesLinux);
+        Platforms.onFreeBSD(Cleanup::purgePackagesFreeBSD);
 
         // remove elasticsearch users
         Platforms.onLinux(() -> {
             sh.runIgnoreExitCode("userdel elasticsearch");
             sh.runIgnoreExitCode("groupdel elasticsearch");
         });
+        Platforms.onFreeBSD(() -> {
+            sh.runIgnoreExitCode("pw user del elasticsearch");
+            sh.runIgnoreExitCode("pw group del elasticsearch");
+        });
         // when we run es as a role user on windows, add the equivalent here
         // delete files that may still exist
 
         lsGlob(getRootTempDir(), "elasticsearch*").forEach(FileUtils::rm);
-        final List<String> filesToDelete = Platforms.WINDOWS ? ELASTICSEARCH_FILES_WINDOWS : ELASTICSEARCH_FILES_LINUX;
+        final List<String> filesToDelete = Platforms.WINDOWS
+            ? ELASTICSEARCH_FILES_WINDOWS
+            : (Platforms.FREEBSD ? ELASTICSEARCH_FILES_FREEBSD_FINAL : ELASTICSEARCH_FILES_LINUX);
         filesToDelete.stream().map(Paths::get).filter(Files::exists).forEach(FileUtils::rm);
     }
 
@@ -91,5 +133,10 @@ public class Cleanup {
         if (isDPKG()) {
             sh.runIgnoreExitCode("dpkg --purge elasticsearch elasticsearch-oss");
         }
+    }
+
+    private static void purgePackagesFreeBSD() {
+        final Shell sh = new Shell();
+        sh.runIgnoreExitCode("pkg delete -y elasticsearch");
     }
 }
