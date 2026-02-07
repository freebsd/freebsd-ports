--- core/OOXML/Binary/Presentation/Converter.cpp.orig	2023-02-13 16:17:44 UTC
+++ core/OOXML/Binary/Presentation/Converter.cpp
@@ -203,7 +203,7 @@ namespace PPTX2EditorAdvanced
 			// проверяем note
 			size_t pPointerN = (size_t)(slide->Note.operator ->());
 			LONG nNoteIndex = -1;
-			if (NULL != pPointerN)
+			if (0 != pPointerN)
 			{
 				std::map<size_t, LONG>::const_iterator pSearchN = pCommon->notes.find(pPointerN);
 				if (pSearchN == pCommon->notes.end())
