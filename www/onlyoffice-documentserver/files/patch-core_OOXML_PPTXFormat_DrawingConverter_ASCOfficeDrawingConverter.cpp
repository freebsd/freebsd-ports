--- core/OOXML/PPTXFormat/DrawingConverter/ASCOfficeDrawingConverter.cpp.orig	2023-06-14 14:39:19 UTC
+++ core/OOXML/PPTXFormat/DrawingConverter/ASCOfficeDrawingConverter.cpp
@@ -1953,11 +1953,11 @@ bool CDrawingConverter::ParceObject(const std::wstring
 {
 	XmlUtils::CXmlNode oMainNode;
 	if (!oMainNode.FromXmlString(strXml))
-		return NULL;
+		return 0;
 
 	std::vector<XmlUtils::CXmlNode> oNodes;
     if (!oMainNode.GetNodes(L"*", oNodes))
-		return NULL;
+		return 0;
 
 	m_pBinaryWriter->StartRecord(0);
 	m_pBinaryWriter->ClearCurShapePositionAndSizes();
