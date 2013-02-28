--- plugins/VOIP/VOIP.pro.orig	2012-10-29 11:31:20.931921695 +0100
+++ plugins/VOIP/VOIP.pro	2012-10-29 12:17:47.694925531 +0100
@@ -9,7 +9,7 @@
 QT_VER_MAJ = $$member(QT_VERSION, 0)
 QT_VER_MIN = $$member(QT_VERSION, 1)
  
-lessThan(QT_VER_MAJ, 4) | lessThan(QT_VER_MIN, 7) | win32 {
+lessThan(QT_VER_MAJ, 4) | lessThan(QT_VER_MIN, 7) | win32 | freebsd-* {
    QT += multimedia
 }
 
