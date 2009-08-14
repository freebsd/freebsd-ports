--- ./nslcd/cfg.c.orig	2009-08-02 22:32:27.000000000 +0000
+++ ./nslcd/cfg.c	2009-08-02 22:49:26.000000000 +0000
@@ -37,14 +37,13 @@
 #include <errno.h>
 #include <netdb.h>
 #include <sys/socket.h>
-#ifdef HAVE_GSSAPI_H
-#include <gssapi.h>
-#endif /* HAVE_GSSAPI_H */
-#ifdef HAVE_GSSAPI_GSSAPI_KRB5_H
+#if HAVE_GSSAPI_GSSAPI_H
 #include <gssapi/gssapi.h>
-#include <gssapi/gssapi_krb5.h>
-#endif /* HAVE_GSSAPI_GSSAPI_KRB5_H */
-#include <sys/types.h>
+#elif HAVE_GSSAPI_GSSAPI_GENERIC_H
+#include <gssapi/gssapi_generic.h>
+#elif HAVE_GSSAPI_H
+#include <gssapi.h>
+#endif
 #include <pwd.h>
 #include <grp.h>
 
