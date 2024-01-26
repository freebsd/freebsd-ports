--- core/DesktopEditor/fontengine/ApplicationFonts.cpp.orig	2022-05-11 19:33:56 UTC
+++ core/DesktopEditor/fontengine/ApplicationFonts.cpp
@@ -1616,6 +1616,8 @@ void CApplicationFonts::Initialize(bool bIsCheckSelect
 
 #if defined(_LINUX) && !defined(_MAC) && !defined(__ANDROID__)
 	m_oList.LoadFromFolder(L"/usr/share/fonts");
+#elif defined(__FreeBSD__)
+    m_oList.LoadFromFolder(L"%%LOCALBASE%%/share/fonts");
 #endif
 
 #if defined(_MAC) && !defined(_IOS)
@@ -1802,6 +1804,9 @@ std::vector<std::wstring> CApplicationFonts::GetSetupF
 	NSDirectory::GetFiles2(L"/usr/X11R6/lib/X11/fonts", _array, true);
 	NSDirectory::GetFiles2(L"/usr/local/share/fonts", _array, true);
 	NSDirectory::GetFiles2(L"/run/host/fonts", _array, true);
+#elif defined(__FreeBSD__)
+     std::vector<std::wstring> _array = NSDirectory::GetFiles(L"/usr/share/fonts", true);
+     NSDirectory::GetFiles2(L"%%LOCALBASE%%/share/fonts", _array, true);
 
 #ifndef BUILDING_WASM_MODULE
 	std::wstring custom_fonts_path = NSSystemUtils::GetEnvVariable(L"CUSTOM_FONTS_PATH");
