--- ./alpine/alpine.c.orig	2013-08-14 23:36:01.000000000 -0500
+++ ./alpine/alpine.c	2014-05-25 19:15:31.000000000 -0500
@@ -50,7 +50,6 @@
 #include "init.h"
 #include "remote.h"
 #include "pattern.h"
-#include "newuser.h"
 #include "setup.h"
 #include "adrbkcmd.h"
 #include "signal.h"
@@ -767,7 +766,6 @@
 	pine_state->mangled_header = 1;
 	show_main_screen(pine_state, 0, FirstMenu, &main_keymenu, 0,
 			 (Pos *) NULL);
-	new_user_or_version(pine_state);
 	ClearScreen();
     }
     
