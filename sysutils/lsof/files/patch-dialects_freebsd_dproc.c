--- dialects/freebsd/dproc.c.orig	2019-05-08 07:32:25 UTC
+++ dialects/freebsd/dproc.c
@@ -37,6 +37,14 @@ static char *rcsid = "$Id: dproc.c,v 1.20 2018/02/14 1
 
 #include "lsof.h"
 
+/*
+ * This is not an exact version but it should not matter. At worst there
+ * is a small version window where this lsof does not compile on older
+ * -CURRENT.
+ */
+#if __FreeBSD_version >= 1300081
+#define HAS_PWD
+#endif
 
 _PROTOTYPE(static void enter_vn_text,(KA_T va, int *n));
 _PROTOTYPE(static void get_kernel_access,(void));
@@ -132,6 +140,15 @@ gather_proc_info()
 	KA_T fa;
 #endif	/* defined(HAS_FDESCENTTBL) */
 
+#if	defined(HAS_PWD)
+	struct pwd pwd;
+	KA_T pwd_addr;
+#endif	/* defined(HAS_FDESCENTTBL) */
+
+	struct vnode *cdir;
+	struct vnode *rdir;
+	struct vnode *jdir;
+
 	static ofb_t *ofb = NULL;
 	static int ofbb = 0;
 	int pgid, pid;
@@ -312,6 +329,22 @@ gather_proc_info()
 		continue;
 #endif	/* defined(HAS_FDESCENTTBL) */
 
+#if	defined(HAS_PWD)
+	    cdir = rdir = jdir = NULL;
+	    pwd_addr = (KA_T)FILEDESC_KVM_LOAD_PWD(&fd);
+	    if (pwd_addr != 0) {
+		    if (!kread(pwd_addr, (char *)&pwd, sizeof(pwd))) {
+			    cdir = pwd.pwd_cdir;
+			    rdir = pwd.pwd_rdir;
+			    jdir = pwd.pwd_jdir;
+		    }
+	    }
+#else
+	    cdir = fd.fd_cdir;
+	    rdir = fd.fd_rdir;
+	    jdir = fd.fd_jdir;
+#endif
+
 	/*
 	 * Allocate a local process structure.
 	 */
@@ -347,20 +380,20 @@ gather_proc_info()
 	/*
 	 * Save current working directory information.
 	 */
-	    if (!ckscko && fd.fd_cdir) {
+	    if (!ckscko && cdir) {
 		alloc_lfile(CWD, -1);
 		Cfp = (struct file *)NULL;
-		process_node((KA_T)fd.fd_cdir);
+		process_node((KA_T)cdir);
 		if (Lf->sf)
 		    link_lfile();
 	    }
 	/*
 	 * Save root directory information.
 	 */
-	    if (!ckscko && fd.fd_rdir) {
+	    if (!ckscko && rdir) {
 		alloc_lfile(RTD, -1);
 		Cfp = (struct file *)NULL;
-		process_node((KA_T)fd.fd_rdir);
+		process_node((KA_T)rdir);
 		if (Lf->sf)
 		    link_lfile();
 	    }
@@ -369,10 +402,10 @@ gather_proc_info()
 	/*
 	 * Save jail directory information.
 	 */
-	    if (!ckscko && fd.fd_jdir) {
+	    if (!ckscko && jdir) {
 		alloc_lfile("jld", -1);
 		Cfp = (struct file *)NULL;
-		process_node((KA_T)fd.fd_jdir);
+		process_node((KA_T)jdir);
 		if (Lf->sf)
 		    link_lfile();
 	    }
@@ -655,7 +688,29 @@ kread(addr, buf, len)
 	return((br == len) ? 0 : 1);
 }
 
+static int
+vm_map_reader(void *token, vm_map_entry_t addr, vm_map_entry_t dest)
+{
+	return (kread((KA_T)addr, (char *)dest, sizeof(*dest)));
+}
 
+#if	__FreeBSD_version < 1300060
+typedef int vm_map_entry_reader(void *token, vm_map_entry_t addr,
+    vm_map_entry_t dest);
+
+static inline vm_map_entry_t
+vm_map_entry_read_succ(void *token, struct vm_map_entry *const clone,
+     vm_map_entry_reader reader)
+{
+	vm_map_entry_t next;
+
+	next = clone->next;
+	if (!reader(token, next, clone))
+		return (NULL);
+	return (next);
+}
+#endif	/*  __FreeBSD_version < 1300060 */
+
 /*
  * process_text() - process text information
  */
@@ -682,20 +737,15 @@ process_text(vm)
 /*
  * Read the vm_map structure.  Search its vm_map_entry structure list.
  */
+	vmme = vmsp.vm_map.header;
+	e = &vmme;
 	for (i = 0; i < vmsp.vm_map.nentries; i++) {
 
 	/*
 	 * Read the next vm_map_entry.
 	 */
-	    if (i == 0)
-		e = &vmsp.vm_map.header;
-	    else {
-		if (!(ka = (KA_T)e->next))
-		    return;
-		e = &vmme;
-		if (kread(ka, (char *)e, sizeof(vmme)))
-		    return;
-	    }
+	    if (!vm_map_entry_read_succ(NULL, e, vm_map_reader))
+		return;
 
 #if	defined(MAP_ENTRY_IS_A_MAP)
 	    if (e->eflags & (MAP_ENTRY_IS_A_MAP|MAP_ENTRY_IS_SUB_MAP))
