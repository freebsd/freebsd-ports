--- library/gnome-keyring-memory.c.orig	Sat Mar 31 14:59:37 2012
+++ library/gnome-keyring-memory.c	Sat Oct 27 14:36:16 2012
@@ -62,19 +62,19 @@ static GStaticMutex memory_mutex = G_STATIC_MUTEX_INIT
  * locking for memory between threads
  */
 
-void
+static void
 egg_memory_lock (void)
 {
 	g_static_mutex_lock (&memory_mutex);
 }
 
-void
+static void
 egg_memory_unlock (void)
 {
 	g_static_mutex_unlock (&memory_mutex);
 }
 
-void*
+static void *
 egg_memory_fallback (void *p, size_t sz)
 {
 	const gchar *env;
@@ -107,6 +107,10 @@ egg_memory_fallback (void *p, size_t sz)
 	return g_realloc (p, sz);
 }
 
+EGG_SECURE_DEFINE_GLOBALS (egg_memory_lock, egg_memory_unlock, egg_memory_fallback);
+
+EGG_SECURE_DECLARE (libgnome_keyring_memory);
+
 /* -----------------------------------------------------------------------------
  * PUBLIC FUNCTIONS
  */
@@ -129,7 +133,7 @@ gnome_keyring_memory_alloc (gulong sz)
 	gpointer p;
 
 	/* Try to allocate secure memory */
-	p = egg_secure_alloc_full (sz, GKR_SECURE_USE_FALLBACK);
+	p = egg_secure_alloc (sz);
 
 	/* Our fallback will always allocate */
 	g_assert (p);
@@ -151,7 +155,7 @@ gnome_keyring_memory_alloc (gulong sz)
 gpointer
 gnome_keyring_memory_try_alloc (gulong sz)
 {
-	return egg_secure_alloc_full (sz, 0);
+	return egg_secure_alloc_full ("libgnome_keyring_memory", sz, 0);
 }
 
 /**
@@ -187,7 +191,7 @@ gnome_keyring_memory_realloc (gpointer p, gulong sz)
 	}
 
 	/* First try and ask secure memory to reallocate */
-	n = egg_secure_realloc_full (p, sz, GKR_SECURE_USE_FALLBACK);
+	n = egg_secure_realloc (p, sz);
 
 	g_assert (n);
 
@@ -226,7 +230,7 @@ gnome_keyring_memory_try_realloc (gpointer p, gulong s
 	}
 
 	/* First try and ask secure memory to reallocate */
-	n = egg_secure_realloc_full (p, sz, 0);
+	n = egg_secure_realloc_full ("libgnome_keyring_memory", p, sz, 0);
 
 	g_assert (n);
 
@@ -247,7 +251,7 @@ gnome_keyring_memory_free (gpointer p)
 {
 	if (!p)
 		return;
-	egg_secure_free_full (p, GKR_SECURE_USE_FALLBACK);
+	egg_secure_free (p);
 }
 
 /**
