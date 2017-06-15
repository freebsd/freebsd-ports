/wrkdirs/usr/ports/net-im/kmess-kde4/work/kmess-2.0.6.2/src/utils/xautolock.cpp:110:7: error: call to 'abs' is ambiguous
  if( abs( lastCheck_ - now ) > 120 )
      ^~~
/usr/include/stdlib.h:83:6: note: candidate function
int      abs(int) __pure2;
         ^
/usr/include/c++/v1/stdlib.h:115:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long      abs(     long __x) _NOEXCEPT {return  labs(__x);}
                                           ^
/usr/include/c++/v1/stdlib.h:117:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long long abs(long long __x) _NOEXCEPT {return llabs(__x);}
                                           ^

--- src/utils/xautolock.cpp.orig	2012-02-17 20:16:31 UTC
+++ src/utils/xautolock.cpp
@@ -106,8 +106,9 @@ void XAutoLock::checkIdle()
   unsigned long timeIdle;
 
   now = (uint)time( 0 );
-
-  if( abs( lastCheck_ - now ) > 120 )
+   
+  unsigned int delta = (lastCheck_ > now ? lastCheck_ - now : now - lastCheck_);
+  if( delta > 120 )
   {
     // Whoah, two minutes since we were last called?  Something strange is happening...
     resetTimer();
