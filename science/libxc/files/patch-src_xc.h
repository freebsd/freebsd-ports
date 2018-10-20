--- src/xc.h.orig	2018-10-20 19:30:09 UTC
+++ src/xc.h
@@ -14,7 +14,7 @@ extern "C" {
 #endif
 
 #ifdef HAVE_CONFIG_H
-#include "config.h"
+//#include "config.h" // "config.h" should never be included by the installed package: https://gitlab.com/libxc/libxc/issues/66
 #endif
 
 #include <xc_version.h>
