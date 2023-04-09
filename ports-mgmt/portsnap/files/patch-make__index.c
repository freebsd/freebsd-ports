--- make_index.c.orig	2023-04-09 15:19:46 UTC
+++ make_index.c
@@ -1,4 +1,6 @@
 /*-
+ * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
+ *
  * Copyright 2005 Colin Percival
  * All rights reserved
  *
@@ -25,7 +27,7 @@
  */
 
 #include <sys/cdefs.h>
-__FBSDID("$FreeBSD: src/usr.sbin/portsnap/make_index/make_index.c,v 1.5 2005/12/01 22:14:44 cperciva Exp $");
+__FBSDID("$FreeBSD$");
 
 #include <err.h>
 #include <stdio.h>
