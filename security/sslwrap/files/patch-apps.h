--- apps.h.orig	Wed Oct 15 22:28:24 2003
+++ apps.h	Wed Oct 15 22:28:45 2003
@@ -65,9 +65,9 @@
 #include "../e_os.h"
 #endif
 
-#include OPENSSL"buffer.h"
-#include OPENSSL"bio.h"
-#include OPENSSL"crypto.h"
+#include "%%OPENSSL%%/buffer.h"
+#include "%%OPENSSL%%/bio.h"
+#include "%%OPENSSL%%/crypto.h"
 /*#include "progs.h"*/
 
 #ifdef WIN16
