--- ./xbmc/VideoDatabase.cpp.orig	2010-11-09 22:55:18.000000000 +0100
+++ ./xbmc/VideoDatabase.cpp	2010-12-01 12:17:34.199531299 +0100
@@ -4423,7 +4423,7 @@
     }
 
     CLog::Log(LOGDEBUG,"Time for actual SQL query = %d",
-              CTimeUtils::GetTimeMS() - time); time = CTimeUtils::GetTimeMS();
+              (int)(CTimeUtils::GetTimeMS() - time)); time = CTimeUtils::GetTimeMS();
 
     // get data from returned rows
     items.Reserve(iRowsFound);
@@ -4443,7 +4443,7 @@
     }
 
     CLog::Log(LOGDEBUG,"Time to retrieve movies from dataset = %d",
-              CTimeUtils::GetTimeMS() - time);
+              (int)(CTimeUtils::GetTimeMS() - time));
 
     // cleanup
     m_pDS->close();
@@ -4495,7 +4495,7 @@
     }
 
     CLog::Log(LOGDEBUG,"Time for actual SQL query = %d",
-              CTimeUtils::GetTimeMS() - time); time = CTimeUtils::GetTimeMS();
+              (int)(CTimeUtils::GetTimeMS() - time)); time = CTimeUtils::GetTimeMS();
 
     // get data from returned rows
     items.Reserve(iRowsFound);
@@ -4523,7 +4523,7 @@
     }
 
     CLog::Log(LOGDEBUG,"Time to retrieve tvshows from dataset = %d",
-              CTimeUtils::GetTimeMS() - time);
+              (int)(CTimeUtils::GetTimeMS() - time));
 
     CStdString order(where);
     bool maintainOrder = order.ToLower().Find("order by") != -1;
@@ -4777,7 +4777,7 @@
     }
 
     CLog::Log(LOGDEBUG,"Time for actual SQL query = %d",
-              CTimeUtils::GetTimeMS() - time); time = CTimeUtils::GetTimeMS();
+              (int)(CTimeUtils::GetTimeMS() - time)); time = CTimeUtils::GetTimeMS();
 
     // get data from returned rows
     items.Reserve(iRowsFound);
@@ -4802,7 +4802,7 @@
     }
 
     CLog::Log(LOGDEBUG,"Time to retrieve episodes from dataset = %d",
-              CTimeUtils::GetTimeMS() - time);
+              (int)(CTimeUtils::GetTimeMS() - time));
 
     // cleanup
     m_pDS->close();
@@ -5600,7 +5600,8 @@
     // run query
     if (!m_pDS->query(strSQL.c_str()))
       return false;
-    CLog::Log(LOGDEBUG, "%s time for actual SQL query = %d", __FUNCTION__, CTimeUtils::GetTimeMS() - time); time = CTimeUtils::GetTimeMS();
+    CLog::Log(LOGDEBUG, "%s time for actual SQL query = %d", __FUNCTION__,
+      (int)(CTimeUtils::GetTimeMS() - time)); time = CTimeUtils::GetTimeMS();
 
     int iRowsFound = m_pDS->num_rows();
     if (iRowsFound == 0)
@@ -5627,7 +5628,8 @@
       m_pDS->next();
     }
 
-    CLog::Log(LOGDEBUG, "%s time to retrieve from dataset = %d", __FUNCTION__, CTimeUtils::GetTimeMS() - time); time = CTimeUtils::GetTimeMS();
+    CLog::Log(LOGDEBUG, "%s time to retrieve from dataset = %d", __FUNCTION__,
+      (int)(CTimeUtils::GetTimeMS() - time)); time = CTimeUtils::GetTimeMS();
 
     // cleanup
     m_pDS->close();
