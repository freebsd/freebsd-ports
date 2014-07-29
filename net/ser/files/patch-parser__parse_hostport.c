
$FreeBSD$

--- parser/parse_hostport.c.orig
+++ parser/parse_hostport.c
@@ -25,8 +25,6 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
-#ifdef _OBSOLETED
-
 #include "parse_hostport.h"
 #include <string.h>    /* strlen */
 #include "../dprint.h"
@@ -43,7 +41,6 @@
 	if (*tmp==0) {
 		*port=0;
 	} else {
-		*tmp=0;
 		*port=str2s((unsigned char*)(tmp+1), strlen(tmp+1), &err);
 		if (err ){
 			LOG(L_INFO, 
@@ -56,4 +53,3 @@
 	return host->s;
 }
 
-#endif
