--- pcf2bdf.cc.orig	2015-05-18 02:55:57 UTC
+++ pcf2bdf.cc
@@ -580,7 +580,7 @@ int main(int argc, char *argv[])
   }
   if (ifilename)
   {
-    ifp = fopen(ifilename, "rb");
+    ifp = fopen(ifilename, "r");
     if (!ifp)
       return error_exit("failed to open input pcf file");
   }
@@ -607,7 +607,7 @@ int main(int argc, char *argv[])
 
   if (ofilename)
   {
-    ofp = fopen(ofilename, "wb");
+    ofp = fopen(ofilename, "w");
     if (!ofp)
       return error_exit("failed to open output bdf file");
   }
