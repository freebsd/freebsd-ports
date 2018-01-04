Fix bogus pointer comparisons.

--- xbmc/utils/RssReader.cpp.orig	2017-11-14 16:55:01 UTC
+++ xbmc/utils/RssReader.cpp
@@ -269,11 +269,11 @@ void CRssReader::GetNewsItems(TiXmlElement* channelXml
   if (m_tagSet.empty())
     AddTag("title");
 
-  while (itemNode > 0)
+  while (itemNode)
   {
     TiXmlNode* childNode = itemNode->FirstChild();
     mTagElements.clear();
-    while (childNode > 0)
+    while (childNode)
     {
       std::string strName = childNode->ValueStr();
 
