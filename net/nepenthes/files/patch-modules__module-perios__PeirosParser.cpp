--- modules/module-peiros/PeirosParser.cpp.orig
+++ modules/module-peiros/PeirosParser.cpp
@@ -18,8 +18,9 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  */
 
-#include <ctype.h>
-#include <stdio.h>
+#include <cctype>
+#include <cstdio>
+#include <cstdlib>
 #include "PeirosParser.hpp"
 #include "Nepenthes.hpp"
 #include "LogManager.hpp"
