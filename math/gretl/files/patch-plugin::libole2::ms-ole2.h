--- plugin/libole2/ms-ole.h.orig	Fri Apr 12 03:41:50 2002
+++ plugin/libole2/ms-ole.h	Thu Dec 19 06:28:05 2002
@@ -13,10 +13,10 @@
 
 /* This should be done in glib */
 /* Allin Cottrell modifications here */
+# include <sys/types.h>
 #ifndef _WIN32
 #	include <fcntl.h>	/* for mode_t */
 #else
-# include <sys/types.h>
 # ifdef notdef
 	typedef unsigned long mode_t;
 	typedef /* signed */ long off_t;
