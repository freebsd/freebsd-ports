--- src/IGBheader.cc.orig	Tue Oct 15 02:15:19 2002
+++ src/IGBheader.cc	Tue Oct 15 02:15:44 2002
@@ -17,7 +17,10 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 #include<stdlib.h>
+#include <iostream>
 #include "IGBheader.h"
+
+using namespace std;
 
 /* -------------- Bits de statut pour Header_Read et Header_Write ------ */
 
