--- lencod/inc/defines.h.orig	2020-09-29 10:32:12 UTC
+++ lencod/inc/defines.h
@@ -77,7 +77,7 @@
 
 
 //AVC Profile IDC definitions
-enum {
+extern enum {
   NO_PROFILE     =  0,       //!< disable profile checking for experimental coding (enables FRExt, but disables MV)
   FREXT_CAVLC444 = 44,       //!< YUV 4:4:4/14 "CAVLC 4:4:4"
   BASELINE       = 66,       //!< YUV 4:2:0/8  "Baseline"
@@ -164,7 +164,7 @@ enum {
 
 
 //  Available MB modes
-enum {
+extern enum {
   PSKIP        =  0,
   BSKIP_DIRECT =  0,
   P16x16       =  1,
@@ -188,13 +188,13 @@ enum {
 #define NO_INTRA_PMODE  9
 
 // Direct Mode types
-enum {
+extern enum {
   DIR_TEMPORAL = 0, //!< Temporal Direct Mode
   DIR_SPATIAL  = 1 //!< Spatial Direct Mode
 } DirectModes;
 
 // CAVLC block types
-enum {
+extern enum {
   LUMA              =  0,
   LUMA_INTRA16x16DC =  1,
   LUMA_INTRA16x16AC =  2,
@@ -207,7 +207,7 @@ enum {
 } CAVLCBlockTypes;
 
 // CABAC block types
-enum {
+extern enum {
   LUMA_16DC     =   0,
   LUMA_16AC     =   1,
   LUMA_8x8      =   2,
@@ -233,7 +233,7 @@ enum {
 } CABACBlockTypes;
 
 // Color components
-enum {
+typedef enum {
   Y_COMP = 0,    // Y Component
   U_COMP = 1,    // U Component
   V_COMP = 2,    // V Component
@@ -241,8 +241,9 @@ enum {
   G_COMP = 4,    // G Component
   B_COMP = 5,    // B Component
   T_COMP = 6
-} ColorComponent;
+} ColorComponent_t;
 
+extern ColorComponent_t ColorComponent;
 
 #define LEVEL_NUM         6
 #define TOTRUN_NUM       15
@@ -255,7 +256,7 @@ enum {
 #define SHIFT_QP        12
 
 // 4x4 intra prediction modes 
-enum {
+extern enum {
   VERT_PRED            = 0,
   HOR_PRED             = 1,
   DC_PRED              = 2,
@@ -268,7 +269,7 @@ enum {
 } I4x4PredModes;
 
 // 16x16 intra prediction modes
-enum {
+extern enum {
   VERT_PRED_16   = 0,
   HOR_PRED_16    = 1,
   DC_PRED_16     = 2,
@@ -276,7 +277,7 @@ enum {
 } I16x16PredModes;
 
 // 8x8 chroma intra prediction modes
-enum {
+extern enum {
   DC_PRED_8     =  0,
   HOR_PRED_8    =  1,
   VERT_PRED_8   =  2,
@@ -291,7 +292,7 @@ enum {
 };
 
 // MV Prediction types
-enum {
+extern enum {
   MVPRED_MEDIAN   = 0,
   MVPRED_L        = 1,
   MVPRED_U        = 2,
@@ -341,14 +342,14 @@ enum {
 #define NUM_ONE_CTX    5
 #define NUM_ABS_CTX    5
 
-enum // JLT : on-the-fly levels/modes
+extern enum // JLT : on-the-fly levels/modes
 {
   OTF_L0 = 0, // Disable, interpolate & store all positions
   OTF_L1 = 1, // Store full pel & interpolated 1/2 pel positions; 1/4 pel positions interpolate on-the-fly
   OTF_L2 = 2  // Store only full pell positions; 1/2 & 1/4 pel positions interpolate on-the-fly  
 } OTFMode;
 
-enum
+extern enum
 {
   OTF_ME = 0,
   OTF_MC = 1
