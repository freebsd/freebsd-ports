--- agent/gpg-agent.c	Wed Dec  4 13:08:25 2002
+++ agent/gpg-agent.c.new	Wed Jan 29 19:34:14 2003
@@ -37,6 +37,9 @@
 # include <pth.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 #include <gcrypt.h>
 
 #define JNLIB_NEED_LOG_LOGV
