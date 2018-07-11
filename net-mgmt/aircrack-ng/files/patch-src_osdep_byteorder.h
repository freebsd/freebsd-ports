--- src/aircrack-osdep/byteorder.h.orig
+++ src/aircrack-osdep/byteorder.h
@@ -189,7 +189,7 @@ typedef uint8_t u_int8_t;
 	 * Solaris
 	 * -------
 	 */
-#if defined(__SVR4) && defined(__sun__)
+#if defined(__sparc__) && defined(__SVR4) && defined(__sun__)
 #include <sys/byteorder.h>
 #include <sys/types.h>
 #include <unistd.h>
