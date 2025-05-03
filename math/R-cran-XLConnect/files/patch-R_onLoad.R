--- R/onLoad.R.orig	2025-04-29 09:58:50 UTC
+++ R/onLoad.R
@@ -55,50 +55,7 @@
     repo <- "https://repo1.maven.org/maven2"
   }
   apachePrefix <- paste0(repo, "/org/apache")
-  sharedPaths <- tryCatch({
-    c(
-      xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi-ooxml-full/5.4.1/poi-ooxml-full-5.4.1.jar"), "poi-ooxml-full.jar", 
-      "5.4.1",  libname, pkgname),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi-ooxml/5.4.1/poi-ooxml-5.4.1.jar"), "poi-ooxml.jar", 
-      "5.4.1",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi/5.4.1/poi-5.4.1.jar"), "poi.jar", 
-      "5.4.1",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-compress/1.27.1/commons-compress-1.27.1.jar"), "commons-compress.jar",
-      "1\\.(2[5-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg = "libcommons-compress-java", rpmpkg="apache-commons-compress"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-lang3/3.16.0/commons-lang3-3.16.0.jar"), "commons-lang3-3.16.0.jar",
-      "3\\.(1[4-9]|[2-9][0-9])\\.*",  libname, pkgname, debianpkg="libcommons-lang3-java", rpmpkg="apache-commons-lang3"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/xmlbeans/xmlbeans/5.3.0/xmlbeans-5.3.0.jar"), "xmlbeans.jar",
-      "5\\..*",  libname, pkgname, debianpkg="libxmlbeans-java"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-collections4/4.4/commons-collections4-4.4.jar"), "commons-collections4.jar",
-      "4-4\\.([2-9]|1[0-9]).*",  libname, pkgname, debianpkg="libcommons-collections4-java", rpmpkg="apache-commons-collections4"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-math3/3.6.1/commons-math3-3.6.1.jar"), "commons-math3.jar",
-      "3\\.([6-9]|1[0-9]).*",  libname, pkgname, debianpkg="libcommons-math3-java"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/logging/log4j/log4j-api/2.24.3/log4j-api-2.24.3.jar"), "log4j-api.jar",
-      "2\\.24\\..*",  libname, pkgname),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/commons-codec/commons-codec/1.18.0/commons-codec-1.18.0.jar"), "commons-codec-1.18.0.jar",
-      "1\\.(1[1-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg="libcommons-codec-java", rpmpkg="apache-commons-codec"),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/commons-io/commons-io/2.18.0/commons-io-2.18.0.jar"), "commons-io-2.18.0.jar",
-      "2\\.(1[5-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg="libcommons-io-java", rpmpkg="apache-commons-io"),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/com/zaxxer/SparseBitSet/1.3/SparseBitSet-1.3.jar"), "SparseBitSet.jar",
-      "1\\.([2-9]|[1-9][0-9]).*",  libname, pkgname)
-    )
-  },
-  error=function(e) {
-          e
-        }
-  )
+  sharedPaths <- ""
   .jpackage(name = pkgname, jars = "*", morePaths = sharedPaths, own.loader=TRUE)  
   # Perform general XLConnect settings - pass package description
   XLConnectSettings(packageDescription(pkgname))
