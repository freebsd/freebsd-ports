--- libk9copy/k9ifo.cpp.orig  Sun Dec 18 23:40:34 2005
+++ libk9copy/k9ifo.cpp       Sun Dec 18 23:40:52 2005
@@ -21,6 +21,9 @@
 #include <dvdread/dvd_reader.h>
 #include <dvdread/ifo_read.h>
 #include <dvdread/ifo_print.h>
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 #include "bswap.h"

 #ifndef DVD_BLOCK_LEN
