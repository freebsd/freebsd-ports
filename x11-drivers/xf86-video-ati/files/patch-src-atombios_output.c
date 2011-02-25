--- src/atombios_output.c.orig	2011-01-27 10:05:58.000000000 -0700
+++ src/atombios_output.c	2011-02-05 12:20:30.000000000 -0700
@@ -172,7 +172,6 @@
 #define DP_SET_POWER_D3  0x2
 
 static void do_displayport_link_train(xf86OutputPtr output);
-static void atombios_pick_dig_encoder(xf86OutputPtr output);
 
 static int
 atombios_output_dac_setup(xf86OutputPtr output, int action)
@@ -1469,7 +1468,6 @@
 
     if (radeon_encoder == NULL)
         return;
-    atombios_pick_dig_encoder(output);
 
     switch (radeon_encoder->encoder_id) {
     case ENCODER_OBJECT_ID_INTERNAL_TMDS1:
@@ -1781,7 +1779,7 @@
     }
 }
 
-static void
+void
 atombios_pick_dig_encoder(xf86OutputPtr output)
 {
     xf86CrtcConfigPtr   xf86_config = XF86_CRTC_CONFIG_PTR(output->scrn);
@@ -1878,7 +1876,6 @@
 	return;
 
     radeon_output->pixel_clock = adjusted_mode->Clock;
-    atombios_pick_dig_encoder(output);
     atombios_output_overscan_setup(output, mode, adjusted_mode);
     atombios_output_scaler_setup(output);
     atombios_set_output_crtc_source(output);
