
$FreeBSD$

--- directory/c-sdk/ldap/libraries/liblber/lber-int.h	2001/11/21 14:24:09	1.1
+++ directory/c-sdk/ldap/libraries/liblber/lber-int.h	2001/11/21 14:24:31
@@ -48,7 +48,7 @@
 #ifdef macintosh
 # include "ldap-macos.h"
 #else /* macintosh */
-#if !defined(BSDI) && !defined(DARWIN)
+#if !defined(BSDI) && !defined(DARWIN) && !defined(FREEBSD)
 # include <malloc.h>
 #endif
 # include <errno.h>
