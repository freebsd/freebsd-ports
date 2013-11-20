--- library/gnome-keyring-utils.c.orig	Fri Aug 17 12:15:17 2012
+++ library/gnome-keyring-utils.c	Sat Oct 27 14:36:16 2012
@@ -32,6 +32,8 @@
 
 #include "egg/egg-secure-memory.h"
 
+EGG_SECURE_DECLARE (libgnome_keyring_utils);
+
 /**
  * SECTION:gnome-keyring-result
  * @title: Result Codes
