--- fileio.h	Sat Jan  6 14:46:36 1996
+++ fileio.h.new	Wed Jun 11 20:35:03 2003
@@ -28,7 +28,7 @@
 #ifdef LINUX
 #  define PGP_SYSTEM_DIR "/var/lib/pgp/"
 #else
-#  define PGP_SYSTEM_DIR "/usr/local/lib/pgp/"
+#  define PGP_SYSTEM_DIR PREFIX "/share/pgp/"
 #endif
 #define FOPRBIN		"r"
 #define FOPRTXT		"r"
