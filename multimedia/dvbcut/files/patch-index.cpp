--- src/index.cpp~	Thu Dec 15 22:16:01 2005
+++ src/index.cpp	Mon Apr  9 16:55:43 2007
@@ -25,12 +25,18 @@
 #include <string.h>
 #include <list>
 #include <utility>
+
+#include "port.h"
 #include "index.h"
 #include "mpgfile.h"
 #include "streamhandle.h"
 #include "types.h"
 #include "logoutput.h"
 
+#ifndef O_BINARY
+#define O_BINARY    0
+#endif /* O_BINARY */
+
 static inline ssize_t writer(int fd, const void *buf, size_t count)
   {
   int written=0;
@@ -59,7 +65,7 @@
   int fd=-1;
   bool usestdout=false;
   int pictureswritten=0;
-  off_t filesize;
+  dvbcut_off_t filesize;
 
   if (savefilename && savefilename[0]) {
     if (savefilename[0]=='-' && savefilename[1]==0) // use stdout
@@ -67,7 +73,7 @@
       fd=STDOUT_FILENO;
       usestdout=true;
       } else
-      if ((fd=::open(savefilename,O_WRONLY|O_CREAT|O_TRUNC,0666))<0) {
+      if ((fd=::open(savefilename,O_WRONLY|O_CREAT|O_TRUNC|O_BINARY,0666))<0) {
         if (errorstring)
           *errorstring+=std::string("Open (")+savefilename+"): "+strerror(errno)+"\n";
         return fd;
@@ -102,8 +108,15 @@
   int seqheaderpic=0;
   pts_t referencepts=0; // pts of picture #0 in current sequence
   int maxseqnr=-1; // maximum sequence number in current sequence
-  std::list<std::pair<int,int> > curseqnumbers; // seqnr->picnr relation for current sequence
   pts_t lastpts=1ll<<31;
+  int last_non_b_pic = -1;
+  int last_non_b_seqnr = -1;
+  int last_seqnr = -1;
+  int ptsmod = -1;
+  int errcnt = 0;
+  int err1cnt = 0;
+  int lasterr = 0;
+  int lastiframe = -1;
 
   while (mpg.streamreader(s)>0) {
     while (sd->getbuffer().inbytes()< (sd->getbuffer().getsize()/2))
@@ -149,6 +162,12 @@
 
       if (*(uint32_t*)(data+skip)==mbo32(0x000001b3)) // sequence header
         {
+        if (last_non_b_pic >= 0) {
+          p[last_non_b_pic].setsequencenumber(++maxseqnr);
+          last_non_b_pic = -1;
+          }
+	last_seqnr = -1;
+
         waitforfirstsequenceheader=false;
         foundseqheader=true;
         sd->discard(skip);
@@ -166,16 +185,6 @@
         inbytes=sd->inbytes();
         skip=0;
 
-        // ensure that sequence numbers are okay in the last sequence
-        if (!curseqnumbers.empty())
-          {
-          curseqnumbers.sort();
-          int n=0;
-          for(std::list<std::pair<int,int> >::iterator it=curseqnumbers.begin();it!=curseqnumbers.end();++it)
-            p[it->second].setsequencenumber(n++);
-          curseqnumbers.clear();
-          }
-
         } else if ((*(uint32_t*)(data+skip)==mbo32(0x00000100))&&!waitforfirstsequenceheader) // picture header
         {
         sd->discard(skip);
@@ -183,8 +192,6 @@
 
         filepos_t picpos=sd->itemlist().front().fileposition;
         int seqnr=(data[4]<<2)|((data[5]>>6)&3);
-        if (seqnr>maxseqnr)
-          maxseqnr=seqnr;
         int frametype=(data[5]>>3)&7;
         if (frametype>3)
           frametype=0;
@@ -192,12 +199,43 @@
         pts_t pts=sd->itemlist().front().headerpts();
         if (pts>=0)
           {
+          pts=ptsreference(pts,lastpts);
+          lastpts = pts;
+          int ptsdelta = mpgfile::frameratescr[framerate] / 300;
+          int epsilon = ptsdelta / 100;	/* allow at most 1% deviation */
+          int mod = pts % ptsdelta;
+          if (ptsmod == -1)
+	    ptsmod = mod;
+          else if (mod != ptsmod) {
+	    int error = (mod - ptsmod + ptsdelta) % ptsdelta;
+	    if (error > ptsdelta / 2)
+	      error -= ptsdelta;
+	    bool complain = false;
+	    if (lasterr != error) {
+	      if (err1cnt > 0) {
+		fprintf(stderr, "last video PTS error repeated %d times\n", err1cnt);
+		err1cnt = 0;
+		}
+	      complain = true;
+	      lasterr = error;
+	      }
+	    else
+	      ++err1cnt;
+	    ++errcnt;
+	    if (-epsilon <= error && error <= epsilon) {
+	      if (complain)
+		fprintf(stderr, "inconsistent video PTS (%+d), correcting\n", error);
+	      pts -= error;
+	      } else {
+	      if (complain)
+		fprintf(stderr, "inconsistent video PTS (%+d) in %c frame %d, NOT correcting\n",
+		  error, frametype["?IPB"], pictures);
+	      }
+	    }
           referencepts=pts-(seqnr*mpgfile::frameratescr[framerate])/300;
           sd->discardheader();
           } else
           pts=referencepts+(seqnr*mpgfile::frameratescr[framerate])/300;
-        pts=ptsreference(pts,lastpts);
-        lastpts=pts;
 
         if (pictures>=size)
           {
@@ -205,8 +243,62 @@
           p=(picture*)realloc((void*)p,size*sizeof(picture));
           }
 
-        curseqnumbers.push_back(std::pair<int,int>(seqnr,pictures));
-        p[pictures++]=picture(foundseqheader?seqheaderpos:picpos,pts,framerate,aspectratio,seqnr,frametype,foundseqheader);
+        p[pictures]=picture(foundseqheader?seqheaderpos:picpos,pts,framerate,aspectratio,seqnr,frametype,foundseqheader);
+
+        if (frametype == IDX_PICTYPE_I) {
+	  if (lastiframe >= 0) {
+	    int framepts = mpgfile::frameratescr[framerate] / 300;
+	    pts_t ptsdelta = pts - p[lastiframe].getpts();
+	    int pdelta = pictures - lastiframe;
+	    if (pdelta * framepts < ptsdelta)
+	      fprintf(stderr, "missing frames in GOP (%d, %d): %d\n",
+		lastiframe, pictures, ptsdelta / framepts - pdelta);
+	    }
+	  lastiframe = pictures;
+	  }
+
+        if (frametype == IDX_PICTYPE_B) {
+	  /* check sequence number */
+	  if (seqnr != last_seqnr + 1) {
+	    fprintf(stderr,
+	      "missing frame(s) before B frame %d (%d != %d)\n",
+	      pictures, seqnr, last_seqnr + 1);
+	    if (seqnr <= last_seqnr) {
+	      fprintf(stderr, "sequence number reset (%d => %d)\n", last_seqnr + 1, seqnr);
+	      if (last_non_b_pic >= 0 && last_non_b_seqnr > last_seqnr) {
+		fprintf(stderr, "inserting delayed picture (%d)\n", last_non_b_seqnr);
+		p[last_non_b_pic].setsequencenumber(++maxseqnr);
+		last_non_b_pic = -1;
+		}
+	      }
+	    else if (last_non_b_pic >= 0 && last_non_b_seqnr < seqnr) {
+	      fprintf(stderr, "inserting delayed picture (%d)\n", last_non_b_seqnr);
+	      p[last_non_b_pic].setsequencenumber(++maxseqnr);
+	      last_non_b_pic = -1;
+	      }
+	    }
+	  p[pictures].setsequencenumber(++maxseqnr);
+	  last_seqnr = seqnr;
+	  } else {
+	    /* I and P frames are delayed */
+	    if (last_non_b_pic >= 0) {
+	      /* check sequence number */
+	      if (last_non_b_seqnr != last_seqnr + 1) {
+		fprintf(stderr,
+		  "missing frame(s) before %c frame %d (%d != %d)\n",
+		  p[last_non_b_pic].isiframe() ? 'I' : 'P',
+		  pictures, last_non_b_seqnr, last_seqnr + 1);
+		}
+	      p[last_non_b_pic].setsequencenumber(++maxseqnr);
+	      last_seqnr = last_non_b_seqnr;
+	      }
+	    last_non_b_pic = pictures;
+	    last_non_b_seqnr = seqnr;
+	    if (frametype == IDX_PICTYPE_I)
+	      last_seqnr = -1;
+	  }
+
+	++pictures;
 
         foundseqheader=false;
         sd->discard(8);
@@ -219,13 +311,14 @@
     sd->discard(skip);
     }
 
-  // ensure that sequence numbers are okay in the last sequence
-  if (!curseqnumbers.empty()) {
-    curseqnumbers.sort();
-    int n=0;
-    for(std::list<std::pair<int,int> >::iterator it=curseqnumbers.begin();it!=curseqnumbers.end();++it)
-      p[it->second].setsequencenumber(n++);
-    curseqnumbers.clear();
+  if (err1cnt > 0)
+    fprintf(stderr, "last video PTS error repeated %d times\n", err1cnt);
+  if (errcnt > 0)
+    fprintf(stderr, "found %d video PTS errors\n", errcnt);
+
+  if (last_non_b_pic >= 0) {
+    p[last_non_b_pic].setsequencenumber(++maxseqnr);
+    last_non_b_pic = -1;
     }
 
   if (pictures==0) {
@@ -263,7 +356,7 @@
     fd=STDOUT_FILENO;
     usestdout=true;
     } else
-    if ((fd=::open(filename,O_WRONLY|O_CREAT|O_TRUNC,0666))<0) {
+    if ((fd=::open(filename,O_WRONLY|O_CREAT|O_TRUNC|O_BINARY,0666))<0) {
       if (errorstring)
         *errorstring+=std::string("Open (")+filename+"): "+strerror(errno)+"\n";
       return fd;
@@ -287,7 +380,7 @@
 
 int index::load(const char *filename, std::string *errorstring)
   {
-  int fd=::open(filename,O_RDONLY,0666);
+  int fd=::open(filename,O_RDONLY|O_BINARY,0666);
   if (fd<0) {
     if (errorstring) {
       int serrno=errno;
@@ -424,12 +517,12 @@
   if (p[firstiframe].getsequencenumber()>0) {
     int fifseqnr=p[firstiframe].getsequencenumber();
 
-    for(int i=sequencebegin;(!p[i].getseqheader()||i==sequencebegin)&&(i<pictures);++i)
+    for(int i=sequencebegin;(i<pictures)&&(!p[i].getseqheader()||i==sequencebegin);++i)
       if (p[i].getsequencenumber()<fifseqnr)
         ++skipfirst;
     }
 
-  realpictures=pictures-skipfirst-1;
+  realpictures=pictures-skipfirst;
   if (realpictures<1)
     return 0;
 
