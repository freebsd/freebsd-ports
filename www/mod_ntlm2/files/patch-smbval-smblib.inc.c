--- smbval/smblib.inc.c.orig	2008-07-03 01:44:33.000000000 +0400
+++ smbval/smblib.inc.c	2008-07-03 01:45:18.000000000 +0400
@@ -20,10 +20,10 @@
  * with this program; if not, write to the Free Software Foundation, Inc., 
  * 675 Mass Ave, Cambridge, MA 02139, USA. */
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 
-static int SMBlib_errno;
-static int SMBlib_SMB_Error;
+int SMBlib_errno;
+int SMBlib_SMB_Error;
 #define SMBLIB_ERRNO
 #define uchar unsigned char
 #include "smblib-priv.h"
@@ -32,7 +32,7 @@
 
 #include <signal.h>
 
-static SMB_State_Types SMBlib_State;
+SMB_State_Types SMBlib_State;
 
 /* Initialize the SMBlib package     */
 static int 
