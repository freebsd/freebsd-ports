--- src/DirPanel.cc.orig	Wed Apr 27 20:08:40 2005
+++ src/DirPanel.cc	Wed Apr 27 20:02:33 2005
@@ -76,8 +76,10 @@ FXDEFMAP(DirPanel) DirPanelMap[]={
                                    FXMAPFUNC(SEL_COMMAND,DirPanel::ID_TOGGLE_HIDDEN,DirPanel::onCmdToggleHidden),
                                    FXMAPFUNC(SEL_COMMAND,DirPanel::ID_TOGGLE_TREE,DirPanel::onCmdToggleTree),
                                    FXMAPFUNC(SEL_UPDATE,DirPanel::ID_TOGGLE_TREE,DirPanel::onUpdToggleTree),
+#if defined(linux)
                                	   FXMAPFUNC(SEL_UPDATE,DirPanel::ID_MOUNT,DirPanel::onUpdMount),
                                    FXMAPFUNC(SEL_UPDATE,DirPanel::ID_UMOUNT,DirPanel::onUpdUnmount),
+#endif								   
                                    FXMAPFUNC(SEL_UPDATE,DirPanel::ID_STATUS,DirPanel::onUpdStatus),
                           		};
 
@@ -798,7 +800,6 @@ long DirPanel::onCmdMount(FXObject*,FXSe
 
     return 1;
 }
-#endif
 
 // Update the Mount menu item
 long DirPanel::onUpdMount(FXObject* o,FXSelector sel,void*)
@@ -838,6 +839,7 @@ long DirPanel::onUpdUnmount(FXObject* o,
 
     return 1;
 }
+#endif
 
 
 // Update the paste button and menus
