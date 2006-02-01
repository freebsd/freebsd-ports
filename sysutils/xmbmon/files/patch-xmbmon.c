--- xmbmon.c.orig	Thu Aug 12 06:37:03 2004
+++ xmbmon.c	Wed Feb  1 20:44:54 2006
@@ -23,16 +23,16 @@
 #define RES_NAME   "XMBmon"
 
 #define DEFAULT_GEOMETRY  "100x140"
-#define DEFAULT_FONT      "-adobe-helvetica-bold-r-*-*-10-*-*-*-*-*-*-*"
+#define DEFAULT_FONT      "fixed"
 
-#define DEFAULT_LBFONT    "-adobe-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*"
+#define DEFAULT_LBFONT    "fixed"
 #define DEFAULT_LBCOLOR   "black"
 
 #define DEFAULT_COUNT        "4"
 #define DEFAULT_CSEC        "20"
 #define DEFAULT_WSEC      "1800"
 #define DEFAULT_TMIN      "10.0"
-#define DEFAULT_TMAX      "50.0"
+#define DEFAULT_TMAX      "90.0"
 #define DEFAULT_TMINF     "50.0"	/* for Fahrenheit */
 #define DEFAULT_TMAXF     "130.0"	/* for Fahrenheit */
 #define DEFAULT_VMIN      "1.80"
