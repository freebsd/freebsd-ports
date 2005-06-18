--- asterisk-driver/chan_oh323.c.orig	Tue Dec 21 17:28:11 2004
+++ asterisk-driver/chan_oh323.c	Fri Jun 17 13:23:19 2005
@@ -56,6 +56,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <math.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <sys/signal.h>
 
@@ -1155,7 +1156,7 @@ static struct ast_frame *oh323_exception
 	p->fr.src = type;
 	p->fr.offset = 0;
 	p->fr.mallocd = 0;
-	p->fr.src = __FUNCTION__;
+	p->fr.src = "oh323_exception";
 
 	/* -- User input */
 	if (p->except_struct.type == OH323EXC_USER_INPUT_TONE) {
@@ -1770,7 +1771,7 @@ static struct ast_frame *oh323_read(stru
 	p->fr.src = type;
 	p->fr.offset = AST_FRIENDLY_OFFSET;
 	p->fr.samples = 0;
-	p->fr.src = __FUNCTION__;
+	p->fr.src = "oh323_read";
 
 	/* Check the event pipe */
 	//CHECK_BLOCKING(c);
