--- src/audiodecoding/mp3/k3bmaddecoder.cpp.orig	Mon Sep  1 12:14:10 2003
+++ src/audiodecoding/mp3/k3bmaddecoder.cpp	Fri Nov  7 12:35:44 2003
@@ -37,6 +37,8 @@
 #include <stdlib.h>
 #include <cmath>
 #include <cstdlib>
+#include <sys/types.h>
+#include <sys/mman.h>
 
 #include <config.h>
 
@@ -716,23 +718,24 @@
     return false;
   }
 
-  // there seem to be mp3 files starting with a lot of zeros
-  // we try to skip these.
-  // there might still be files with more than bufLen zeros...
-  const int bufLen = 4096;
-  char buf[bufLen];
-  if( f.readBlock( buf, bufLen ) < bufLen ) {
-    kdDebug() << "(K3bMadDecoder) unable to read " << bufLen << " bytes from " << url.path() << endl;
+  // EXPERIMENTAL!!!!!!!!
+  
+  const int bufLen = f.size();
+  const char * buf = (const char *)mmap(0, bufLen, PROT_READ, MAP_SHARED, f.handle(), 0);
+  if (buf == MAP_FAILED)
+  {
+    kdDebug() << "(K3bMp3Module) unable to read from " << url.path() << endl;
     f.close();
     return false;
   }
-  f.close();
 
   // skip any 0
   int i = 0;
   while( i < bufLen && buf[i] == '\0' ) i++;
   if( i == bufLen ) {
     kdDebug() << "(K3bMadDecoder) only zeros found in the beginning of " << url.path() << endl;
+    munmap((void *)buf, bufLen);
+    f.close();
     return false;
   }
 
@@ -744,6 +747,8 @@
       ( (unsigned short)buf[i+3] < 0xff && (unsigned short)buf[i+4] < 0xff ) ) {
     kdDebug() << "(K3bMadDecoder) found id3 magic: ID3 " 
 	      << (unsigned short)buf[i+3] << "." << (unsigned short)buf[i+4] << endl;
+    munmap((void *)buf, bufLen);
+    f.close();
     return true;
   }
 
@@ -756,15 +761,22 @@
     short m = (short)( buf[i+20] | (buf[i+21]<<8) );
     if( m == 80 ) {
       kdDebug() << "(K3bMadDecoder) found RIFF MPEG magic." << endl;
+      munmap((void *)buf, bufLen);
+      f.close();
       return true;
     }
     else if( m == 85 ) {
       kdDebug() << "(K3bMadDecoder) found RIFF MPEG III magic." << endl;
+      munmap((void *)buf, bufLen);
+      f.close();
       return true;
     }
-    else
+    else {
+      munmap((void *)buf, bufLen);
+      f.close();
       return false;
   }
+  }
       
 
 
@@ -775,16 +787,41 @@
   mad_stream_init( &stream );
   mad_header_init( &header );
 
-  mad_stream_buffer( &stream, (unsigned char*)&buf[i], bufLen-i );
-  stream.error = MAD_ERROR_NONE;
+  mad_stream_buffer( &stream, (unsigned char*)buf, bufLen );
+  unsigned long bitrate, kbps, count;
+  int vbr;
+  bitrate = kbps = count = vbr = 0;
+  mad_timer_t duration = mad_timer_zero;
   bool success = true;
-  if( mad_header_decode( &header, &stream ) ) {
+  while (1) {
+    if (mad_header_decode(&header, &stream) == -1) {
+      if (MAD_RECOVERABLE(stream.error))
+	continue;
+      else
+      {
+        break;
+      }
+    }
+    if (bitrate && header.bitrate != bitrate)
+      vbr = 1;
+
+    bitrate = header.bitrate;
+
+    kbps += bitrate / 1000;
+    ++count;
+
+    mad_timer_add(&duration, header.duration);
+  }
+  kbps = count?((kbps * 2) / count + 1) / 2 * (vbr ? -1 : 1):0;
+  kdDebug() << "(K3bMp3Module) File: " << url.path() << ", bitrate: " << kbps << ", duration: " << duration.seconds << "." << duration.fraction << endl;
+  if (duration.seconds == 0 || kbps == 0)
+  {
     kdDebug() << "(K3bMadDecoder) could not find mpeg header." << endl;
     success = false;
   }
 
-  mad_header_finish( &header );
-  mad_stream_finish( &stream );
+  munmap((void *)buf, bufLen);
+  f.close();
   
   return success;
 }
