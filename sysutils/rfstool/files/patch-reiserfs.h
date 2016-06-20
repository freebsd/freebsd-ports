--- reiserfs.h.orig	2016-06-20 13:19:25 UTC
+++ reiserfs.h
@@ -268,7 +268,7 @@ class ReiserFsBlock : public PNode
         {
         }
 
-        ReiserFsBlock::~ReiserFsBlock()
+        ~ReiserFsBlock()
         {
             delete m_lpbMemory;
         }
