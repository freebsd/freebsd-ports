diff --git a/src/afs/FBSD/osi_vm.c b/src/afs/FBSD/osi_vm.c
index 5fd9703..65f5333 100644
--- a/src/afs/FBSD/osi_vm.c
+++ b/src/afs/FBSD/osi_vm.c
@@ -29,13 +29,15 @@
 #include "afs/afs_stats.h"	/* statistics */
 #include <vm/vm_object.h>
 #include <vm/vm_map.h>
-#include <limits.h>
-#include <float.h>
+#include <sys/limits.h>
+#if __FreeBSD_version >= 1000030
+#include <sys/rwlock.h>
+#endif
 
 /*
  * FreeBSD implementation notes:
  * Most of these operations require us to frob vm_objects.  Most
- * functions require that the object be locked (with VM_OBJECT_LOCK)
+ * functions require that the object be locked (with VM_OBJECT_*LOCK)
  * on entry and leave it locked on exit.  The locking protocol
  * requires that we access vp->v_object with the heavy vnode lock
  * held and the vnode interlock unlocked.
@@ -58,6 +60,14 @@
 #define islocked_vnode(v)	VOP_ISLOCKED((v), curthread)
 #endif
 
+#if __FreeBSD_version >= 1000030
+#define AFS_VM_OBJECT_WLOCK(o)	VM_OBJECT_WLOCK(o)
+#define AFS_VM_OBJECT_WUNLOCK(o)	VM_OBJECT_WUNLOCK(o)
+#else
+#define AFS_VM_OBJECT_WLOCK(o)	VM_OBJECT_LOCK(o)
+#define AFS_VM_OBJECT_WUNLOCK(o)	VM_OBJECT_UNLOCK(o)
+#endif
+
 /* Try to discard pages, in order to recycle a vcache entry.
  *
  * We also make some sanity checks:  ref count, open count, held locks.
@@ -155,9 +165,9 @@ osi_VM_StoreAllSegments(struct vcache *avc)
 	    if (!vget(vp, LK_EXCLUSIVE | LK_RETRY, curthread)) {
 		    obj = vp->v_object;
 		    if (obj != NULL) {
-			VM_OBJECT_LOCK(obj);
+			AFS_VM_OBJECT_WLOCK(obj);
 			vm_object_page_clean(obj, 0, 0, OBJPC_SYNC);
-			VM_OBJECT_UNLOCK(obj);
+			AFS_VM_OBJECT_WUNLOCK(obj);
 			anyio = 1;
 		    }
 		    vput(vp);
@@ -203,7 +213,7 @@ osi_VM_TryToSmush(struct vcache *avc, afs_ucred_t *acred, int sync)
 	lock_vnode(vp, LK_EXCLUSIVE);
 
     if (vp->v_bufobj.bo_object != NULL) {
-	VM_OBJECT_LOCK(vp->v_bufobj.bo_object);
+	AFS_VM_OBJECT_WLOCK(vp->v_bufobj.bo_object);
 	/*
 	 * Do we really want OBJPC_SYNC?  OBJPC_INVAL would be
 	 * faster, if invalidation is really what we are being
@@ -219,7 +229,7 @@ osi_VM_TryToSmush(struct vcache *avc, afs_ucred_t *acred, int sync)
 	 */
 
 	vm_object_page_clean(vp->v_bufobj.bo_object, 0, 0, OBJPC_SYNC);
-	VM_OBJECT_UNLOCK(vp->v_bufobj.bo_object);
+	AFS_VM_OBJECT_WUNLOCK(vp->v_bufobj.bo_object);
     }
 
     tries = 5;
@@ -249,9 +259,9 @@ osi_VM_FlushPages(struct vcache *avc, afs_ucred_t *credp)
     ASSERT_VOP_LOCKED(vp, __func__);
     obj = vp->v_object;
     if (obj != NULL) {
-	VM_OBJECT_LOCK(obj);
+	AFS_VM_OBJECT_WLOCK(obj);
 	vm_object_page_remove(obj, 0, 0, FALSE);
-	VM_OBJECT_UNLOCK(obj);
+	AFS_VM_OBJECT_WUNLOCK(obj);
     }
     osi_vinvalbuf(vp, 0, 0, 0);
 }
