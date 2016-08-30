--- src/global.h.orig	2001-02-14 20:54:50 UTC
+++ src/global.h
@@ -20,6 +20,7 @@
  * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
+#include <errno.h>
 #include "sysdef.h"
 #include "utils.h"
 
@@ -208,7 +209,7 @@ extern char mname[];
 extern char nname[];
 
 extern VOIDSTAR parse_hash;
-extern double __plinf, __neinf, __nan;
+extern double __plinf, __neinf, ___nan;
 
 /* These have two uses.  During parsing, these contain the 
  * base address of all relative references.  During evaluation,
@@ -231,7 +232,6 @@ extern int default_lock;
 
 extern unsigned short current_cycle;
 extern int ioerror;
-extern int errno;
 extern const char oleo_version_string[];
 
 extern double astof (char **);
