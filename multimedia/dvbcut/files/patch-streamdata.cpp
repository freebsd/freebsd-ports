--- src/streamdata.cpp~	Sun Dec 11 21:08:34 2005
+++ src/streamdata.cpp	Mon Apr  9 16:55:43 2007
@@ -23,25 +23,30 @@
     44100,48000,32000,16000
   };
 static const int mpegaudio_bitrate[][16]=
-  { {
-      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
-    }
-    , // undefined layer
-    {0,32,64,96,128,160,192,224,256,288,320,352,384,416,448}, // layer 1
+  { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // undefined layer
+    {0,32,40,48, 56, 64, 80, 96,112,128,160,192,224,256,320}, // layer 3
     {0,32,48,56, 64, 80, 96,112,128,160,192,224,256,320,384}, // layer 2
-    {0,32,40,48, 56, 64, 80, 96,112,128,160,192,224,256,320} // layer 3
+    {0,32,64,96,128,160,192,224,256,288,320,352,384,416,448}  // layer 1
   };
 
+static inline int is_mpa(const unsigned char *header)
+{
+  return header[0] == 0xff		/* sync word */
+      && (header[1] & 0xe6) > 0xe0	/* sync word & layer */
+      && (header[2] & 0xf0) != 0xf0	/* bitrate code */
+      && (header[2] & 0x0c) != 0x0c;	/* sampling rate code */
+}
+
 static int mpaframe(const void *data, int &pos, int len)
   {
   const unsigned char *d=(const unsigned char *)data;
-  while ((pos+2)<len && (d[pos]!=0xff || (d[pos+1]&0xf0!=0xf0)))
+  while ((pos+2)<len && !is_mpa(&d[pos]))
     ++pos;
   if (pos+2>=len)
     return 0;
 
-  int layer=4-((d[pos+1]>>1)&0x03);
-  int samples=(layer==1)?384:1152;
+  int layer=(d[pos+1]>>1)&0x03;
+  int samples=(layer==4-1)?384:1152;
   int samplingrate=mpegaudio_rates[(d[pos+2]>>2)&0x03];
   int bitratecode=(d[pos+2]>>4)&0x0f;
 
@@ -51,7 +56,7 @@
   else
     pos+=3;
 
-  while ((pos+2)<len && (d[pos]!=0xff || (d[pos+1]&0xf0!=0xf0)))
+  while ((pos+2)<len && !is_mpa(&d[pos]))
     ++pos;
   return samples*90000/samplingrate; // Duration of MPEG audio frame in 90000Hz units
   }
@@ -117,7 +122,7 @@
   itemlisttype::iterator it=items.begin();
 
   while(it!=items.end())
-    if (!(it->data_alignment_indicator()&&it->headerhaspts()))
+    if (!it->headerhaspts())
       it=items.erase(it);
     else
       ++it;
@@ -135,8 +140,8 @@
       needsync=false;
 
       for(;it!=items.end();++it)
-        if (it->headerhaspts() && it->data_alignment_indicator())
-          // header carries PTS and data alignment indicator
+        if (it->headerhaspts())
+          // header carries PTS
           break;
 
       if (it==items.end())
@@ -148,7 +153,7 @@
           } else {
           itemlisttype::iterator n=it;
           for(++n;n!=items.end();++n)
-            if (it->headerhaspts() && it->data_alignment_indicator())
+            if (it->headerhaspts())
               break;
           if (n!=items.end())
             stopbufferpos=n->bufferposition;
@@ -289,6 +294,7 @@
       }
     }
 
+#if 0	// --mr
   if (type==streamtype::mpegaudio) {
     if (s>=2)
       if (data[0]==0xff && (data[1]&0xf0)==0xf0)
@@ -307,6 +313,7 @@
     s-=ac3offset+2;
     flags|=STREAM_ITEM_FLAG_DATA_ALIGNMENT_INDICATOR;
     }
+#endif
 
 
   if (s>0) {
