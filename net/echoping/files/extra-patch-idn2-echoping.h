--- echoping.h.orig	2025-05-05 00:28:45.991560000 +0700
+++ echoping.h	2025-05-05 01:41:01.729365000 +0700
@@ -52,8 +52,7 @@
 #endif
 
 #ifdef LIBIDN
-#include <stringprep.h>		/* stringprep_locale_to_utf8() */
-#include <idna.h>		/* idna_to_ascii_from_utf8() */
+#include <idn2.h>		/* idna_to_ascii_from_utf8() */
 #endif
 
 #ifndef FALSE
