--- file.h.orig	2013-03-16 09:40:32.000000000 +0400
+++ file.h	2013-03-16 09:41:06.000000000 +0400
@@ -12,6 +12,8 @@
  * Author: John Whitney <jjw@deltup.org>
  */
 
+#include <zlib.h>
+
 class IStream {
 public:
   virtual unsigned read(void *data, unsigned num) = 0;
@@ -56,7 +58,7 @@
 };
 
 class GZ_IFStream : public IStream {
-  void *file;
+  gzFile file;
 public:
   GZ_IFStream(string fname);
   virtual ~GZ_IFStream();
@@ -65,7 +67,7 @@
 };
 
 class GZ_OFStream : public OStream {
-  void *file;
+  gzFile file;
 public:
   GZ_OFStream(string fname);
   virtual ~GZ_OFStream();
