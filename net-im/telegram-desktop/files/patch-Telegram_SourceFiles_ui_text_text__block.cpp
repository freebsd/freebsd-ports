--- Telegram/SourceFiles/ui/text/text_block.cpp.orig	2019-07-07 13:34:35 UTC
+++ Telegram/SourceFiles/ui/text/text_block.cpp
@@ -335,6 +335,9 @@ TextBlock::TextBlock(const style::font &font, const QS
 
 		QStackTextEngine engine(part, blockFont->f);
 		BlockParser parser(&engine, this, minResizeWidth, _from, part);
+		QTextLayout layout(part, blockFont->f);
+		layout.beginLayout();
+		layout.createLine();
 
 		CrashReports::ClearAnnotationRef("CrashString");
 	}
