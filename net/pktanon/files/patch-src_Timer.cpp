--- src/Timer.cpp.orig	2013-10-01 17:57:00.000000000 +0000
+++ src/Timer.cpp
@@ -16,6 +16,7 @@
 // Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 //
 
+#include <unistd.h>
 #include "Timer.h"
 
 Timer::Timer ()
