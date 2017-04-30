--- chrome/browser/renderer_context_menu/render_view_context_menu.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/renderer_context_menu/render_view_context_menu.cc
@@ -1390,7 +1390,7 @@ void RenderViewContextMenu::AppendEditab
 // 'Undo' and 'Redo' for text input with no suggestions and no text selected.
 // We make an exception for OS X as context clicking will select the closest
 // word. In this case both items are always shown.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_UNDO,
                                   IDS_CONTENT_CONTEXT_UNDO);
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_REDO,
@@ -1428,7 +1428,7 @@ void RenderViewContextMenu::AppendLangua
   if (!use_spelling)
     return;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_LANGUAGE_SETTINGS,
                                   IDS_CONTENT_CONTEXT_LANGUAGE_SETTINGS);
 #else
@@ -1666,7 +1666,7 @@ bool RenderViewContextMenu::IsCommandIdE
     case IDC_CHECK_SPELLING_WHILE_TYPING:
       return prefs->GetBoolean(spellcheck::prefs::kEnableSpellcheck);
 
-#if !defined(OS_MACOSX) && defined(OS_POSIX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD) && defined(OS_POSIX)
     // TODO(suzhe): this should not be enabled for password fields.
     case IDC_INPUT_METHODS_MENU:
       return true;
