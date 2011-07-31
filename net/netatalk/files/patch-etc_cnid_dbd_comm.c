--- etc/cnid_dbd/comm.c.orig	2011-07-30 18:27:55.000000000 -0400
+++ etc/cnid_dbd/comm.c	2011-07-30 18:28:04.000000000 -0400
@@ -9,9 +9,6 @@
 #include "config.h"
 #endif
 
-#ifndef _XOPEN_SOURCE
-# define _XOPEN_SOURCE 600
-#endif
 #ifndef __EXTENSIONS__
 # define __EXTENSIONS__
 #endif
