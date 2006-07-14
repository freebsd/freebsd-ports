--- misc/os_spec.c.orig	Fri Jul 14 08:46:10 2006
+++ misc/os_spec.c	Fri Jul 14 08:46:38 2006
@@ -1275,7 +1275,7 @@
 	return( sysCaps );
 	}
 
-#elif defined( __GNUC__ ) && defined( __i386__ )
+#elif defined( __GNUC__ ) && defined( __i386__ ) && !defined(__FreeBSD__)
 
 #if SYSCAP_FLAG_RDTSC != 0x01
   #error Need to sync SYSCAP_FLAG_RDTSC with equivalent asm definition
