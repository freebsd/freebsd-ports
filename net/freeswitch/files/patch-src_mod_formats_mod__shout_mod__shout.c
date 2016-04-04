--- src/mod/formats/mod_shout/mod_shout.c.orig	2016-01-12 16:32:36 UTC
+++ src/mod/formats/mod_shout/mod_shout.c
@@ -35,7 +35,7 @@
 #include <switch.h>
 #include "mpg123.h"
 #include <shout/shout.h>
-#include <lame.h>
+#include <lame/lame.h>
 #include <switch_curl.h>
 
 #define OUTSCALE 8192 * 2
