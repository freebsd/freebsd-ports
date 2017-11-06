Generate split out debug files on FreeBSD too.

--- src/core/core_module.pro.orig	2017-04-20 22:41:02 UTC
+++ src/core/core_module.pro
@@ -42,7 +42,7 @@ CONFIG -= bsymbolic_functions
 
 contains(QT_CONFIG, egl): CONFIG += egl
 
-linux: contains(QT_CONFIG, separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
+unix: contains(QT_CONFIG, separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
 
 REPACK_DIR = $$OUT_PWD/$$getConfigDir()/gen/repack
 # Duplicated from resources/resources.gyp
