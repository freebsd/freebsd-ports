--- noatun/library/engine.cpp	Sun Mar  3 01:36:38 2002
+++ noatun/library/engine.cpp.new	Wed Jun 12 22:30:55 2002
@@ -40,7 +40,7 @@
 #elif defined(__linux__)
 #include <sys/soundcard.h>
 #elif defined(__FreeBSD__)
-#include "machine/soundcard.h"
+#include <sys/soundcard.h>
 #elif defined(__NetBSD__)
 #include <soundcard.h>
 #elif defined(___SOMETHING_UNKNOWN__)
