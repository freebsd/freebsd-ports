--- src/lib/libast/aso/aso.c.orig	2023-01-11 01:32:04.000000000 -0800
+++ src/lib/libast/aso/aso.c	2023-02-15 06:41:07.380213000 -0800
@@ -836,7 +836,7 @@
 
 #if defined(_aso_casptr)
 	if (!state.lockf)
-		return _aso_casptr((void**)p, o, n);
+		return _aso_cas64((void**)p, o, n);
 #endif
 	k = lock(state.data, 0, p);
 	if (*(void* volatile*)p == o)
