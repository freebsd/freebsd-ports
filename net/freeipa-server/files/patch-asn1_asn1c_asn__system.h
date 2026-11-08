--- asn1/asn1c/asn_system.h.orig	2025-01-15 09:52:47 UTC
+++ asn1/asn1c/asn_system.h
@@ -27,6 +27,8 @@
 
 #ifdef	HAVE_ALLOCA_H
 #include <alloca.h>	/* For alloca(3) */
+#elif defined(__FreeBSD__)
+#define alloca(size) __builtin_alloca(size)
 #endif
 
 #ifdef	_WIN32
