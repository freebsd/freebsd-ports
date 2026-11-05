--- qa/packaging/src/test/java/org/elasticsearch/packaging/util/Archives.java.orig	2026-10-28 21:29:53 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/util/Archives.java
@@ -108,6 +108,7 @@ public class Archives {
         }
 
         Platforms.onLinux(() -> setupArchiveUsersLinux(fullInstallPath));
+        Platforms.onFreeBSD(() -> setupArchiveUsersFreeBSD(fullInstallPath));
 
         sh.chown(fullInstallPath);
 
@@ -154,6 +155,18 @@ public class Archives {
         }
     }
 
+    private static void setupArchiveUsersFreeBSD(Path installPath) {
+        final Shell sh = new Shell();
+
+        if (sh.runIgnoreExitCode("getent group elasticsearch").isSuccess() == false) {
+            sh.run("pw group add -n elasticsearch");
+        }
+
+        if (sh.runIgnoreExitCode("id elasticsearch").isSuccess() == false) {
+            sh.run("pw user add -q -g elasticsearch -s /usr/sbin/nologin -c 'elasticsearch user' -n elasticsearch");
+        }
+    }
+
     public static void verifyArchiveInstallation(Installation installation, Distribution distribution) {
         verifyOssInstallation(installation, distribution, ARCHIVE_OWNER);
         verifyDefaultInstallation(installation, distribution, ARCHIVE_OWNER);
@@ -366,6 +379,7 @@ public class Archives {
 
         final Shell sh = new Shell();
         Platforms.onLinux(() -> sh.run("kill -SIGTERM " + pid + " && tail --pid=" + pid + " -f /dev/null"));
+        Platforms.onFreeBSD(() -> sh.run("kill -15 " + pid)); // todo: add PID check
         Platforms.onWindows(() -> {
             sh.run("Get-Process -Id " + pid + " | Stop-Process -Force; Wait-Process -Id " + pid);
 
