--- src/translators/freedb_util.cpp.orig	Thu Dec  2 16:15:30 2004
+++ src/translators/freedb_util.cpp	Thu Dec  2 16:20:39 2004
@@ -60,6 +60,7 @@
 
 #elif defined(__FreeBSD__)
 
+#include <netinet/in.h>
 #include <sys/cdio.h>
 #define        CDROM_LBA       CD_LBA_FORMAT   /* first frame is 0 */
 #define        CD_MSF_OFFSET   150     /* MSF offset of first frame */
