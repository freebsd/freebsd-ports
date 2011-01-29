--- Load.xs	2002-08-31 02:00:32.000000000 +0000
+++ Load.xs	2011-01-19 12:07:14.000000000 +0000
@@ -2,6 +2,7 @@
 #include "perl.h"
 #include "XSUB.h"
 #include "stdlib.h"
+#include <time.h>
 
 
 MODULE = Sys::Load         PACKAGE = Sys::Load
@@ -22,3 +23,16 @@
     XPUSHs(sv_2mortal(newSVnv(load[2])));
   }
 
+void
+uptime()
+PROTOTYPE:
+PREINIT:
+  struct timespec t;
+  int i;
+PPCODE:
+  i = clock_gettime(CLOCK_MONOTONIC, &t);
+  if(i == -1)
+		XSRETURN_EMPTY;
+  else {
+		XPUSHs(sv_2mortal(newSVnv(t.tv_sec)));
+	}
