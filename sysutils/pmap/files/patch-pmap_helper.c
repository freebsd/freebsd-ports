--- pmap_helper/pmap_helper.c.orig	2006-06-22 15:55:17.000000000 +0400
+++ pmap_helper/pmap_helper.c	2008-01-16 04:00:46.000000000 +0300
@@ -43,6 +43,7 @@
 #include <sys/lock.h>
 #include <sys/vnode.h>
 #include <sys/malloc.h>
+#include <sys/sysproto.h>
 
 #include <vm/vm.h>
 #include <vm/pmap.h>
@@ -77,7 +78,6 @@
 	struct proc *p;
 	static struct vm_map *map;
 	struct vm_map_entry *entry;
-	pmap_t pmap;
 	int nmaps = 0;
 	int error;
 	struct pmh pmh;
@@ -91,17 +91,16 @@
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
@@ -129,7 +128,7 @@
 		addr = entry->start;
 		/* estimate number of phys. resident pages in map */
 		while (addr < entry->end) {
-			if (pmap_extract(pmap, addr))
+			if (pmap_extract(map->pmap, addr))
 				resident++;
 			addr += PAGE_SIZE;
 		}
@@ -163,7 +162,9 @@
 					free(freepath, M_TEMP);
 			}
 		}
+		vm_map_unlock_read(map);
 		error = copyout(&pmhm, &pmh.maps[nmaps], sizeof pmh.maps[nmaps]);
+		vm_map_lock_read(map);
 		if (error)
 			break;
 		nmaps++;
@@ -171,10 +172,7 @@
 			break;
 	}
 
-        if (map != &curthread->td_proc->p_vmspace->vm_map)
-               vm_map_unlock_read(map);
-
-	PROC_UNLOCK(p);	/* locked by pfind(9) */
+	vm_map_unlock_read(map);
 
 	if (error == 0)
 		error = copyout(&nmaps, &uap->pmh->nmaps, sizeof uap->pmh->nmaps);
