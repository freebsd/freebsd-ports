--- fuse_module/fuse_vnops.c	Sat Jul 14 13:14:27 2007
+++ fuse_module/fuse_vnops.c	Sat Jul 14 13:14:27 2007
@@ -42,6 +42,10 @@
 #include "fuse_vnode.h"
 #include "fuse_io.h"
 
+#if USE_PRIVILEGE_API
+#include <sys/priv.h>
+#endif
+
 /* function prototype for iterators over filehandles (of a vp) */
 typedef int fuse_metrics_t(struct vnode *vp, struct thread *td,
                            struct ucred *cred, struct fuse_filehandle *fufh,
@@ -63,7 +67,9 @@ struct fuse_access_param {
 #define FACCESS_CHOWN      0x08 /* do permission check for owner changing */
 #define FACCESS_NOCHECKSPY 0x10 /* don't check if daemon is allowed to spy on
                                    user */
-#define FACCESS_XQUERIES FACCESS_STICKY | FACCESS_CHOWN
+#define FACCESS_SETGID     0x12 /* do permission check for setting setgid flag */
+
+#define FACCESS_XQUERIES FACCESS_STICKY | FACCESS_CHOWN | FACCESS_SETGID
 
 #define FVP_ACCESS_NOOP   0x01 /* vnode based control flag for doing access check */
 
@@ -855,6 +861,7 @@ fuse_access(ap)
 
 /*
  * Attribute caching hasn't yet been implemented.
+ * [... Update: it _has been_ implemented.]
  * However, within one function we don't wanna query attributes
  * several times. Now it's enough pull the attributes once, and throw
  * it into the following routine with various modes.
@@ -929,12 +936,16 @@ fuse_access_i(struct vnode *vp, mode_t m
 			    mode == VWRITE) {
 				if (cred->cr_uid != facp->xuid &&
 				    cred->cr_uid != VTOVA(vp)->va_uid)
-					    err = suser_cred(cred, SUSER_ALLOWJAIL);
+	    				err = priv_check_cred(cred,
+					                      PRIV_VFS_ADMIN,
+					                      0);
 			}
 			/*
 			 * We return here because this flags is exlusive
 			 * with the others
 			 */
+			KASSERT(facp->facc_flags == FACCESS_STICKY,
+			        ("sticky access check comes in mixed"));
 			return (err);
 		}
 
@@ -947,10 +958,21 @@ fuse_access_i(struct vnode *vp, mode_t m
 			    (cred->cr_gid != facp->xgid &&
 			         facp->xgid != (gid_t)VNOVAL &&
 			         ! groupmember(facp->xgid, cred)))
-				err = suser_cred(cred, SUSER_ALLOWJAIL);
-			return (err);
+				err = priv_check_cred(cred, PRIV_VFS_CHOWN, 0);
+			if (err)
+				return (err);
 		}
 
+		if (facp->facc_flags & FACCESS_SETGID) {
+			gid_t sgid = facp->xgid;
+
+			if (sgid == (gid_t)VNOVAL)
+				sgid = VTOVA(vp)->va_gid;
+
+			if (! groupmember(sgid, cred))
+				err = priv_check_cred(cred, PRIV_VFS_SETGID, 0);
+			return (err);
+		}
 
 	} else {
 #if FUSE_HAS_ACCESS
@@ -1234,7 +1256,13 @@ fuse_lookup(ap)
 		 */
 		if (nameiop == RENAME && wantparent && islastcn) {
 			DEBUG("something to rename...\n");
-			if ((err = fuse_access_i(dvp, VWRITE, cred, td, &facp)))
+
+			facp.xuid = fattr->uid;
+			facp.facc_flags |= FACCESS_STICKY;
+			err = fuse_access_i(dvp, VWRITE, cred, td, &facp);
+			facp.facc_flags &= ~FACCESS_XQUERIES;
+
+			if (err)
 				goto out;
 
 			/*
@@ -2948,8 +2976,14 @@ fuse_setattr(ap)
 	}
 
 	if (vap->va_mode != (mode_t)VNOVAL) {
+#if _DEBUG
 		if (vap->va_mode & S_IFMT)
-			DEBUG("fuse_setattr -- weird: format bits in mode field, 0%o\n", vap->va_mode);
+			DEBUG("fuse_setattr -- weird: "
+			      "format bits in mode field, 0%o\n",
+			      vap->va_mode);
+#endif
+		if (vap->va_mode & S_ISGID)
+			facp.facc_flags |= FACCESS_SETGID;
 		fsai->FUSEATTR(mode) = vap->va_mode & ALLPERMS;
 		fsai->valid |= FATTR_MODE;
 	}

