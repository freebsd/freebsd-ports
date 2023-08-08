--- src/core/core_module.pro.orig	2021-12-15 16:12:54 UTC
+++ src/core/core_module.pro
@@ -41,7 +41,7 @@ CONFIG -= bsymbolic_functions
 # and doesn't let Chromium get access to libc symbols through dlsym.
 CONFIG -= bsymbolic_functions
 
-linux {
+unix {
     !ccache:!use_gold_linker:!use_lld_linker {
         QMAKE_LINK="ulimit -n 4096 && $$QMAKE_LINK"
         QMAKE_LINK_SHLIB="ulimit -n 4096 && $$QMAKE_LINK_SHLIB"
