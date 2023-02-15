--- src/lib/libast/aso/aso.c.orig	2022-10-21 20:05:14.000000000 -0700
+++ src/lib/libast/aso/aso.c	2023-02-15 06:39:08.156515000 -0800
@@ -836,7 +836,7 @@
 
 #if defined(_aso_casptr)
 	if (!state.lockf)
-		return _aso_casptr((void**)p, o, n);
+		return _aso_cas64((void**)p, o, n);
 #endif
 	k = lock(state.data, 0, p);
 	if (*(void* volatile*)p == o)
