
$FreeBSD$

--- IDEA.xs	2002/10/21 11:18:42	1.1
+++ IDEA.xs	2002/10/21 11:27:32
@@ -9,6 +9,10 @@
 
 #include "idea.h"
 
+#ifndef sv_undef
+#define sv_undef PL_sv_undef
+#endif
+
 MODULE = Crypt::IDEA		PACKAGE = Crypt::IDEA		PREFIX = idea_
 
 char *
