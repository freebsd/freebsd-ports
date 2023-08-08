--- core/OOXML/PPTXFormat/DrawingConverter/ASCOfficeDrawingConverter.cpp.orig	2023-06-14 14:39:19.258894000 +0200
+++ core/OOXML/PPTXFormat/DrawingConverter/ASCOfficeDrawingConverter.cpp	2023-06-14 14:49:20.247098000 +0200
@@ -1928,11 +1928,11 @@ bool CDrawingConverter::ParceObject(const std::wstring
 {
 	XmlUtils::CXmlNode oMainNode;
 	if (!oMainNode.FromXmlString(strXml))
-		return NULL;
+		return 0;
 
 	XmlUtils::CXmlNodes oNodes;
     if (!oMainNode.GetNodes(L"*", oNodes))
-		return NULL;
+		return 0;
 
 	m_pBinaryWriter->StartRecord(0);
 	m_pBinaryWriter->ClearCurShapePositionAndSizes();
