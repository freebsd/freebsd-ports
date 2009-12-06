--- helpers/negotiate_auth/squid_kerb_auth/squid_kerb_auth.c.orig	Mon Jul 16 21:10:10 2007
+++ helpers/negotiate_auth/squid_kerb_auth/squid_kerb_auth.c	Mon Jul 16 21:10:35 2007
@@ -31,6 +31,7 @@
 #include <unistd.h>
 #include <time.h>
 #include <sys/time.h>
+#include <sys/param.h>
 
 #include "base64.h"
 #ifndef HAVE_SPNEGO
