--- ./libssh/auth.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/auth.c	2009-07-09 08:21:13.000000000 +1000
@@ -22,12 +22,17 @@
  * MA 02111-1307, USA.
  */
 
-#include "libssh/priv.h"
-#include "libssh/ssh2.h"
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
+#include "libssh/priv.h"
+#include "libssh/ssh2.h"
+
 /** \defgroup ssh_auth SSH Authentication functions
  * \brief functions to authenticate to servers
  */
