--- libraries/liblunicode/ucstr.c.orig	Fri Apr 11 03:57:10 2003
+++ libraries/liblunicode/ucstr.c	Sat Jul  5 10:53:04 2003
@@ -15,6 +15,8 @@
 #include <ldap_utf8.h>
 #include <ldap_pvt_uc.h>
 
+#include "lber_pvt.h"
+
 #define	malloc(x)	ber_memalloc_x(x,ctx)
 #define	realloc(x,y)	ber_memrealloc_x(x,y,ctx)
 #define	free(x)		ber_memfree_x(x,ctx)
