--- src/FXGZStream.cpp.orig	2012-10-03 10:13:33.000000000 +0200
+++ src/FXGZStream.cpp	2012-10-03 10:15:57.000000000 +0200
@@ -60,7 +60,7 @@
   FXASSERT(wrptr<=endptr);
   if(code==FXStreamOK){
     m=wrptr-rdptr;
-    n=gzwrite((gzFile*)file,rdptr,m);
+    n=gzwrite((gzFile)file,rdptr,m);
     if(0<n){
       m-=n;
       if(m){memmove(begptr,rdptr+n,m);}
@@ -85,7 +85,7 @@
     if(m){memmove(begptr,rdptr,m);}
     rdptr=begptr;
     wrptr=begptr+m;
-    n=gzread((gzFile*)file,wrptr,endptr-wrptr);
+    n=gzread((gzFile)file,wrptr,endptr-wrptr);
     if(0<n){
       wrptr+=n;
       }
@@ -117,7 +117,7 @@
 FXbool FXGZFileStream::close(){
   if(dir){
     if(dir==FXStreamSave) flush();
-    gzclose((gzFile*)file);
+    gzclose((gzFile)file);
     return FXStream::close();
     }
   return FALSE;
