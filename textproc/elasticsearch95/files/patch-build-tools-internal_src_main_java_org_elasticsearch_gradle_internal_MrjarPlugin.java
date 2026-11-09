--- build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/MrjarPlugin.java.orig	2026-10-28 21:58:41 UTC
+++ build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/MrjarPlugin.java
@@ -9,6 +9,7 @@ package org.elasticsearch.gradle.internal;
 
 package org.elasticsearch.gradle.internal;
 
+import org.elasticsearch.gradle.internal.conventions.util.Util;
 import org.elasticsearch.gradle.internal.info.BuildParameterExtension;
 import org.elasticsearch.gradle.internal.precommit.CheckForbiddenApisTask;
 import org.elasticsearch.gradle.util.GradleUtils;
@@ -131,21 +132,52 @@ public class MrjarPlugin implements Plugin<Project> {
             GradleUtils.extendSourceSet(project, parentSourceSetName, sourceSetName);
         }
 
+        int finalJavaVersion;
+
+        // Override Java version when building on FreeBSD
+        // Required Java compiler minimum is 21
+        if (System.getProperty("os.name").startsWith("FreeBSD") && Util.getBooleanProperty("freebsd.build.override-jdk", false)) {
+            if (javaVersion != 21 && javaVersion != 25) {
+                // Project-level overrides
+                if (javaVersion == 22) {
+                    if (project.getPath().equals(":libs:foreign-adapter") || project.getPath().equals(":libs:cli-terminal")) {
+                        System.out.printf(
+                            "********** Overriding JDK version %d to 25 for %s (%s) **********\n",
+                            javaVersion,
+                            project.getDisplayName(),
+                            sourceSetName
+                        );
+                        finalJavaVersion = 25;
+                    } else {
+                        finalJavaVersion = javaVersion;
+                    }
+                } else {
+                    finalJavaVersion = javaVersion;
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
+                .set(javaToolchains.compilerFor(spec -> {
+                    spec.getLanguageVersion().set(JavaLanguageVersion.of(finalJavaVersion));
+                }));
+            compileTask.setSourceCompatibility(Integer.toString(finalJavaVersion));
             CompileOptions compileOptions = compileTask.getOptions();
-            compileOptions.getRelease().set(javaVersion);
+            compileOptions.getRelease().set(finalJavaVersion);
         });
         if (isMainSourceSet) {
             project.getTasks().register(sourceSet.getJavadocTaskName(), Javadoc.class, javadocTask -> {
                 javadocTask.getJavadocTool().set(javaToolchains.javadocToolFor(spec -> {
-                    spec.getLanguageVersion().set(JavaLanguageVersion.of(javaVersion));
+                    spec.getLanguageVersion().set(JavaLanguageVersion.of(finalJavaVersion));
                 }));
             });
         }
-        configurePreviewFeatures(project, sourceSet, javaVersion);
+        configurePreviewFeatures(project, sourceSet, finalJavaVersion);
 
         // Since we configure MRJAR sourcesets to allow preview apis, class signatures for those
         // apis are not known by forbidden apis, so we must ignore all missing classes. We could, in theory,
