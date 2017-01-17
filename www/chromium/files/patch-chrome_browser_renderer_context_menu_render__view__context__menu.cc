--- chrome/browser/renderer_context_menu/render_view_context_menu.cc.orig	2016-12-18 00:37:45.100012000 +0100
+++ chrome/browser/renderer_context_menu/render_view_context_menu.cc	2016-12-18 00:42:54.851203000 +0100
@@ -1325,7 +1325,7 @@
 // 'Undo' and 'Redo' for text input with no suggestions and no text selected.
 // We make an exception for OS X as context clicking will select the closest
 // word. In this case both items are always shown.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_UNDO,
                                   IDS_CONTENT_CONTEXT_UNDO);
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_REDO,
@@ -1361,7 +1361,7 @@
   if (!use_spelling)
     return;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   menu_model_.AddItemWithStringId(IDC_CONTENT_CONTEXT_LANGUAGE_SETTINGS,
                                   IDS_CONTENT_CONTEXT_LANGUAGE_SETTINGS);
 #else
@@ -1602,7 +1602,7 @@
     case IDC_CHECK_SPELLING_WHILE_TYPING:
       return prefs->GetBoolean(spellcheck::prefs::kEnableSpellcheck);
 
-#if !defined(OS_MACOSX) && defined(OS_POSIX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD) && defined(OS_POSIX)
     // TODO(suzhe): this should not be enabled for password fields.
     case IDC_INPUT_METHODS_MENU:
       return true;
