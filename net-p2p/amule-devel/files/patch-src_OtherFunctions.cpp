--- src/OtherFunctions.cpp.orig	2017-06-02 17:07:14.000000000 +0200
+++ src/OtherFunctions.cpp	2017-06-03 23:19:52.518208000 +0200
@@ -1107,7 +1107,7 @@
 #if defined(__WXMAC__) || defined(__WINDOWS__)
 	locale.AddCatalogLookupPathPrefix(JoinPaths(wxStandardPaths::Get().GetDataDir(), wxT("locale")));
 #else
-#if (wxCHECK_VERSION(2,9,5) && !wxCHECK_VERION(3,0,3)) || (wxCHECK_VERSION(3,1,0) && !wxCHECK_VERSION(3,1,1))
+#if (wxCHECK_VERSION(2,9,5) && !wxCHECK_VERSION(3,0,3)) || (wxCHECK_VERSION(3,1,0) && !wxCHECK_VERSION(3,1,1))
 	// Add correct place to look for catalog files if we're using a wxWidgets version where it's broken
 	// See also http://trac.wxwidgets.org/ticket/17740
 	locale.AddCatalogLookupPathPrefix(JoinPaths(JoinPaths(wxStandardPaths::Get().GetInstallPrefix(), wxT("share")), wxT("locale")));
