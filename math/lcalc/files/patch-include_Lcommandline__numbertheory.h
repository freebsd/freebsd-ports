--- include/Lcommandline_numbertheory.h.orig	2012-08-08 21:21:55 UTC
+++ include/Lcommandline_numbertheory.h
@@ -18,12 +18,15 @@
    with the package; see the file 'COPYING'. If not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
+   Patches borrowed from SageMath.
+
 */
 
 
 #ifndef Lcommandline_numbertheory_H
 #define Lcommandline_numbertheory_H
 
+#include <time.h>
 #include <stdlib.h>     //for things like srand
 #include <iostream>     //for input and output
 #include <iomanip>      //for manipulating output such as setprecision
