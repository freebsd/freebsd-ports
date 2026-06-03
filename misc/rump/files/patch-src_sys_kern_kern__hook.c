--- src/sys/kern/kern_hook.c.orig	2025-09-09 03:38:01 UTC
+++ src/sys/kern/kern_hook.c
@@ -102,7 +102,7 @@ hook_proc_run(hook_list_t *list, struct proc *p)
 	struct hook_desc *hd;
 
 	LIST_FOREACH(hd, list, hk_list)
-		((void (*)(struct proc *, void *))*hd->hk_fn)(p, hd->hk_arg);
+		((void (*)(struct proc *, void *))(void *)*hd->hk_fn)(p, hd->hk_arg);
 }
 
 /*
@@ -168,7 +168,7 @@ mountroothook_establish(void (*fn)(device_t), device_t
 void *
 mountroothook_establish(void (*fn)(device_t), device_t dev)
 {
-	return hook_establish(&mountroothook_list, (void (*)(void *))fn, dev);
+	return hook_establish(&mountroothook_list, (void (*)(void *))(void *)fn, dev);
 }
 
 void
@@ -201,7 +201,7 @@ exechook_establish(void (*fn)(struct proc *, void *), 
 void *
 exechook_establish(void (*fn)(struct proc *, void *), void *arg)
 {
-	return hook_establish(&exechook_list, (void (*)(void *))fn, arg);
+	return hook_establish(&exechook_list, (void (*)(void *))(void *)fn, arg);
 }
 
 void
@@ -228,7 +228,7 @@ exithook_establish(void (*fn)(struct proc *, void *), 
 	void *rv;
 
 	rw_enter(&exec_lock, RW_WRITER);
-	rv = hook_establish(&exithook_list, (void (*)(void *))fn, arg);
+	rv = hook_establish(&exithook_list, (void (*)(void *))(void *)fn, arg);
 	rw_exit(&exec_lock);
 	return rv;
 }
@@ -256,7 +256,7 @@ forkhook_establish(void (*fn)(struct proc *, struct pr
 void *
 forkhook_establish(void (*fn)(struct proc *, struct proc *))
 {
-	return hook_establish(&forkhook_list, (void (*)(void *))fn, NULL);
+	return hook_establish(&forkhook_list, (void (*)(void *))(void *)fn, NULL);
 }
 
 void
@@ -274,7 +274,7 @@ doforkhooks(struct proc *p2, struct proc *p1)
 	struct hook_desc *hd;
 
 	LIST_FOREACH(hd, &forkhook_list, hk_list) {
-		((void (*)(struct proc *, struct proc *))*hd->hk_fn)
+		((void (*)(struct proc *, struct proc *))(void *)*hd->hk_fn)
 		    (p2, p1);
 	}
 }
