--- mymalloc.c.orig	Sun Feb 20 15:51:11 2005
+++ mymalloc.c	Sun Feb 20 15:52:01 2005
@@ -1,46 +1,46 @@
 /*++
-/* NAME
-/*	mymalloc 3
-/* SUMMARY
-/*	memory management wrappers
-/* SYNOPSIS
-/*	#include <mymalloc.h>
-/*
-/*	char	*mymalloc(len)
-/*	int	len;
-/*
-/*	char	*myrealloc(ptr, len)
-/*	char	*ptr;
-/*	int	len;
-/*
-/*	char	*mystrdup(str)
-/*	const char *str;
-/* DESCRIPTION
-/*	This module performs low-level memory management with error
-/*	handling. A call of these functions either succeeds or it does
-/*	not return at all.
-/*
-/*	mymalloc() allocates the requested amount of memory. The memory
-/*	is not set to zero.
-/*
-/*	myrealloc() resizes memory obtained from mymalloc() or myrealloc()
-/*	to the requested size. The result pointer value may differ from
-/*	that given via the \fBptr\fR argument.
-/*
-/*	mystrdup() returns a dynamic-memory copy of its null-terminated
-/*	argument. This routine uses mymalloc().
-/* SEE ALSO
-/*	error(3) error reporting module.
-/* DIAGNOSTICS
-/*	Fatal errors: the requested amount of memory is not available.
-/* LICENSE
-/*	This software is distributed under the IBM Public License.
-/* AUTHOR(S)
-/*	Wietse Venema
-/*	IBM T.J. Watson Research
-/*	P.O. Box 704
-/*	Yorktown Heights, NY 10598, USA
-/*--*/
+ * NAME
+ *	mymalloc 3
+ * SUMMARY
+ *	memory management wrappers
+ * SYNOPSIS
+ *	#include <mymalloc.h>
+ *
+ *	char	*mymalloc(len)
+ *	int	len;
+ *
+ *	char	*myrealloc(ptr, len)
+ *	char	*ptr;
+ *	int	len;
+ *
+ *	char	*mystrdup(str)
+ *	const char *str;
+ * DESCRIPTION
+ *	This module performs low-level memory management with error
+ *	handling. A call of these functions either succeeds or it does
+ *	not return at all.
+ *
+ *	mymalloc() allocates the requested amount of memory. The memory
+ *	is not set to zero.
+ *
+ *	myrealloc() resizes memory obtained from mymalloc() or myrealloc()
+ *	to the requested size. The result pointer value may differ from
+ *	that given via the \fBptr\fR argument.
+ *
+ *	mystrdup() returns a dynamic-memory copy of its null-terminated
+ *	argument. This routine uses mymalloc().
+ * SEE ALSO
+ *	error(3) error reporting module.
+ * DIAGNOSTICS
+ *	Fatal errors: the requested amount of memory is not available.
+ * LICENSE
+ *	This software is distributed under the IBM Public License.
+ * AUTHOR(S)
+ *	Wietse Venema
+ *	IBM T.J. Watson Research
+ *	P.O. Box 704
+ *	Yorktown Heights, NY 10598, USA
+ *--*/
 
 /* System library. */
 
