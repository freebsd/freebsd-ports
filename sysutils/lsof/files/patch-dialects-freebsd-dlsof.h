--- dialects/freebsd/dlsof.h.orig	2020-11-10 19:00:21 UTC
+++ dialects/freebsd/dlsof.h
@@ -559,7 +559,7 @@ typedef	u_long		KA_T;
  * Global storage definitions (including their structure definitions)
  */
 
-struct file * Cfp;
+extern struct file * Cfp;
 
 # if	FREEBSDV>=2000
 extern kvm_t *Kd;
@@ -663,9 +663,15 @@ struct sfile {
  */
 
 struct	namecache {
+#   if  __FreeBSD_version < 1202000 || (__FreeBSD_version >= 1300000 && __FreeBSD_version < 1300105)
 	LIST_ENTRY(namecache) nc_hash;	/* hash chain */
 	LIST_ENTRY(namecache) nc_src;	/* source vnode list */
 	TAILQ_ENTRY(namecache) nc_dst;	/* destination vnode list */
+#   else
+	LIST_ENTRY(namecache) nc_src;	/* source vnode list */
+	TAILQ_ENTRY(namecache) nc_dst;	/* destination vnode list */
+	LIST_ENTRY(namecache) nc_hash;	/* hash chain */
+#   endif
 	struct	vnode *nc_dvp;		/* vnode of parent of name */
 	struct	vnode *nc_vp;		/* vnode the name refers to */
 	u_char	nc_flag;		/* flag bits */
