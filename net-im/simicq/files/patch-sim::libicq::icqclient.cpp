--- sim/libicq/icqclient.cpp.orig	Tue Sep  2 01:47:04 2003
+++ sim/libicq/icqclient.cpp	Tue Sep  2 01:47:21 2003
@@ -128,7 +128,7 @@
         time_t now;
         time(&now);
         struct tm *tm = localtime(&now);
-        if (((tm->tm_mon + 1) == month) && ((tm->tm_mday + 1) == day))
+        if (((tm->tm_mon + 1) == month) && (tm->tm_mday == day))
             m_bBirthday = true;
     }
     if ((m_bBirthday != oldValue) && (m_state == Logged))
