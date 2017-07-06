--- signon.pro.orig	2015-04-19 18:24:47 UTC
+++ signon.pro
@@ -7,8 +7,6 @@ tests.depends = lib src
 
 include( common-installs-config.pri )
 
-include( doc/doc.pri )
-
 DISTNAME = $${PROJECT_NAME}-$${PROJECT_VERSION}
 dist.commands = "git archive --format=tar --prefix=$${DISTNAME}/ HEAD | bzip2 -9 > $${DISTNAME}.tar.bz2"
 QMAKE_EXTRA_TARGETS += dist
