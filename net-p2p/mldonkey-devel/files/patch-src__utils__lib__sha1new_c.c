--- src/utils/lib/sha1new_c.c.orig	Sun Nov 27 21:34:48 2005
+++ src/utils/lib/sha1new_c.c	Sun Nov 27 22:10:11 2005
@@ -152,6 +152,7 @@
 
 #if   defined( __alpha__ ) || defined( __alpha ) || defined( i386 )       || \
       defined( __i386__ )  || defined( _M_I86 )  || defined( _M_IX86 )    || \
+      defined(__amd64__)   || defined(__ia64__)  || \
       defined( __OS2__ )   || defined( sun386 )  || defined( __TURBOC__ ) || \
       defined( vax )       || defined( vms )     || defined( VMS )        || \
       defined( __VMS )
@@ -162,6 +163,7 @@
       defined( ibm370 )   || defined( mc68000 ) || defined( m68k )       || \
       defined( __MRC__ )  || defined( __MVS__ ) || defined( __MWERKS__ ) || \
       defined( sparc )    || defined( __sparc)  || defined( SYMANTEC_C ) || \
+      defined(__sparc64__) || \
       defined( __TANDEM ) || defined( THINK_C ) || defined( __VMCMS__ )
 #  define PLATFORM_BYTE_ORDER BRG_BIG_ENDIAN
 
