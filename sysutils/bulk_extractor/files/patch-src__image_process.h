--- ./src/image_process.h.orig	2014-01-15 15:00:06.000000000 +0000
+++ ./src/image_process.h	2014-06-09 14:15:54.000000000 +0000
@@ -128,7 +128,7 @@
     virtual int open()=0;				    /* open; return 0 if successful */
     virtual int pread(uint8_t *,size_t bytes,int64_t offset) const =0;	    /* read */
     virtual int64_t image_size() const=0;
-    virtual std::string image_fname() const { return image_fname_;}
+    virtual const std::string &image_fname() const { return image_fname_;}
 
     /* iterator support; these virtual functions are called by iterator through (*myimage) */
     virtual image_process::iterator begin() const =0;
@@ -154,7 +154,7 @@
  ****************************************************************/
 
 #ifdef HAVE_LIBAFFLIB
-//#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
+#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
 #include <afflib/afflib.h>
 #include <vector>			
 class process_aff : public image_process {
