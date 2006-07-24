--- packages/extra/gtk/glib/glib.pp	Sat Jul 15 12:26:06 2006
+++ packages/extra/gtk/glib/glib.pp	Sat Jul 15 12:27:13 2006
@@ -45,8 +45,8 @@
   {$else}
     const
      {$ifdef FreeBSD}
-      glibdll='glib12';
-      {$linklib glib12}
+      glibdll='glib-12';
+      {$linklib glib-12}
      {$else}
      {$ifdef darwin}
       glibdll='glib-1.2.0';
