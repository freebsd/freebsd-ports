--- dialects/freebsd/dnode.c.orig	2019-05-08 07:32:25 UTC
+++ dialects/freebsd/dnode.c
@@ -58,9 +58,7 @@ _PROTOTYPE(static int lkup_dev_tty,(dev_t *dr, INODETY
 
 
 #if	defined(HAS_TMPFS)
-#define	_KERNEL
 #include <fs/tmpfs/tmpfs.h>
-#undef	_KERNEL
 #endif	/* defined(HAS_TMPFS) */
 
 _PROTOTYPE(static void get_lock_state,(KA_T f));
@@ -562,7 +560,7 @@ process_overlaid_node:
  * Get the pseudo vnode tag type for FreeBSD >= 5.
  */
 	vtag = VT_UNKNOWN;
-	if (v->v_tag && !kread((KA_T)v->v_tag, (char *)&vtbuf, sizeof(vtbuf)))
+	if (!kread((KA_T)v->v_lock.lock_object.lo_name, (char *)&vtbuf, sizeof(vtbuf)))
 	{
 	    vtbuf[sizeof(vtbuf) - 1] = '\0';
 	    vtbp = vtbuf;
