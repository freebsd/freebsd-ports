diff --git a/src/via_driver.h b/src/via_driver.h
index b01229d..bfad2ee 100644
--- src/via_driver.h
+++ src/via_driver.h
@@ -361,8 +361,8 @@ void viaSetupDefaultOptions(ScrnInfoPtr pScrn);
 void viaProcessOptions(ScrnInfoPtr pScrn);
 
 /* In via_display.c. */
-const xf86CrtcFuncsRec iga1_crtc_funcs;
-const xf86CrtcFuncsRec iga2_crtc_funcs;
+extern const xf86CrtcFuncsRec iga1_crtc_funcs;
+extern const xf86CrtcFuncsRec iga2_crtc_funcs;
 
 /* In via_exa.c. */
 Bool viaInitExa(ScreenPtr pScreen);
diff --git a/src/via_sii164.h b/src/via_sii164.h
index 1a402aa..250ac75 100644
--- src/via_sii164.h
+++ src/via_sii164.h
@@ -51,7 +51,7 @@ typedef struct _viaSiI164 {
 } viaSiI164Rec, *viaSiI164RecPtr;
 
 
-const xf86OutputFuncsRec via_sii164_funcs;
+extern const xf86OutputFuncsRec via_sii164_funcs;
 
 Bool viaSiI164Probe(ScrnInfoPtr pScrn, I2CBusPtr pI2CBus);
 void viaSiI164Init(ScrnInfoPtr pScrn);
diff --git a/src/via_vt1632.h b/src/via_vt1632.h
index 4f93f6c..61dada1 100644
--- src/via_vt1632.h
+++ src/via_vt1632.h
@@ -51,7 +51,7 @@ typedef struct _VIAVT1632 {
 } viaVT1632Rec, *viaVT1632RecPtr;
 
 
-const xf86OutputFuncsRec via_vt1632_funcs;
+extern const xf86OutputFuncsRec via_vt1632_funcs;
 
 Bool viaVT1632Probe(ScrnInfoPtr pScrn, I2CBusPtr pI2CBus);
 void viaVT1632Init(ScrnInfoPtr pScrn);
