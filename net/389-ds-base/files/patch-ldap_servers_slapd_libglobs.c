--- ldap/servers/slapd/libglobs.c.orig	2026-06-28 10:40:56 UTC
+++ ldap/servers/slapd/libglobs.c
@@ -10299,6 +10299,9 @@ config_get_malloc_mmap_threshold()
     return retVal;
 }
 
+#endif /* __GLIBC__ */
+#endif /* LINUX */
+
 static struct {
     const char *name;
     fgot_id_t id;
@@ -10461,9 +10464,6 @@ config_is_control_criticality_ignored(const char *oid)
     return res;
 }
 
-
-#endif
-#endif
 
 char *
 slapi_err2string(int result)
