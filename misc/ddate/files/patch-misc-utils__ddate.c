--- ./misc-utils/ddate.c.orig	2012-07-23 23:21:56.336319000 +0200
+++ ./misc-utils/ddate.c	2012-11-23 21:47:57.000000000 +0100
@@ -51,7 +51,9 @@
  * Church of the SubGenius and do not wish your copy of ddate(1) to contain
  * code for counting down to X-Day, undefine KILL_BOB */
 
+/*
 #define KILL_BOB 13013
+*/
 
 /* If you wish ddate(1) to contain SubGenius slogans, define PRAISE_BOB */
 
@@ -62,9 +64,10 @@
 #include <time.h>
 #include <stdio.h>
 
-#include "nls.h"
-#include "closestream.h"
-#include "c.h"
+#include "../include/nls.h"
+#include "../include/closestream.h"
+#include "../include/c.h"
+#include "../config.h"
 
 #ifndef __GNUC__
 #define inline /* foo */
