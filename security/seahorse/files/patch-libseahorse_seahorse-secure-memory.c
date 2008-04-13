--- libseahorse/seahorse-secure-memory.c.orig	2008-04-12 12:09:58.000000000 -0400
+++ libseahorse/seahorse-secure-memory.c	2008-04-12 12:10:05.000000000 -0400
@@ -97,13 +97,31 @@
 void
 seahorse_secure_memory_init ()
 {
-    GMemVTable vtable;
-    
-    memset (&vtable, 0, sizeof (vtable));
-    vtable.malloc = switch_malloc;
-    vtable.realloc = switch_realloc;
-    vtable.free = switch_free;
-    vtable.calloc = switch_calloc;
-    g_mem_set_vtable (&vtable);
+    if (seahorse_try_gk_secure_memory() == TRUE) {
+        GMemVTable vtable;
+
+        memset (&vtable, 0, sizeof (vtable));
+        vtable.malloc = switch_malloc;
+        vtable.realloc = switch_realloc;
+        vtable.free = switch_free;
+        vtable.calloc = switch_calloc;
+        g_mem_set_vtable (&vtable);
+    } else {
+        g_warning ("Unable to allocate secure memory from gnome-keyring.\n");
+        g_warning ("Proceeding with insecure password memory instead.\n");
+    }
 }
 
+gboolean
+seahorse_try_gk_secure_memory ()
+{
+    gpointer p;
+
+    p = gnome_keyring_memory_try_alloc (10);
+    if (p != NULL) {
+        gnome_keyring_memory_free (p);
+        return TRUE;
+    }
+
+    return FALSE;
+}
