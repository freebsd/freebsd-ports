--- src/ui/wxWidgets/wxUtilities.cpp.orig	2025-02-08 10:26:13 UTC
+++ src/ui/wxWidgets/wxUtilities.cpp
@@ -355,7 +355,7 @@ bool IsTaskBarIconAvailable()
 // on Fedora or Ubuntu
 bool IsTaskBarIconAvailable()
 {
-#if defined(__WXGTK__) && !defined(__OpenBSD__)
+#if defined(__WXGTK__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
   const wxVersionInfo verInfo = wxGetLibraryVersionInfo();
   int major = verInfo.GetMajor();
   int minor = verInfo.GetMinor();
