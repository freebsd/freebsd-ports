--- utils/cado-endian.h.orig	2021-09-16 01:25:08 UTC
+++ utils/cado-endian.h
@@ -27,20 +27,16 @@
 
 // pragma no prototypes
 
-#ifdef HAVE_GLIBC
-// GNU libc offers the helpful header <endian.h> which defines
-// __BYTE_ORDER
-# include <endian.h>
-# if (__BYTE_ORDER == __LITTLE_ENDIAN)
+# if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
 #  define CADO_LITTLE_ENDIAN
-# elif (__BYTE_ORDER == __BIG_ENDIAN)
+# elif (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
 #  define CADO_BIG_ENDIAN
-# elif (__BYTE_ORDER == __PDP_ENDIAN)
+# elif (__BYTE_ORDER__ == __PDP_ENDIAN)
 #  define CADO_PDP_ENDIAN
 # else
 #  error Unknown machine endianness detected.
 # endif
-# define CADO_BYTE_ORDER __BYTE_ORDER
+# define CADO_BYTE_ORDER __BYTE_ORDER__
 /* There is no serious reason to think that _BIG_ENDIAN or _LITTLE_ENDIAN
  * being defined actually means that the machine is big (resp, little)
  * endian. Systems may like to unconditionally define these as constants
@@ -54,25 +50,4 @@
 # define CADO_LITTLE_ENDIAN
 # define CADO_BYTE_ORDER 1234
  */
-#elif defined(__sparc) || defined(__sparc__) \
-   || defined(_POWER) || defined(__powerpc__) \
-   || defined(__ppc__) || defined(__hpux) \
-   || defined(_MIPSEB) || defined(_POWER) \
-   || defined(__AARCH64EB__) \
-   || defined(__s390__)
-# define CADO_BIG_ENDIAN
-# define CADO_BYTE_ORDER 4321
-#elif defined(__i386__) || defined(__alpha__) \
-   || defined(__ia64) || defined(__ia64__) \
-   || defined(_M_IX86) || defined(_M_IA64) \
-   || defined(_M_ALPHA) || defined(__amd64) \
-   || defined(__amd64__) || defined(_M_AMD64) \
-   || defined(__x86_64) || defined(__x86_64__) \
-   || defined(__AARCH64EL__) \
-   || defined(_M_X64)
-# define CADO_LITTLE_ENDIAN
-# define CADO_BYTE_ORDER 1234
-#else
-# error The file cado-endian.h needs to be set up for your CPU type.
-#endif
 #endif
