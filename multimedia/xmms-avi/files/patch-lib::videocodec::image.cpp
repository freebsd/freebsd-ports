--- lib/videocodec/image.cpp.orig	Sun Jan 28 02:46:37 2001
+++ lib/videocodec/image.cpp	Sun Dec  7 02:30:26 2003
@@ -27,7 +27,7 @@
     _width=abs(_info->biWidth);
     _height=abs(_info->biHeight);
 }
-CImage::CImage(const BitmapInfo* header, unsigned char* data=0, bool copy=true)
+CImage::CImage(const BitmapInfo* header, unsigned char* data, bool copy)
     :_info(new BitmapInfo(header)),_refcount(1)
 {
     fill_members();
@@ -57,7 +57,7 @@
     register_image();
 }
 
-CImage::CImage(const CImage* im, int depth=-1)
+CImage::CImage(const CImage* im, int depth)
     :_info(new BitmapInfo(im->get_fmt())), _refcount(1)
 {
     if(depth!=-1)
@@ -208,7 +208,7 @@
 {
 	return (int(b)<<16)+(int(g)<<8)+int(r);
 }
-void CImage::ToYUV(int destfmt=0)
+void CImage::ToYUV(int destfmt)
 {
     struct yuv* src;
     src=(struct yuv*)_data+_width*_height-1;
@@ -431,7 +431,7 @@
 		return;    
 	    }
     }
-    cerr<<"Unsupported"<<endl;
+    std::cerr<<"Unsupported"<< std::endl;
 }
 BitmapInfo* CImage::get_fmt(){return _info;}
 const BitmapInfo* CImage::get_fmt() const{return _info;}
