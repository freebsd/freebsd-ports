$FreeBSD$

--- src/authinfo_pam.c.orig	Sat Nov 10 05:52:17 2001
+++ src/authinfo_pam.c	Sat Nov 10 05:51:29 2001
@@ -15,7 +15,7 @@
 #include "authinfo_pam.h"
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+/* #include <security/pam_misc.h> */
 
 /*
  * pam authenticator.
