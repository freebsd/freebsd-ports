--- src/timer.cc.orig	2010-03-25 15:58:11.000000000 +0100
+++ src/timer.cc	2015-03-08 22:18:05.760740000 +0100
@@ -33,12 +33,15 @@
     #include "autoconfig.h"
 #endif
 
+#include "singleton.h"
+
+class Timer;
+SINGLETON_MUTEX(Timer, true);
+
 #include "timer.h"
 
 using namespace zmm;
 
-SINGLETON_MUTEX(Timer, true);
-
 template <>
 Ref<Array<Timer::TimerSubscriberElement<TimerSubscriberSingleton<Object> > > > Timer::getAppropriateSubscribers<TimerSubscriberSingleton<Object> >()
 {
