--- third_party/blink/renderer/core/loader/resource/font_resource.h.orig	2026-10-18 13:29:39 UTC
+++ third_party/blink/renderer/core/loader/resource/font_resource.h
@@ -47,7 +47,6 @@ class FetchParameters;
 class ResourceFetcher;
 class FontCustomPlatformData;
 class FontResourceClient;
-class IftPatcher;
 
 // An observer that will be notified when original data is cleared
 // from the resource. Inspector may collect this data and store it for
@@ -78,7 +77,6 @@ class CORE_EXPORT FontResource final : public Resource
   String OtsParsingMessage() const { return ots_parsing_message_; }
 
   const FontCustomPlatformData* GetCustomFontData();
-  std::unique_ptr<IftPatcher> TakeIftPatcher();
 
   // Returns true if the loading priority of the remote font resource can be
   // lowered. The loading priority of the font can be lowered only if the
@@ -127,7 +125,6 @@ class CORE_EXPORT FontResource final : public Resource
   };
 
   Member<FontCustomPlatformData> font_data_;
-  std::unique_ptr<IftPatcher> ift_patcher_;
   String ots_parsing_message_;
   LoadLimitState load_limit_state_;
   bool cors_failed_;
