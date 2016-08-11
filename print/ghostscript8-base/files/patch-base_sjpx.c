Submitted By: Ken Moffat <ken at linuxfromscratch dot org>
Date: 2009-02-11
Initial Package Version: 8.63 (well, it's needed for 8.63, obviously ex 8.61)
Upstream Status: unknown
Origin: fedora
Description: Allows gnu-ghostscript to compile against external libjasper.
 To do that, you need to remove the jasper/ directory.  The included version
is 1.701 which is somewhat old.  Forward-ported to 8.64 (the structure of
the file source tree has changed) by km.

--- base/sjpx.c.orig	2009-06-18 05:16:48 UTC
+++ base/sjpx.c
@@ -33,14 +33,6 @@ static void s_jpxd_set_defaults(stream_s
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
@@ -58,7 +50,6 @@ s_jpxd_init(stream_state * ss)
     }
 
     status = jas_init();
-    jas_set_error_cb(s_jpx_jas_error_cb);
 #ifdef JPX_DEBUG
     /* raise the error reporting threshold from the default (0) */
     jas_setdbglevel(1);
