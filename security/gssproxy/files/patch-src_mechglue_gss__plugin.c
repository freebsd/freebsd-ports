--- src/mechglue/gss_plugin.c.orig	2026-10-20 15:29:35 UTC
+++ src/mechglue/gss_plugin.c
@@ -2,6 +2,7 @@
 
 #include "gss_plugin.h"
 #include <signal.h>
+#include <unistd.h>
 #include <sys/auxv.h>
 #include <endian.h>
 #include <gssapi/gssapi_krb5.h>
@@ -81,7 +82,11 @@ static bool enabled(void)
     bool ret = GSS_ALWAYS_INTERPOSE;
 
     /* check if this is a "secure" client */
+#ifdef __FreeBSD__
+    auxval = issetugid() ? 1 : 0;
+#else
     auxval = getauxval(AT_SECURE);
+#endif
 
     /* in "secure" clients gp_getenv(0 always fails (it uses secure_getenv),
      * therefore for "secure" clients we check if we can access the per
