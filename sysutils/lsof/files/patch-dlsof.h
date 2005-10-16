--- dialects/freebsd/dlsof.h.orig	Mon Oct  3 06:22:52 2005
+++ dialects/freebsd/dlsof.h	Sun Oct 16 00:18:58 2005
@@ -306,6 +306,9 @@ struct vop_advlock_args { int dummy; };	
 #include <fs/devfs/devfs_int.h>
 #   endif	/* defined(SI_PRIV) */
 
+#if	FREEBSDV>=6000
+#include <sys/sx.h>       
+#endif	/* FREEBSDV>=6000 */
 #include <fs/devfs/devfs.h>
 #undef	_KERNEL
 #  endif	/* FREEBSDV>=5000 */
