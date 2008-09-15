--- ClamAV.pm.orig	2007-02-20 11:42:16.000000000 -0200
+++ ClamAV.pm	2008-09-13 12:02:25.000000000 -0300
@@ -58,7 +58,6 @@
     CL_EACCES
     CL_ENULLARG
     CL_ETMPFILE
-    CL_EFSYNC
     CL_EMEM
     CL_EOPEN
     CL_EMALFDB
@@ -71,11 +70,6 @@
     CL_EIO
     CL_EFORMAT
     CL_ESUPPORT
-    CL_ELOCKDB
-
-    CL_ENCINIT
-    CL_ENCLOAD
-    CL_ENCIO
 
     CL_SCAN_RAW
     CL_SCAN_ARCHIVE
@@ -88,7 +82,6 @@
     CL_SCAN_MAILURL
     CL_SCAN_BLOCKMAX
     CL_SCAN_ALGORITHMIC
-    CL_SCAN_PHISHING_DOMAINLIST
     CL_SCAN_PHISHING_BLOCKSSL
 
     CL_SCAN_PHISHING_BLOCKCLOAK
@@ -169,12 +162,9 @@
     VERSION  => $VERSION,
     PREFIX   => 'clamav_perl_',
     NAME     => "Mail::ClamAV",
-    LIBS     => "-lclamav";
-# removed on install
-BEGIN {
-require "./config.pl";
-}
-# end removed on install
+    OPTIMIZE => '-g',
+    LIBS     => " -lclamav";
+
 use Inline C => <<'END_OF_C';
 #include <stdio.h>
 #include <string.h>
@@ -210,12 +200,10 @@
 
     /* set defaults for limits */
     c->limits.maxreclevel = 5;
-    c->limits.maxmailrec = 10;
     c->limits.maxfiles = 1000;
     c->limits.maxfilesize = 1024 * 1028 * 10; /* 10 Megs */
 
     /* XXX need to figure out a nice default */
-    c->limits.maxratio = 200;
     c->limits.archivememlim = 1;
 
     if (S_ISDIR(st.st_mode)) {
@@ -290,19 +278,6 @@
     return SvClam(self)->limits.maxreclevel;
 }
 
-int clamav_perl_maxmailrec(SV *self, ...)
-{
-    Inline_Stack_Vars;
-    if (Inline_Stack_Items > 1) {
-        SV *max;
-        if (Inline_Stack_Items > 2)
-            croak("Invalid number of arguments to maxmailrec()");
-        max = Inline_Stack_Item(1);
-        SvClam(self)->limits.maxmailrec = SvIV(max);
-    }
-    return SvClam(self)->limits.maxmailrec;
-}
-
 int clamav_perl_maxfiles(SV *self, ...)
 {
     Inline_Stack_Vars;
@@ -329,19 +304,6 @@
     return SvClam(self)->limits.maxfilesize;
 }
 
-int clamav_perl_maxratio(SV *self, ...)
-{
-    Inline_Stack_Vars;
-    if (Inline_Stack_Items > 1) {
-        SV *max;
-        if (Inline_Stack_Items > 2)
-            croak("Invalid number of arguments to maxratio()");
-        max = Inline_Stack_Item(1);
-        SvClam(self)->limits.maxratio = (long int)SvIV(max);
-    }
-    return SvClam(self)->limits.maxratio;
-}
-
 int clamav_perl_archivememlim(SV *self, ...)
 {
     Inline_Stack_Vars;
@@ -481,7 +443,6 @@
     if (strEQ("CL_EACCES", name)) return CL_EACCES;
     if (strEQ("CL_ENULLARG", name)) return CL_ENULLARG;
     if (strEQ("CL_ETMPFILE", name)) return CL_ETMPFILE;
-    if (strEQ("CL_EFSYNC", name)) return CL_EFSYNC;
     if (strEQ("CL_EMEM", name)) return CL_EMEM;
     if (strEQ("CL_EOPEN", name)) return CL_EOPEN;
     if (strEQ("CL_EMALFDB", name)) return CL_EMALFDB;
@@ -494,15 +455,8 @@
     if (strEQ("CL_EIO", name)) return CL_EIO;
     if (strEQ("CL_EFORMAT", name)) return CL_EFORMAT;
     if (strEQ("CL_ESUPPORT", name)) return CL_ESUPPORT;
-    if (strEQ("CL_ELOCKDB", name)) return CL_ELOCKDB;
-
-    /* NodalCore */
-    if (strEQ("CL_ENCINIT", name)) return CL_ENCINIT;
-    if (strEQ("CL_ENCLOAD", name)) return CL_ENCLOAD;
-    if (strEQ("CL_ENCIO", name)) return CL_ENCIO;
 
     /* db options */
-    if (strEQ("CL_DB_NCORE", name)) return CL_DB_NCORE;
     if (strEQ("CL_DB_PHISHING", name)) return CL_DB_PHISHING;
     if (strEQ("CL_DB_ACONLY", name)) return CL_DB_ACONLY;
     if (strEQ("CL_DB_PHISHING_URLS", name)) return CL_DB_PHISHING_URLS;
@@ -522,7 +476,6 @@
     if (strEQ("CL_SCAN_MAILURL", name)) return CL_SCAN_MAILURL;
     if (strEQ("CL_SCAN_BLOCKMAX", name)) return CL_SCAN_BLOCKMAX;
     if (strEQ("CL_SCAN_ALGORITHMIC", name)) return CL_SCAN_ALGORITHMIC;
-    if (strEQ("CL_SCAN_PHISHING_DOMAINLIST", name)) return CL_SCAN_PHISHING_DOMAINLIST;
     if (strEQ("CL_SCAN_PHISHING_BLOCKSSL", name)) return CL_SCAN_PHISHING_BLOCKSSL;
     if (strEQ("CL_SCAN_PHISHING_BLOCKCLOAK", name)) return CL_SCAN_PHISHING_BLOCKCLOAK;
     if (strEQ("CL_SCAN_ELF", name)) return CL_SCAN_ELF;
@@ -602,11 +555,9 @@
 
     # Set some limits (only applies to scan())
     $c->maxreclevel(4);
-    $c->maxmailrec(4);
     $c->maxfiles(20);
     $c->maxfilesize(1024 * 1024 * 20); # 20 megs
     $c->archivememlim(0); # limit memory usage for bzip2 (0/1)
-    $c->maxratio(0);
 
     # Scan a filehandle (scandesc in clamav)
     # scan(FileHandle or path, Bitfield of options)
@@ -701,10 +652,6 @@
 
 Enable algorithmic detection of viruses. 
 
-=item CL_SCAN_PHISHING_DOMAINLIST
-
-Phishing module: restrict URL scanning to domains from .pdf (RECOMMENDED). 
-
 =item CL_SCAN_PHISHING_BLOCKSSL
 
 Phishing module: always block SSL mismatches in URLs. 
@@ -793,10 +740,6 @@
 
 tmpfile() failed 
 
-=item CL_EFSYNC
-
-fsync() failed 
-
 =item CL_EMEM
 
 memory allocation error 
@@ -845,10 +788,6 @@
 
 not supported data format 
 
-=item CL_ELOCKDB
-
-can't lock DB directory 
-
 =item CL_ENCINIT
 
 NodalCore initialization failed 
@@ -890,10 +829,6 @@
 
 Sets the maximum recursion level into archives [default 5].
 
-=item maxmailrec
-
-Sets the maximum recursion level into emails [default 10].
-
 =item maxfiles
 
 Maximum number of files that will be scanned [default 1000]. A value of zero
@@ -904,12 +839,6 @@
 Maximum file size that will be scanned in bytes [default 10M]. A value of zero
 disables the check.
 
-=item maxratio
-
-Maximum compression ratio. So if this is set to 200, libclamav will give up
-decompressing a file if it reaches 200x its compressed size [default 200]. A
-value of zero disables the check.
-
 =item archivememlim
 
 Turns on/off memory usage limits for bzip2. [default 1]
