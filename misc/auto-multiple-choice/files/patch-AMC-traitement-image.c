--- ./AMC-traitement-image.c.orig	2013-07-28 22:22:29.000000000 +0900
+++ ./AMC-traitement-image.c	2014-04-16 17:44:03.000000000 +0900
@@ -218,6 +218,22 @@
   printf("CC %d %d\n",n,imax);
 }
 
+#define deplace(_i,_j) \
+  do { \
+    int i = _i, j = _j; \
+    coins[i].x+=delta*(coins[j].x-coins[i].x); \
+    coins[i].y+=delta*(coins[j].y-coins[i].y); \
+  } while (0)
+
+#define restreint(_x,_y) \
+  do { \
+    int *x = _x, *y = _y; \
+    if(*x<0) *x=0; \
+    if(*y<0) *y=0; \
+    if(*x>=tx) *x=tx-1; \
+    if(*y>=ty) *y=ty-1; \
+  } while (0)
+
 void mesure_case(pixel **img,int tx,int ty,pixval maxval,
 		 double prop,point *coins) {
   int npix,npixnoir,xmin,xmax,ymin,ymax,x,y;
@@ -225,18 +241,6 @@
   int i,ok;
   double delta;
 
-  void deplace(int i,int j) {
-    coins[i].x+=delta*(coins[j].x-coins[i].x);
-    coins[i].y+=delta*(coins[j].y-coins[i].y);
-  }
-
-  void restreint(int *x,int *y) {
-    if(*x<0) *x=0;
-    if(*y<0) *y=0;
-    if(*x>=tx) *x=tx-1;
-    if(*y>=ty) *y=ty-1;
-  }
-
   npix=0;
   npixnoir=0;
   xmin=tx-1;
@@ -292,47 +296,48 @@
   int xmin,xmax,ymin,ymax;
 } infocol;
 
-void repere_magick(pixel **img,int tx,int ty,pixval maxval) {
-  infocol *infos;
-
-  int ninfo,ninfo_alloc;
-  int i,x,y,red;
-  int en_couleur;
+int trouve_id(int magick,int exo,int quest,infocol **infos_p,int *ninfo_p,int *ninfo_alloc_p) {
+  int i,ii;
+  ii=-1;
+  for(i=0;i<*ninfo_p;i++) {
+    if((*infos_p)[i].magick==magick 
+       && (*infos_p)[i].exo==exo && (*infos_p)[i].quest==quest) ii=i;
+  }
+  if(ii<0) {
+    ii=*ninfo_p;
 
-  int trouve_id(int magick,int exo,int quest) {
-    int i,ii;
-    ii=-1;
-    for(i=0;i<ninfo;i++) {
-      if(infos[i].magick==magick 
-	 && infos[i].exo==exo && infos[i].quest==quest) ii=i;
+    if(*ninfo_alloc_p<ii+1) {
+      *ninfo_alloc_p+=INFO_BLOC;
+      *infos_p=(infocol*)realloc(*infos_p,*ninfo_alloc_p*sizeof(infocol));
     }
-    if(ii<0) {
-      ii=ninfo;
 
-      if(ninfo_alloc<ii+1) {
-	ninfo_alloc+=INFO_BLOC;
-	infos=(infocol*)realloc(infos,ninfo_alloc*sizeof(infocol));
-      }
-
-      infos[ii].magick=magick;
-      infos[ii].exo=exo;
-      infos[ii].quest=quest;
-      infos[ii].xmin=100000;
-      infos[ii].ymin=100000;
-      infos[ii].xmax=-1;
-      infos[ii].ymax=-1;
-      ninfo++;
-    }
-    return(ii);
+    (*infos_p)[ii].magick=magick;
+    (*infos_p)[ii].exo=exo;
+    (*infos_p)[ii].quest=quest;
+    (*infos_p)[ii].xmin=100000;
+    (*infos_p)[ii].ymin=100000;
+    (*infos_p)[ii].xmax=-1;
+    (*infos_p)[ii].ymax=-1;
+    (*ninfo_p)++;
   }
+  return(ii);
+}
 
-  void ajoute(int id,int x,int y) {
-    if(x > infos[id].xmax) infos[id].xmax=x;
-    if(x < infos[id].xmin) infos[id].xmin=x;
-    if(y > infos[id].ymax) infos[id].ymax=y;
-    if(y < infos[id].ymin) infos[id].ymin=y;
-  }
+#define ajoute(_id,_x,_y) \
+  do { \
+    int id = _id, x = _x, y = _y; \
+    if(x > infos[id].xmax) infos[id].xmax=x; \
+    if(x < infos[id].xmin) infos[id].xmin=x; \
+    if(y > infos[id].ymax) infos[id].ymax=y; \
+    if(y < infos[id].ymin) infos[id].ymin=y; \
+  } while (0)
+
+void repere_magick(pixel **img,int tx,int ty,pixval maxval) {
+  infocol *infos;
 
+  int ninfo,ninfo_alloc;
+  int i,x,y,red;
+  int en_couleur;
 
   infos=NULL;
   ninfo_alloc=0;
@@ -347,7 +352,7 @@
 	if(red!=PPM_GETG(img[y][x])) en_couleur=1;
 	if(red!=PPM_GETB(img[y][x])) en_couleur=1;
 	if(en_couleur)
-	  ajoute(trouve_id(red,PPM_GETG(img[y][x]),PPM_GETB(img[y][x])),x,y);
+	  ajoute(trouve_id(red,PPM_GETG(img[y][x]),PPM_GETB(img[y][x]),&infos,&ninfo,&ninfo_alloc),x,y);
       }
     }
   }
