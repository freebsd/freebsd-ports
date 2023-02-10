--- R/onLoad.R.orig	2023-01-24 09:49:21 UTC
+++ R/onLoad.R
@@ -55,47 +55,7 @@
     repo <- "https://repo1.maven.org/maven2"
   }
   apachePrefix <- paste0(repo, "/org/apache")
-  sharedPaths <- tryCatch({
-    c(
-      xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi-ooxml-full/5.2.3/poi-ooxml-full-5.2.3.jar"), "poi-ooxml-full.jar", 
-      "5.2.3",  libname, pkgname),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi-ooxml/5.2.3/poi-ooxml-5.2.3.jar"), "poi-ooxml.jar", 
-      "5.2.3",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi/5.2.3/poi-5.2.3.jar"), "poi.jar", 
-      "5.2.3",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-compress/1.21/commons-compress-1.21.jar"), "commons-compress.jar",
-      "1\\.(1[8-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg = "libcommons-compress-java", rpmpkg="apache-commons-compress"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/xmlbeans/xmlbeans/5.1.1/xmlbeans-5.1.1.jar"), "xmlbeans.jar",
-      "5\\..*",  libname, pkgname, debianpkg="libxmlbeans-java"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-collections4/4.4/commons-collections4-4.4.jar"), "commons-collections4.jar",
-      "4-4\\.([2-9]|1[0-9]).*",  libname, pkgname, debianpkg="libcommons-collections4-java", rpmpkg="apache-commons-collections4"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-math3/3.6.1/commons-math3-3.6.1.jar"), "commons-math3.jar",
-      "3\\.([6-9]|1[0-9]).*",  libname, pkgname, debianpkg="libcommons-math3-java"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/logging/log4j/log4j-api/2.18.0/log4j-api-2.18.0.jar"), "log4j-api.jar",
-      "2.17.2",  libname, pkgname),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/commons-codec/commons-codec/1.15/commons-codec-1.15.jar"), "commons-codec-1.15.jar",
-      "1\\.(1[1-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg="libcommons-codec-java", rpmpkg="apache-commons-codec"),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/commons-io/commons-io/2.11.0/commons-io-2.11.0.jar"), "commons-io-2.11.0.jar",
-      "2\\.(1[1-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg="libcommons-io-java", rpmpkg="apache-commons-io"),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/com/zaxxer/SparseBitSet/1.2/SparseBitSet-1.2.jar"), "SparseBitSet.jar",
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
