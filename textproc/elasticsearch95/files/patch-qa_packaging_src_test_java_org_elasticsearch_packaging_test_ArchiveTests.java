--- qa/packaging/src/test/java/org/elasticsearch/packaging/test/ArchiveTests.java.orig	2026-11-18 21:35:56 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/test/ArchiveTests.java
@@ -196,6 +196,10 @@ public class ArchiveTests extends PackagingTestCase {
             createKeystoreIfMissing();
             sh.run("chmod u-w " + installation.config);
         });
+        Platforms.onFreeBSD(() -> {
+            createKeystoreIfMissing();
+            sh.run("chmod u-w " + installation.config);
+        });
         try {
             startElasticsearch();
             verifySecurityNotAutoConfigured(installation);
@@ -219,6 +223,7 @@ public class ArchiveTests extends PackagingTestCase {
                 sh.chown(installation.config);
             });
             Platforms.onLinux(() -> { sh.run("chmod u+w " + installation.config); });
+            Platforms.onFreeBSD(() -> { sh.run("chmod u+w " + installation.config); });
             FileUtils.rm(installation.data);
         }
     }
@@ -259,6 +264,10 @@ public class ArchiveTests extends PackagingTestCase {
             createKeystoreIfMissing();
             bin.keystoreTool.run("passwd", password + "\n" + password + "\n");
         });
+        Platforms.onFreeBSD(() -> {
+            createKeystoreIfMissing();
+            bin.keystoreTool.run("passwd", password + "\n" + password + "\n");
+        });
         Platforms.onWindows(() -> {
             createKeystoreIfMissing();
             sh.run("Invoke-Command -ScriptBlock {echo '" + password + "'; echo '" + password + "'} | " + bin.keystoreTool + " passwd");
@@ -276,6 +285,7 @@ public class ArchiveTests extends PackagingTestCase {
 
         // Revert to an empty password for the rest of the tests
         Platforms.onLinux(() -> bin.keystoreTool.run("passwd", password + "\n" + "" + "\n"));
+        Platforms.onFreeBSD(() -> bin.keystoreTool.run("passwd", password + "\n" + "" + "\n"));
         Platforms.onWindows(
             () -> sh.run("Invoke-Command -ScriptBlock {echo '" + password + "'; echo '" + "" + "'} | " + bin.keystoreTool + " passwd")
         );
@@ -309,6 +319,10 @@ public class ArchiveTests extends PackagingTestCase {
             String systemJavaHome1 = sh.run("echo $SYSTEM_JAVA_HOME").stdout().trim();
             sh.getEnv().put("ES_JAVA_HOME", systemJavaHome1);
         });
+        Platforms.onFreeBSD(() -> {
+            String systemJavaHome1 = sh.run("echo $SYSTEM_JAVA_HOME").stdout().trim();
+            sh.getEnv().put("ES_JAVA_HOME", systemJavaHome1);
+        });
         Platforms.onWindows(() -> {
             final String systemJavaHome1 = sh.run("$Env:SYSTEM_JAVA_HOME").stdout().trim();
             sh.getEnv().put("ES_JAVA_HOME", systemJavaHome1);
@@ -330,6 +344,12 @@ public class ArchiveTests extends PackagingTestCase {
             // ensure that ES_JAVA_HOME is not set for the test
             sh.getEnv().remove("ES_JAVA_HOME");
         });
+        Platforms.onFreeBSD(() -> {
+            String systemJavaHome1 = sh.run("echo $SYSTEM_JAVA_HOME").stdout().trim();
+            sh.getEnv().put("JAVA_HOME", systemJavaHome1);
+            // ensure that ES_JAVA_HOME is not set for the test
+            sh.getEnv().remove("ES_JAVA_HOME");
+        });
         Platforms.onWindows(() -> {
             final String systemJavaHome1 = sh.run("$Env:SYSTEM_JAVA_HOME").stdout().trim();
             sh.getEnv().put("JAVA_HOME", systemJavaHome1);
@@ -360,6 +380,10 @@ public class ArchiveTests extends PackagingTestCase {
                 String systemJavaHome1 = sh.run("echo $SYSTEM_JAVA_HOME").stdout().trim();
                 sh.getEnv().put("ES_JAVA_HOME", systemJavaHome1);
             });
+            Platforms.onFreeBSD(() -> {
+                String systemJavaHome1 = sh.run("echo $SYSTEM_JAVA_HOME").stdout().trim();
+                sh.getEnv().put("ES_JAVA_HOME", systemJavaHome1);
+            });
             Platforms.onWindows(() -> {
                 final String systemJavaHome1 = sh.run("$Env:SYSTEM_JAVA_HOME").stdout().trim();
                 sh.getEnv().put("ES_JAVA_HOME", systemJavaHome1);
@@ -422,6 +446,27 @@ public class ArchiveTests extends PackagingTestCase {
                 FileUtils.rm(Paths.get(testJavaHome));
             }
         });
+
+        Platforms.onFreeBSD(() -> {
+            // Create temporary directory with a space and link to real java home
+            String testJavaHome = Paths.get("/tmp", "java home").toString();
+            try {
+                final String systemJavaHome = sh.run("echo $SYSTEM_JAVA_HOME").stdout().trim();
+                sh.run("ln -s \"" + systemJavaHome + "\" \"" + testJavaHome + "\"");
+                sh.getEnv().put("ES_JAVA_HOME", testJavaHome);
+
+                // verify ES can start, stop and run plugin list
+                startElasticsearch();
+                runElasticsearchTests();
+                stopElasticsearch();
+
+                String pluginListCommand = installation.bin + "/elasticsearch-plugin list";
+                Result result = sh.run(pluginListCommand);
+                assertThat(result.exitCode(), equalTo(0));
+            } finally {
+                FileUtils.rm(Paths.get(testJavaHome));
+            }
+        });
     }
 
     public void test65ForceBundledJdkEmptyJavaHome() throws Exception {
@@ -571,6 +616,7 @@ public class ArchiveTests extends PackagingTestCase {
             assertThat(result.stderr(), containsString("Unknown command [invalid-command]"));
         };
         Platforms.onLinux(action);
+        Platforms.onFreeBSD(action);
         Platforms.onWindows(action);
     }
 
@@ -583,6 +629,7 @@ public class ArchiveTests extends PackagingTestCase {
         };
 
         Platforms.onLinux(action);
+        Platforms.onFreeBSD(action);
         Platforms.onWindows(action);
     }
 
@@ -595,6 +642,7 @@ public class ArchiveTests extends PackagingTestCase {
         };
 
         Platforms.onLinux(action);
+        Platforms.onFreeBSD(action);
         Platforms.onWindows(action);
     }
 
@@ -634,6 +682,7 @@ public class ArchiveTests extends PackagingTestCase {
         };
 
         Platforms.onLinux(action);
+        Platforms.onFreeBSD(action);
         Platforms.onWindows(action);
     }
 }
