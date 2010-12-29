--- ./xbmc/cores/DllLoader/exports/emu_msvcrt.h.orig	2010-05-28 21:31:42.000000000 +0200
+++ ./xbmc/cores/DllLoader/exports/emu_msvcrt.h	2010-12-01 12:17:34.210600869 +0100
@@ -35,9 +35,15 @@
 
 typedef void ( *PFV)(void);
 
+#if defined(__FreeBSD__)
+#define __IS_STDIN_STREAM(stream)   (stream->_file == STDIN_FILENO)
+#define __IS_STDOUT_STREAM(stream)  (stream->_file == STDOUT_FILENO)
+#define __IS_STDERR_STREAM(stream)  (stream->_file == STDERR_FILENO)
+#else
 #define __IS_STDIN_STREAM(stream)   (stream == stdin  || stream->_file == stdin->_file || stream->_file == 0)
 #define __IS_STDOUT_STREAM(stream)  (stream == stdout || stream->_file == stdout->_file || stream->_file == 1)
 #define __IS_STDERR_STREAM(stream)  (stream == stderr || stream->_file == stderr->_file || stream->_file == 2)
+#endif
 #define IS_STDIN_STREAM(stream)     (stream != NULL && __IS_STDIN_STREAM(stream))
 #define IS_STDOUT_STREAM(stream)    (stream != NULL && __IS_STDOUT_STREAM(stream))
 #define IS_STDERR_STREAM(stream)    (stream != NULL && __IS_STDERR_STREAM(stream))
