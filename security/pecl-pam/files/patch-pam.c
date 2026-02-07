--- pam.c.orig	2021-06-08 06:30:45 UTC
+++ pam.c
@@ -25,7 +25,7 @@
 #include "ext/standard/info.h"
 #include "php_pam.h"
 #include <security/pam_appl.h>
-#include <security/_pam_macros.h>
+#include "_pam_macros.h"
 
 #if PHP_VERSION_ID < 80000
 #include "pam_legacy_arginfo.h"
