--- ldap/libraries/liblber/lber-int.h.orig	2011-01-06 12:05:39 UTC
+++ ldap/libraries/liblber/lber-int.h
@@ -63,7 +63,7 @@ extern "C" {
 #ifdef macintosh
 # include "ldap-macos.h"
 #else /* macintosh */
-#if !defined(BSDI) && !defined(DARWIN) && !defined(FREEBSD)
+#if !defined(BSDI) && !defined(DARWIN) && !defined(FREEBSD) && !defined(DRAGONFLY)
 # include <malloc.h>
 #endif
 # include <errno.h>
