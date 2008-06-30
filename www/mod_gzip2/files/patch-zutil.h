--- /dev/null	2008-06-29 21:37:16.000000000 -0700
+++ zutil.h	2008-06-29 21:37:12.114407940 -0700
@@ -0,0 +1,65 @@
+/* zutil.h -- stripped version just containing  OS_CODE 
+ * Copyright (C) 1995-2005 Jean-loup Gailly.
+ * For conditions of distribution and use, see copyright notice in zlib.h
+ */
+
+/* WARNING: this file should *not* be used by applications. It is
+   part of the implementation of the compression library and is
+   subject to change. Applications should only use zlib.h.
+ */
+
+#ifndef ZUTIL_H
+#define ZUTIL_H
+
+#define ZLIB_INTERNAL
+#include "zlib.h"
+
+        /* target dependencies */
+
+#if defined(MSDOS) || (defined(WINDOWS) && !defined(WIN32))
+#  define OS_CODE  0x00
+#endif
+
+#ifdef AMIGA
+#  define OS_CODE  0x01
+#endif
+
+#if defined(VAXC) || defined(VMS)
+#  define OS_CODE  0x02
+#endif
+
+#if defined(ATARI) || defined(atarist)
+#  define OS_CODE  0x05
+#endif
+
+#ifdef OS2
+#  define OS_CODE  0x06
+#  ifdef M_I86
+     #include <malloc.h>
+#  endif
+#endif
+
+#if defined(MACOS) || defined(TARGET_OS_MAC)
+#  define OS_CODE  0x07
+#endif
+
+#ifdef TOPS20
+#  define OS_CODE  0x0a
+#endif
+
+#ifdef WIN32
+#  ifndef __CYGWIN__  /* Cygwin is Unix, not Win32 */
+#    define OS_CODE  0x0b
+#  endif
+#endif
+
+#ifdef __50SERIES /* Prime/PRIMOS */
+#  define OS_CODE  0x0f
+#endif
+
+        /* common defaults */
+
+#ifndef OS_CODE
+#  define OS_CODE  0x03  /* assume Unix */
+#endif
+#endif
