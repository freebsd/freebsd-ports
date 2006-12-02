--- HtmlPage.cpp.orig	Tue Apr  4 01:59:24 2000
+++ HtmlPage.cpp	Fri Dec  1 22:34:09 2006
@@ -26,6 +26,8 @@
 #endif
 
 using std::string;
+using std::ios;
+using std::endl;
 
 HtmlPage::HtmlPage(	const string& path, 
 					const string& _filename,
