--- smbval/smblib.inc.c.orig	Wed Sep 26 12:42:22 2007
+++ smbval/smblib.inc.c	Wed Sep 26 12:43:08 2007
@@ -20,7 +20,7 @@
  * with this program; if not, write to the Free Software Foundation, Inc., 
  * 675 Mass Ave, Cambridge, MA 02139, USA. */
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 static int SMBlib_errno;
 static int SMBlib_SMB_Error;
