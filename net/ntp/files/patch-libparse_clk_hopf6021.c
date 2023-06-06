--- libparse/clk_hopf6021.c.orig	2023-06-06 04:33:42.000000000 -0700
+++ libparse/clk_hopf6021.c	2023-06-06 06:36:00.964222000 -0700
@@ -20,6 +20,8 @@
 # include <config.h>
 #endif
 
+#include <ntp_types.h>
+
 #if defined(REFCLOCK) && defined(CLOCK_PARSE) && defined(CLOCK_HOPF6021)
 
 #include "ntp_fp.h"
