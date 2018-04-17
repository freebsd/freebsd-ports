--- Telegram/SourceFiles/ui/text/text_block.cpp.orig	2018-04-08 17:34:33 UTC
+++ Telegram/SourceFiles/ui/text/text_block.cpp
@@ -332,6 +332,9 @@ TextBlock::TextBlock(const style::font &
 
 		QStackTextEngine engine(part, blockFont->f);
 		BlockParser parser(&engine, this, minResizeWidth, _from, part);
+		QTextLayout layout(part, blockFont->f);
+		layout.beginLayout();
+		layout.createLine();
 
 		CrashReports::ClearAnnotationRef("CrashString");
 	}
