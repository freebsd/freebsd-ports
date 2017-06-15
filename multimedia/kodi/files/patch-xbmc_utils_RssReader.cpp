Fix bogus pointer comparisons.

--- xbmc/utils/RssReader.cpp.orig	2017-01-21 21:11:51 UTC
+++ xbmc/utils/RssReader.cpp
@@ -266,11 +266,11 @@ void CRssReader::GetNewsItems(TiXmlEleme
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
 
