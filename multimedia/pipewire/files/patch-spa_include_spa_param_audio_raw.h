--- spa/include/spa/param/audio/raw.h.orig	2024-09-27 10:02:20 UTC
+++ spa/include/spa/param/audio/raw.h
@@ -11,9 +11,7 @@ extern "C" {
 
 #include <stdint.h>
 
-#if !defined(__FreeBSD__) && !defined(__MidnightBSD__)
 #include <endian.h>
-#endif
 
 /**
  * \addtogroup spa_param
