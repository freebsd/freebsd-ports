--- texk/xdvik/dvisel.c.orig	2019-07-27 23:56:42 UTC
+++ texk/xdvik/dvisel.c
@@ -30,6 +30,7 @@
 #include <string.h>
 #include <ctype.h>
 
+#include "xdvi-config.h"
 #include "dvi.h"
 #include "pagesel.h"
 #include "dvisel.h"
@@ -512,6 +513,12 @@ WriteDVI(FILE *fin, FILE *fout, long *fout_pos, int c)
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
@@ -521,6 +528,12 @@ WriteDVI(FILE *fin, FILE *fout, long *fout_pos, int c)
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
