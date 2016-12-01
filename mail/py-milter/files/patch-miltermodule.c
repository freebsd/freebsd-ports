--- miltermodule.c.orig 2013-03-15 20:50:01 UTC
+++ miltermodule.c
@@ -285,7 +285,7 @@ $ python setup.py help
  * published.  Unfortunately I know of no good way to do this
  * other than with OS-specific tests.
  */
-#if defined(__FreeBSD_kernel__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__linux__)
 #define HAVE_IPV6_RFC2553
 #include <arpa/inet.h>
 #endif
