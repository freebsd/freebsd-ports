--- kadmin/server/misc.c.orig	Sat Mar 11 14:23:28 2006
+++ kadmin/server/misc.c	Wed Apr  4 13:53:04 2007
@@ -171,3 +171,12 @@
 
     return kadm5_free_principal_ent(handle->lhandle, &princ);
 }
+
+#define MAXPRINCLEN 125
+
+void
+trunc_name(size_t *len, char **dots)
+{
+    *dots = *len > MAXPRINCLEN ? "..." : "";
+    *len = *len > MAXPRINCLEN ? MAXPRINCLEN : *len;
+}
