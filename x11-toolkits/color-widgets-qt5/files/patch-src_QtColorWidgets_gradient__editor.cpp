--- src/QtColorWidgets/gradient_editor.cpp.orig	2020-05-31 15:42:28 UTC
+++ src/QtColorWidgets/gradient_editor.cpp
@@ -221,7 +221,10 @@ void GradientEditor::mouseDoubleClickEvent(QMouseEvent
             qreal highlighted_pos = p->paint_pos(p->stops[p->highlighted], this);
             qreal mouse_pos = orientation() == Qt::Vertical ? ev->pos().y() : ev->pos().x();
             qreal tolerance = 4;
-            if ( std::abs(mouse_pos - highlighted_pos) <= tolerance )
+            auto xfabs = [](qreal r) { // see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=248190
+                return r>=0 ? r : -r;
+            };
+            if ( xfabs(mouse_pos - highlighted_pos) <= tolerance )
             {
                 p->dialog_selected = p->highlighted;
                 p->color_dialog.setColor(p->stops[p->highlighted].second);
