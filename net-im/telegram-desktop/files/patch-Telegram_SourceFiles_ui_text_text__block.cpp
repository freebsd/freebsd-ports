--- Telegram/SourceFiles/ui/text/text_block.cpp.orig	2019-09-06 13:41:43 UTC
+++ Telegram/SourceFiles/ui/text/text_block.cpp
@@ -337,6 +337,9 @@ TextBlock::TextBlock(const style::font &font, const QS
 
 		QStackTextEngine engine(part, blockFont->f);
 		BlockParser parser(&engine, this, minResizeWidth, _from, part);
+		QTextLayout layout(part, blockFont->f);
+		layout.beginLayout();
+		layout.createLine();
 
 		CrashReports::ClearAnnotationRef("CrashString");
 	}
