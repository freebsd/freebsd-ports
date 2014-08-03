--- ddr_ctrl.h.orig	2014-06-29 00:49:05.000000000 +0900
+++ ddr_ctrl.h	2014-06-29 00:49:52.000000000 +0900
@@ -10,6 +10,8 @@
 #ifndef _DDR_CTRL_H
 #define _DDR_CTRL_H
 
+typedef long long loff_t;
+
 /* Options */
 typedef struct _opt_t {
 	const char *iname, *oname, *lname, *bbname;
