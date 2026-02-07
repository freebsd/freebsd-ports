diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ stak.h.orig stak.h
--- stak.h.orig	Fri Jun  4 02:51:02 2004
+++ stak.h	Sat Jun 19 18:42:24 2004
@@ -34,7 +34,7 @@
 /* for local use only since it hands
  * out a real address for the stack top
  */
-STKPTR		locstak();
+PROC STKPTR	locstak(VOID);
 
 /* Will allocate the item being used and return its
  * address (safe now).
@@ -44,33 +44,36 @@
 /* For use after `locstak' to hand back
  * new stack top and then allocate item
  */
-STKPTR		endstak();
+PROC STKPTR	endstak(STRING);
 
 /* Copy a string onto the stack and
  * allocate the space.
  */
-STKPTR		cpystak();
+PROC STKPTR	cpystak(CSTKPTR);
 
 /* Allocate given ammount of stack space */
-STKPTR		getstak();
+PROC STKPTR	getstak(POS);
 
 /* A chain of ptrs of stack blocks that
  * have become covered by heap allocation.
  * `tdystak' will return them to the heap.
  */
-BLKPTR		stakbsy;
+EXTERN BLKPTR		stakbsy;
 
 /* Base of the entire stack */
-STKPTR		stakbas;
+EXTERN STKPTR		stakbas;
 
 /* Top of entire stack */
-STKPTR		brkend;
+EXTERN STKPTR		brkend;
 
 /* Base of current item */
-STKPTR		stakbot;
+EXTERN STKPTR		stakbot;
 
 /* Top of current item */
-STKPTR		staktop;
+EXTERN STKPTR		staktop;
 
 /* Used with tdystak */
-STKPTR		savstak();
+PROC STKPTR	savstak(VOID);
+
+PROC VOID	tdystak(STKPTR);
+PROC VOID	stakchk(VOID);
