--- core/PdfFile/PdfEditor.cpp.orig	2025-06-17 15:35:44 UTC
+++ core/PdfFile/PdfEditor.cpp
@@ -1391,7 +1391,7 @@ bool CPdfEditor::EditPage(int _nPageIndex, bool bSet, 
 	PDFDoc* pPDFDocument = NULL;
 	int nPageIndex = m_pReader->GetPageIndex(_nPageIndex, &pPDFDocument);
 	if (nPageIndex < 0 || !pPDFDocument)
-		return NULL;
+		return 0;
 
 	PdfWriter::CDocument* pDoc = m_pWriter->GetDocument();
 	if (!pPDFDocument || !pDoc)
