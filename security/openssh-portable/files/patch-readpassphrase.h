--- openbsd-compat/readpassphrase.h.orig	Sun Jan 27 19:18:10 2002
+++ openbsd-compat/readpassphrase.h	Sun Jan 27 19:18:54 2002
@@ -28,6 +28,6 @@
  */
 
-#ifndef _READPASSPHRASE_H_
-#define _READPASSPHRASE_H_
+#ifndef READPASSPHRASE_H_
+#define READPASSPHRASE_H_
 
 #include "includes.h"
@@ -43,6 +43,7 @@
 
 char *readpassphrase(const char *, char *, size_t, int);
-
+#else /* HAVE_READPASSPHRASE */
+#include <readpassphrase.h>
 #endif /* HAVE_READPASSPHRASE */
 
-#endif /* !_READPASSPHRASE_H_ */
+#endif /* !READPASSPHRASE_H_ */


