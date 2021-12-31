--- LANDrop/LANDrop.pro.orig	2021-12-30 18:09:20 UTC
+++ LANDrop/LANDrop.pro
@@ -73,8 +73,8 @@ unix {
     desktop.files = $$OUT_PWD/landrop.desktop
     desktop.extra = \
         cp "$$PWD/../misc/LANDrop.desktop" "$$OUT_PWD/landrop.desktop" && \
-        sed -i 's/Exec=LANDrop/Exec=landrop/g' "$$OUT_PWD/landrop.desktop" && \
-        sed -i 's/Icon=LANDrop/Icon=landrop/g' "$$OUT_PWD/landrop.desktop"
+        sed -i.bak 's/Exec=LANDrop/Exec=landrop/g' "$$OUT_PWD/landrop.desktop" && \
+        sed -i.bak 's/Icon=LANDrop/Icon=landrop/g' "$$OUT_PWD/landrop.desktop"
     desktop.CONFIG = no_check_exist 
 
     INSTALLS += binary icon desktop
