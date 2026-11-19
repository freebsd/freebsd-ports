--- native/CefBrowser_N.cpp.orig	2026-09-08 14:07:06 UTC
+++ native/CefBrowser_N.cpp
@@ -24,7 +24,7 @@
 #include "temp_window.h"
 #include "window_handler.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #define XK_3270  // for XK_3270_BackTab
 #include <X11/XF86keysym.h>
 #include <X11/keysym.h>
@@ -71,7 +71,7 @@ int GetCefModifiers(JNIEnv* env, jclass cls, int modif
   return cef_modifiers;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 
 // From ui/events/keycodes/keyboard_codes_posix.h.
 enum KeyboardCode {
@@ -731,7 +731,7 @@ int GetControlCharacter(KeyboardCode windows_key_code,
   }
 }
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_MACOSX)
 // A convenient array for getting symbol characters on the number keys.
@@ -989,7 +989,7 @@ void create(std::shared_ptr<JNIObjectsForCreate> objs,
     CefWindowHandle browserContentView =
         util_mac::CreateBrowserContentView(parent, rect);
     windowInfo.SetAsChild(browserContentView, rect);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
     CefWindowHandle parent = TempWindow::GetWindowHandle();
     if (objs->canvas != nullptr) {
       parent = GetDrawableOfCanvas(objs->canvas, env);
@@ -1279,7 +1279,7 @@ Java_org_cef_browser_CefBrowser_1N_N_1GetWindowHandle(
   CefWindowHandle windowHandle = kNullWindowHandle;
 #if defined(OS_WIN)
   windowHandle = ::WindowFromDC((HDC)displayHandle);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   return displayHandle;
 #elif defined(OS_MACOSX)
   ASSERT(util_mac::IsNSView((void*)displayHandle));
@@ -1669,7 +1669,7 @@ Java_org_cef_browser_CefBrowser_1N_N_1WasResized(JNIEn
   if (browser->GetHost()->IsWindowRenderingDisabled()) {
     browser->GetHost()->WasResized();
   }
-#if (defined(OS_WIN) || defined(OS_LINUX))
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD))
   else {
     CefWindowHandle browserHandle = browser->GetHost()->GetWindowHandle();
     if (CefCurrentlyOn(TID_UI)) {
@@ -1719,7 +1719,7 @@ Java_org_cef_browser_CefBrowser_1N_N_1SendKeyEvent(JNI
   BYTE VkCode = LOBYTE(MapVirtualKey(scanCode, MAPVK_VSC_TO_VK));
   cef_event.native_key_code = (scanCode << 16) |  // key scan code
                               1;                  // key repeat count
-#elif defined(OS_LINUX) || defined(OS_MACOSX)
+#elif defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FREEBSD)
   int key_code;
   if (!CallJNIMethodI_V(env, cls, key_event, "getKeyCode", &key_code)) {
     return;
@@ -1735,7 +1735,7 @@ Java_org_cef_browser_CefBrowser_1N_N_1SendKeyEvent(JNI
   JNI_STATIC_DEFINE_INT(env, cls, VK_TAB);
   JNI_STATIC_DEFINE_INT(env, cls, VK_UP);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   if (key_code == JNI_STATIC(VK_BACK_SPACE))
     cef_event.native_key_code = XK_BackSpace;
   else if (key_code == JNI_STATIC(VK_DELETE))
@@ -1877,7 +1877,7 @@ Java_org_cef_browser_CefBrowser_1N_N_1SendKeyEvent(JNI
       cef_event.character = 29;
   }
 #endif  // defined(OS_MACOSX)
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FREEBSD)
 
   if (event_type == JNI_STATIC(KEY_PRESSED)) {
 #if defined(OS_WIN)
@@ -2137,7 +2137,7 @@ Java_org_cef_browser_CefBrowser_1N_N_1SetParent(JNIEnv
   if (CefCurrentlyOn(TID_UI)) {
     util::SetParent(browserHandle, parentHandle, std::move(callback));
   } else {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     CriticalLock lock;
     CriticalWait waitCond(&lock);
     lock.Lock();
@@ -2157,7 +2157,7 @@ Java_org_cef_browser_CefBrowser_1N_N_1NotifyMoveOrResi
 JNIEXPORT void JNICALL
 Java_org_cef_browser_CefBrowser_1N_N_1NotifyMoveOrResizeStarted(JNIEnv* env,
                                                                 jobject obj) {
-#if (defined(OS_WIN) || defined(OS_LINUX))
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD))
   CefRefPtr<CefBrowser> browser = JNI_GET_BROWSER_OR_RETURN(env, obj);
   if (!browser->GetHost()->IsWindowRenderingDisabled()) {
     browser->GetHost()->NotifyMoveOrResizeStarted();
