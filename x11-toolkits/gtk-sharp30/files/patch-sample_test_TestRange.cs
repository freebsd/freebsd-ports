--- sample/test/TestRange.cs.orig	2013-08-18 15:32:57 UTC
+++ sample/test/TestRange.cs
@@ -57,7 +57,7 @@ namespace WidgetViewer {
 			vscale.SetSizeRequest (-1, 200);
 			vscale.Digits = 2;
 			vscale.DrawValue = true;
-			((Range) vscale).Inverted = true;
+			((Gtk.Range) vscale).Inverted = true;
 			hbox.PackStart (vscale, true, true, 0);
 
 			vscale = new VScale (adjustment);
