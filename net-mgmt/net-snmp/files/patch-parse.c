--- snmplib/parse.c.orig	Tue Jan 25 10:04:35 2005
+++ snmplib/parse.c	Tue Jan 25 10:05:02 2005
@@ -106,6 +106,9 @@
 #if defined(HAVE_REGEX_H) && defined(HAVE_REGCOMP)
 #include <regex.h>
 #endif
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
