--- buildSrc/src/main/java/org/zaproxy/zap/tasks/GradleBuildWithGitRepos.java	2022-12-19 14:49:43.923955000 -0500
+++ buildSrc/src/main/java/org/zaproxy/zap/tasks/GradleBuildWithGitRepos.java	2022-12-19 14:49:59.270410000 -0500
@@ -48,6 +48,7 @@
 import org.gradle.api.provider.Property;
 import org.gradle.api.tasks.Console;
 import org.gradle.api.tasks.Input;
+import org.gradle.api.tasks.InputDirectory;
 import org.gradle.api.tasks.InputFile;
 import org.gradle.api.tasks.Nested;
 import org.gradle.api.tasks.TaskAction;
@@ -80,7 +81,7 @@
         return repositoriesDataFile;
     }
 
-    @Input
+    @InputDirectory
     public DirectoryProperty getRepositoriesDirectory() {
         return repositoriesDirectory;
     }
