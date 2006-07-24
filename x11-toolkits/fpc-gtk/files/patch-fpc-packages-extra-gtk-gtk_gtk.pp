--- packages/extra/gtk/gtk/gtk.pp	Sat Jul 15 12:40:22 2006
+++ packages/extra/gtk/gtk/gtk.pp	Sat Jul 15 12:40:36 2006
@@ -49,8 +49,8 @@
   {$else}
     const
     {$ifdef FreeBSD}
-      gtkdll='gtk12';
-      {$linklib gtk12}
+      gtkdll='gtk-12';
+      {$linklib gtk-12}
     {$else}
     {$ifdef darwin}
       {$define gtkdarwin}
