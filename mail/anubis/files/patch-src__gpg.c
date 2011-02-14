--- ./src/gpg.c.orig	2008-12-16 11:21:54.000000000 -0500
+++ ./src/gpg.c	2011-02-09 20:52:34.000000000 -0500
@@ -23,7 +23,7 @@
 #include "rcfile.h"
 
 #ifdef HAVE_GPG
-#include <gpgme.h>
+#include <gpgme/gpgme.h>
 #define obstack_chunk_alloc malloc
 #define obstack_chunk_free free
 #include <obstack.h>
