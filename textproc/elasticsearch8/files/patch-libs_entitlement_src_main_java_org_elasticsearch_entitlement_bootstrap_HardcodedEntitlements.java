--- libs/entitlement/src/main/java/org/elasticsearch/entitlement/bootstrap/HardcodedEntitlements.java.orig	2026-10-28 21:29:53 UTC
+++ libs/entitlement/src/main/java/org/elasticsearch/entitlement/bootstrap/HardcodedEntitlements.java
@@ -40,6 +40,7 @@ import static org.elasticsearch.entitlement.runtime.po
 import static org.elasticsearch.entitlement.runtime.policy.PathLookup.BaseDir.PLUGINS;
 import static org.elasticsearch.entitlement.runtime.policy.PathLookup.BaseDir.SHARED_DATA;
 import static org.elasticsearch.entitlement.runtime.policy.PathLookup.BaseDir.SHARED_REPO;
+import static org.elasticsearch.entitlement.runtime.policy.Platform.FREEBSD;
 import static org.elasticsearch.entitlement.runtime.policy.Platform.LINUX;
 import static org.elasticsearch.entitlement.runtime.policy.entitlements.FilesEntitlement.Mode.READ;
 import static org.elasticsearch.entitlement.runtime.policy.entitlements.FilesEntitlement.Mode.READ_WRITE;
@@ -79,7 +80,10 @@ class HardcodedEntitlements {
             FilesEntitlement.FileData.ofPath(Path.of("/sys/fs/cgroup/"), READ).withPlatform(LINUX),
             // // io stats on Linux
             FilesEntitlement.FileData.ofPath(Path.of("/proc/self/mountinfo"), READ).withPlatform(LINUX),
-            FilesEntitlement.FileData.ofPath(Path.of("/proc/diskstats"), READ).withPlatform(LINUX)
+            FilesEntitlement.FileData.ofPath(Path.of("/proc/diskstats"), READ).withPlatform(LINUX),
+            // OS release on FreeBSD
+            FilesEntitlement.FileData.ofPath(Path.of("/etc/os-release"), READ).withPlatform(FREEBSD),
+            FilesEntitlement.FileData.ofPath(Path.of("/proc/curproc/rlimit"), READ).withPlatform(FREEBSD)
         );
         if (pidFile != null) {
             serverModuleFileDatas.add(FilesEntitlement.FileData.ofPath(pidFile, READ_WRITE));
