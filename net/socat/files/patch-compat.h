--- compat.h.orig	2021-01-03 18:23:22 UTC
+++ compat.h
@@ -134,6 +134,8 @@ typedef int sig_atomic_t;
 #    define F_uint64_t "%u"
 #  elif HAVE_BASIC_UINT64_T==6
 #    define F_uint64_t "%lu"
+#  elif HAVE_BASIC_UINT64_T==8
+#    define F_uint64_t "%llu"
 #  else
 #    error "HAVE_BASIC_UINT64_T is out of range:" HAVE_BASIC_UINT64_T
 #  endif
@@ -147,7 +149,7 @@ typedef int sig_atomic_t;
 #  elif HAVE_BASIC_INT16_T==3
 #    define F_int16_t "%d"
 #  elif HAVE_BASIC_INT16_T==5
-#    define F_int16_t "%l"
+#    define F_int16_t "%ld"
 #  else
 #    error "HAVE_BASIC_INT16_T is out of range:" HAVE_BASIC_INT16_T
 #  endif
@@ -161,7 +163,7 @@ typedef int sig_atomic_t;
 #  elif HAVE_BASIC_INT32_T==3
 #    define F_int32_t "%d"
 #  elif HAVE_BASIC_INT32_T==5
-#    define F_int32_t "%l"
+#    define F_int32_t "%ld"
 #  else
 #    error "HAVE_BASIC_INT32_T is out of range:" HAVE_BASIC_INT32_T
 #  endif
@@ -175,7 +177,9 @@ typedef int sig_atomic_t;
 #  elif HAVE_BASIC_INT64_T==3
 #    define F_int64_t "%d"
 #  elif HAVE_BASIC_INT64_T==5
-#    define F_int64_t "%l"
+#    define F_int64_t "%ld"
+#  elif HAVE_BASIC_INT64_T==7
+#    define F_int64_t "%lld"
 #  else
 #    error "HAVE_BASIC_INT64_T is out of range:" HAVE_BASIC_INT64_T
 #  endif
