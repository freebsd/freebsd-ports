Do not go into the examples/ directory, which contains only platformplugin/.

Even though it is not part of the default target, it is included in `make
install', and platformplugin's .pro file has a DESTDIR setting that causes the
file system to be touched even though there is nothing to build or install.
--- Source/QtWebKit.pro
+++ Source/QtWebKit.pro
@@ -38,9 +38,4 @@ build?(webkit1) {
         tests.file = tests.pri
         SUBDIRS += tests
     }
-
-    examples.file = WebKit/qt/examples/examples.pro
-    examples.CONFIG += no_default_target
-    examples.makefile = Makefile
-    SUBDIRS += examples
 }
