--- nnpfs/bsd/nnpfs_syscalls-wrap-freebsd.c.orig	Sun Jun 27 00:39:27 2004
+++ nnpfs/bsd/nnpfs_syscalls-wrap-freebsd.c	Fri Jan  7 14:09:32 2005
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 1995 - 2002 Kungliga Tekniska Högskolan
+ * Copyright (c) 1995 - 2004 Kungliga Tekniska Högskolan
  * (Royal Institute of Technology, Stockholm, Sweden).
  * All rights reserved.
  *
@@ -33,7 +33,7 @@
 
 #include <nnpfs/nnpfs_locl.h>
 
-RCSID("$Id: nnpfs_syscalls-wrap-freebsd.c,v 1.15 2004/06/26 22:39:27 lha Exp $");
+RCSID("$Id: nnpfs_syscalls-wrap-freebsd.c,v 1.17 2005/01/07 13:09:32 lha Exp $");
 
 /*
  * NNPFS system calls.
@@ -68,7 +68,7 @@
 static int
 nnpfs_setgroups_freebsd (d_thread_t *proc, void *varg)
 {
-    int retval = 0;
+    register_t retval = 0;
     int ret;
 
     ret = nnpfs_setgroups(proc, varg, &retval);
