--- ./ldapaddressbook/libldapsearch.c.orig	Sat Feb 18 16:36:06 2006
+++ ./ldapaddressbook/libldapsearch.c	Sat Feb 18 16:36:18 2006
@@ -8,6 +8,7 @@
 #include "libldapsearch.h"
 #include <stdlib.h>
 #include <errno.h>
+#include <sys/time.h>
 
 /*
 ** Allocate and deallocate the ldapsearch struct.
