--- src/3rdparty/chromium/third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2017-04-11 14:26:52 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp
@@ -357,7 +357,7 @@ PassRefPtr<SharedBuffer> FontPlatformData::openTypeTab
 {
     RefPtr<SharedBuffer> buffer;
 
-    SkFontTableTag tag = WTF::bswap32(table);
+    SkFontTableTag tag = bswap32(table);
     const size_t tableSize = m_typeface->getTableSize(tag);
     if (tableSize) {
         Vector<char> tableBuffer(tableSize);
