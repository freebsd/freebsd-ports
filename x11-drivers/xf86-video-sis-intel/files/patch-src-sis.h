--- src/sis.h.orig	2007-05-02 05:13:01.000000000 +0400
+++ src/sis.h	2008-06-10 19:44:21.000000000 +0400
@@ -60,7 +60,6 @@
 #define TWDEBUG    
 #endif
 
-#include "xf86_ansic.h"
 #include "compiler.h"
 #include "xf86Pci.h"
 #include "xf86Priv.h"
@@ -88,16 +87,16 @@
 	(((major) * 10000000) + ((minor) * 100000) + ((patch) * 1000) + snap)
 #define XF86_VERSION_CURRENT XF86_VERSION_NUMERIC(4,3,99,902,0)
 #endif
-#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,0,0,0)
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,0,0,0) || XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(4,0,0,0,0)
 #define SIS_HAVE_RR_FUNC
 #ifdef HaveDriverFuncs
 #undef  SIS_HaveDriverFuncs
 #define SIS_HaveDriverFuncs HaveDriverFuncs
 #define SIS_HAVE_DRIVER_FUNC
 #endif /* HaveDriverFuncs */
-#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,99,900,0)
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,99,900,0) || XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(4,0,0,0,0)
 #define SISISXORG6899900
-#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,99,901,0)
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,99,901,0) || XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(4,0,0,0,0)
 #define SISISXORG6899901
 #ifdef RANDR
 #define SIS_HAVE_RR_GET_MODE_MM
@@ -181,7 +180,6 @@
 #if XF86_VERSION_CURRENT >= XF86_VERSION_NUMERIC(4,3,99,14,0)
 #define SISNEWDRI
 #endif
-#define SIS315DRI		/* define this if dri is adapted for 315/330 series */
 #include "xf86drm.h"
 #include "sarea.h"
 #define _XF86DRI_SERVER_
@@ -230,14 +228,14 @@
 
 #undef SISCHECKOSSSE
 #ifdef XORG_VERSION_CURRENT
-#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,99,13,0)
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,99,13,0) || XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(4,0,0,0,0)
 #define SISCHECKOSSSE		/* Automatic check OS for SSE; requires SigIll facility */
 #endif
 #endif
 
 #undef SISGAMMARAMP
 #ifdef XORG_VERSION_CURRENT
-#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,99,13,0)
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(6,8,99,13,0) || XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(4,0,0,0,0)
 #define SISGAMMARAMP		/* Driver can set gamma ramp; requires additional symbols in xf86sym.h */
 #endif
 #endif
