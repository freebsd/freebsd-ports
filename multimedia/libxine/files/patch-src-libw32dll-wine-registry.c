--- src/libw32dll/wine/registry.c.orig
+++ src/libw32dll/wine/registry.c
@@ -7,6 +7,10 @@
 #include <pwd.h>
 #include <sys/types.h>
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 #include "winbase.h"
 #include "winreg.h"
 #include "winnt.h"
