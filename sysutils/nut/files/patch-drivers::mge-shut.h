--- drivers/mge-shut.h.orig	Mon Sep  8 16:05:30 2003
+++ drivers/mge-shut.h	Mon Sep  8 16:06:24 2003
@@ -166,7 +166,7 @@
   char	item_path[MAX_STRING];		/* HID object (fully qualified string path) */
   char	fmt[6];						/* printf format string for INFO entry   */
   char	*dfl;						/* default value */
-  ulong	shut_flags;					/* specific SHUT flags */
+  unsigned long	shut_flags;					/* specific SHUT flags */
 } mge_info_item;
 
 /* Array containing information to translate between UTalk and NUT info
