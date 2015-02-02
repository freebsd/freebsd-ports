--- texk/xdvik/dvisel.c.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/dvisel.c	2015-01-31 21:02:18.000000000 +0900
@@ -28,6 +28,7 @@
 #include <string.h>
 #include <ctype.h>
 
+#include "xdvi-config.h"
 #include "dvi.h"
 #include "pagesel.h"
 #include "dvisel.h"
@@ -510,6 +511,12 @@
 	    n += 4;
 	    /* fall through */
 	    
+	case SET4:
+	case PUT4: 
+	    if (!resource.omega) {
+		dvi_fmt_error("%s:%d: WriteDVI: op-code %d only works with the \"-omega\" option",
+			      __FILE__, __LINE__, c);
+	    }
 	case RIGHT4:
 	case W4:
 	case X4:
@@ -519,6 +526,12 @@
 	    n++;
 	    /* fall through */
 
+	case SET3:
+	case PUT3: 
+	    if (!resource.omega) {
+		dvi_fmt_error("%s:%d: WriteDVI: op-code %d only works with the \"-omega\" option",
+			      __FILE__, __LINE__, c);
+	    }
 	case RIGHT3:
 	case W3:
 	case X3:
