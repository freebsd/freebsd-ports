--- libxml++/io/ostreamoutputbuffer.cc.orig	2010-12-15 10:41:27 UTC
+++ libxml++/io/ostreamoutputbuffer.cc
@@ -29,13 +29,13 @@ namespace xmlpp
     // here we rely on the ostream implicit conversion to boolean, to know if the stream can be used and/or if the write succeded.
     if(output_)
       output_.write(buffer, len);
-    return output_;
+    return bool(output_);
   }
 
   bool OStreamOutputBuffer::do_close()
   {
     if(output_)
         output_.flush();
-    return output_;
+    return bool(output_);
   }
 }
