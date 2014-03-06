--- include/plConfig.h.in.orig	2013-12-29 21:11:07.000000000 +0100
+++ include/plConfig.h.in	2014-03-06 15:35:44.000000000 +0100
@@ -44,7 +44,8 @@
 #ifndef __PLCONFIG_H__
 #define __PLCONFIG_H__
 
-#ifdef HAVE_CONFIG_H
+// plplot_config.h won't be installed: don't let it be used by consumers
+#if defined(HAVE_CONFIG_H) && defined(_IS_BUILDING_PLPLOT_PORT_)
 #  include <plplot_config.h>
 #endif
 
