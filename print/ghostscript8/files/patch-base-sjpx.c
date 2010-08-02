Submitted By: Ken Moffat <ken at linuxfromscratch dot org>
Date: 2009-02-11
Initial Package Version: 8.63 (well, it's needed for 8.63, obviously ex 8.61)
Upstream Status: unknown
Origin: fedora
Description: Allows gnu-ghostscript to compile against external libjasper.
 To do that, you need to remove the jasper/ directory.  The included version
is 1.701 which is somewhat old.  Forward-ported to 8.64 (the structure of
the file source tree has changed) by km.

diff -Naur ghostscript-8.64.orig/base/sjpx.c ghostscript-8.64/base/sjpx.c
--- base/sjpx.c	2008-08-21 00:22:49.000000000 +0100
+++ base/sjpx.c	2009-02-10 21:59:41.000000000 +0000
@@ -34,14 +34,6 @@
 private_st_jpxd_state(); /* creates a gc object for our state,
 			    defined in sjpx.h */
 
-/* error reporting callback for the jpx library */
-static void
-s_jpx_jas_error_cb(jas_error_t err, char *msg)
-{
-  dprintf2("jasper (code %d) %s", (int)err, msg);
-}
-
-
 /* initialize the steam.
    this involves allocating the stream and image structures, and
    initializing the decoder.
@@ -59,7 +51,6 @@
     }
 
     status = jas_init();
-    jas_set_error_cb(s_jpx_jas_error_cb);
 #ifdef JPX_DEBUG
     /* raise the error reporting threshold from the default (0) */
     jas_setdbglevel(1);
