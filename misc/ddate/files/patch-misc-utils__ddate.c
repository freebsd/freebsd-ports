--- ./misc-utils/ddate.c.orig	2011-12-18 21:29:45.802837000 +0100
+++ ./misc-utils/ddate.c	2012-03-07 11:19:23.000000000 +0100
@@ -51,7 +51,7 @@
  * Church of the SubGenius and do not wish your copy of ddate(1) to contain
  * code for counting down to X-Day, undefine KILL_BOB */
 
-#define KILL_BOB 13013
+/* #define KILL_BOB 13013 */
 
 /* If you wish ddate(1) to contain SubGenius slogans, define PRAISE_BOB */
 
@@ -62,8 +62,9 @@
 #include <time.h>
 #include <stdio.h>
 
-#include "nls.h"
-#include "c.h"
+#include "../include/nls.h"
+#include "../include/c.h"
+#include "../config.h"
 
 #ifndef __GNUC__
 #define inline /* foo */
