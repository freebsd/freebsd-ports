--- userauth_pubkey_from_pam.c.orig	2020-05-31 10:22:03 UTC
+++ userauth_pubkey_from_pam.c
@@ -31,6 +31,7 @@
 #include "config.h"
 
 #include <string.h>
+#include <sys/types.h>
 
 #include "defines.h"
 #include "key.h"
