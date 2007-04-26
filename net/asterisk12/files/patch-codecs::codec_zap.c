
$FreeBSD$

--- codecs/codec_zap.c
+++ codecs/codec_zap.c
@@ -39,7 +39,11 @@
 #include <sys/ioctl.h>
 #include <errno.h>
 #include <sys/mman.h>
+#if defined(__linux__)
 #include <linux/zaptel.h>
+#else
+#include <zaptel/zaptel.h>
+#endif
 
 #include "asterisk/lock.h"
 #include "asterisk/translate.h"
