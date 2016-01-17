--- src/FilePanel.cpp.orig	2016-01-14 08:35:03 UTC
+++ src/FilePanel.cpp
@@ -124,7 +124,7 @@ FXDEFMAP(FilePanel) FilePanelMap[] =
     FXMAPFUNC(SEL_COMMAND, FilePanel::ID_RUN_SCRIPT, FilePanel::onCmdRunScript),
     FXMAPFUNC(SEL_UPDATE, FilePanel::ID_RUN_SCRIPT, FilePanel::onUpdRunScript),
     FXMAPFUNC(SEL_COMMAND, FilePanel::ID_GO_SCRIPTDIR, FilePanel::onCmdGoScriptDir),
-    FXMAPFUNC(SEL_COMMAND, FilePanel::ID_DIR_USAGE, FilePanel::onCmdDirUsage),
+    //FXMAPFUNC(SEL_COMMAND, FilePanel::ID_DIR_USAGE, FilePanel::onCmdDirUsage),
     FXMAPFUNC(SEL_RIGHTBUTTONRELEASE, FilePanel::ID_FILELIST, FilePanel::onCmdPopupMenu),
     FXMAPFUNC(SEL_COMMAND, FilePanel::ID_POPUP_MENU, FilePanel::onCmdPopupMenu),
     FXMAPFUNC(SEL_DOUBLECLICKED, FilePanel::ID_FILELIST, FilePanel::onCmdItemDoubleClicked),
