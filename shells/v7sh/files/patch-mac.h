diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ mac.h.orig mac.h
--- mac.h.orig	Fri Jun  4 02:51:01 2004
+++ mac.h	Sat Jun 19 18:42:23 2004
@@ -9,10 +9,12 @@
 
 #define LOCAL	static
 #define PROC	extern
+#define CONST	const
+#define EXTERN	extern
 #define TYPE	typedef
 #define STRUCT	TYPE struct
 #define UNION	TYPE union
-#define REG	register
+#define REG	/* register */
 
 #define IF	if(
 #define THEN	){
