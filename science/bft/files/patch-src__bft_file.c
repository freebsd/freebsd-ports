--- src/bft_file.c.orig	2008-01-14 19:19:31.000000000 +0100
+++ src/bft_file.c	2010-05-01 11:20:00.000000000 +0200
@@ -106,6 +106,13 @@
    We redefine prototypes for gzseek() and gztell() ;
    This is ugly, but should work with an unmodified Zlib (as of Zlib 1.2.1) */
 
+#if defined (__FreeBSD__)
+#  if __FreeBSD_version < 900010
+typedef long bft_z_off_t;
+#  else
+typedef off_t bft_z_off_t;
+#  endif
+#else
 #if defined (BFT_SIZEOF_Z_OFF_T)
 #  if (BFT_SIZEOF_Z_OFF_T == BFT_SIZEOF_LONG)
 typedef long bft_z_off_t;
@@ -119,6 +126,7 @@
 #else
 typedef z_off_t bft_z_off_t;
 #endif
+#endif
 
 typedef bft_z_off_t (bft_gzseek_t) (gzFile file,
                                     bft_z_off_t offset,
