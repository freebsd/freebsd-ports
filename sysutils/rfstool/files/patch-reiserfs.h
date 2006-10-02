--- reiserfs.h.orig	Mon Oct  2 13:58:35 2006
+++ reiserfs.h	Mon Oct  2 13:58:39 2006
@@ -268,7 +268,7 @@
         {
         }
 
-        ReiserFsBlock::~ReiserFsBlock()
+        ~ReiserFsBlock()
         {
             delete m_lpbMemory;
         }
