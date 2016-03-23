--- lib/notmuch.h.orig	2015-10-30 10:14:41 UTC
+++ lib/notmuch.h
@@ -60,7 +60,7 @@ NOTMUCH_BEGIN_DECLS
 #define LIBNOTMUCH_MICRO_VERSION	0
 
 #define NOTMUCH_DEPRECATED(major,minor) \
-    __attribute__ ((deprecated ("function deprecated as of libnotmuch " #major "." #minor)))
+    __attribute__ ((deprecated))
 #endif /* __DOXYGEN__ */
 
 /**
