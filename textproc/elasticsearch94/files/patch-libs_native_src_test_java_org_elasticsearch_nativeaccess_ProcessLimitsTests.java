--- libs/native/src/test/java/org/elasticsearch/nativeaccess/ProcessLimitsTests.java.orig	2026-10-28 20:24:18 UTC
+++ libs/native/src/test/java/org/elasticsearch/nativeaccess/ProcessLimitsTests.java
@@ -36,6 +36,17 @@ public class ProcessLimitsTests extends ESTestCase {
                 }
             }
             fail("should have read max processes from /proc/self/limits");
+        } else if (Constants.FREE_BSD) {
+            final List<String> lines = Files.readAllLines(PathUtils.get("/proc/curproc/rlimit"));
+            for (final String line : lines) {
+                if (line != null && line.startsWith("nproc")) {
+                    final String[] fields = line.split("\\s+");
+                    final long limit = Long.parseLong(fields[1]);
+                    assertThat(nativeAccess.getProcessLimits().maxThreads(), equalTo(limit));
+                    return;
+                }
+            }
+            fail("should have read max processes from /proc/curproc/rlimit (is /proc mounted?)");
         } else {
             assertThat(nativeAccess.getProcessLimits().maxThreads(), equalTo(-1L));
         }
@@ -53,6 +64,17 @@ public class ProcessLimitsTests extends ESTestCase {
                 }
             }
             fail("should have read max size virtual memory from /proc/self/limits");
+        } else if (Constants.FREE_BSD) {
+            final List<String> lines = Files.readAllLines(PathUtils.get("/proc/curproc/rlimit"));
+            for (final String line : lines) {
+                if (line != null && line.startsWith("vmem")) {
+                    final String[] fields = line.split("\\s+");
+                    final long limit = "-1".equals(fields[1]) ? ProcessLimits.UNLIMITED : Long.parseLong(fields[1]);
+                    assertThat(nativeAccess.getProcessLimits().maxVirtualMemorySize(), equalTo(limit));
+                    return;
+                }
+            }
+            fail("should have read max virtual memory size from /proc/curproc/rlimit (is /proc mounted?)");
         } else if (Constants.MAC_OS_X) {
             assertThat(nativeAccess.getProcessLimits().maxVirtualMemorySize(), greaterThanOrEqualTo(0L));
         } else {
@@ -72,6 +94,17 @@ public class ProcessLimitsTests extends ESTestCase {
                 }
             }
             fail("should have read max file size from /proc/self/limits");
+        } else if (Constants.FREE_BSD) {
+            final List<String> lines = Files.readAllLines(PathUtils.get("/proc/curproc/rlimit"));
+            for (final String line : lines) {
+                if (line != null && line.startsWith("fsize")) {
+                    final String[] fields = line.split("\\s+");
+                    final long limit = "-1".equals(fields[1]) ? ProcessLimits.UNLIMITED : Long.parseLong(fields[1]);
+                    assertThat(nativeAccess.getProcessLimits().maxFileSize(), equalTo(limit));
+                    return;
+                }
+            }
+            fail("should have read max file size from /proc/curproc/rlimit (is /proc mounted?)");
         } else if (Constants.MAC_OS_X) {
             assertThat(nativeAccess.getProcessLimits().maxFileSize(), greaterThanOrEqualTo(0L));
         } else {
