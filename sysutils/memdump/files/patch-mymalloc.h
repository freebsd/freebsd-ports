--- mymalloc.h.orig	Sun Feb 20 15:48:02 2005
+++ mymalloc.h	Sun Feb 20 15:49:36 2005
@@ -1,14 +1,14 @@
 /*++
-/* NAME
-/*	mymalloc 3h
-/* SUMMARY
-/*	memory management wrappers
-/* SYNOPSIS
-/*	#include "mymalloc.h"
-/* DESCRIPTION
-/* .nf
+ * NAME
+ *	mymalloc 3h
+ * SUMMARY
+ *	memory management wrappers
+ * SYNOPSIS
+ *	#include "mymalloc.h"
+ * DESCRIPTION
+ * .nf
 
- /*
+  *
   * External interface.
   */
 extern char *mymalloc(int);
@@ -16,12 +16,12 @@
 extern char *mystrdup(const char *);
 
 /* LICENSE
-/* .ad
-/* .fi
-/*	The IBM Public License must be distributed with this software.
-/* AUTHOR(S)
-/*	Wietse Venema
-/*	IBM T.J. Watson Research
-/*	P.O. Box 704
-/*	Yorktown Heights, NY 10598, USA
-/*--*/
+ * .ad
+ * .fi
+ *	The IBM Public License must be distributed with this software.
+ * AUTHOR(S)
+ *	Wietse Venema
+ *	IBM T.J. Watson Research
+ *	P.O. Box 704
+ *	Yorktown Heights, NY 10598, USA
+ *--*/
