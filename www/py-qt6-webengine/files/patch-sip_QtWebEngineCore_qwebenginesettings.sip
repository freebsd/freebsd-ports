quint8 is more on point. uint8_t requires <sys/types.h>

--- sip/QtWebEngineCore/qwebenginesettings.sip.orig	2025-10-16 10:34:51 UTC
+++ sip/QtWebEngineCore/qwebenginesettings.sip
@@ -125,11 +125,11 @@ class QWebEngineSettings /NoDefaultCtors/ (public)
     void setUnknownUrlSchemePolicy(QWebEngineSettings::UnknownUrlSchemePolicy policy);
     void resetUnknownUrlSchemePolicy();
 %If (QtWebEngine_6_10_0 -)
-    typedef unsigned char uint8_t /PyInt/;
+    typedef unsigned char quint8 /PyInt/;
 %End
 %If (QtWebEngine_6_8_0 -)
 
-    enum class ImageAnimationPolicy : uint8_t
+    enum class ImageAnimationPolicy : quint8
     {
         Allow,
         AnimateOnce,
