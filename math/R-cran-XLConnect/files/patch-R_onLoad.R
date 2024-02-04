--- R/onLoad.R.orig	2024-01-30 12:03:57 UTC
+++ R/onLoad.R
@@ -55,47 +55,7 @@
     repo <- "https://repo1.maven.org/maven2"
   }
   apachePrefix <- paste0(repo, "/org/apache")
-  sharedPaths <- tryCatch({
-    c(
-      xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi-ooxml-full/5.2.5/poi-ooxml-full-5.2.5.jar"), "poi-ooxml-full.jar", 
-      "5.2.5",  libname, pkgname),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi-ooxml/5.2.5/poi-ooxml-5.2.5.jar"), "poi-ooxml.jar", 
-      "5.2.5",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi/5.2.5/poi-5.2.5.jar"), "poi.jar", 
-      "5.2.5",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-compress/1.25.0/commons-compress-1.25.0.jar"), "commons-compress.jar",
-      "1\\.(2[5-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg = "libcommons-compress-java", rpmpkg="apache-commons-compress"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/xmlbeans/xmlbeans/5.2.0/xmlbeans-5.2.0.jar"), "xmlbeans.jar",
-      "5\\..*",  libname, pkgname, debianpkg="libxmlbeans-java"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-collections4/4.4/commons-collections4-4.4.jar"), "commons-collections4.jar",
-      "4-4\\.([2-9]|1[0-9]).*",  libname, pkgname, debianpkg="libcommons-collections4-java", rpmpkg="apache-commons-collections4"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-math3/3.6.1/commons-math3-3.6.1.jar"), "commons-math3.jar",
-      "3\\.([6-9]|1[0-9]).*",  libname, pkgname, debianpkg="libcommons-math3-java"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/logging/log4j/log4j-api/2.21.1/log4j-api-2.21.1.jar"), "log4j-api.jar",
-      "2.21.1",  libname, pkgname),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/commons-codec/commons-codec/1.16.0/commons-codec-1.16.0.jar"), "commons-codec-1.16.0.jar",
-      "1\\.(1[1-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg="libcommons-codec-java", rpmpkg="apache-commons-codec"),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/commons-io/commons-io/2.15.0/commons-io-2.15.0.jar"), "commons-io-2.15.0.jar",
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
