See https://invent.kde.org/sdk/kdiff3/-/merge_requests/31

When writing out files, don't treat removed lines as real lines,
and append a newline to the whole output file.
--- src/mergeresultwindow.cpp.orig	2021-05-17 17:26:58 UTC
+++ src/mergeresultwindow.cpp
@@ -2964,6 +2964,9 @@ bool MergeResultWindow::saveDocument(const QString& fi
         textOutStream.setGenerateByteOrderMark(true); // Only for UTF-16
     textOutStream.setCodec(pEncoding);
 
+    // Determine the line feed for this file
+    const QString lineFeed(eLineEndStyle == eLineEndStyleDos ? QString("\r\n") : QString("\n"));
+
     int line = 0;
     MergeLineList::iterator mlIt = m_mergeLineList.begin();
     for(mlIt = m_mergeLineList.begin(); mlIt != m_mergeLineList.end(); ++mlIt)
@@ -2976,18 +2979,14 @@ bool MergeResultWindow::saveDocument(const QString& fi
 
             if(mel.isEditableText())
             {
-                QString str = mel.getString(m_pldA, m_pldB, m_pldC);
+                const QString str = mel.getString(m_pldA, m_pldB, m_pldC);
 
-                if(line > 0) // Prepend line feed, but not for first line
+                if(line > 0 && !mel.isRemoved())
                 {
-                    if(eLineEndStyle == eLineEndStyleDos)
-                    {
-                        str.prepend("\r\n");
-                    }
-                    else
-                    {
-                        str.prepend("\n");
-                    }
+                    // Put line feed between lines, but not for the first line
+                    // or between lines that have been removed (because there
+                    // isn't a line there).
+                    textOutStream << lineFeed;
                 }
 
                 textOutStream << str;
@@ -2995,6 +2994,8 @@ bool MergeResultWindow::saveDocument(const QString& fi
             }
         }
     }
+    // At the end of the stream, needs a newline
+    textOutStream << lineFeed;
     textOutStream.flush();
     bool bSuccess = file.writeFile(dataArray.data(), dataArray.size());
     if(!bSuccess)
