No need to limit max open file descriptors.
See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=270041

--- src/core/core_module.pro.orig	2021-12-15 16:12:54 UTC
+++ src/core/core_module.pro
@@ -41,10 +41,10 @@ QMAKE_INFO_PLIST = Info_mac.plist
 # and doesn't let Chromium get access to libc symbols through dlsym.
 CONFIG -= bsymbolic_functions
 
-linux {
+unix {
     !ccache:!use_gold_linker:!use_lld_linker {
-        QMAKE_LINK="ulimit -n 4096 && $$QMAKE_LINK"
-        QMAKE_LINK_SHLIB="ulimit -n 4096 && $$QMAKE_LINK_SHLIB"
+        QMAKE_LINK="$$QMAKE_LINK"
+        QMAKE_LINK_SHLIB="$$QMAKE_LINK_SHLIB"
     }
     qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
 }
