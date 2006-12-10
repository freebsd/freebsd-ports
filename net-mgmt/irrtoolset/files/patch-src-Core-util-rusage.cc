--- src/Core/util/rusage.cc.orig	2004-07-30 12:58:10.000000000 +0200
+++ src/Core/util/rusage.cc
@@ -52,7 +52,11 @@
 //  Author(s): Cengiz Alaettinoglu <cengiz@ISI.EDU>
 
 #include "config.h"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 #include "rusage.hh"
 #include <iomanip>
 
@@ -83,7 +87,6 @@ extern "C" {
 #endif
 }
 
-
 double tv2f(timeval &tv)
 /* Converts a timeval into a double giving the time in seconds. */
 {
@@ -114,7 +117,7 @@ ostream& operator<<(ostream& stream, Rus
     stime = tv2f(self.ru_stime) - ru.last_stime;
     rtime = tv2f(end_time)      - ru.last_rtime;
 
-    stream << fixed << setprecision(2);
+    stream << setiosflags(ostream::fixed) << setprecision(2);
     stream <<  "     times:    "
            << utime << " "
            << stime << " "
@@ -137,7 +140,7 @@ ostream& operator<<(ostream& stream, Rus
     stream << "     vo/nv cs: "
            << self.ru_nvcsw << " "
            << self.ru_nivcsw << endl;
-    stream << scientific << setprecision(0);
+    stream << setiosflags(ostream::scientific) << setprecision(0);
     return stream;
 }
 
