--- core/DesktopEditor/fontengine/ApplicationFonts.cpp.orig	2022-05-11 19:33:56 UTC
+++ core/DesktopEditor/fontengine/ApplicationFonts.cpp
@@ -1595,6 +1595,8 @@ void CApplicationFonts::Initialize(bool bIsCheckSelect
 
 #if defined(_LINUX) && !defined(_MAC) && !defined(__ANDROID__)
     m_oList.LoadFromFolder(L"/usr/share/fonts");
+#elif defined(__FreeBSD__)
+    m_oList.LoadFromFolder(L"%%LOCALBASE%%/share/fonts");
 #endif
 
 #if defined(_MAC) && !defined(_IOS)
@@ -1782,6 +1784,10 @@ std::vector<std::wstring> CApplicationFonts::GetSetupF
      std::wstring custom_fonts_path = NSSystemUtils::GetEnvVariable(L"CUSTOM_FONTS_PATH");
      if (!custom_fonts_path.empty())
         NSDirectory::GetFiles2(custom_fonts_path, _array, true);
+
+#elif defined(__FreeBSD__)
+     std::vector<std::wstring> _array = NSDirectory::GetFiles(L"/usr/share/fonts", true);
+     NSDirectory::GetFiles2(L"%%LOCALBASE%%/share/fonts", _array, true);
 #endif
 
      return _array;
