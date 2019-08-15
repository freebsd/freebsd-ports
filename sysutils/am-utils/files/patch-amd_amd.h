Index: amd/amd.h
===================================================================
--- amd/amd.h	(revision 350048)
+++ amd/amd.h	(revision 350049)
@@ -625,7 +625,7 @@
 extern void mapc_add_kv(mnt_map *, char *, char *);
 extern mnt_map *mapc_find(char *, char *, const char *, const char *);
 extern void mapc_free(opaque_t);
-extern int  mapc_keyiter(mnt_map *, key_fun, opaque_t);
+extern int  mapc_keyiter(mnt_map *, key_fun *, opaque_t);
 extern void mapc_reload(void);
 extern int  mapc_search(mnt_map *, char *, char **);
 extern void mapc_showtypes(char *buf, size_t l);
