--- include/infotypes.h.orig	Mon Dec 18 17:46:08 2000
+++ include/infotypes.h	Sun Dec  7 02:30:26 2003
@@ -40,13 +40,13 @@
     std::string dll;
     enum Kind {Win32, Source, Plugin, DShow_Dec};
     Kind kind;
-    vector<AttributeInfo> decoder_info;
-    vector<AttributeInfo> encoder_info;
+    std::vector<AttributeInfo> decoder_info;
+    std::vector<AttributeInfo> encoder_info;
     GUID* guid;
     CodecInfo(){}
     CodecInfo(int* array, const char* info, const char* path, const char* a,
-     Kind _kind, GUID* id=0, const vector<AttributeInfo>& ei=vector<AttributeInfo>(), 
-     const vector<AttributeInfo>& di=vector<AttributeInfo>())
+	      Kind _kind, GUID* id=0, const std::vector<AttributeInfo>& ei=std::vector<AttributeInfo>(), 
+	      const std::vector<AttributeInfo>& di=std::vector<AttributeInfo>())
 	:kind(_kind), dll(path), text(info), about(a), fourcc(array[0]), decoder_info(di), encoder_info(ei), guid(id)
     {
 	if(!*array) // uncompressed codec
