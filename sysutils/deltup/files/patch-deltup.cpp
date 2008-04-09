--- deltup.cpp.orig	2007-07-13 09:22:20.000000000 +0600
+++ deltup.cpp		2008-03-10 14:03:08.000000000 +0500
@@ -32,6 +32,7 @@
 #include "filetypes.h"
 #include "system.h"
 #include "bzip2.h"
+#include "gzip.h"
 
 bool force_overwrite = false, remove_intermediate = false,
      info_mode = false, ensure_md5sum = false, use_bdelta = false;
@@ -150,28 +151,33 @@
 
 void gzip_without_header(string in, string out, char compression) {
   string tempfile = getTmpFilename();
-  
-  deflate("gzip", in, tempfile, compression, false);
+  find_gzip_compressor();
+  if (gzip_name != NULL) {
+    deflate(gzip_name, in, tempfile, compression, false);
 //  printf("here2 %s %s %c\n", in.c_str(), tempfile.c_str(), compression);
-  unsigned filesize = getLenOfFile(tempfile);
-  char inbuf[12];
-  IFStream *f = new IFStream(tempfile);
-  f->read(inbuf, 10);
-  char flags = inbuf[3];
-  
-  if (flags & 2) f->read(inbuf, 2);
-  if (flags & 4) {
-    unsigned extrafieldsize = read_word(*f);
-    while (extrafieldsize) 
-      extrafieldsize -= f->read(inbuf, extrafieldsize<10?extrafieldsize:10);
-  }
-  if (flags & 8) do f->read(inbuf, 1); while (*inbuf);
-  if (flags & 16) do f->read(inbuf, 1); while (*inbuf);
-  if (flags & 32) f->read(inbuf, 2);
-  
-  OFStream o(out);
-  copy_bytes_to_file(*f, o, filesize-f->loc());
-  delete f;
+    unsigned filesize = getLenOfFile(tempfile);
+    char inbuf[12];
+    IFStream *f = new IFStream(tempfile);
+    f->read(inbuf, 10);
+    char flags = inbuf[3];
+  
+    if (flags & 2) f->read(inbuf, 2);
+    if (flags & 4) {
+       unsigned extrafieldsize = read_word(*f);
+       while (extrafieldsize) 
+         extrafieldsize -= f->read(inbuf, extrafieldsize<10?extrafieldsize:10);
+    }
+    if (flags & 8) do f->read(inbuf, 1); while (*inbuf);
+    if (flags & 16) do f->read(inbuf, 1); while (*inbuf);
+    if (flags & 32) f->read(inbuf, 2);
+  
+    OFStream o(out);
+    copy_bytes_to_file(*f, o, filesize-f->loc());
+    delete f;
+    gzip_found = 1;
+  } else {
+    gzip_found = 0;
+  }
   doneTmpFile(tempfile);
 
 }
@@ -245,12 +251,16 @@
     string gzip_temp = getTmpFilename();
     const char *lev = "968712534";
     do {
-      printf("here %c\n", *lev);
       gzip_without_header(file2.uname, gzip_temp, *lev);
+      if (gzip_found == 0) { break; 
+//      } else {
+//         printf("here %c\n", *lev);
+      }
       makeDelta(use_bdelta, gzip_temp, file2.fullname(), pristineName);
       ++lev;
     } while (*lev && getLenOfFile(pristineName)>1024);
-    if (!*lev) error("Unknown gzip compression format");
+    if (gzip_found == 0) { error("Can't find GNU gzip");
+    } else if (!*lev) { error("Unknown gzip compression format"); }
     compression_level=*(lev-1)-'0';
     doneTmpFile(gzip_temp);
   } else if (file2.type==BZIP2) {
@@ -365,7 +375,10 @@
                            bzip2_name[i]);
       } else fprintf(stderr, "Error: Deltup cannot find the proper bzip2 to rebuild the package\n");
       break;
-    case GZIP: gzip_without_header(f.uname, finalName, c); break;
+    case GZIP: 
+      gzip_without_header(f.uname, finalName, c); 
+      if (gzip_found == 0) error("Can't find GNU gzip");
+      break;
     case UNKNOWN_FMT: cat(f.uname, finalName, false);
     
   };
@@ -520,14 +533,14 @@
   IStream *f = new IFStream(fname);
   Injectable_IStream f2(*f);
   if (((IFStream*)f)->bad()) {
-    fprintf(stderr, "file is missing: %s\n", fname.c_str()); return;}
+    fprintf(stderr, "file is missing: %s\n", fname.c_str()); exit(1);}
   unsigned type = determine_filetype(f2);
   delete f;
   switch (type) {
     case GZIP: f = new GZ_IFStream(fname); break;
     case BZIP2: f = new BZ_IFStream(fname); break;
     case DTU: f = new IFStream(fname); break;
-    case UNKNOWN_FMT: fprintf(stderr, "cannot read file %s\n", fname.c_str()); return;
+    case UNKNOWN_FMT: fprintf(stderr, "cannot read file %s\n", fname.c_str()); exit(1);
     case TARBALL :
       f = new IFStream(fname);
       unsigned zero_count;
