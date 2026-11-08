-- environ is not declared by the FreeBSD headers; declare it. Not supported upstream.
--- jaxlib/mosaic/gpu/dump.cc.orig	2026-10-20 13:31:57 UTC
+++ jaxlib/mosaic/gpu/dump.cc
@@ -26,6 +26,9 @@ limitations under the License.
 #include <spawn.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+extern char** environ;
+#endif
 #endif
 
 #include <atomic>
