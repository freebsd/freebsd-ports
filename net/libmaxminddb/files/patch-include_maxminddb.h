--- include/maxminddb.h.orig	2022-09-30 21:50:22 UTC
+++ include/maxminddb.h
@@ -5,18 +5,6 @@ extern "C" {
 #ifndef MAXMINDDB_H
 #define MAXMINDDB_H
 
-/* Request POSIX.1-2008. However, we want to remain compatible with
- * POSIX.1-2001 (since we have been historically and see no reason to drop
- * compatibility). By requesting POSIX.1-2008, we can conditionally use
- * features provided by that standard if the implementation provides it. We can
- * check for what the implementation provides by checking the _POSIX_VERSION
- * macro after including unistd.h. If a feature is in POSIX.1-2008 but not
- * POSIX.1-2001, check that macro before using the feature (or check for the
- * feature directly if possible). */
-#ifndef _POSIX_C_SOURCE
-#define _POSIX_C_SOURCE 200809L
-#endif
-
 #include "maxminddb_config.h"
 #include <stdarg.h>
 #include <stdbool.h>
