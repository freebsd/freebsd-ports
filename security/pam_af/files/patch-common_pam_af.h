--- common/pam_af.h.orig	2005-10-16 19:55:28.000000000 +0400
+++ common/pam_af.h	2008-08-03 12:00:10.000000000 +0400
@@ -37,7 +37,7 @@
 #define CFGDB "/etc/pam_af.conf"
 #define CFGDB_PERM (S_IRUSR | S_IWUSR)
 
-#ifdef _OPENPAM
+#if defined(OPENPAM) || defined(_OPENPAM)
 # define PAM_AF_LOG(...) \
 	PAM_LOG(__VA_ARGS__)
 # define PAM_AF_LOGERR(...) \
