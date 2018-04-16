--- pam_pwdfile.c.orig	2018-04-13 14:25:49.414568000 +0300
+++ pam_pwdfile.c	2018-04-13 14:42:33.040919000 +0300
@@ -38,18 +38,7 @@
  * OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#ifdef USE_CRYPT_R
-#define _GNU_SOURCE
-#include <crypt.h>
-#else
-#ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE 700
-#endif
-#ifndef _BSD_SOURCE
-#define _BSD_SOURCE
-#endif
-#endif
-
+#include <stdint.h>
 #include <syslog.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -66,7 +55,9 @@
 
 #define PAM_SM_AUTH
 #include <security/pam_modules.h>
-#include <security/pam_ext.h>
+/* #include <security/pam_ext.h> */
+
+#define pam_syslog(H, C, ...)	syslog(C, __VA_ARGS__)
 
 #include "md5.h"
 #include "bigcrypt.h"
