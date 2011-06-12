
$FreeBSD$

--- src/PdfMod/Gui/DocumentIconView.cs.orig
+++ src/PdfMod/Gui/DocumentIconView.cs
@@ -319,7 +319,7 @@
                 if (to_index < 0)
                     return;
 
-                var pages = args.SelectionData.Data as Hyena.Gui.DragDropList<Page>;
+                Hyena.Gui.DragDropList<Page> pages = args.SelectionData;
                 to_index -= pages.Count (p => p.Index < to_index);
                 var action = new MoveAction (document, pages, to_index);
                 action.Do ();
