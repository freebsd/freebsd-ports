Backport of upstream commit 0d08c4e (fixes issue #291), not yet in a
release version.

https://github.com/AltraMayor/f3/commit/0d08c4e367f08fc4930badf07c9bcfd6567d4d7b

--- src/libutils.h.orig	2026-05-01 15:47:00 UTC
+++ src/libutils.h
@@ -26,10 +26,12 @@
 		return a < b ? a : b;			\
 	}
 
+GEN_MIN(ui, unsigned int)
 GEN_MIN(ul, unsigned long)
 GEN_MIN(ull, unsigned long long)
 
 #define MIN(a, b) _Generic(1 ? (a) : (b),	\
+	unsigned int: ui_min,			\
 	unsigned long: ul_min,			\
 	unsigned long long: ull_min		\
 	)(a, b)
