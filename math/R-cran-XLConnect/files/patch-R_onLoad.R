--- R/onLoad.R.orig	2021-09-30 08:28:06 UTC
+++ R/onLoad.R
@@ -54,44 +54,7 @@
     repo <- "https://repo1.maven.org/maven2"
   }
   apachePrefix <- paste0(repo, "/org/apache")
-  sharedPaths <- tryCatch({
-    c(
-      xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi-ooxml-schemas/4.1.2/poi-ooxml-schemas-4.1.2.jar"), "poi-ooxml-schemas.jar", 
-      "4\\.[1-9].*",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi-ooxml/4.1.2/poi-ooxml-4.1.2.jar"), "poi-ooxml.jar", 
-      "4\\.[1-9].*",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/poi/4.1.2/poi-4.1.2.jar"), "poi.jar", 
-      "4\\.[1-9].*",  libname, pkgname, debianpkg = "libapache-poi-java", rpmpkg="apache-poi"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-compress/1.20/commons-compress-1.20.jar"), "commons-compress.jar",
-      "1\\.(1[8-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg = "libcommons-compress-java", rpmpkg="apache-commons-compress"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/xmlbeans/xmlbeans/3.1.0/xmlbeans-3.1.0.jar"), "xmlbeans.jar",
-      "3\\..*",  libname, pkgname, debianpkg="libxmlbeans-java"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-collections4/4.4/commons-collections4-4.4.jar"), "commons-collections4.jar",
-      "4-4\\.([2-9]|1[0-9]).*",  libname, pkgname, debianpkg="libcommons-collections4-java", rpmpkg="apache-commons-collections4"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/commons/commons-math3/3.6.1/commons-math3-3.6.1.jar"), "commons-math3.jar",
-      "3\\.([6-9]|1[0-9]).*",  libname, pkgname, debianpkg="libcommons-math3-java"),
-    xlcEnsureDependenciesFor(
-      paste0(repo, "/commons-codec/commons-codec/1.15/commons-codec-1.15.jar"), "commons-codec-1.15.jar",
-      "1\\.(1[1-9]|[2-9][0-9]).*",  libname, pkgname, debianpkg="libcommons-codec-java", rpmpkg="apache-commons-codec"),
-    xlcEnsureDependenciesFor(
-      paste0(apachePrefix, "/poi/ooxml-schemas/1.4/ooxml-schemas-1.4.jar"), "ooxml-schemas.jar",
-      "1\\.([4-9]|[1-9][0-9]).*",  libname, pkgname),
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
   .jpackage(name = pkgname, jars = "*", morePaths = sharedPaths)
   # Perform general XLConnect settings - pass package description
   XLConnectSettings(packageDescription(pkgname))
