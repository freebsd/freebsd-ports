--- src/linc-protocols.c.orig	Sat Oct  7 21:41:04 2006
+++ src/linc-protocols.c	Sat Oct  7 21:41:18 2006
@@ -609,7 +609,7 @@
 /* FIXME: is IN6ADDR_ANY_INIT exported on Mac OS X ? */
 /* on Mac OS X 10.1 inaddr6_any isn't exported by libc */
 #ifndef in6addr_any
-	static const struct in6_addr in6addr_any = { { { 0 } } };
+	const struct in6_addr in6addr_any = { { { 0 } } };
 #endif
 
 static gboolean
