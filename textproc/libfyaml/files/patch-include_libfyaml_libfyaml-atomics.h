https://github.com/pantoniou/libfyaml/commit/1026d76850909dc9b1c5f95b8cd94e865a313fd5

--- include/libfyaml/libfyaml-atomics.h.orig	2026-03-15 13:48:50 UTC
+++ include/libfyaml/libfyaml-atomics.h
@@ -78,7 +78,7 @@ extern "C" {
 #if !defined(FY_HAVE_C11_ATOMICS)
 #undef FY_HAVE_STDATOMIC_H
 
-#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
+#if defined(__GNUC__) && !defined(__STRICT_ANSI__) && !defined(__cplusplus)
 #define FY_HAVE_C11_ATOMICS
 #elif defined(__clang__) && defined(__has_extension)
 #if __has_extension(c_atomic)
@@ -123,7 +123,7 @@ typedef bool atomic_flag;
 
 #define atomic_store(_ptr, _val) \
 	do { \
-		*(_obj) = (_val); \
+		*(_ptr) = (_val); \
 	} while(0)
 
 #define atomic_exchange(_ptr, _v) \
@@ -152,6 +152,7 @@ typedef bool atomic_flag;
 
 #define atomic_fetch_add(_ptr, _v) \
 	({ \
+		__typeof__(_ptr) __ptr = (_ptr); \
 		__typeof__(*(_ptr)) __old = *__ptr; \
 		*__ptr += (_v); \
 		__old; \
@@ -159,6 +160,7 @@ typedef bool atomic_flag;
 
 #define atomic_fetch_sub(_ptr, _v) \
 	({ \
+		__typeof__(_ptr) __ptr = (_ptr); \
 		__typeof__(*(_ptr)) __old = *__ptr; \
 		*__ptr -= (_v); \
 		__old; \
@@ -166,6 +168,7 @@ typedef bool atomic_flag;
 
 #define atomic_fetch_or(_ptr, _v) \
 	({ \
+		__typeof__(_ptr) __ptr = (_ptr); \
 		__typeof__(*(_ptr)) __old = *__ptr; \
 		*__ptr |= (_v); \
 		__old; \
@@ -173,6 +176,7 @@ typedef bool atomic_flag;
 
 #define atomic_fetch_xor(_ptr, _v) \
 	({ \
+		__typeof__(_ptr) __ptr = (_ptr); \
 		__typeof__(*(_ptr)) __old = *__ptr; \
 		*__ptr ^= (_v); \
 		__old; \
@@ -180,6 +184,7 @@ typedef bool atomic_flag;
 
 #define atomic_fetch_and(_ptr, _v) \
 	({ \
+		__typeof__(_ptr) __ptr = (_ptr); \
 		__typeof__(*(_ptr)) __old = *__ptr; \
 		*__ptr &= (_v); \
 		__old; \
@@ -199,13 +204,14 @@ typedef bool atomic_flag;
 #define atomic_flag_test_and_set(_ptr) \
 	({ \
 		volatile atomic_flag *__ptr = (_ptr); \
+		bool __ret; \
 		if (!*__ptr) { \
 			*__ptr = true; \
 			__ret = true; \
 		} else \
 			__ret = false; \
 		__ret; \
-	}
+	})
 
 #endif
 
