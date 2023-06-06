--- libparse/clk_wharton.c.orig	2023-06-06 04:33:42.000000000 -0700
+++ libparse/clk_wharton.c	2023-06-06 06:36:02.108114000 -0700
@@ -9,6 +9,8 @@
 #include <config.h>
 #endif
 
+#include <ntp_types.h>
+
 #if defined(REFCLOCK) && defined(CLOCK_PARSE) && defined(CLOCK_WHARTON_400A)
 /*
  * Support for WHARTON 400A Series clock + 404.2 serial interface.
