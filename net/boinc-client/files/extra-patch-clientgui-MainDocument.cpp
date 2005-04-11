--- clientgui/MainDocument.cpp.orig	Tue Mar 15 16:53:12 2005
+++ clientgui/MainDocument.cpp	Sun Mar 20 21:59:15 2005
@@ -178,7 +178,7 @@
     if ( IsConnected() )
         return BOINC_SUCCESS;
 
-    str.clear();
+    str = "";
 
     if ( strMachine.empty() && !m_strConnectedComputerName.empty() )
         str = m_strConnectedComputerName.c_str();
@@ -416,7 +416,7 @@
 
     m_fProjectTotalResourceShare = 0.0;
     for (i=0; i < (long)project_status.projects.size(); i++) {
-        m_fProjectTotalResourceShare += project_status.projects.at( i )->resource_share;
+        m_fProjectTotalResourceShare += project_status.projects[i]->resource_share;
     }
 
     return iRetVal;
@@ -445,7 +445,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -470,7 +470,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -491,7 +491,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -512,7 +512,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -533,7 +533,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -554,7 +554,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -575,7 +575,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -603,7 +603,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -653,7 +653,7 @@
 
     if ( NULL != pProject )
     {
-        Url = pProject->gui_urls.at( iWebsiteIndex );
+        Url = pProject->gui_urls[iWebsiteIndex];
         strBuffer = Url.name.c_str();
     }
 
@@ -676,7 +676,7 @@
 
     if ( NULL != pProject )
     {
-        Url = pProject->gui_urls.at( iWebsiteIndex );
+        Url = pProject->gui_urls[iWebsiteIndex];
         strBuffer = Url.description.c_str();
     }
 
@@ -699,7 +699,7 @@
 
     if ( NULL != pProject )
     {
-        Url = pProject->gui_urls.at( iWebsiteIndex );
+        Url = pProject->gui_urls[iWebsiteIndex];
         strBuffer = Url.url.c_str();
     }
 
@@ -715,7 +715,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -737,7 +737,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -765,7 +765,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -787,7 +787,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -809,7 +809,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -832,7 +832,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -866,7 +866,7 @@
     try
     {
         if ( !project_status.projects.empty() )
-            pProject = project_status.projects.at( iIndex );
+            pProject = project_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -930,7 +930,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -963,7 +963,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -987,7 +987,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1027,7 +1027,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1064,7 +1064,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1085,7 +1085,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1106,7 +1106,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1127,7 +1127,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1148,7 +1148,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1169,7 +1169,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1191,7 +1191,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1213,7 +1213,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1235,7 +1235,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1257,7 +1257,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1279,7 +1279,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1301,7 +1301,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1323,7 +1323,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1345,7 +1345,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1368,7 +1368,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1404,7 +1404,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1440,7 +1440,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1472,7 +1472,7 @@
     try
     {
         if ( !results.results.empty() )
-            pResult = results.results.at( iIndex );
+            pResult = results.results[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1512,7 +1512,7 @@
     }
 
     if ( messages.messages.size() != 0 )
-        m_iMessageSequenceNumber = messages.messages.at( messages.messages.size()-1 )->seqno;
+        m_iMessageSequenceNumber = messages.messages[messages.messages.size()-1]->seqno;
 
     return iRetVal;
 }
@@ -1539,7 +1539,7 @@
     try
     {
         if ( !messages.messages.empty() )
-            pMessage = messages.messages.at( iIndex );
+            pMessage = messages.messages[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1560,7 +1560,7 @@
     try
     {
         if ( !messages.messages.empty() )
-            pMessage = messages.messages.at( iIndex );
+            pMessage = messages.messages[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1584,7 +1584,7 @@
     try
     {
         if ( !messages.messages.empty() )
-            pMessage = messages.messages.at( iIndex );
+            pMessage = messages.messages[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1605,7 +1605,7 @@
     try
     {
         if ( !messages.messages.empty() )
-            pMessage = messages.messages.at( iIndex );
+            pMessage = messages.messages[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1663,7 +1663,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1684,7 +1684,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1705,7 +1705,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1726,7 +1726,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1747,7 +1747,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1768,7 +1768,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1789,7 +1789,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1810,7 +1810,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1832,7 +1832,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1853,7 +1853,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1875,7 +1875,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1897,7 +1897,7 @@
     try
     {
         if ( !ft.file_transfers.empty() )
-            pFT = ft.file_transfers.at( iIndex );
+            pFT = ft.file_transfers[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1949,7 +1949,7 @@
     try
     {
         if ( !resource_status.projects.empty() )
-            pProject = resource_status.projects.at( iIndex );
+            pProject = resource_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
@@ -1978,7 +1978,7 @@
     try
     {
         if ( !resource_status.projects.empty() )
-            pProject = resource_status.projects.at( iIndex );
+            pProject = resource_status.projects[iIndex];
     }
     catch ( std::out_of_range e )
     {
