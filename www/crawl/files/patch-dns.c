$FreeBSD$

--- dns.c.orig	Fri Mar 12 07:29:07 2004
+++ dns.c	Fri Mar 12 07:29:19 2004
@@ -46,6 +46,7 @@
 #include "tree.h"
 #include "http.h"
 #include "dns.h"
+#include "getaddrinfo.h"
 
 ssize_t atomicio(ssize_t (*f)(), int, void *, size_t);
 
