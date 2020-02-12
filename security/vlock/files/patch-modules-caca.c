Remove legacy header as libcucul has now been merged into libcaca.

--- modules/caca.c.orig	2011-09-18 15:22:35 UTC
+++ modules/caca.c
@@ -37,7 +37,6 @@
 
 #include <ncurses.h>
 
-#include <cucul.h>
 #include <caca.h>
 
 #include "process.h"
