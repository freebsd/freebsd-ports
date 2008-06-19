--- clients/ftp/domacro.c
+++ clients/ftp/domacro.c
@@ -42,7 +42,7 @@
 #include <errno.h>
 #include <ctype.h>
 
-#if !defined(SCO) && !defined(_SEQUENT_) && !defined(linux)
+#if !defined(SCO) && !defined(_SEQUENT_) && !defined(linux) && !defined(__FreeBSD__)
 #include <sys/ttychars.h>
 #endif
 
