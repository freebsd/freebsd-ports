--- ldecod/inc/defines.h.orig	2020-09-29 10:22:20 UTC
+++ ldecod/inc/defines.h
@@ -229,7 +229,7 @@ typedef enum {
 } I8x8PredModes;
 
 // Color components
-enum {
+typedef enum {
   Y_COMP = 0,    // Y Component
   U_COMP = 1,    // U Component
   V_COMP = 2,    // V Component
@@ -237,7 +237,9 @@ enum {
   G_COMP = 4,    // G Component
   B_COMP = 5,    // B Component
   T_COMP = 6
-} ColorComponent;
+} ColorComponent_t;
+
+extern ColorComponent_t ColorComponent;
 
 enum {
   EOS = 1,    //!< End Of Sequence
