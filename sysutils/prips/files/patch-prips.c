--- prips.c.orig	Tue Dec 14 12:44:46 1999
+++ prips.c	Fri May 26 03:56:39 2006
@@ -1,8 +1,7 @@
+#include "prips.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
-#include <arpa/inet.h>
-#include "prips.h"
 
 #if !defined(INET_ADDRSTRLEN)
 #define INET_ADDRSTRLEN 16
