--- src/psfile.cpp~	Sun Dec 11 21:10:46 2005
+++ src/psfile.cpp	Mon Apr  9 16:55:43 2007
@@ -139,7 +139,7 @@
     if (bytes<minbytes) {
       sh.fileposition+=skipped;
       skipped=0;
-      bytes=buf.providedata(4<<10,sh.fileposition);
+      bytes=buf.providedata(minbytes,sh.fileposition);
       if (bytes<0)
         return bytes;
       if (bytes<minbytes)
@@ -197,7 +197,9 @@
       skipped=0;
 
       int payloadbegin=data[8]+9;
-      if (sid&0x300)
+      if (sid >= 0x180 && sid <= 0x187)	// ac3audio
+	payloadbegin += 4;
+      else if (sid&0x300)
         ++payloadbegin;
       else if (sid&0xf0==0xe0) {
         if ( *(uint32_t*)(data+payloadbegin)==mbo32(0x00000001) )
