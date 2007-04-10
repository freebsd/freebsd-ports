--- src/mpgfile.cpp~	Wed Dec 14 22:32:55 2005
+++ src/mpgfile.cpp	Mon Apr  9 16:55:43 2007
@@ -25,6 +25,7 @@
 #include <list>
 #include <utility>
 
+#include "port.h"
 #include "mpgfile.h"
 #include "tsfile.h"
 #include "psfile.h"
@@ -57,7 +58,7 @@
   {
   if (errormessage)
     errormessage->clear();
-  inbuffer buf(64 << 10, 128 << 10);
+  inbuffer buf(64 << 10, -1, false, 128 << 10);
 
   int fd = buf.open(filename.c_str());
   if (fd < 0) {
@@ -123,9 +124,11 @@
   int last_cpn=-1;
   bool firstframe=true, firstsequence=true;
 
-  while (pic<stop && (streampic+1)<idx.getrealpictures()) {
-    filepos_t tp=idx[streampic+1].getpos();
-    while (sd->itemlist().empty() || sd->itemlist().back().fileposition<tp)
+  while (pic<stop && streampic<idx.getpictures()) {
+    filepos_t tp(getfilesize(),0);
+    if ((streampic+1)<idx.getpictures())
+      tp=idx[streampic+1].getpos();
+    while (sd->itemlist().empty() || s.fileposition<tp.fileposition())
       if (streamreader(s)<=0)
         break;
 
@@ -184,6 +187,18 @@
     ++streampic;
     }
 
+  if (pic < stop) {
+    int frameFinished=0;
+    avcodec_decode_video(S->avcc, avf, &frameFinished, NULL, 0);
+    if (frameFinished) {
+      if (last_cpn!=avf->coded_picture_number) {
+	last_cpn=avf->coded_picture_number;
+	if (pic>=start)
+	  framelist.push_back(new avframe(avf,S->avcc));
+	}
+      }
+    }
+
   avcodec_close(S->avcc);
   }
 
@@ -232,8 +247,8 @@
   if (avcodec_open(S->avcc, S->dec))
     return;
 
-  int16_t samples[4096];
-  int frame_size=4096;
+  int16_t samples[6*1536];	// must be enough for 6 AC-3 channels --mr
+  int frame_size=sizeof(samples);
   avcodec_decode_audio(S->avcc,samples,&frame_size,(uint8_t*) sd->getdata(),sd->inbytes());
   avcodec_close(S->avcc);
   }
@@ -258,21 +273,20 @@
   int stopreadpic=idx.indexnr(picture);
   while (stopreadpic<pictures-1 && idx[stopreadpic].getpts()<stoppts+180000)
     ++stopreadpic;
-  off_t stopreadpos=idx[stopreadpic].getpos().packetposition();
+  dvbcut_off_t stopreadpos=idx[stopreadpic].getpos().packetposition();
 
   streamhandle sh(idx[seekpic].getpos().packetposition());
   streamdata *sd=sh.newstream(audiostream(aud),s[audiostream(aud)].type,istransportstream());
 
   while (sd->empty()) {
-    if (sh.fileposition<stopreadpos && streamreader(sh)<=0)
+    if (sh.fileposition > stopreadpos || streamreader(sh)<=0)
       return; // data does not reach the point in time from which we like to start playing
-    while (!sd->empty() &&
-           !(sd->itemlist().begin()->headerhaspts()&&sd->itemlist().begin()->data_alignment_indicator()))
+    while (!sd->empty() && !sd->itemlist().begin()->headerhaspts())
       sd->pop();
     }
 
   for(;;) {
-    if (sh.fileposition<stopreadpos && streamreader(sh)<=0)
+    if (sh.fileposition > stopreadpos || streamreader(sh)<=0)
       return; // data does not reach the point in time from which we like to start playing
     if (sd->empty())
       continue;
@@ -281,7 +295,7 @@
     int pop=1;
     pts_t pts=AV_NOPTS_VALUE;
     for(++it;it!=sd->itemlist().end();++it,++pop)
-      if (it->headerhaspts()&&it->data_alignment_indicator()) //if (streamdata::headerhaspts(it->header))
+      if (it->headerhaspts()) //if (streamdata::headerhaspts(it->header))
         {
         pts=it->headerpts(startpts);
         break;
@@ -297,7 +311,7 @@
   while (streamreader(sh)>0) {
     streamdata::itemlisttype::const_reverse_iterator it=sd->itemlist().rbegin();
     while(it!=sd->itemlist().rend())
-      if (it->headerhaspts()&&it->data_alignment_indicator())
+      if (it->headerhaspts())
         break;
       else
         --it;
@@ -373,7 +387,7 @@
   while (seekpic>0 && idx[seekpic].getpts()>=videostartpts-180000)
     --seekpic;
 
-  off_t tpos;
+  dvbcut_off_t tpos;
     {
     int stoppic=idx.indexnr(start);
     while (stoppic<pictures &&
@@ -470,6 +484,7 @@
           isfirstseq=false;
         isfirstpic=false;
 
+        int seqoff=0;
         if (!isfirstseq || idx[streampic].getsequencenumber()>=firstseqnr) {
           if (isfirstseq && firstseqnr>0) // need to subtract offset from picture sequence number
             {
@@ -489,7 +504,7 @@
                   } else
                   ++j;
               }
-
+            seqoff=firstseqnr;
             }
           pts_t vidpts=idx[streampic].getpts()-videooffset;
           pts_t viddts=vidpts;
@@ -497,6 +512,13 @@
             viddts=mux.getdts(VIDEOSTREAM);
             mux.setdts(VIDEOSTREAM,vidpts);
             }
+	  if (idx[streampic].getseqheader()) {
+	    int tcpic=streampic;
+	    while (tcpic < copystop && idx[tcpic].getsequencenumber() != seqoff)
+	      ++tcpic;
+	    pts_t tcpts=idx[tcpic].getpts()-videooffset;
+	    fixtimecode((uint8_t*)vsd->getdata(),picsize,tcpts);
+	    }
           if (!mux.putpacket(VIDEOSTREAM,vsd->getdata(),picsize,vidpts,viddts,
                              idx[streampic].isiframe() ? MUXER_FLAG_KEY:0  ))
             if (log)
@@ -671,6 +693,7 @@
     pts_t vidpts=idx[idx.indexnr(outpicture)].getpts()-offset;
     pts_t viddts=mux.getdts(VIDEOSTREAM);
     mux.setdts(VIDEOSTREAM,vidpts);
+    fixtimecode(buf,out,vidpts);
     mux.putpacket(VIDEOSTREAM,buf,out,vidpts,viddts,
                   (avcc->coded_frame && avcc->coded_frame->key_frame)?MUXER_FLAG_KEY:0 );
     ++outpicture;
@@ -684,3 +707,42 @@
   avcodec_close(avcc);
   }
 
+void mpgfile::fixtimecode(uint8_t *buf, int len, pts_t pts) {
+  int frc=-1;
+  int i=0;
+  for (;;) {
+    if (i+8>len)
+      return;
+    else if (buf[i+2]&0xfe)
+      i+=3;
+    else if (buf[i]!=0 || buf[i+1]!=0 || buf[i+2]!=1)
+      i+=1;
+    else if (buf[i+3]==0xb3) {	// sequence header
+      frc=buf[i+7]&0x0f;
+      i+=12;
+      }
+    else if (buf[i+3]==0xb8)	// GOP header
+      break;
+    else
+      i+=4;
+    }
+  buf+=i;
+  buf[4]=0x00;
+  buf[5]=0x00;
+  buf[6]=0x08;
+  buf[7]&=0x7f;
+  if (frc==-1)
+    return;
+  if (frc==1 || frc==4 || frc==7)
+    ++frc;	// use nearest integer
+  int framerate=27000000/frameratescr[frc];
+  int ss=pts/90000;
+  int mm=ss/60; ss %= 60;
+  int hh=mm/60; mm %= 60;
+  int pp=pts%90000;
+  pp=(pp*framerate)/90000;
+  buf[4] = (hh<<2) & 0x7c | (mm>>4) & 0x03;
+  buf[5] = (mm<<4) & 0xf0 | (ss>>3) & 0x07 | 0x08;
+  buf[6] = (ss<<5) & 0xe0 | (pp>>1) & 0x1f;
+  buf[7] |= (pp<<7) & 0x80;
+  }
