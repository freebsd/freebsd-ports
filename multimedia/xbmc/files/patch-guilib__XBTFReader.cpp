--- ./guilib/XBTFReader.cpp.orig	2010-02-14 19:20:07.000000000 +0100
+++ ./guilib/XBTFReader.cpp	2010-12-01 12:17:34.289131542 +0100
@@ -187,7 +187,7 @@
   {
     return false;
   }
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
     if (fseeko(m_file, (off_t)frame.GetOffset(), SEEK_SET) == -1)
 #else
     if (fseeko64(m_file, (off_t)frame.GetOffset(), SEEK_SET) == -1)
