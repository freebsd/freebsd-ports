--- ddr_ctrl.h.orig	2016-12-28 22:37:15 UTC
+++ ddr_ctrl.h
@@ -10,6 +10,8 @@
 #ifndef _DDR_CTRL_H
 #define _DDR_CTRL_H
 
+typedef long long loff_t;
+
 /* Options */
 typedef struct _opt_t {
 	const char *iname, *oname, *lname, *bbname;
