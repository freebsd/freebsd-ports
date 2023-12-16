--- src/3rdparty/chromium/ui/events/ozone/layout/xkb/xkb_keyboard_layout_engine.cc.orig	2023-10-03 19:49:54 UTC
+++ src/3rdparty/chromium/ui/events/ozone/layout/xkb/xkb_keyboard_layout_engine.cc
@@ -637,7 +637,7 @@ void LoadKeymap(const std::string& layout_name,
                           .options = ""};
   std::unique_ptr<xkb_context, XkbContextDeleter> context;
   context.reset(xkb_context_new(XKB_CONTEXT_NO_DEFAULT_INCLUDES));
-  xkb_context_include_path_append(context.get(), "/usr/share/X11/xkb");
+  xkb_context_include_path_append(context.get(), "%%LOCALBASE%%/share/X11/xkb");
   std::unique_ptr<xkb_keymap, XkbKeymapDeleter> keymap;
   keymap.reset(xkb_keymap_new_from_names(context.get(), &names,
                                          XKB_KEYMAP_COMPILE_NO_FLAGS));
@@ -671,7 +671,7 @@ XkbKeyboardLayoutEngine::XkbKeyboardLayoutEngine(
   // TODO: add XKB_CONTEXT_NO_ENVIRONMENT_NAMES
   xkb_context_.reset(xkb_context_new(XKB_CONTEXT_NO_DEFAULT_INCLUDES));
   xkb_context_include_path_append(xkb_context_.get(),
-                                  "/usr/share/X11/xkb");
+                                  "%%LOCALBASE%%/share/X11/xkb");
 }
 
 XkbKeyboardLayoutEngine::~XkbKeyboardLayoutEngine() {
