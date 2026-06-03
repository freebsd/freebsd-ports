--- src/scf/ks/xcfunc.h.orig	2026-04-20 18:27:14 UTC
+++ src/scf/ks/xcfunc.h
@@ -33,6 +33,7 @@
 #include <bagel_config.h>
 #ifdef HAVE_XC_H
 #include <xc.h> // header provided by libxc
+#include <xc_funcs.h>
 #endif
 
 namespace bagel {
