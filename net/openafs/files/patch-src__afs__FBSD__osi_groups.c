diff --git a/src/afs/FBSD/osi_groups.c b/src/afs/FBSD/osi_groups.c
index ef62478..e897f46 100644
--- a/src/afs/FBSD/osi_groups.c
+++ b/src/afs/FBSD/osi_groups.c
@@ -48,9 +48,17 @@ Afs_xsetgroups(struct thread *td, struct setgroups_args *uap)
     AFS_GUNLOCK();
     crfree(cr);
     if (code)
+#if (__FreeBSD_version >= 900044)
+	return sys_setgroups(td, uap);	/* afs has shut down */
+#else
 	return setgroups(td, uap);	/* afs has shut down */
+#endif
 
+#if (__FreeBSD_version >= 900044)
+    code = sys_setgroups(td, uap);
+#else
     code = setgroups(td, uap);
+#endif
     /* Note that if there is a pag already in the new groups we don't
      * overwrite it with the old pag.
      */
