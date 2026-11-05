--- qa/packaging/src/test/java/org/elasticsearch/packaging/util/Distribution.java.orig	2026-10-28 20:24:18 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/util/Distribution.java
@@ -40,8 +40,10 @@ public class Distribution {
             this.packaging = Packaging.valueOf(filename.substring(lastDot + 1).toUpperCase(Locale.ROOT));
         }
 
-        this.platform = filename.contains("windows") ? Platform.WINDOWS : Platform.LINUX;
-        this.hasJdk = filename.contains("no-jdk") == false;
+        this.platform = filename.contains("windows")
+            ? Platform.WINDOWS
+            : (filename.contains("freebsd") ? Platform.FREEBSD : Platform.LINUX);
+        this.hasJdk = (filename.contains("no-jdk") || filename.contains("freebsd")) == false;
         this.baseVersion = filename.split("-", 3)[1];
         this.version = filename.contains("-SNAPSHOT") ? this.baseVersion + "-SNAPSHOT" : this.baseVersion;
     }
@@ -66,7 +68,7 @@ public class Distribution {
 
     public enum Packaging {
 
-        TAR(".tar.gz", Platforms.LINUX || Platforms.DARWIN),
+        TAR(".tar.gz", Platforms.LINUX || Platforms.DARWIN || Platforms.FREEBSD),
         ZIP(".zip", Platforms.WINDOWS),
         DEB(".deb", Platforms.isDPKG()),
         RPM(".rpm", Platforms.isRPM()),
@@ -90,7 +92,8 @@ public class Distribution {
     public enum Platform {
         LINUX,
         WINDOWS,
-        DARWIN;
+        DARWIN,
+        FREEBSD;
 
         public String toString() {
             return name().toLowerCase(Locale.ROOT);
