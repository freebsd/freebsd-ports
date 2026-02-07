--- usr/sbin/p11sak/p11sak.c.orig	2022-04-25 11:04:51 UTC
+++ usr/sbin/p11sak/p11sak.c
@@ -19,7 +19,7 @@
 #include "cfgparser.h"
 #include "configuration.h"
 #include <ctype.h>
-#include <linux/limits.h>
+#include <limits.h>
 
 #include <unistd.h>
 #include <sys/types.h>
@@ -81,7 +81,7 @@ static void load_pkcs11lib(void)
     const char *libname;
 
     /* check for environment variable PKCSLIB */
-    libname = secure_getenv("PKCSLIB");
+    libname = getenv("PKCSLIB");
     if (libname == NULL || strlen(libname) < 1)
         libname = default_pkcs11lib;
 
