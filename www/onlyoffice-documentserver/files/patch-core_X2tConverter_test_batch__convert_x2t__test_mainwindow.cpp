--- core/X2tConverter/test/batch_convert/x2t_test/mainwindow.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/X2tConverter/test/batch_convert/x2t_test/mainwindow.cpp
@@ -85,7 +85,7 @@ class CDirectoryParse : public NSThreads::CBaseThread 
         CApplicationFonts oApplication;
         std::vector<std::wstring> strFontsW_Cur = oApplication.GetSetupFontFiles();
 
-#if defined(_LINUX)
+#if defined(_LINUX) || defined(__FreeBSD__)
         std::wstring sHome = GetHomeDirectory();
         if (!sHome.empty())
         {
@@ -767,7 +767,7 @@ class CConverter : public NSThreads::CBaseThread (publ
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
         pid_t pid = fork(); // create child process
         int status;
 
