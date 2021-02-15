--- platform/memory/mozjemalloc/jemalloc.c.orig	2021-02-05 18:43:01 UTC
+++ platform/memory/mozjemalloc/jemalloc.c
@@ -5251,7 +5251,7 @@ malloc_init_hard(void)
 		 * Another thread initialized the allocator before this one
 		 * acquired init_lock.
 		 */
-#ifndef MOZ_MEMORY_WINDOWS
+#if !(defined(MOZ_MEMORY_WINDOWS) || defined(__FreeBSD__))
 		malloc_mutex_unlock(&init_lock);
 #endif
 		return (false);
@@ -6755,7 +6755,8 @@ jemalloc_darwin_init(void)
 #define is_malloc_(a) malloc_is_ ## a
 #define is_malloc(a) is_malloc_(a)
 
-#if !defined(MOZ_MEMORY_DARWIN) && (is_malloc(malloc_impl) == 1)
+#if !(defined(MOZ_MEMORY_DARWIN) || defined(MOZ_MEMORY_BSD)) && \
+	(is_malloc(malloc_impl) == 1)
 #  if defined(__GLIBC__) && !defined(__UCLIBC__)
 /*
  * glibc provides the RTLD_DEEPBIND flag for dlopen which can make it possible
