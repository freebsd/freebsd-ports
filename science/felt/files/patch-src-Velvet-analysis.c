--- src/Velvet/analysis.c.orig	Tue Mar 13 19:14:27 2007
+++ src/Velvet/analysis.c	Tue Mar 13 19:14:35 2007
@@ -964,7 +964,7 @@
  ************************************************************************/
 
 # if defined(__STDC__)
-void AnalysisDialogUpdate (AnalysisDialog analysisd, int force)
+void AnalysisDialogUpdate (AnalysisDialog analysisd, Boolean force)
 # else
 void AnalysisDialogUpdate (analysisd,force)
     AnalysisDialog	analysisd;
