--- codec/encoder-jpeg.cpp.orig	Thu Jan 23 18:22:29 2003
+++ codec/encoder-jpeg.cpp	Thu Jan 23 18:22:37 2003
@@ -127,12 +127,12 @@
     void size(int w, int h);
     int consume(const VideoFrame*);
 
-  protected:
     struct huffentry {
 	u_short val;
 	u_short nb;
     };
 
+  protected:
     int command(int argc, const char*const* argv);
 
     int flush(pktbuf* pb, int nbit, pktbuf* npb);
