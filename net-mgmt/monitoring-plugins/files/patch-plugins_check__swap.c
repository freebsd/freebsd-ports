--- plugins/check_swap.c.orig	2023-03-19 09:10:16.525073000 +0100
+++ plugins/check_swap.c	2023-03-19 09:10:31.862180000 +0100
@@ -34,9 +34,6 @@ const char *email = "devel@monitoring-plugins.org";
 #include "common.h"
 #include "popen.h"
 #include "utils.h"
-#include <string.h>
-#include <math.h>
-#include <libintl.h>
 
 #ifdef HAVE_DECL_SWAPCTL
 # ifdef HAVE_SYS_PARAM_H
