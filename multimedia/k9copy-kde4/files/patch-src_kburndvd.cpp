--- src/kburndvd.cpp.orig      Thu Jan  5 06:04:49 2006
+++ src/kburndvd.cpp   Thu Jan  5 06:05:18 2006
@@ -24,7 +24,11 @@
 #include <qdir.h>
 #include <kmessagebox.h>
 #include <kprocess.h>
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+       #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+       #include <inttypes.h>
+#endif
 #include <kfiledialog.h>

 kBurnDVD::kBurnDVD()
