--- src/lib/howl/NotOSX/DNSServices.h.orig	Fri Jul  2 00:53:26 2004
+++ src/lib/howl/NotOSX/DNSServices.h	Fri Jul  2 00:56:58 2004
@@ -98,6 +98,10 @@
 #include	<stddef.h>
 #include <salt/salt.h>
 
+#ifdef HAVE_STDINT_H
+#include <stdint.h>
+#endif
+
 #ifdef	__cplusplus
 	extern "C" {
 #endif
@@ -224,7 +228,11 @@
 	@abstract	8-bit unsigned data type.
 */
 
+#ifdef HAVE_STDINT_H
+typedef uint8_t			DNSUInt8;
+#else
 typedef unsigned char		DNSUInt8;
+#endif
 
 dns_check_compile_time( sizeof( DNSUInt8 ) == 1 );
 
@@ -234,7 +242,11 @@
 	@abstract	16-bit unsigned data type.
 */
 
+#ifdef HAVE_STDINT_H
+typedef uint16_t		DNSUInt16;
+#else
 typedef unsigned short		DNSUInt16;
+#endif
 
 dns_check_compile_time( sizeof( DNSUInt16 ) == 2 );
 
@@ -244,7 +256,11 @@
 	@abstract	32-bit unsigned data type.
 */
 
+#ifdef HAVE_STDINT_H
+typedef uint32_t		DNSUInt32;
+#else
 typedef unsigned long		DNSUInt32;
+#endif
 
 dns_check_compile_time( sizeof( DNSUInt32 ) == 4 );
 
@@ -254,7 +270,11 @@
 	@abstract	32-bit signed data type.
 */
 
+#ifdef HAVE_STDINT_H
+typedef int32_t			DNSSInt32;
+#else
 typedef signed long		DNSSInt32;
+#endif
 
 dns_check_compile_time( sizeof( DNSSInt32 ) == 4 );
 
