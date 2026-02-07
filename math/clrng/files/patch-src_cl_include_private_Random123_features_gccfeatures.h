--- src/cl/include/private/Random123/features/gccfeatures.h.orig	2020-01-02 12:50:28 UTC
+++ src/cl/include/private/Random123/features/gccfeatures.h
@@ -44,7 +44,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
  Please let the authors know of any successes (or failures). */
 #endif
 
-#ifdef __powerpc__
+#if defined(__powerpc__) && !defined(__clang__)
 #include <ppu_intrinsics.h>
 #endif
 
