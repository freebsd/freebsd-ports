--- deltup.cpp.orig	2007-07-13 09:22:20.000000000 +0600
+++ deltup.cpp		2008-03-08 23:18:08.000000000 +0500
@@ -520,14 +520,14 @@
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
