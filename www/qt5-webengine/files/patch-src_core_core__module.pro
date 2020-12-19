--- src/core/core_module.pro.orig	2020-11-07 01:22:36 UTC
+++ src/core/core_module.pro
@@ -41,7 +41,7 @@ QMAKE_INFO_PLIST = Info_mac.plist
 # and doesn't let Chromium get access to libc symbols through dlsym.
 CONFIG -= bsymbolic_functions
 
-linux:qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
+unix:qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
 
 REPACK_DIR = $$OUT_PWD/$$getConfigDir()
 
