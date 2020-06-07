--- liblttng-ust/compat.h.orig	2016-11-29 01:46:24 UTC
+++ liblttng-ust/compat.h
@@ -73,9 +73,15 @@ void lttng_ust_getprocname(char *name)
 }
 
 /*
- * If pthread_set_name_np is available.
+ * If pthread_setname_np or pthread_set_name_np is available.
  */
-#ifdef HAVE_PTHREAD_SET_NAME_NP
+#ifdef HAVE_PTHREAD_SETNAME_NP
+static inline
+int lttng_pthread_setname_np(pthread_t thread, const char *name)
+{
+	return pthread_setname_np(thread, name);
+}
+#elif defined(HAVE_PTHREAD_SET_NAME_NP)
 static inline
 int lttng_pthread_setname_np(pthread_t thread, const char *name)
 {
