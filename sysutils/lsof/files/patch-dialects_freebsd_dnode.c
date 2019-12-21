--- dialects/freebsd/dnode.c.orig	2019-12-19 21:29:42 UTC
+++ dialects/freebsd/dnode.c
@@ -58,9 +58,7 @@ _PROTOTYPE(static int lkup_dev_tty,(dev_t *dr, INODETY
 
 
 #if	defined(HAS_TMPFS)
-#define	_KERNEL
 #include <fs/tmpfs/tmpfs.h>
-#undef	_KERNEL
 #endif	/* defined(HAS_TMPFS) */
 
 _PROTOTYPE(static void get_lock_state,(KA_T f));
