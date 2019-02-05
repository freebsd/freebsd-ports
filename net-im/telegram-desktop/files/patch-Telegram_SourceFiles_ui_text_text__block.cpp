--- Telegram/SourceFiles/ui/text/text_block.cpp.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/ui/text/text_block.cpp
@@ -332,6 +332,9 @@ TextBlock::TextBlock(const style::font &font, const QS
 
 		QStackTextEngine engine(part, blockFont->f);
 		BlockParser parser(&engine, this, minResizeWidth, _from, part);
+		QTextLayout layout(part, blockFont->f);
+		layout.beginLayout();
+		layout.createLine();
 
 		CrashReports::ClearAnnotationRef("CrashString");
 	}
