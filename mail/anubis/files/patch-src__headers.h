--- ./src/headers.h.orig	2008-12-16 11:21:54.000000000 -0500
+++ ./src/headers.h	2011-02-09 20:52:34.000000000 -0500
@@ -51,11 +51,11 @@
 # else
 #  error POSIX Regular Expressions are required!
 # endif	/* HAVE_REGEX_H and HAVE_REGCOMP */
-# if defined(HAVE_LIBPAM) && defined(HAVE_LIBPAM_MISC)
-#  if defined(HAVE_SECURITY_PAM_APPL_H) && defined(HAVE_SECURITY_PAM_MISC_H)
+# if defined(HAVE_LIBPAM)
+#  if defined(HAVE_SECURITY_PAM_APPL_H) && defined(HAVE_SECURITY_OPENPAM_H)
 #   define HAVE_PAM
-#  endif /* HAVE_SECURITY_PAM_APPL_H and HAVE_SECURITY_PAM_MISC_H */
-# endif	/* HAVE_LIBPAM and HAVE_LIBPAM_MISC */
+#  endif /* HAVE_SECURITY_PAM_APPL_H and HAVE_SECURITY_OPENPAM_H */
+# endif	/* HAVE_LIBPAM */
 # if defined(HAVE_LIBWRAP) && defined(HAVE_TCPD_H)
 #  define USE_LIBWRAP
 # endif	/* HAVE_LIBWRAP and HAVE_TCPD_H */
@@ -121,7 +121,7 @@
 
 #ifdef HAVE_PAM
 # include <security/pam_appl.h>
-# include <security/pam_misc.h>
+# include <security/openpam.h>
 #endif /* HAVE_PAM */
 
 #if defined(WITH_GSASL)
