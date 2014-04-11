--- sash.c.orig
+++ sash.c
@@ -107,7 +107,7 @@
 		"srcName ... destName"
 	},
 
-#ifdef	HAVE_LINUX_CHROOT
+#if	HAVE_LINUX_CHROOT
 	{
 		"-chroot",	do_chroot,	2,	2,
 		"change root file system",
@@ -189,7 +189,7 @@
 		"[-sig] pid ..."
 	},
 
-#ifdef	HAVE_LINUX_LOSETUP
+#if	HAVE_LINUX_LOSETUP
 	{
 		"-losetup",	do_losetup,	3,	3,
 		"Associate a loopback device with a file",
@@ -253,7 +253,7 @@
 		"srcName ... destName"
 	},
 
-#ifdef	HAVE_LINUX_PIVOT
+#if	HAVE_LINUX_PIVOT
 	{
 		"-pivot_root",	do_pivot_root,	3,	3,
 		"pivot the root file system",
