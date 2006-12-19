--- libs/libmythupnp/upnpglobal.h~	Tue Jun  6 20:03:35 2006
+++ libs/libmythupnp/upnpglobal.h	Tue Nov 14 10:40:52 2006
@@ -15,9 +15,11 @@

 // __suseconds_t doesn't exist on some older Unixes. e.g. Darwin/Mac OS X

+#ifndef __FreeBSD__
 #ifndef __suseconds_t_defined
 #define __suseconds_t_defined
 typedef int32_t __suseconds_t;
+#endif
 #endif

 //////////////////////////////////////////////////////////////////////////////
