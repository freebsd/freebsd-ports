--- libmpdvdkit2/bswap.h.orig	Thu Mar 10 23:40:06 2005
+++ libmpdvdkit2/bswap.h	Mon May  9 12:31:34 2005
@@ -24,6 +24,10 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
  */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(WORDS_BIGENDIAN)
 /* All bigendian systems are fine, just ignore the swaps. */  
 #define B2N_16(x) (void)(x)
@@ -37,6 +41,12 @@
 #define B2N_16(x) x = bswap_16(x)
 #define B2N_32(x) x = bswap_32(x)
 #define B2N_64(x) x = bswap_64(x)
+
+#elif (defined(__FreeBSD__) && __FreeBSD_version >= 500000)
+#include <sys/endian.h>
+#define B2N_16(x) be16toh(x)
+#define B2N_32(x) be32toh(x)
+#define B2N_64(x) be64toh(x)
 
 #elif defined(__NetBSD__)
 #include <sys/endian.h>
