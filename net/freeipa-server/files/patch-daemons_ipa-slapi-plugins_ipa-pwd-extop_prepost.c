--- daemons/ipa-slapi-plugins/ipa-pwd-extop/prepost.c.orig	2026-07-01 19:49:00 UTC
+++ daemons/ipa-slapi-plugins/ipa-pwd-extop/prepost.c
@@ -37,6 +37,12 @@
  * All rights reserved.
  * END COPYRIGHT BLOCK **/
 
+#ifdef __FreeBSD__
+#ifndef _XOPEN_SOURCE
+#define _XOPEN_SOURCE 700
+#endif
+#endif
+
 #ifdef HAVE_CONFIG_H
 #  include <config.h>
 #endif
