--- pagespeed/kernel/image/test_utils.cc.orig	2017-10-06 17:27:24 UTC
+++ pagespeed/kernel/image/test_utils.cc
@@ -168,8 +168,8 @@ void DecodeAndCompareImagesByPSNR(
 
 void CompareImageReaders(ScanlineReaderInterface* reader1,
                          ScanlineReaderInterface* reader2) {
-  ASSERT_NE(reinterpret_cast<ScanlineReaderInterface*>(NULL), reader1);
-  ASSERT_NE(reinterpret_cast<ScanlineReaderInterface*>(NULL), reader2);
+  ASSERT_NE(reinterpret_cast<ScanlineReaderInterface*>((void *)NULL), reader1);
+  ASSERT_NE(reinterpret_cast<ScanlineReaderInterface*>((void *)NULL), reader2);
   ASSERT_EQ(reader1->GetPixelFormat(), reader2->GetPixelFormat());
   ASSERT_EQ(reader1->GetImageHeight(), reader2->GetImageHeight());
   ASSERT_EQ(reader1->GetImageWidth(), reader2->GetImageWidth());
