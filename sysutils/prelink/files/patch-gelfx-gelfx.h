diff -Nur gelfx/gelfx.h gelfx/gelfx.h
--- gelfx/gelfx.h	2013-02-19 23:54:34.000000000 +0200
+++ gelfx/gelfx.h	2013-02-19 23:50:32.000000000 +0200
@@ -19,8 +19,12 @@
 #ifndef GELFX_H
 #define	GELFX_H
 
+#include "../gelf/elf.h"
+#define _SYS_ELF32_H_ 1
+#define _SYS_ELF64_H_ 1
 #include <libelf.h>
-#include <gelf.h>
+#include "../gelf/gelf.h"
+#undef HAVE_GELFX_GETSHDR
 
 #ifndef HAVE_GELFX_GETSHDR
 
