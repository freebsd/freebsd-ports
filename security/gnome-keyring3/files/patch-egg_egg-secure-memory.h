--- egg/egg-secure-memory.h.orig	Wed Sep 26 10:28:35 2012
+++ egg/egg-secure-memory.h	Sat Oct 27 14:46:28 2012
@@ -27,16 +27,16 @@
 #include <stdlib.h>
 
 /* -------------------------------------------------------------------
- * Low Level Secure Memory 
- * 
- * IMPORTANT: This is pure vanila standard C, no glib. We need this 
- * because certain consumers of this protocol need to be built 
+ * Low Level Secure Memory
+ *
+ * IMPORTANT: This is pure vanila standard C, no glib. We need this
+ * because certain consumers of this protocol need to be built
  * without linking in any special libraries. ie: the PKCS#11 module.
- * 
+ *
  * Thread locking
- * 
+ *
  * In order to use these functions in a module the following functions
- * must be defined somewhere, and provide appropriate locking for 
+ * must be defined somewhere, and provide appropriate locking for
  * secure memory between threads:
  */
 
@@ -66,12 +66,12 @@ typedef struct {
 
 extern egg_secure_glob EGG_SECURE_GLOBALS;
 
-/* 
+/*
  * Main functionality
- *  
+ *
  * Allocations return NULL on failure.
- */ 
- 
+ */
+
 #define EGG_SECURE_USE_FALLBACK     0x0001
 
 #define EGG_SECURE_DECLARE(tag) \
@@ -83,23 +83,28 @@ extern egg_secure_glob EGG_SECURE_GLOBALS;
 	} \
 	static inline void* egg_secure_strdup (const char *str) { \
 		return egg_secure_strdup_full (G_STRINGIFY (tag), str, EGG_SECURE_USE_FALLBACK); \
+	} \
+	static inline void* egg_secure_strndup (const char *str, size_t length) { \
+		return egg_secure_strndup_full (G_STRINGIFY (tag), str, length, EGG_SECURE_USE_FALLBACK); \
 	}
 
 void*  egg_secure_alloc_full   (const char *tag, size_t length, int options);
 
 void*  egg_secure_realloc_full (const char *tag, void *p, size_t length, int options);
 
-void   egg_secure_free         (void* p); 
+void   egg_secure_free         (void* p);
 
-void   egg_secure_free_full    (void* p, int fallback); 
+void   egg_secure_free_full    (void* p, int fallback);
 
 void   egg_secure_clear        (void *p, size_t length);
 
-int    egg_secure_check        (const void* p); 
+int    egg_secure_check        (const void* p);
 
 void   egg_secure_validate     (void);
 
 char*  egg_secure_strdup_full  (const char *tag, const char *str, int options);
+
+char*  egg_secure_strndup_full (const char *tag, const char *str, size_t length, int options);
 
 void   egg_secure_strclear     (char *str);
 
