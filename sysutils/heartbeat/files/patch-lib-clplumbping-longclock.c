--- lib/clplumbing/longclock.c.orig	2008-08-18 07:32:19.000000000 -0500
+++ lib/clplumbing/longclock.c	2011-09-07 17:52:32.000000000 -0500
@@ -68,7 +68,7 @@
 #	define	TIMES_PARAM	&dummy_longclock_tms_struct
 #endif
 
-unsigned long
+clock_t
 cl_times(void)	/* Make times(2) behave rationally on Linux */
 {
 	clock_t		ret;
@@ -108,7 +108,7 @@
 	}
 	errno = save_errno;
 #endif /* DISABLE_TIMES_KLUDGE */
-	return (unsigned long)ret;
+	return ret;
 }
 
 #ifdef CLOCK_T_IS_LONG_ENOUGH
@@ -124,8 +124,9 @@
 
 #define	BITSPERBYTE	8
 #define	WRAPSHIFT	(BITSPERBYTE*sizeof(clock_t))
-#define MAXIMUMULONG	((unsigned long)~(0UL))
-#define MINJUMP		((MAXIMUMULONG/100UL)*99UL)
+#define WRAPAMOUNT	(((longclock_t) 1) << WRAPSHIFT)
+#define MAXIMUMCLOCK	(WRAPAMOUNT - 1)
+#define MINJUMP		((MAXIMUMCLOCK/100UL)*99UL)
 
 longclock_t
 time_longclock(void)
@@ -136,20 +137,20 @@
 	 * because then this can recurse infinitely; that is why the
 	 * cl_log call is where it is; found by Simon Graham. */
 	static	gboolean	calledbefore	= FALSE;
-	static	unsigned long	lasttimes	= 0L;
-	static	unsigned long	wrapcount	= 0L;
+	static	longclock_t	lasttimes	= 0L;
+	static	longclock_t	wrapcount	= 0L;
 	static	unsigned long	callcount	= 0L;
-	static	longclock_t	lc_wrapcount	= 0L;
-	unsigned long		timesval;
+	
+	longclock_t	timesval;
 
 	++callcount;
 
-	timesval = (unsigned long) cl_times();
+	timesval = ((longclock_t) cl_times()) & MAXIMUMCLOCK; /* this AND prevents sign extension */
 
 	if (calledbefore && timesval < lasttimes)  {
-		clock_t		jumpbackby = lasttimes - timesval;
+		longclock_t	jumpbackby = lasttimes - timesval;
 
-		if (jumpbackby < (clock_t)MINJUMP) {
+		if (jumpbackby < MINJUMP) {
 			/* Kernel weirdness */
 			cl_log(LOG_CRIT
 			,	"%s: clock_t from times(2) appears to"
@@ -172,8 +173,7 @@
 			   to double update of wrapcount! */
 
 			lasttimes = timesval;
-			++wrapcount;
-			lc_wrapcount = ((longclock_t)wrapcount) << WRAPSHIFT;
+			wrapcount += WRAPAMOUNT;
 
 			cl_log(LOG_INFO
 			,	"%s: clock_t wrapped around (uptime)."
@@ -184,7 +184,7 @@
 		lasttimes = timesval;
 		calledbefore = TRUE;
 	}
-	return (lc_wrapcount | (longclock_t)timesval);
+	return (wrapcount | timesval);
 }
 #endif	/* ! CLOCK_T_IS_LONG_ENOUGH */
 
