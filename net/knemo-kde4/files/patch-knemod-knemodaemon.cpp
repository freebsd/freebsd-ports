--- src/knemod/knemodaemon.cpp.orig	Mon Jun 12 15:47:54 2006
+++ src/knemod/knemodaemon.cpp	Mon Jun 12 16:30:45 2006
@@ -306,6 +306,8 @@
 
     // needed to calculate the current speed
     mGeneralData.secondsSinceLastUpdate = mLastUpdateTime.secsTo( QDateTime::currentDateTime() );
+    if (mGeneralData.secondsSinceLastUpdate == 0)
+        mGeneralData.secondsSinceLastUpdate = 1;
     mLastUpdateTime.setDate( QDate::currentDate() );
     mLastUpdateTime.setTime( QTime::currentTime() );
 
