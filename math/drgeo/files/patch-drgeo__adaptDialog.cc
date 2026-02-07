--- drgeo_adaptDialog.cc.orig	Mon Jun  7 02:30:06 2004
+++ drgeo_adaptDialog.cc	Tue Jun  8 13:20:32 2004
@@ -33,7 +33,7 @@
 #include "drgeo_menu.h"
 #include "drgenius_mdi.h"
 
-#ifndef G_PLATFORM_WIN32
+#if !defined(G_PLATFORM_WIN32) && !defined(__FreeBSD__)
    #include <crypt.h>
 #endif 
 
