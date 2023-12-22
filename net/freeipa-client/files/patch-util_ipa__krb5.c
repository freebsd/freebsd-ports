--- util/ipa_krb5.c.orig	2021-11-25 17:34:42 UTC
+++ util/ipa_krb5.c
@@ -25,6 +25,7 @@
 #include <errno.h>
 #include <lber.h>
 #include <errno.h>
+#include <sys/endian.h>
 
 #include <libintl.h>
 #define _(STRING) gettext(STRING)
