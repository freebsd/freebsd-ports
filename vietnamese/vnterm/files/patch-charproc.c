--- charproc.c.orig	Mon Aug 21 08:47:46 2000
+++ charproc.c	Sun Sep  8 16:41:40 2002
@@ -72,6 +72,10 @@
 #include <X11/Shell.h>
 #endif /* NO_ACTIVE_ICON */
 
+#ifndef NO_VIETNAMESE
+#include <vnkeys.h>
+#endif /* NO_VIETNAMESE */
+
 /*
  * Check for both EAGAIN and EWOULDBLOCK, because some supposedly POSIX
  * systems are broken and return EWOULDBLOCK when they should return EAGAIN.
@@ -91,9 +95,11 @@
 
 extern XtAppContext app_con;
 extern Widget toplevel;
+#if 0	/* get these from std headers... */
 extern void exit();
 extern char *malloc();
 extern char *realloc();
+#endif
 extern fd_set Select_mask;
 extern fd_set X_mask;
 extern fd_set pty_mask;
@@ -619,6 +625,10 @@
 	for( ; ; ) {
 	        switch (parsestate[c = doinput()]) {
 		 case CASE_PRINT:
+#ifndef NO_VIETNAMESE
+label_CASE_PRINT:     /* for escaping from the CASE_IGNORE
+			state with Vietnamese characters */
+#endif /* NO_VIETNAMESE */
 			/* printable characters */
 			top = bcnt > TEXT_BUF_SIZE ? TEXT_BUF_SIZE : bcnt;
 			cp = bptr;
@@ -656,6 +666,9 @@
 			break;
 
 		 case CASE_IGNORE:
+#ifndef NO_VIETNAMESE
+			if (isgraph(c)) goto label_CASE_PRINT;
+#endif /* NO_VIETNAMESE */
 			/* Ignore character */
 			break;
 
@@ -666,17 +679,32 @@
 
 		 case CASE_BS:
 			/* backspace */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			CursorBack(screen, 1);
 			break;
 
 		 case CASE_CR:
 			/* carriage return */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			CarriageReturn(screen);
 			parsestate = groundtable;
 			break;
 
 		 case CASE_ESC:
 			/* escape */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			parsestate = esctable;
 			break;
 
@@ -684,6 +712,11 @@
 			/*
 			 * form feed, line feed, vertical tab
 			 */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			Index(screen, 1);
 			if (term->flags & LINEFEED)
 				CarriageReturn(screen);
@@ -695,6 +728,11 @@
 
 		 case CASE_TAB:
 			/* tab */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			screen->cur_col = TabNext(term->tabs, screen->cur_col);
 			if (screen->cur_col > screen->max_col)
 				screen->cur_col = screen->max_col;
@@ -762,6 +800,11 @@
 
 		 case CASE_ICH:
 			/* ICH */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			InsertChar(screen, row);
@@ -770,6 +813,11 @@
 
 		 case CASE_CUU:
 			/* CUU */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			CursorUp(screen, row);
@@ -778,6 +826,11 @@
 
 		 case CASE_CUD:
 			/* CUD */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			CursorDown(screen, row);
@@ -786,6 +839,11 @@
 
 		 case CASE_CUF:
 			/* CUF */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			CursorForward(screen, row);
@@ -794,6 +852,11 @@
 
 		 case CASE_CUB:
 			/* CUB */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			CursorBack(screen, row);
@@ -802,6 +865,11 @@
 
 		 case CASE_CUP:
 			/* CUP | HVP */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			if(nparam < 2 || (col = param[1]) < 1)
@@ -821,6 +889,11 @@
 
 		 case CASE_ED:
 			/* ED */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			switch (param[0]) {
 			 case DEFAULT:
 			 case 0:
@@ -840,6 +913,11 @@
 
 		 case CASE_EL:
 			/* EL */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			switch (param[0]) {
 			 case DEFAULT:
 			 case 0:
@@ -857,6 +935,11 @@
 
 		 case CASE_IL:
 			/* IL */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			InsertLine(screen, row);
@@ -865,6 +948,11 @@
 
 		 case CASE_DL:
 			/* DL */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			DeleteLine(screen, row);
@@ -873,6 +961,11 @@
 
 		 case CASE_DCH:
 			/* DCH */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			if((row = param[0]) < 1)
 				row = 1;
 			DeleteChar(screen, row);
@@ -1092,6 +1185,11 @@
 
 		 case CASE_NEL:
 			/* NEL */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			Index(screen, 1);
 			CarriageReturn(screen);
 			
@@ -1109,6 +1207,11 @@
 
 		 case CASE_RI:
 			/* RI */
+#ifndef NO_VIETNAMESE
+			/* flush the Vietnamese FSM */
+			dotext(screen, term->flags,
+				screen->gsets[screen->curgl], 0, 0);
+#endif /* NO_VIETNAMESE */
 			RevIndex(screen, 1);
 			parsestate = groundtable;
 			break;
@@ -1460,6 +1563,13 @@
 	register int	len;
 	register int	n;
 	register int	next_col;
+#ifndef NO_VIETNAMESE
+	extern Boolean        vn_filter_screen;
+	extern Vk_Fsm vn_screen_id;
+	unsigned char buf2[TEXT_BUF_SIZE+3]; /* at most three pending
+						chars from previous
+						call */
+#endif /* NO_VIETNAMESE */
 
 	switch (charset) {
 	case 'A':	/* United Kingdom set			*/
@@ -1480,6 +1590,32 @@
 	default:	/* any character sets we don't recognize*/
 		return;
 	}
+
+#ifndef NO_VIETNAMESE
+	if (buf == 0 && ptr == 0) { /* flush the FSM */
+
+		int                 count;
+
+		vk_flush(vn_screen_id, buf2, &count);
+		buf = (char *)buf2;
+		ptr = (char *)buf + count;
+	} else if (vn_filter_screen) {
+		/* translate output into 8-bit Vietnamese */
+		register unsigned char      *s1, *s2;
+		register int        i;
+		unsigned char       outchars[5];
+		int                 count;
+
+		for (s1 = (unsigned char*)buf, s2 = buf2;
+			s1 < (unsigned char*)ptr; s1++) {
+			vk_step(vn_screen_id, *s1, outchars, &count);
+			for (i = 0; i < count; i++) *s2++ = outchars[i];
+		}
+
+		buf = (char *)buf2;
+		ptr = (char *)s2;
+	}
+#endif /* NO_VIETNAMESE */
 
 	len = ptr - buf; 
 	ptr = buf;
