--- src/imageprovider.h~	Wed Dec 28 20:37:37 2005
+++ src/imageprovider.h	Wed Dec 28 20:59:23 2005
@@ -47,7 +47,7 @@
   virtual void decodepicture(int picture, bool decodeallgop=false);
   
 public:
-  imageprovider(mpgfile &mpg, busyindicator *bi=0, bool unscaled=false, int factor=1, int cachesize=50);
+  imageprovider(mpgfile &mpg, busyindicator *bi=0, bool unscaled=false, int factor=1, int cachesize=8);
   virtual ~imageprovider();
   int rtti() const
     {
