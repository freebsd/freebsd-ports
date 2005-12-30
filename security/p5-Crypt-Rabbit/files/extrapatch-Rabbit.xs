--- Rabbit.xs.orig	Sat Dec 31 03:49:51 2005
+++ Rabbit.xs	Sat Dec 31 03:50:13 2005
@@ -4,6 +4,15 @@
 #include "ppport.h"
 #include "_rabbit.c"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 typedef struct rabbit {
     t_instance state;
 }* Crypt__Rabbit;
