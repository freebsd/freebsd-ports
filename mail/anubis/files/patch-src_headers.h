--- src/headers.h.orig	2014-05-22 05:42:44 UTC
+++ src/headers.h
@@ -43,11 +43,11 @@
 #   define HAVE_PCRE
 #  endif /* HAVE_PCRE_H or HAVE_PCRE_PCRE_H */
 # endif	/* HAVE_LIBPCRE */
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
@@ -111,7 +111,7 @@
 
 #ifdef HAVE_PAM
 # include <security/pam_appl.h>
-# include <security/pam_misc.h>
+# include <security/openpam.h>
 #endif /* HAVE_PAM */
 
 #if defined(WITH_GSASL)
