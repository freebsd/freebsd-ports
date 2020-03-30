--- include/Lglobals.h.orig	2012-08-08 21:21:55 UTC
+++ include/Lglobals.h
@@ -18,15 +18,17 @@
    with the package; see the file 'COPYING'. If not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
+   Patches borrowed from SageMath.
+
 */
 
 
 #ifndef Lglobals_H
 #define Lglobals_H
 
+#include <valarray>
 using namespace std;
 
-#include <valarray>
 #ifdef USE_MPFR
     #include "Lgmpfrxx.h"
     typedef mpfr_class Double;
