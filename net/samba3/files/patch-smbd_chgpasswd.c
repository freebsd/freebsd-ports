--- smbd/chgpasswd.c.orig	Mon Apr  5 21:33:21 2004
+++ smbd/chgpasswd.c	Mon Apr  5 21:33:34 2004
@@ -49,7 +49,6 @@
 #include "includes.h"
 
 #ifdef HAVE_WORKING_CRACKLIB
-#include <crack.h>
 
 #ifndef HAVE_CRACKLIB_DICTPATH
 #ifndef CRACKLIB_DICTPATH
