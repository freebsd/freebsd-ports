--- crypto/lhash/lhash_test.cc.orig	2017-06-28 13:35:29 UTC
+++ crypto/lhash/lhash_test.cc
@@ -12,10 +12,6 @@
  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
 
-#if !defined(_POSIX_C_SOURCE)
-#define _POSIX_C_SOURCE 201410L
-#endif
-
 #include <openssl/lhash.h>
 
 #include <stdio.h>
