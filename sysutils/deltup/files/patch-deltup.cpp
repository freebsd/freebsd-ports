--- deltup.cpp.orig	Fri May 27 18:53:49 2005
+++ deltup.cpp	Fri May 27 18:55:24 2005
@@ -748,14 +748,14 @@
 void applyPatchfile(char *fname) {
   IStream *f = new IFStream(fname);
   Injectable_IStream f2(*f);
-  if (((IFStream*)f)->bad()) {fprintf(stderr, "file is missing: %s\n", fname); return;}
+  if (((IFStream*)f)->bad()) {fprintf(stderr, "file is missing: %s\n", fname); exit(1);}
   int type = determine_filetype(f2);
   delete f;
   switch (type) {
     case GZIP: f = new GZ_IFStream(fname); break;
     case BZIP2: f = new BZ_IFStream(fname); break;
     case DTU: f = new IFStream(fname); break;
-    case UNKNOWN_FMT: fprintf(stderr, "cannot read file %s\n", fname); return;
+    case UNKNOWN_FMT: fprintf(stderr, "cannot read file %s\n", fname); exit(1);
     case TARBALL :
       f = new IFStream(fname);
       unsigned zero_count;
