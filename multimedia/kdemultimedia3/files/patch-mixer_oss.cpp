--- kmix/mixer_oss.cpp	Wed May  8 20:29:20 2002
+++ kmix/mixer_oss.cpp.new	Wed Jun 12 22:35:44 2002
@@ -32,7 +32,7 @@
 #include <sys/soundcard.h>
 // FreeBSD section, according to Sebestyen Zoltan
 #elif defined(__FreeBSD__)
-#include "machine/soundcard.h"
+#include <sys/soundcard.h>
 // NetBSD section, according to  Lennart Augustsson <augustss@cs.chalmers.se>
 #elif defined(__NetBSD__)
 #include <soundcard.h>
