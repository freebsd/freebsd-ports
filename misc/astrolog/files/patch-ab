--- astrolog.h.orig	2002-04-27 22:50:39.000000000 +0400
+++ astrolog.h	2012-02-25 21:25:04.000000000 +0400
@@ -72,9 +72,11 @@
 /*#define MACG /* Comment out this #define if you don't have a Mac, or else  */
              /* have one and don't wish to compile in Mac screen graphics. */
 
-/*#define MOUSE /* Comment out this #define if you don't have a mouse, or    */
+#if defined(X11) || defined(WIN) || defined(MSG) || defined(BGI) || defined(MACG)
+#define MOUSE /* Comment out this #define if you don't have a mouse, or    */
               /* don't wish to compile in mouse tracking features. This is */
               /* only valid if X11, WIN, MSG, BGI, or MACG above are set.  */
+#endif
 
 #define TIME /* Comment out this #define if your compiler can't take the  */
              /* calls to the 'time' or 'localtime' functions as in time.h */
@@ -138,9 +140,13 @@
 */
 
 #ifndef PC
+#ifndef DEFAULT_DIR
 #define DEFAULT_DIR "~/astrolog"
 #define EPHE_DIR "~/astrolog/ephe"
 #else
+#define EPHE_DIR DEFAULT_DIR
+#endif
+#else
 #define DEFAULT_DIR "C:\\ASTROLOG"
 #define EPHE_DIR DEFAULT_DIR
 #endif
@@ -292,6 +298,8 @@
 #define ISG
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
+#else
+#include <sys/types.h>
 #endif
 #ifdef WIN
 #define ISG
@@ -1068,9 +1076,9 @@
 */
 
 #define byte  unsigned char
-#define word  unsigned short
-#define dword unsigned long
-#define word4 long
+#define word  u_int16_t
+#define dword u_int32_t
+#define word4 int32_t
 #define real  double
 #define _char unsigned char
 #define _int  unsigned int
