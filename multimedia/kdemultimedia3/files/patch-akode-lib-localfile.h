===================================================================
RCS file: /home/kde/kdemultimedia/akode/lib/localfile.h,v
retrieving revision 1.6
retrieving revision 1.7
diff -u -r1.6 -r1.7
--- akode/lib/localfile.h	2004/07/29 14:45:13	1.6
+++ akode/lib/localfile.h	2004/09/19 19:16:50	1.7
@@ -23,6 +23,15 @@
 
 #include "file.h"
 
+#ifdef __FreeBSD__
+// There is an unfortunate #define in some obscure FBSD system
+// header that turns fileno into a macro to account for threading
+// issues; we undef it in this case.
+#ifdef fileno
+#undef fileno
+#endif
+#endif
+
 namespace aKode {
 
 //! An implementation of the File interface for local-file access
