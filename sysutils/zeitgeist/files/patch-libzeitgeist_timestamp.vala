--- libzeitgeist/timestamp.vala.orig	2014-07-03 07:46:47 UTC
+++ libzeitgeist/timestamp.vala
@@ -76,8 +76,7 @@ namespace Zeitgeist.Timestamp
      */
     public int64 from_timeval (TimeVal timeval)
     {
-        var m_seconds = (int64) (timeval.tv_sec) * 1000;
-        return m_seconds + ((int64) timeval.tv_usec / 1000);
+        return timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
     }
 
     /**
