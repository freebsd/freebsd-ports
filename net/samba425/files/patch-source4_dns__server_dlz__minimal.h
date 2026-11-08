--- source4/dns_server/dlz_minimal.h.orig	2026-01-20 15:42:54 UTC
+++ source4/dns_server/dlz_minimal.h
@@ -26,31 +26,25 @@
 #include <stdint.h>
 #include <stdbool.h>
 
-#if defined (BIND_VERSION_9_8)
-# error Bind 9.8 is not supported!
-#elif defined (BIND_VERSION_9_9)
-# error Bind 9.9 is not supported!
-#elif defined (BIND_VERSION_9_10)
-# define DLZ_DLOPEN_VERSION 3
-# define DNS_CLIENTINFO_VERSION 1
-# define ISC_BOOLEAN_AS_BOOL 0
-#elif defined (BIND_VERSION_9_11)
-# define DLZ_DLOPEN_VERSION 3
-# define DNS_CLIENTINFO_VERSION 2
-# define ISC_BOOLEAN_AS_BOOL 0
-#elif defined (BIND_VERSION_9_12)
-# define DLZ_DLOPEN_VERSION 3
-# define DNS_CLIENTINFO_VERSION 2
-# define ISC_BOOLEAN_AS_BOOL 0
-#elif defined (BIND_VERSION_9_14)
-# define DLZ_DLOPEN_VERSION 3
-# define DNS_CLIENTINFO_VERSION 2
-#elif defined (BIND_VERSION_9_16)
-# define DLZ_DLOPEN_VERSION 3
-# define DNS_CLIENTINFO_VERSION 2
-#elif defined (BIND_VERSION_9_18)
-# define DLZ_DLOPEN_VERSION 3
-# define DNS_CLIENTINFO_VERSION 2
+#if defined (BIND_VERSION)
+# if BIND_VERSION == 908
+#  error Bind 9.8 is not supported!
+# elif BIND_VERSION == 909
+#  error Bind 9.9 is not supported!
+# elif BIND_VERSION == 910
+#  define DLZ_DLOPEN_VERSION 3
+#  define DNS_CLIENTINFO_VERSION 1
+#  define ISC_BOOLEAN_AS_BOOL 0
+# elif BIND_VERSION == 911 || BIND_VERSION == 912
+#  define DLZ_DLOPEN_VERSION 3
+#  define DNS_CLIENTINFO_VERSION 2
+#  define ISC_BOOLEAN_AS_BOOL 0
+# elif BIND_VERSION >= 914
+#  define DLZ_DLOPEN_VERSION 3
+#  define DNS_CLIENTINFO_VERSION 2
+# else
+#  error Unsupported BIND version
+# endif
 #else
 # error Unsupported BIND version
 #endif
