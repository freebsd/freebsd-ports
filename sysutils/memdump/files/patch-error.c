--- error.c.orig	Sun Feb 20 15:52:40 2005
+++ error.c	Sun Feb 20 15:53:14 2005
@@ -1,59 +1,59 @@
 /*++
-/* NAME
-/*	error 3
-/* SUMMARY
-/*	diagnostics handlers
-/* SYNOPSIS
-/*	#include <error.h>
-/*
-/*	void	error(format, ...)
-/*	char	*format;
-/*
-/*	void	remark(format, ...)
-/*	char	*format;
-/*
-/*	void	panic(format, ...)
-/*	char	*format;
-/*
-/*	char	*progname;
-/*	int	verbose;
-/* DESCRIPTION
-/*	This module reports diagnostics. Each routine produces a one-line
-/*	record with the program name and a caller-provided informative
-/*	message. In the format string, %m is replaced by the text that
-/*	corresponds to the present \fBerrno\fR value.
-/*
-/*	error() writes a message to the standard error stream and
-/*	terminates the process with a non-zero exit status.
-/*
-/*	remark() writes a message to the standard error stream.
-/*
-/*	panic() writes a message to the standard error stream and
-/*	forces a core dump.
-/*
-/*	progname is a global variable that the application should
-/*	assign the program name. The initial value is a pointer to
-/*	the string \fB"unknown"\fR.
-/*
-/*	verbose is a global variable (initially, zero), that exists
-/*	solely for the convenience of the application. Typical usage
-/*	is like:
-/*
-/* .ti +5
-/*	if (verbose) remark(...);
-/* SEE ALSO
-/*	errno(2) error numbers
-/* HISTORY
-/*	error() and remark() appear in "Software Tools" by B.W. Kernighan
-/*	and P.J. Plaugher.
-/* LICENSE
-/*	This software is distributed under the IBM Public License.
-/* AUTHOR(S)
-/*	Wietse Venema
-/*	IBM T.J. Watson Research
-/*	P.O. Box 704
-/*	Yorktown Heights, NY 10598, USA
-/*--*/
+ * NAME
+ *	error 3
+ * SUMMARY
+ *	diagnostics handlers
+ * SYNOPSIS
+ *	#include <error.h>
+ *
+ *	void	error(format, ...)
+ *	char	*format;
+ *
+ *	void	remark(format, ...)
+ *	char	*format;
+ *
+ *	void	panic(format, ...)
+ *	char	*format;
+ *
+ *	char	*progname;
+ *	int	verbose;
+ * DESCRIPTION
+ *	This module reports diagnostics. Each routine produces a one-line
+ *	record with the program name and a caller-provided informative
+ *	message. In the format string, %m is replaced by the text that
+ *	corresponds to the present \fBerrno\fR value.
+ *
+ *	error() writes a message to the standard error stream and
+ *	terminates the process with a non-zero exit status.
+ *
+ *	remark() writes a message to the standard error stream.
+ *
+ *	panic() writes a message to the standard error stream and
+ *	forces a core dump.
+ *
+ *	progname is a global variable that the application should
+ *	assign the program name. The initial value is a pointer to
+ *	the string \fB"unknown"\fR.
+ *
+ *	verbose is a global variable (initially, zero), that exists
+ *	solely for the convenience of the application. Typical usage
+ *	is like:
+ *
+ * .ti +5
+ *	if (verbose) remark(...);
+ * SEE ALSO
+ *	errno(2) error numbers
+ * HISTORY
+ *	error() and remark() appear in "Software Tools" by B.W. Kernighan
+ *	and P.J. Plaugher.
+ * LICENSE
+ *	This software is distributed under the IBM Public License.
+ * AUTHOR(S)
+ *	Wietse Venema
+ *	IBM T.J. Watson Research
+ *	P.O. Box 704
+ *	Yorktown Heights, NY 10598, USA
+ *--*/
 
 /* System library. */
 
