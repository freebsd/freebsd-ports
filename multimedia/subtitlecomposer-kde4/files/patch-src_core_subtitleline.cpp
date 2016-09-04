--- src/core/subtitleline.cpp.orig	2014-09-26 10:33:30 UTC
+++ src/core/subtitleline.cpp
@@ -53,7 +53,7 @@ SubtitleLine::errorID(SubtitleLine::Erro
 	if(flag < 1)
 		return ErrorUNKNOWN;
 
-	int id = (int)log2(flag);
+	int id = (int)log2((double)flag);
 	return id < ErrorSIZE ? (ErrorID)id : ErrorUNKNOWN;
 }
 
