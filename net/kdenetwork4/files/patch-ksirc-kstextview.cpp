--- ksirc/kstextview.cpp
+++ ksirc/kstextview.cpp
@@ -1954,9 +1954,5 @@ void TextView::contentsMouseReleaseEvent
     if (ev->button() & Qt::MidButton)
     {
-        QClipboard *cp = KApplication::clipboard();
-        bool restoreMode = cp->selectionModeEnabled();
-        cp->setSelectionMode(true);
-        emit pasteReq( cp->text() );
-        cp->setSelectionMode(restoreMode);
+        emit pasteReq( KApplication::clipboard()->text( QClipboard::Selection) );
         return;
     }
