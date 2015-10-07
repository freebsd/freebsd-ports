Remove legacy header as libcucul has now been merged into libcaca.

--- ./modules/caca.c.orig	2015-07-21 20:34:23.876845709 +0200
+++ ./modules/caca.c	2015-07-21 20:34:33.937820107 +0200
@@ -37,7 +37,6 @@
 
 #include <ncurses.h>
 
-#include <cucul.h>
 #include <caca.h>
 
 #include "process.h"
