--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2015-10-14 15:15:21.746018000 -0400
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp	2015-10-14 15:36:04.640922000 -0400
@@ -358,7 +358,11 @@
 {
     RefPtr<SharedBuffer> buffer;
 
+#if defined(__FreeBSD__)
+    SkFontTableTag tag = bswap32(table);
+#else
     SkFontTableTag tag = WTF::bswap32(table);
+#endif
     const size_t tableSize = m_typeface->getTableSize(tag);
     if (tableSize) {
         Vector<char> tableBuffer(tableSize);
