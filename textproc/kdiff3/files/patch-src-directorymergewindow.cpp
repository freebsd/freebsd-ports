--- src/directorymergewindow.cpp.orig	Fri Oct  3 18:32:57 2003
+++ src/directorymergewindow.cpp	Fri Oct  3 18:33:00 2003
@@ -863,7 +863,7 @@
 
       mfi.m_subPath = mfi.m_fileInfoA.exists() ? mfi.m_fileInfoA.filePath() :
                       mfi.m_fileInfoB.exists() ? mfi.m_fileInfoB.filePath() :
-                      mfi.m_fileInfoC.exists() ? mfi.m_fileInfoC.filePath() : "";
+                      mfi.m_fileInfoC.exists() ? mfi.m_fileInfoC.filePath() : QString("");
 
       g_pProgressDialog->setInformation(
          "Processing " + QString::number(currentIdx) +" / "+ QString::number(nrOfFiles)
