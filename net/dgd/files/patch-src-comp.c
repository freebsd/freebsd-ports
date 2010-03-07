$FreeBSD$

--- src/comp/comp.c.orig	2010-02-20 08:34:08.000000000 -0800
+++ src/comp/comp.c	2010-02-20 08:34:17.000000000 -0800
@@ -631,7 +631,7 @@
  * NAME:	comm->init()
  * DESCRIPTION:	pretend to initialize communications
  */
-#ifndef NETWORK_EXTENSION
+#ifndef NETWORK_EXTENSIONS
 bool comm_init(n, thosts, bhosts, tports, bports, ntelnet, nbinary)
 int n, ntelnet, nbinary;
 #else
@@ -765,7 +765,7 @@
  * NAME:	comm->users()
  * DESCRIPTION:	pretend to return an array with all user objects
  */
-#ifndef NETWORK_EXTENSION
+#ifndef NETWORK_EXTENSIONS
 array *comm_users(data)
 dataspace *data;
 {
