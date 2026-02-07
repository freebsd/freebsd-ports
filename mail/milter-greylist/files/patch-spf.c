--- spf.c.orig	2021-01-11 23:09:20 UTC
+++ spf.c
@@ -61,6 +61,7 @@ __RCSID("$Id: spf.c,v 1.40 2015/10/30 18:22:30 manu Ex
 
 #ifdef  __FreeBSD__
 #define HAVE_NS_TYPE
+#include <arpa/nameser.h>
 #endif
 
