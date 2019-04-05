--- src/3rdparty/chromium/content/public/browser/web_ui.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/public/browser/web_ui.h
@@ -11,7 +11,6 @@
 
 #include "base/callback.h"
 #include "base/strings/string16.h"
-#include "base/strings/string_piece.h"
 #include "content/common/content_export.h"
 #include "ui/base/page_transition_types.h"
 
@@ -75,7 +74,7 @@ class CONTENT_EXPORT WebUI {
   // Used by WebUIMessageHandlers. If the given message is already registered,
   // the call has no effect.
   using MessageCallback = base::RepeatingCallback<void(const base::ListValue*)>;
-  virtual void RegisterMessageCallback(base::StringPiece message,
+  virtual void RegisterMessageCallback(const std::string& message,
                                        const MessageCallback& callback) = 0;
 
   // This is only needed if an embedder overrides handling of a WebUIMessage and
