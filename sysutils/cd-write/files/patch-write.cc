--- write.cc.orig	Wed Oct 15 15:48:59 2003
+++ write.cc	Wed Oct 15 15:49:52 2003
@@ -97,11 +97,11 @@
 
     TkToplevel (".tray -class Dialog");
     TkWm ("title .tray", "{Open/Close tray}");
-    TkLabel (".tray.msg -wraplength 4i -justify center -text {
+    TkLabel (".tray.msg -wraplength 4i -justify center -text {\n\
  It is advised to open and close the tray if you already did a dummy write,\
  in order to avoid an End Of Medium error. \
  If you just inserted a blank in the drive click on the \"Continue\" button.\
- Click on the \"Open/CLose\" button to open and close the tray.
+ Click on the \"Open/CLose\" button to open and close the tray.\n\
 }");
     button = -1;
     TkPack (".tray.msg -side top -padx 1c -pady 1c");
@@ -693,12 +693,12 @@
     bsel = TkButton (".write.f.bs", "-text {Select >>>} -state disabled");
     bsel.command (mfilesel);
     TkFrame (".write.f.f");
-    hlist = tixScrolledHList (".write.f.f.l", "-relief flat -options {
-                    hlist.columns 4
-                    hlist.gap 0
-                    hlist.header  true
-                    hlist.selectMode single
-                    hlist.width 40 hlist.height 15
+    hlist = tixScrolledHList (".write.f.f.l", "-relief flat -options {\n\
+                    hlist.columns 4\n\
+                    hlist.gap 0\n\
+                    hlist.header  true\n\
+                    hlist.selectMode single\n\
+                    hlist.width 40 hlist.height 15\n\
              }");
     hlist.subwidget ("hlist")->browsecmd (hlistcmd); 
     bb = tixButtonBox (".write.f.f.b", "-relief flat -orientation horizontal -padx 0");
