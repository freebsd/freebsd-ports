--- icb/icb.h.orig	Fri Dec 15 01:33:57 2006
+++ icb/icb.h	Fri Dec 15 01:34:21 2006
@@ -129,15 +129,6 @@
 #endif
 
 
-/* include function prototypes if ANSI compiler */
-/* otherwise, include file that shows return type for each function */
-
-#if defined __STDC__ || defined __GNUC__
-#include "protos.h"
-#else
-#include "funcs.h"
-#endif
-
 #define MAX_HOSTLEN 256
 #define MAX_PASSLEN 256
 
@@ -182,6 +173,15 @@
        ColPERSFROMHILITE,
        ColTIMESTAMP
 } colorlist;
+
+/* include function prototypes if ANSI compiler */
+/* otherwise, include file that shows return type for each function */
+
+#if defined __STDC__ || defined __GNUC__
+#include "protos.h"
+#else
+#include "funcs.h"
+#endif
 
 
 /* Returns an ANSI color sequence for 'primary', or for
