--- kmidi/b_out.cpp	Wed Jun 12 22:26:03 2002
+++ kmidi/b_out.cpp.new	Wed Jun 12 22:27:40 2002
@@ -17,7 +17,7 @@
 #endif
 
 #ifdef __FreeBSD__
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 
 #ifdef __bsdi__
