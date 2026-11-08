--- daemons/ipa-otpd/oauth2.c.orig	2026-07-01 20:11:02 UTC
+++ daemons/ipa-otpd/oauth2.c
@@ -32,6 +32,7 @@
 #include <fcntl.h>
 #include <sys/random.h>
 #include <sys/uio.h>
+#include <sys/wait.h>
 
 #include "internal.h"
 
