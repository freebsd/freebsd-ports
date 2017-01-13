--- libxml++/io/istreamparserinputbuffer.cc.orig	2010-12-15 10:41:27 UTC
+++ libxml++/io/istreamparserinputbuffer.cc
@@ -39,6 +39,6 @@ namespace xmlpp
 
   bool IStreamParserInputBuffer::do_close()
   {
-    return input_;
+    return bool(input_);
   }
 }
