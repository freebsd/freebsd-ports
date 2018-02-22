--- include/czmq_prelude.h.orig	2017-12-31 14:43:10 UTC
+++ include/czmq_prelude.h
@@ -683,6 +683,9 @@ char *if_indextoname (unsigned int ifind
 #if defined (__UTYPE_OSX) && !defined (HAVE_UUID)
 #   define HAVE_UUID 1
 #endif
+#if defined (__UTYPE_FREEBSD) && !defined (HAVE_UUID)
+#   define HAVE_UUID 1
+#endif
 #if defined (HAVE_UUID)
 #   if defined (__UTYPE_FREEBSD) || defined (__UTYPE_NETBSD) || defined(__UTYPE_OPENBSD)
 #       include <uuid.h>
