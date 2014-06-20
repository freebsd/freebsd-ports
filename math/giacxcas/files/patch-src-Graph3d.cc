--- src/Graph3d.cc.orig	2014-05-01 10:34:20.000000000 +0200
+++ src/Graph3d.cc	2014-05-01 10:22:33.000000000 +0200
@@ -582,7 +582,7 @@
   // surface without grid evaluation, should not happen!
   void glsurface(const vecteur & point,const gen & uv,double umin,double umax,double vmin,double vmax,int nu,int nv,int draw_mode,GIAC_CONTEXT){
     double u=umin,v=vmin,deltau=(umax-umin)/nu,deltav=(vmax-vmin)/nv;
-    gen prevline[nv+1];//,line[nv+1];
+    gen * prevline=new gen[nv+1];//,line[nv+1]; //cf clang
     vecteur curuv(2);
     gen old,current;
     curuv[0]=u;
@@ -615,6 +615,7 @@
 	cerr << endl;
       */
     }
+    delete [] prevline; //cf clang
   }
 
   unsigned int line_stipple(unsigned int i){
