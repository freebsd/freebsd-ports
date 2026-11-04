--- build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/MrjarPlugin.java.orig	2026-10-28 21:29:53 UTC
+++ build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/MrjarPlugin.java
@@ -9,6 +9,7 @@ package org.elasticsearch.gradle.internal;
 
 package org.elasticsearch.gradle.internal;
 
+import org.elasticsearch.gradle.internal.conventions.util.Util;
 import org.elasticsearch.gradle.internal.info.BuildParameterExtension;
 import org.elasticsearch.gradle.internal.info.GlobalBuildInfoPlugin;
 import org.elasticsearch.gradle.internal.precommit.CheckForbiddenApisTask;
@@ -128,13 +129,40 @@ public class MrjarPlugin implements Plugin<Project> {
             GradleUtils.extendSourceSet(project, parentSourceSetName, sourceSetName);
         }
 
+        int finalJavaVersion;
+
+        // Override Java version when building on FreeBSD
+        if (System.getProperty("os.name").equals("FreeBSD") && Util.getBooleanProperty("freebsd.build.override-jdk", false)) {
+            if (javaVersion != 17 && javaVersion != 21 && javaVersion != 25) {
+                if (javaVersion == 20) {
+                    if (project.getPath().equals(":libs:native")) {
+                        System.out.printf(
+                            "********** Overriding JDK version %d to 21 for %s (%s) **********\n",
+                            javaVersion,
+                            project.getDisplayName(),
+                            sourceSetName
+                        );
+                        finalJavaVersion = 21;
+                    } else {
+                        finalJavaVersion = javaVersion;
+                    }
+                } else {
+                    finalJavaVersion = 25;
+                }
+            } else {
+                finalJavaVersion = javaVersion;
+            }
+        } else {
+            finalJavaVersion = javaVersion;
+        }
+
         project.getTasks().withType(JavaCompile.class).named(sourceSet.getCompileJavaTaskName()).configure(compileTask -> {
             compileTask.getJavaCompiler()
-                .set(javaToolchains.compilerFor(spec -> { spec.getLanguageVersion().set(JavaLanguageVersion.of(javaVersion)); }));
-            compileTask.setSourceCompatibility(Integer.toString(javaVersion));
-            compileTask.setTargetCompatibility(Integer.toString(javaVersion));
+                .set(javaToolchains.compilerFor(spec -> { spec.getLanguageVersion().set(JavaLanguageVersion.of(finalJavaVersion)); }));
+            compileTask.setSourceCompatibility(Integer.toString(finalJavaVersion));
+            compileTask.setTargetCompatibility(Integer.toString(finalJavaVersion));
             CompileOptions compileOptions = compileTask.getOptions();
-            compileOptions.getRelease().set(javaVersion);
+            compileOptions.getRelease().set(finalJavaVersion);
             compileOptions.getCompilerArgs().add("--enable-preview");
             compileOptions.getCompilerArgs().add("-Xlint:-preview");
 
