--- src/OpenMesh/Tools/Utils/Timer.cc.orig	2018-10-21 23:42:34 UTC
+++ src/OpenMesh/Tools/Utils/Timer.cc
@@ -46,6 +46,8 @@
  *                                                                           *
 \*===========================================================================*/
 
+#include <sys/time.h>
+
 #ifndef DOXY_IGNORE_THIS
 // ----------------------------------------------------------------------------
 #include <OpenMesh/Core/System/config.h>
@@ -188,7 +190,7 @@ protected:
 };
 
 // ----------------------------------------------------------- gettimeofday ----
-#elif (defined(__GNUC__) || (defined(__INTEL_COMPILER) && !defined(WIN32))) && !defined(__MINGW32__)
+#elif 0 && (defined(__GNUC__) || (defined(__INTEL_COMPILER) && !defined(WIN32))) && !defined(__MINGW32__)
 
 #  include <sys/time.h>
 #  include <sys/resource.h>
@@ -276,7 +278,7 @@ Timer::Timer(void) :
 #  else
   impl_      = new TimerImplPosix<CLOCK_REALTIME>;
 #  endif
-#elif (defined(__GNUC__) || (defined(__INTEL_COMPILER) && !defined(WIN32)) ) && !defined(__MINGW32__)
+#elif 0 && (defined(__GNUC__) || (defined(__INTEL_COMPILER) && !defined(WIN32)) ) && !defined(__MINGW32__)
   impl_      = new TimerImplGToD;
 #else
   impl_       = new TimerImplStd;
