--- openmx_common.h.orig	2024-06-16 22:56:57 UTC
+++ openmx_common.h
@@ -2656,7 +2656,7 @@ char restart_filename[YOUSO10];
 char filename[YOUSO10],filepath[YOUSO10],command[YOUSO10];
 char ref_diff_charge_filename[YOUSO10];
 char restart_filename[YOUSO10];
-char DFT_DATA_PATH[YOUSO10];
+const char DFT_DATA_PATH[YOUSO10];
 double Oopt_NormD[10];
 double bias_weight,Past_Utot[10],Past_Norm[10];
 double Max_Force,GridVol,W_OrthoNorm;
