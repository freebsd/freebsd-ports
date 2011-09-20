--- include/clplumbing/longclock.h.orig	2008-08-18 07:32:19.000000000 -0500
+++ include/clplumbing/longclock.h	2011-09-07 16:43:50.000000000 -0500
@@ -37,7 +37,7 @@
  *
  *	The functions provided here are:
  *
- *	unsigned long	cl_times(void);
+ *	clock_t		cl_times(void);
  *			A rational wrapper for the times(2) call
  *			for those cases where only the return value
  *			is wanted.
@@ -79,7 +79,7 @@
  *
  *	extern const longclock_t	zero_longclock;
  */
-extern unsigned long cl_times(void);
+extern clock_t cl_times(void);
 
 #ifdef CLOCK_T_IS_LONG_ENOUGH
 #	ifndef	HAVE_LONGCLOCK_ARITHMETIC
