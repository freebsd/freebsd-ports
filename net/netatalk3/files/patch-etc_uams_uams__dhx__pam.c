--- etc/uams/uams_dhx_pam.c.orig	2023-11-22 15:18:15 UTC
+++ etc/uams/uams_dhx_pam.c
@@ -8,6 +8,7 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
+#include <sys/param.h>
 
 #if defined(USE_PAM) && defined(UAM_DHX)
 #include <stdio.h>
@@ -80,7 +80,7 @@ static char *PAM_password;
  * echo off means password.
  */
 static int PAM_conv (int num_msg,
-#ifdef LINUX
+#if defined(LINUX) || (defined(__FreeBSD_version) && __FreeBSD_version >= 1400000)
                      const struct pam_message **msg,
 #else
                      struct pam_message **msg,
