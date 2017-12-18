--- Telegram/SourceFiles/ui/text/text_block.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/ui/text/text_block.cpp
@@ -330,7 +330,7 @@ TextBlock::TextBlock(const style::font &
 		SignalHandlers::setCrashAnnotationRef("CrashString", &part);
 
 		QStackTextEngine engine(part, blockFont->f);
-		QTextLayout layout(&engine);
+		QTextLayout layout(part, blockFont->f);
 		layout.beginLayout();
 		layout.createLine();
 
