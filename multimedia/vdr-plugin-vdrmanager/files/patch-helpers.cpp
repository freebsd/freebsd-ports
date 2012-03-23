--- a/helpers.cpp
+++ b/helpers.cpp
@@ -4,7 +4,9 @@
 
 #include <time.h>
 #include <unistd.h>
+#ifndef __FreeBSD__
 #include <values.h>
+#endif
 #include <vdr/plugin.h>
 #include <vdr/timers.h>
 #include <vdr/recording.h>
