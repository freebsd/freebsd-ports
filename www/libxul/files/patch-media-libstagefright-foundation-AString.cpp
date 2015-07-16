--- media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp~
+++ media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp
@@ -23,6 +23,13 @@
 #include "ADebug.h"
 #include "AString.h"
 
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 900506
+#  undef tolower
+# endif
+#endif
+
 namespace stagefright {
 
 // static
