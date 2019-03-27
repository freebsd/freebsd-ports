--- src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.cc
@@ -40,7 +40,7 @@ namespace content {
 
 class PpapiBlinkPlatformImpl::SandboxSupport : public WebSandboxSupport {
  public:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   explicit SandboxSupport(sk_sp<font_service::FontLoader> font_loader)
       : font_loader_(std::move(font_loader)) {}
 #endif
@@ -48,7 +48,7 @@ class PpapiBlinkPlatformImpl::SandboxSupport : public 
 
 #if defined(OS_MACOSX)
   bool LoadFont(CTFontRef srcFont, CGFontRef* out, uint32_t* fontID) override;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   SandboxSupport();
   void GetFallbackFontForCharacter(
       WebUChar32 character,
@@ -129,7 +129,7 @@ void PpapiBlinkPlatformImpl::SandboxSupport::GetWebFon
 #endif  // !defined(OS_ANDROID) && !defined(OS_WIN)
 
 PpapiBlinkPlatformImpl::PpapiBlinkPlatformImpl() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   font_loader_ =
       sk_make_sp<font_service::FontLoader>(ChildThread::Get()->GetConnector());
   SkFontConfigInterface::SetGlobal(font_loader_);
