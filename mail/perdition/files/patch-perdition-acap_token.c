--- perdition/acap_token.c.orig	2014-08-17 17:24:21.423379005 -0500
+++ perdition/acap_token.c	2014-08-17 17:14:48.823113805 -0500
@@ -5,6 +5,7 @@
 #include <vanessa_adt.h>
 #include <ctype.h>
 #include <limits.h>
+#include <stdint.h>
 
 struct acap_token_status {
 	enum acap_type type;
