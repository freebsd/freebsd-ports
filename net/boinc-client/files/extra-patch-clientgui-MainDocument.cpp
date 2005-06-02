--- clientgui/MainDocument.cpp.orig	Sun May 29 03:29:00 2005
+++ clientgui/MainDocument.cpp	Wed Jun  1 20:36:08 2005
@@ -553,7 +553,7 @@
 
         m_fProjectTotalResourceShare = 0.0;
         for (i=0; i < (long)project_status.projects.size(); i++) {
-            m_fProjectTotalResourceShare += project_status.projects.at(i)->resource_share;
+            m_fProjectTotalResourceShare += project_status.projects[i]->resource_share;
         }
     }
 
@@ -685,7 +685,7 @@
     pProject = state.lookup_project(str);
 
     if (pProject) {
-        Url = pProject->gui_urls.at(iWebsiteIndex);
+        Url = pProject->gui_urls[iWebsiteIndex];
         strBuffer = Url.name.c_str();
     }
 
@@ -706,7 +706,7 @@
     pProject = state.lookup_project(str);
 
     if (pProject) {
-        Url = pProject->gui_urls.at(iWebsiteIndex);
+        Url = pProject->gui_urls[iWebsiteIndex];
         strBuffer = Url.description.c_str();
     }
 
@@ -727,7 +727,7 @@
     pProject = state.lookup_project(str);
 
     if (pProject) {
-        Url = pProject->gui_urls.at(iWebsiteIndex);
+        Url = pProject->gui_urls[iWebsiteIndex];
         strBuffer = Url.url.c_str();
     }
 
@@ -843,7 +843,7 @@
     //   pointer when the exception is thrown.
     try {
         if (!project_status.projects.empty())
-            pProject = project_status.projects.at(i);
+            pProject = project_status.projects[i];
     }
     catch (std::out_of_range e) {
         pProject = NULL;
@@ -1148,7 +1148,7 @@
     //   pointer when the exception is thrown.
     try {
         if (!results.results.empty())
-            pResult = results.results.at(i);
+            pResult = results.results[i];
     }
     catch (std::out_of_range e) {
         pResult = NULL;
@@ -1169,7 +1169,7 @@
         }
 
         if (messages.messages.size() != 0)
-            m_iMessageSequenceNumber = messages.messages.at(messages.messages.size()-1)->seqno;
+            m_iMessageSequenceNumber = messages.messages[messages.messages.size()-1]->seqno;
     }
 
     return iRetVal;
@@ -1257,7 +1257,7 @@
     //   pointer when the exception is thrown.
     try {
         if (!messages.messages.empty())
-            pMessage = messages.messages.at(i);
+            pMessage = messages.messages[i];
     }
     catch (std::out_of_range e) {
         pMessage = NULL;
@@ -1454,7 +1454,7 @@
     //   pointer when the exception is thrown.
     try {
         if (!ft.file_transfers.empty())
-            pFT = ft.file_transfers.at(i);
+            pFT = ft.file_transfers[i];
     }
     catch (std::out_of_range e) {
         pFT = NULL;
@@ -1534,7 +1534,7 @@
     //   pointer when the exception is thrown.
     try {
         if (!resource_status.projects.empty()) {
-            pProject = resource_status.projects.at(i);
+            pProject = resource_status.projects[i];
         }
     }
     catch (std::out_of_range e) {
@@ -1605,7 +1605,7 @@
     //   pointer when the exception is thrown.
     try {
         if (!statistics_status.projects.empty())
-            pProject = statistics_status.projects.at(i);
+            pProject = statistics_status.projects[i];
     }
     catch (std::out_of_range e) {
         pProject = NULL;
