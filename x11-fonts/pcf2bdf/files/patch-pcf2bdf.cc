--- pcf2bdf.cc.orig	Mon Oct 21 01:35:29 2002
+++ pcf2bdf.cc	Mon Jan 20 23:11:46 2003
@@ -577,7 +577,7 @@
   }
   if (ifilename)
   {
-    ifp = fopen(ifilename, "rb");
+    ifp = fopen(ifilename, "r");
     if (!ifp)
       return error_exit("failed to open input pcf file");
   }
@@ -595,7 +595,7 @@
     fclose(ifp);
     char buf[1024];
     sprintf(buf, "gzip -dc %s", ifilename); // TODO
-    ifp = popen(buf, "rb");
+    ifp = popen(buf, "r");
     _setmode(fileno(ifp), O_BINARY);
     read_bytes = 0;
     if (!ifp)
@@ -604,7 +604,7 @@
   
   if (ofilename)
   {
-    ofp = fopen(ofilename, "wb");
+    ofp = fopen(ofilename, "w");
     if (!ofp)
       return error_exit("failed to open output bdf file");
   }
