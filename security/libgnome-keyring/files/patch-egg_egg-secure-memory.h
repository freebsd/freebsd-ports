--- egg/egg-secure-memory.h.orig	Wed Jun  8 10:00:06 2011
+++ egg/egg-secure-memory.h	Sat Oct 27 14:36:16 2012
@@ -40,46 +40,58 @@
  * secure memory between threads:
  */
 
-extern void   egg_memory_lock (void);
+typedef struct {
+	void       (* lock)        (void);
+	void       (* unlock)      (void);
+	void *     (* fallback)    (void *pointer,
+	                            size_t length);
+	void *        pool_data;
+	const char *  pool_version;
+} egg_secure_glob;
 
-extern void   egg_memory_unlock (void);
+#define EGG_SECURE_POOL_VER_STR             "1.0"
+#define EGG_SECURE_GLOBALS SECMEM_pool_data_v1_0
 
-/*
- * Allocation Fallbacks
- *
- * If we cannot allocate secure memory, then this function
- * (defined elsewhere) will be called which has a chance to
- * allocate other memory abort or do whatever.
- *
- * Same call semantics as realloc with regard to NULL and zeros
- */
-extern void*  egg_memory_fallback (void *p, size_t length);
+#define EGG_SECURE_DEFINE_GLOBALS(lock, unlock, fallback) \
+	egg_secure_glob EGG_SECURE_GLOBALS = { \
+		lock, unlock, fallback, NULL, EGG_SECURE_POOL_VER_STR };
 
-#define EGG_SECURE_GLIB_DEFINITIONS() \
+#define EGG_SECURE_DEFINE_GLIB_GLOBALS() \
 	static GStaticMutex memory_mutex = G_STATIC_MUTEX_INIT; \
-	void egg_memory_lock (void) \
+	static void egg_memory_lock (void) \
 		{ g_static_mutex_lock (&memory_mutex); } \
-	void egg_memory_unlock (void) \
+	static void egg_memory_unlock (void) \
 		{ g_static_mutex_unlock (&memory_mutex); } \
-	void* egg_memory_fallback (void *p, size_t sz) \
-		{ return g_realloc (p, sz); } \
+	EGG_SECURE_DEFINE_GLOBALS (egg_memory_lock, egg_memory_unlock, g_realloc);
 
+extern egg_secure_glob EGG_SECURE_GLOBALS;
+
 /*
  * Main functionality
  *
  * Allocations return NULL on failure.
  */
 
-#define GKR_SECURE_USE_FALLBACK     0x0001
+#define EGG_SECURE_USE_FALLBACK     0x0001
 
-void*  egg_secure_alloc        (size_t length);
+#define EGG_SECURE_DECLARE(tag) \
+	static inline void* egg_secure_alloc (size_t length) { \
+		return egg_secure_alloc_full (G_STRINGIFY (tag), length, EGG_SECURE_USE_FALLBACK); \
+	} \
+	static inline void* egg_secure_realloc (void *p, size_t length) { \
+		return egg_secure_realloc_full (G_STRINGIFY (tag), p, length, EGG_SECURE_USE_FALLBACK); \
+	} \
+	static inline void* egg_secure_strdup (const char *str) { \
+		return egg_secure_strdup_full (G_STRINGIFY (tag), str, EGG_SECURE_USE_FALLBACK); \
+	} \
+	static inline void* egg_secure_strndup (const char *str, size_t length) { \
+		return egg_secure_strndup_full (G_STRINGIFY (tag), str, length, EGG_SECURE_USE_FALLBACK); \
+	}
 
-void*  egg_secure_alloc_full   (size_t length, int flags);
+void*  egg_secure_alloc_full   (const char *tag, size_t length, int options);
 
-void*  egg_secure_realloc      (void *p, size_t length);
+void*  egg_secure_realloc_full (const char *tag, void *p, size_t length, int options);
 
-void*  egg_secure_realloc_full (void *p, size_t length, int fallback);
-
 void   egg_secure_free         (void* p);
 
 void   egg_secure_free_full    (void* p, int fallback);
@@ -90,12 +102,20 @@ int    egg_secure_check        (const void* p);
 
 void   egg_secure_validate     (void);
 
-void   egg_secure_dump_blocks  (void);
+char*  egg_secure_strdup_full  (const char *tag, const char *str, int options);
 
-char*  egg_secure_strdup       (const char *str);
+char*  egg_secure_strndup_full (const char *tag, const char *str, size_t length, int options);
 
 void   egg_secure_strclear     (char *str);
 
 void   egg_secure_strfree      (char *str);
+
+typedef struct {
+	const char *tag;
+	size_t request_length;
+	size_t block_length;
+} egg_secure_rec;
+
+egg_secure_rec *   egg_secure_records    (unsigned int *count);
 
 #endif /* EGG_SECURE_MEMORY_H */
