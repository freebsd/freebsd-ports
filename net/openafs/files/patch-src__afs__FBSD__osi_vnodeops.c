diff --git a/src/afs/FBSD/osi_vnodeops.c b/src/afs/FBSD/osi_vnodeops.c
index 01498fa..ac16df0 100644
--- a/src/afs/FBSD/osi_vnodeops.c
+++ b/src/afs/FBSD/osi_vnodeops.c
@@ -54,6 +54,9 @@
 #include <sys/malloc.h>
 #include <sys/namei.h>
 #include <sys/unistd.h>
+#if __FreeBSD_version >= 1000030
+#include <sys/rwlock.h>
+#endif
 #include <vm/vm_page.h>
 #include <vm/vm_object.h>
 #include <vm/vm_pager.h>
@@ -266,6 +269,14 @@ static __inline void ma_vm_page_unlock(vm_page_t m) {};
 #define	MA_PCPU_ADD(c, n) (c) += (n)
 #endif
 
+#if __FreeBSD_version >= 1000030
+#define AFS_VM_OBJECT_WLOCK(o)	VM_OBJECT_WLOCK(o)
+#define AFS_VM_OBJECT_WUNLOCK(o)	VM_OBJECT_WUNLOCK(o)
+#else
+#define AFS_VM_OBJECT_WLOCK(o)	VM_OBJECT_LOCK(o)
+#define AFS_VM_OBJECT_WUNLOCK(o)	VM_OBJECT_UNLOCK(o)
+#endif
+
 #ifdef AFS_FBSD70_ENV
 #ifndef AFS_FBSD80_ENV
 /* From kern_lock.c */
@@ -806,7 +817,7 @@ afs_vop_getpages(struct vop_getpages_args *ap)
     {
 	vm_page_t m = ap->a_m[ap->a_reqpage];
 
-	VM_OBJECT_LOCK(object);
+	AFS_VM_OBJECT_WLOCK(object);
 	ma_vm_page_lock_queues();
 	if (m->valid != 0) {
 	    /* handled by vm_fault now        */
@@ -819,11 +830,11 @@ afs_vop_getpages(struct vop_getpages_args *ap)
 		}
 	    }
 	    ma_vm_page_unlock_queues();
-	    VM_OBJECT_UNLOCK(object);
+	    AFS_VM_OBJECT_WUNLOCK(object);
 	    return (0);
 	}
 	ma_vm_page_unlock_queues();
-	VM_OBJECT_UNLOCK(object);
+	AFS_VM_OBJECT_WUNLOCK(object);
     }
     bp = getpbuf(&afs_pbuf_freecnt);
 
@@ -851,19 +862,19 @@ afs_vop_getpages(struct vop_getpages_args *ap)
     relpbuf(bp, &afs_pbuf_freecnt);
 
     if (code && (uio.uio_resid == ap->a_count)) {
-	VM_OBJECT_LOCK(object);
+	AFS_VM_OBJECT_WLOCK(object);
 	ma_vm_page_lock_queues();
 	for (i = 0; i < npages; ++i) {
 	    if (i != ap->a_reqpage)
 		vm_page_free(ap->a_m[i]);
 	}
 	ma_vm_page_unlock_queues();
-	VM_OBJECT_UNLOCK(object);
+	AFS_VM_OBJECT_WUNLOCK(object);
 	return VM_PAGER_ERROR;
     }
 
     size = ap->a_count - uio.uio_resid;
-    VM_OBJECT_LOCK(object);
+    AFS_VM_OBJECT_WLOCK(object);
     ma_vm_page_lock_queues();
     for (i = 0, toff = 0; i < npages; i++, toff = nextoff) {
 	vm_page_t m;
@@ -893,6 +904,9 @@ afs_vop_getpages(struct vop_getpages_args *ap)
 	}
 
 	if (i != ap->a_reqpage) {
+#if __FreeBSD_version >= 1000042
+	    vm_page_readahead_finish(m);
+#else
 	    /*
 	     * Whether or not to leave the page activated is up in
 	     * the air, but we should put the page on a page queue
@@ -926,10 +940,11 @@ afs_vop_getpages(struct vop_getpages_args *ap)
 		vm_page_free(m);
 		ma_vm_page_unlock(m);
 	    }
+#endif	/* __FreeBSD_version 1000042 */
 	}
     }
     ma_vm_page_unlock_queues();
-    VM_OBJECT_UNLOCK(object);
+    AFS_VM_OBJECT_WUNLOCK(object);
     return 0;
 }
 
@@ -1076,24 +1091,6 @@ afs_vop_poll(ap)
     return (1);
 }
 
-/*
- * Mmap a file
- *
- * NB Currently unsupported.
- */
-/* ARGSUSED */
-int
-afs_vop_mmap(ap)
-     struct vop_mmap_args	/* {
-				 * struct vnode *a_vp;
-				 * int  a_fflags;
-				 * struct ucred *a_cred;
-				 * struct thread *td;
-				 * } */ *ap;
-{
-    return (EINVAL);
-}
-
 int
 afs_vop_fsync(ap)
      struct vop_fsync_args	/* {
