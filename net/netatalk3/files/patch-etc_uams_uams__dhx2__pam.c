--- etc/uams/uams_dhx2_pam.c.orig	2023-11-22 15:19:12 UTC
+++ etc/uams/uams_dhx2_pam.c
@@ -136,7 +136,7 @@ error:
  * echo off means password.
  */
 static int PAM_conv (int num_msg,
-#ifdef LINUX
+#if defined(LINUX) || (defined(FREEBSD) && __FreeBSD_version >= 1400000)
                      const struct pam_message **msg,
 #else
                      struct pam_message **msg,
