--- convert_size.c.orig	Sun Feb 20 15:53:46 2005
+++ convert_size.c	Sun Feb 20 15:54:02 2005
@@ -1,30 +1,30 @@
 /*++
-/* NAME
-/*	convert_size 3
-/* SUMMARY
-/*	string to size conversion
-/* SYNOPSIS
-/*	#include <convert_size.h>
-/*
-/*	size_t	convert_size(str)
-/*	const char *str;
-/* DESCRIPTION
-/*	convert_size() converts its argument to internal form. if the
-/*	argument ends in 'k', 'm' or 'g' the result is multiplied by
-/*	1024 (1K), 1048576 (1M), 1073741824 (1G), respectively.
-/*	The suffix is case insensitive.
-/* SEE ALSO
-/*	error(3) error reporting module.
-/* DIAGNOSTICS
-/*	The result is negative in case of error.
-/* LICENSE
-/*	This software is distributed under the IBM Public License.
-/* AUTHOR(S)
-/*	Wietse Venema
-/*	IBM T.J. Watson Research
-/*	P.O. Box 704
-/*	Yorktown Heights, NY 10598, USA
-/*--*/
+ * NAME
+ *	convert_size 3
+ * SUMMARY
+ *	string to size conversion
+ * SYNOPSIS
+ *	#include <convert_size.h>
+ *
+ *	size_t	convert_size(str)
+ *	const char *str;
+ * DESCRIPTION
+ *	convert_size() converts its argument to internal form. if the
+ *	argument ends in 'k', 'm' or 'g' the result is multiplied by
+ *	1024 (1K), 1048576 (1M), 1073741824 (1G), respectively.
+ *	The suffix is case insensitive.
+ * SEE ALSO
+ *	error(3) error reporting module.
+ * DIAGNOSTICS
+ *	The result is negative in case of error.
+ * LICENSE
+ *	This software is distributed under the IBM Public License.
+ * AUTHOR(S)
+ *	Wietse Venema
+ *	IBM T.J. Watson Research
+ *	P.O. Box 704
+ *	Yorktown Heights, NY 10598, USA
+ *--*/
 
 /* System library. */
 
