--- pmap_helper/pmap_helper.c.orig	2006-06-22 15:55:17.000000000 +0400
+++ pmap_helper/pmap_helper.c	2011-12-01 14:31:48.000000000 -0800
@@ -43,6 +43,7 @@ __RCSID("$Id: pmap_helper.c,v 1.11 2006/
 #include <sys/lock.h>
 #include <sys/vnode.h>
 #include <sys/malloc.h>
+#include <sys/sysproto.h>
 
 #include <vm/vm.h>
 #include <vm/pmap.h>
@@ -77,7 +78,6 @@ pmap_helper(struct proc *curp, struct pm
 	struct proc *p;
 	static struct vm_map *map;
 	struct vm_map_entry *entry;
-	pmap_t pmap;
 	int nmaps = 0;
 	int error;
 	struct pmh pmh;
@@ -91,17 +91,16 @@ pmap_helper(struct proc *curp, struct pm
 		return EINVAL;
 
 	p = pfind(pmh.pid); /* XXX Locks p! */
+	PROC_UNLOCK(p);	/* locked by pfind(9) */
+
 	if (p == NULL)
 		return ESRCH;
 
 	/* map points to description of MI virtual address space */
 	map = &p->p_vmspace->vm_map;
 
-       if (map != &curthread->td_proc->p_vmspace->vm_map)
-               vm_map_lock_read(map);
+	vm_map_lock_read(map);
  
-	/* pmap points to private physiscal map for whole process space */
-	pmap = vmspace_pmap(p->p_vmspace);
 	error = 0;
 
 	for (entry = map->header.next; entry != &map->header; 
@@ -129,7 +128,7 @@ pmap_helper(struct proc *curp, struct pm
 		addr = entry->start;
 		/* estimate number of phys. resident pages in map */
 		while (addr < entry->end) {
-			if (pmap_extract(pmap, addr))
+			if (pmap_extract(map->pmap, addr))
 				resident++;
 			addr += PAGE_SIZE;
 		}
@@ -149,10 +148,19 @@ pmap_helper(struct proc *curp, struct pm
 
 			if (lobj->type == OBJT_DEVICE) {
 			        struct cdevsw *csw;
-	
+#ifdef VV_ETERNALDEV
+				int ref;
+
+				csw = dev_refthread(lobj->handle, &ref);
+#else
 				csw = dev_refthread(lobj->handle);
+#endif	/* __FreeBSD_version */
 				copystr(csw->d_name, pmhm.fname, 254, &done);
+#ifdef VV_ETERNALDEV
+				dev_relthread(lobj->handle, ref);
+#else
 				dev_relthread(lobj->handle);
+#endif
 			} else if (lobj->type == OBJT_VNODE) {
 				char	*fullpath = "[vnode pager]", *freepath = NULL;
 
@@ -163,7 +171,9 @@ pmap_helper(struct proc *curp, struct pm
 					free(freepath, M_TEMP);
 			}
 		}
+		vm_map_unlock_read(map);
 		error = copyout(&pmhm, &pmh.maps[nmaps], sizeof pmh.maps[nmaps]);
+		vm_map_lock_read(map);
 		if (error)
 			break;
 		nmaps++;
@@ -171,10 +181,7 @@ pmap_helper(struct proc *curp, struct pm
 			break;
 	}
 
-        if (map != &curthread->td_proc->p_vmspace->vm_map)
-               vm_map_unlock_read(map);
-
-	PROC_UNLOCK(p);	/* locked by pfind(9) */
+	vm_map_unlock_read(map);
 
 	if (error == 0)
 		error = copyout(&nmaps, &uap->pmh->nmaps, sizeof uap->pmh->nmaps);
