--- core/DesktopEditor/fontengine/ApplicationFonts.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/fontengine/ApplicationFonts.cpp
@@ -1596,6 +1596,8 @@ void CApplicationFonts::Initialize(bool bIsCheckSelect
 
 #if defined(_LINUX) && !defined(_MAC) && !defined(__ANDROID__)
 	m_oList.LoadFromFolder(L"/usr/share/fonts");
+#else if defined(__FreeBSD__)
+	m_oList.LoadFromFolder(L"%%LOCALBASE%%/share/fonts");
 #endif
 
 #if defined(_MAC) && !defined(_IOS)
@@ -1769,6 +1771,10 @@ std::vector<std::wstring> CApplicationFonts::GetSetupF
      NSDirectory::GetFiles2(L"/usr/X11R6/lib/X11/fonts", _array, true);
      NSDirectory::GetFiles2(L"/usr/local/share/fonts", _array, true);
      NSDirectory::GetFiles2(L"/run/host/fonts", _array, true);
+     return _array;
+#elif defined(__FreeBSD__)
+     std::vector<std::wstring> _array = NSDirectory::GetFiles(L"/usr/share/fonts", true);
+     NSDirectory::GetFiles2(L"%%LOCALBASE%%/share/fonts", _array, true);
      return _array;
 #endif
 
