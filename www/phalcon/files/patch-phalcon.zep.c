--- phalcon.zep.c.orig	2024-08-03 14:25:29 UTC
+++ phalcon.zep.c
@@ -62,8 +62,12 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
 #include <ext/standard/info.h>
 #include <ext/standard/file.h>
 #include <ext/standard/php_filestat.h>
+#if PHP_VERSION_ID <= 80300
 #include <ext/standard/php_rand.h>
 #include <ext/standard/php_lcg.h>
+#else
+#include <ext/random/php_random.h>
+#endif
 #include <ext/standard/php_math.h>
 #include <ext/standard/php_array.h>
 #include <ext/standard/php_var.h>
