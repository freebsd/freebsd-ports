Description: Use the FreeBSD endianness symbols.
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2009-11-26

--- a/storage.h
+++ b/storage.h
@@ -27,6 +27,42 @@
    htonll() and ntohll()
 */
 
+#ifdef __FreeBSD__
+
+#include <sys/endian.h>
+
+#if defined(_BYTE_ORDER) && defined(_LITTLE_ENDIAN) && defined(_BIG_ENDIAN)
+# if _BYTE_ORDER == _LITTLE_ENDIAN
+
+#define VPOPMAIL_HOST_LITTLE_ENDIAN
+
+# ifndef ntohll
+# define ntohll(_x_) __bswap64(_x_)
+# endif
+# ifndef htonll
+# define htonll(_x_) __bswap64(_x_)
+# endif
+
+# elif _BYTE_ORDER == _BIG_ENDIAN
+
+#define VPOPMAIL_HOST_BIG_ENDIAN
+
+# ifndef ntohll
+# define ntohll(_x_) _x_
+# endif
+# ifndef htonll
+# define htonll(_x_) _x_
+# endif
+
+# else
+#error A byte order must be selected
+# endif
+#else
+#error Could not find the _BYTE_ORDER, _LITTLE_ENDIAN, or _BIG_ENDIAN defs
+#endif
+
+#else
+
 #include <endian.h>
 #include <byteswap.h>
 
@@ -56,6 +92,8 @@
 # error A byte order must be selected
 #endif
 
+#endif
+
 /*
    Define htonll() and ntohll() if not already defined
 */
