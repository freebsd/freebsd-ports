--- daemons/ipa-otpd/parse.c.orig	2026-07-01 20:11:02 UTC
+++ daemons/ipa-otpd/parse.c
@@ -26,7 +26,7 @@
 
 #define _GNU_SOURCE  /* for asprintf() */
 #include "internal.h"
-#include <asm-generic/errno-base.h>
+#include <errno.h>
 #include <ctype.h>
 #include <krb5/krb5.h>
 
