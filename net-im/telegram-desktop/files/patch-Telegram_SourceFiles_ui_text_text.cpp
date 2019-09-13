--- Telegram/SourceFiles/ui/text/text.cpp.orig	2019-09-06 13:41:43 UTC
+++ Telegram/SourceFiles/ui/text/text.cpp
@@ -2018,11 +2018,11 @@ class Renderer { (private)
 		if (item == -1)
 			return;
 
-#ifdef OS_MAC_OLD
+#if defined(OS_MAC_OLD) || QT_VERSION < QT_VERSION_CHECK(5, 6, 0)
 		auto end = _e->findItem(line.from + line.length - 1);
-#else // OS_MAC_OLD
+#else
 		auto end = _e->findItem(line.from + line.length - 1, item);
-#endif // OS_MAC_OLD
+#endif
 
 		auto blockIndex = _lineStartBlock;
 		auto currentBlock = _t->_blocks[blockIndex].get();
