--- etc/uams/uams_pam.c.orig	2023-11-22 15:00:28 UTC
+++ etc/uams/uams_pam.c
@@ -53,7 +53,7 @@ extern UAM_MODULE_EXPORT void append(struct papfile *,
  * echo off means password.
  */
 static int PAM_conv (int num_msg,
-#ifdef LINUX
+#if defined(LINUX) || (defined(FREEBSD) && __FreeBSD_version >= 1400000)
                      const struct pam_message **msg,
 #else
                      struct pam_message **msg,
