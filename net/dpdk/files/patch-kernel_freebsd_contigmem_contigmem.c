--- kernel/freebsd/contigmem/contigmem.c.orig	2020-01-03 12:22:51 UTC
+++ kernel/freebsd/contigmem/contigmem.c
@@ -297,19 +297,22 @@ contigmem_cdev_pager_fault(vm_object_t object, vm_ooff
 		VM_OBJECT_WLOCK(object);
 		vm_page_updatefake(page, paddr, memattr);
 	} else {
-		vm_page_t mret;
 		/*
 		 * Replace the passed in reqpage page with our own fake page and
 		 * free up the original page.
 		 */
 		page = vm_page_getfake(paddr, memattr);
 		VM_OBJECT_WLOCK(object);
-		mret = vm_page_replace(page, object, (*mres)->pindex);
+#if __FreeBSD__ >= 13
+		vm_page_replace(page, object, (*mres)->pindex, *mres);
+#else
+		vm_page_t mret = vm_page_replace(page, object, (*mres)->pindex);
 		KASSERT(mret == *mres,
 		    ("invalid page replacement, old=%p, ret=%p", *mres, mret));
 		vm_page_lock(mret);
 		vm_page_free(mret);
 		vm_page_unlock(mret);
+#endif
 		*mres = page;
 	}
 
