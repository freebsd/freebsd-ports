--- ./src/imageprovider.cpp~	Thu Dec 15 21:02:14 2005
+++ ./src/imageprovider.cpp	Sat Dec 24 16:18:17 2005
@@ -40,11 +40,14 @@
 void imageprovider::shrinkcache(int free)
   {
   int keep=maxcachedframes;
-  if (free>0)
-    keep-=free;
+  if (free<0)
+    return;
+  if (keep<free)
+    free=keep-1;
+  keep-=free;
 
   std::list<framecacheitem>::iterator it=framecache.begin();
   for(int i=0;i<keep&&it!=framecache.end();++it,++i)
     ;
 
   while(it!=framecache.end())
