--- screen.h.orig	2003-08-22 05:28:43.000000000 -0700
+++ screen.h	2011-11-07 11:53:41.739890820 -0800
@@ -22,6 +22,8 @@
  * $Id: screen.h,v 1.12 1994/05/31 12:32:54 mlschroe Exp $ FAU
  */
 
+#include <string.h>
+
 #include "os.h"
 
 #if defined(__STDC__)
@@ -202,7 +204,7 @@
 	  char preselect[20];
 	  int esc;		/* his new escape character unless -1 */
 	  int meta_esc;		/* his new meta esc character unless -1 */
-	  char envterm[20 + 1];	/* terminal type */
+	  char envterm[63 + 1];	/* terminal type */
 	  int encoding;		/* encoding of display */
 	}
       attach;
