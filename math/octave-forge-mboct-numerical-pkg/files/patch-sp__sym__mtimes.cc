--- sp_sym_mtimes.cc.orig	2025-08-26 03:13:45 UTC
+++ sp_sym_mtimes.cc
@@ -15,6 +15,7 @@
 
 #include "config.h"
 
+#include <assert.h>
 #include <octave/oct.h>
 
 // PKG_ADD: autoload ("sp_sym_mtimes", "__mboct_numerical__.oct");
