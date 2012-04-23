From 7069d717e982adcf8e1d300cbd10eec6322a65c9 Mon Sep 17 00:00:00 2001
From: Akira TAGOH <akira@tagoh.org>
Date: Sun, 22 Apr 2012 12:40:44 +0000
Subject: C++11 requires a space between literal and identifier

Reported by Buganini
---
diff --git a/fontconfig/fontconfig.h b/fontconfig/fontconfig.h
index 0e2ca50..b27ccb5 100644
--- fontconfig/fontconfig.h
+++ fontconfig/fontconfig.h
@@ -112,9 +112,9 @@ typedef int		FcBool;
 #define FC_DECORATIVE	    "decorative"	/* Bool - true if style is a decorative variant */
 #define FC_LCD_FILTER	    "lcdfilter"		/* Int */
 
-#define FC_CACHE_SUFFIX		    ".cache-"FC_CACHE_VERSION
-#define FC_DIR_CACHE_FILE	    "fonts.cache-"FC_CACHE_VERSION
-#define FC_USER_CACHE_FILE	    ".fonts.cache-"FC_CACHE_VERSION
+#define FC_CACHE_SUFFIX		    ".cache-" FC_CACHE_VERSION
+#define FC_DIR_CACHE_FILE	    "fonts.cache-" FC_CACHE_VERSION
+#define FC_USER_CACHE_FILE	    ".fonts.cache-" FC_CACHE_VERSION
 
 /* Adjust outline rasterizer */
 #define FC_CHAR_WIDTH	    "charwidth"	/* Int */
--
cgit v0.9.0.2-2-gbebe
