--- content/public/browser/web_ui.h.orig	2018-07-20 15:49:47.533832000 +0200
+++ content/public/browser/web_ui.h	2018-07-20 15:50:46.750401000 +0200
@@ -9,7 +9,6 @@
 
 #include "base/callback.h"
 #include "base/strings/string16.h"
-#include "base/strings/string_piece.h"
 #include "content/common/content_export.h"
 #include "ui/base/page_transition_types.h"
 
@@ -73,7 +72,7 @@
   // Used by WebUIMessageHandlers. If the given message is already registered,
   // the call has no effect.
   using MessageCallback = base::RepeatingCallback<void(const base::ListValue*)>;
-  virtual void RegisterMessageCallback(base::StringPiece message,
+  virtual void RegisterMessageCallback(const std::string& message,
                                        const MessageCallback& callback) = 0;
 
   // This is only needed if an embedder overrides handling of a WebUIMessage and
