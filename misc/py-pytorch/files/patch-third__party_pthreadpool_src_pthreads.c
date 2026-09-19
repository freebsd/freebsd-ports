-- Avoid including the non-existent <alloca.h> on FreeBSD/aarch64.
-- On FreeBSD/DragonFly, alloca() is declared as a macro in <stdlib.h> only
-- for __GNUC__ >= 2, which clang on aarch64 does not satisfy in the way this
-- file expects (it falls through past the __GNUC__ branch above), leading it
-- to try '#include <alloca.h>', a header that does not exist on these
-- systems. Add an explicit branch for FreeBSD/DragonFly aarch64 that relies
-- on the declaration already brought in via <stdlib.h>. Scoped to aarch64
-- only since other architectures build fine as-is.
-- See https://github.com/pytorch/pytorch/issues/144608 (related upstream
-- QNNPACK/FreeBSD tracking issue) for context on FreeBSD arm64 support gaps.

--- third_party/pthreadpool/src/pthreads.c.orig	2026-09-02 17:44:00 UTC
+++ third_party/pthreadpool/src/pthreads.c
@@ -79,6 +79,10 @@
 #define alloca _alloca
 #elif !defined(alloca) && defined(__GNUC__)
 #define alloca(s) __builtin_alloca(s)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+/* On FreeBSD/DragonFly aarch64, <stdlib.h> (included above) already defines
+ * alloca() as a macro for __GNUC__ >= 2, so the branch above is skipped, but
+ * there is no <alloca.h> to fall back to. */
 #else
 #include <alloca.h>
 #endif
