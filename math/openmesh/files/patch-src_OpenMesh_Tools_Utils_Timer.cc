--- src/OpenMesh/Tools/Utils/Timer.cc.orig	2020-03-12 13:55:54 UTC
+++ src/OpenMesh/Tools/Utils/Timer.cc
@@ -41,6 +41,8 @@
 
 
 
+#include <sys/time.h>
+
 #ifndef DOXY_IGNORE_THIS
 // ----------------------------------------------------------------------------
 #include <OpenMesh/Core/System/config.h>
@@ -145,7 +147,7 @@ double TimerImplWin32::seconds(void) const
 }
 
 // ------------------------------------------------------------- posix time ----
-#elif defined(__GNUC__) && defined(__POSIX__) 
+#elif 0 && defined(__GNUC__) && defined(__POSIX__) 
 
 #ifndef DOXY_IGNORE_THIS
 #  include <time.h>
@@ -183,7 +185,7 @@ class TimerImplPosix : public TimerImpl (protected)
 };
 
 // ----------------------------------------------------------- gettimeofday ----
-#elif (defined(__GNUC__) && !defined(__FreeBSD__) || (defined(__INTEL_COMPILER) && !defined(WIN32))) && !defined(__MINGW32__)
+#elif 0 && (defined(__GNUC__) && !defined(__FreeBSD__) || (defined(__INTEL_COMPILER) && !defined(WIN32))) && !defined(__MINGW32__)
 
 #  include <sys/time.h>
 #  include <sys/resource.h>
