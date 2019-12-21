--- dialects/freebsd/dproc.c.orig	2019-05-08 07:32:25 UTC
+++ dialects/freebsd/dproc.c
@@ -655,7 +655,29 @@ kread(addr, buf, len)
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
@@ -682,20 +704,15 @@ process_text(vm)
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
