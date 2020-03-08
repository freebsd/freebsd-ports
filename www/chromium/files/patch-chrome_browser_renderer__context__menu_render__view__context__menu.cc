--- chrome/browser/renderer_context_menu/render_view_context_menu.cc.orig	2020-03-03 18:53:51 UTC
+++ chrome/browser/renderer_context_menu/render_view_context_menu.cc
@@ -1701,7 +1701,7 @@ void RenderViewContextMenu::AppendEditableItems() {
 // 'Undo' and 'Redo' for text input with no suggestions and no text selected.
 // We make an exception for OS X as context clicking will select the closest
 // word. In this case both items are always shown.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_UNDO,
                                   IDS_CONTENT_CONTEXT_UNDO);
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_REDO,
@@ -1743,7 +1743,7 @@ void RenderViewContextMenu::AppendLanguageSettings() {
   if (!use_spelling)
     return;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_LANGUAGE_SETTINGS,
                                   IDS_CONTENT_CONTEXT_LANGUAGE_SETTINGS);
 #else
@@ -2082,7 +2082,7 @@ bool RenderViewContextMenu::IsCommandIdEnabled(int id)
     case IDC_CHECK_SPELLING_WHILE_TYPING:
       return prefs->GetBoolean(spellcheck::prefs::kSpellCheckEnable);
 
-#if !defined(OS_MACOSX) && defined(OS_POSIX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD) && defined(OS_POSIX)
     // TODO(suzhe): this should not be enabled for password fields.
     case IDC_INPUT_METHODS_MENU:
       return true;
