--- src/radeon_output.c.orig	2011-02-01 17:01:22.000000000 -0700
+++ src/radeon_output.c	2011-02-05 12:22:53.000000000 -0700
@@ -120,6 +120,8 @@
 radeon_bios_output_crtc(xf86OutputPtr output);
 static void
 radeon_bios_output_lock(xf86OutputPtr output, Bool lock);
+extern void
+atombios_pick_dig_encoder(xf86OutputPtr output);
 
 void RADEONPrintPortMap(ScrnInfoPtr pScrn)
 {
@@ -731,6 +733,8 @@
     }
 
     radeon_bios_output_lock(output, TRUE);
+    if (IS_AVIVO_VARIANT)
+	atombios_pick_dig_encoder(output);
     radeon_dpms(output, DPMSModeOff);
     radeon_crtc_dpms(output->crtc, DPMSModeOff);
 
