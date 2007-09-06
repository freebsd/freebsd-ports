--- dev/cxm/cxm.h.orig	2007-09-05 19:10:08.361061000 +0200
+++ dev/cxm/cxm.h	2007-09-05 19:14:25.486827125 +0200
@@ -211,8 +211,6 @@
 			 cxm_pal_60hz_source_format,
 			 cxm_secam_50hz_source_format };
 
-extern const struct cxm_tuner cxm_tuners[];
-
 enum cxm_type { cxm_unknown_type, cxm_iTVC15_type, cxm_iTVC16_type };
 
 /*
@@ -635,6 +633,8 @@
 	const struct cxm_saa7115_command *scaling;
 };
 
+extern const struct cxm_tuner cxm_tuners[];
+
 int cxm_saa7115_init( struct cxm_softc *sc );
 int cxm_saa7115_mute( struct cxm_softc *sc );
 int cxm_saa7115_unmute( struct cxm_softc *sc );
