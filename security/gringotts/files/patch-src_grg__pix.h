--- src/grg_pix.h.orig	2008-01-04 13:08:43 UTC
+++ src/grg_pix.h
@@ -22,13 +22,13 @@
 #ifndef GRG_PIX_H
 #define GRG_PIX_H
 
-const char *red_xpm[58];
-const char *yellow_xpm[58];
-const char *green_xpm[58];
-const char *optimal_xpm[94];
+extern const char *red_xpm[58];
+extern const char *yellow_xpm[58];
+extern const char *green_xpm[58];
+extern const char *optimal_xpm[94];
 
-const char *splash_xpm[180];
+extern const char *splash_xpm[180];
 
-const char *wait_xpm[82];
-const char *clip_xpm[17];
+extern const char *wait_xpm[82];
+extern const char *clip_xpm[17];
 #endif
