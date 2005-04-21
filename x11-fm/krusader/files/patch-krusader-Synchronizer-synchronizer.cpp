--- krusader/Synchronizer/synchronizer.cpp.orig	Sat Feb 12 13:54:06 2005
+++ krusader/Synchronizer/synchronizer.cpp	Fri Apr 15 21:39:03 2005
@@ -1192,8 +1192,6 @@
   waitWindow->setProgress( percent );
 }
 
-void Synchronizer::synchronizeWithKGet()
-{
   class KgetProgressDialog : public KDialogBase
   {
   public:
@@ -1243,6 +1241,8 @@
     bool       mPaused;
   };  
 
+void Synchronizer::synchronizeWithKGet()
+{
   bool isLeftLocal = vfs::fromPathOrURL( leftBaseDirectory() ).isLocalFile();
   KgetProgressDialog *progDlg = 0;
   int  processedCount = 0, totalCount = 0;
