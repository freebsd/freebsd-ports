--- include/eventstr.h.orig	2012-02-05 19:23:06.000000000 +0100
+++ include/eventstr.h	2012-02-05 19:23:35.000000000 +0100
@@ -91,9 +91,9 @@
         uint32_t button;  /**< Button number */
         uint32_t key;     /**< Key code */
     } detail;
-    uint16_t root_x;      /**< Pos relative to root window in integral data */
+    int16_t root_x;      /**< Pos relative to root window in integral data */
     float root_x_frac;    /**< Pos relative to root window in frac part */
-    uint16_t root_y;      /**< Pos relative to root window in integral part */
+    int16_t root_y;      /**< Pos relative to root window in integral part */
     float root_y_frac;    /**< Pos relative to root window in frac part */
     uint8_t    buttons[(MAX_BUTTONS + 7)/8]; /**< Button mask */
     struct {
