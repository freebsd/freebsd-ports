--- a/tools/sys_cap.h
+++ b/tools/sys_cap.h
@@ -11,7 +11,9 @@
 #ifndef _XINELIBOUTPUT_SYS_CAP_H_
 #define _XINELIBOUTPUT_SYS_CAP_H_
 
-#include "../features.h"
+#ifdef HAVE_LIBCAP
+# include "../features.h"
+#endif
 
 #include <unistd.h>
 #include <sys/types.h>
