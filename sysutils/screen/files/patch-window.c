--- window.c.orig	2025-05-15 15:31:27 UTC
+++ window.c
@@ -61,7 +61,7 @@ static void WinRestore(void);
 static void WinClearLine(int, int, int, int);
 static int WinResize(int, int);
 static void WinRestore(void);
-static int DoAutolf(char *, size_t *, int);
+static int DoAutolf(char *, int *, int);
 static void ZombieProcess(char **, size_t *);
 static void win_readev_fn(Event *, void *);
 static void win_writeev_fn(Event *, void *);
@@ -74,9 +74,9 @@ static int ForkWindow(Window *, char **, char *);
 static void win_destroyev_fn(Event *, void *);
 
 static int ForkWindow(Window *, char **, char *);
-static void zmodem_found(Window *, int, char *, size_t);
+static void zmodem_found(Window *, int, char *, int);
 static void zmodemFin(char *, size_t, void *);
-static int zmodem_parse(Window *, char *, size_t);
+static int zmodem_parse(Window *, char *, int);
 
 bool VerboseCreate = false;		/* XXX move this to user.h */
 
@@ -191,10 +191,10 @@ const struct LayFuncs WinLf = {
 	NULL
 };
 
-static int DoAutolf(char *buf, size_t *lenp, int fr)
+static int DoAutolf(char *buf, int *lenp, int fr)
 {
 	char *p;
-	size_t len = *lenp;
+	int len = *lenp;
 	int trunc = 0;
 
 	for (p = buf; len > 0; p++, len--) {
@@ -215,7 +215,7 @@ static void WinProcess(char **bufpp, size_t *lenp)
 
 static void WinProcess(char **bufpp, size_t *lenp)
 {
-	size_t l2 = 0, f, *ilen, l = *lenp, trunc;
+	int l2 = 0, f, *ilen, l = *lenp, trunc;
 	char *ibuf;
 
 	fore = (Window *)flayer->l_data;
@@ -291,7 +291,7 @@ static void ZombieProcess(char **bufpp, size_t *lenp)
 
 static void ZombieProcess(char **bufpp, size_t *lenp)
 {
-	size_t l = *lenp;
+	int l = *lenp;
 	char *buf = *bufpp, b1[10], b2[10];
 
 	fore = (Window *)flayer->l_data;
@@ -699,7 +699,7 @@ int MakeWindow(struct NewWindow *newwin)
 	p->w_readev.data = p->w_writeev.data = (char *)p;
 	p->w_readev.handler = win_readev_fn;
 	p->w_writeev.handler = win_writeev_fn;
-	p->w_writeev.condpos = (int *)&p->w_inlen;
+	p->w_writeev.condpos = &p->w_inlen;
 	evenq(&p->w_readev);
 	evenq(&p->w_writeev);
 	p->w_paster.pa_slowev.type = EV_TIMEOUT;
@@ -1344,7 +1344,7 @@ int winexec(char **av)
 	pwin->p_readev.data = pwin->p_writeev.data = (char *)w;
 	pwin->p_readev.handler = pseu_readev_fn;
 	pwin->p_writeev.handler = pseu_writeev_fn;
-	pwin->p_writeev.condpos = (int *)&pwin->p_inlen;
+	pwin->p_writeev.condpos = &pwin->p_inlen;
 	if (pwin->p_fdpat & (F_PFRONT << F_PSHIFT * 2 | F_PFRONT << F_PSHIFT))
 		evenq(&pwin->p_readev);
 	evenq(&pwin->p_writeev);
@@ -1378,7 +1378,7 @@ void FreePseudowin(Window *w)
 	}
 	evdeq(&pwin->p_readev);
 	evdeq(&pwin->p_writeev);
-	if (w->w_readev.condneg == (int *)&pwin->p_inlen)
+	if (w->w_readev.condneg == &pwin->p_inlen)
 		w->w_readev.condpos = w->w_readev.condneg = NULL;
 	evenq(&w->w_readev);
 	free((char *)pwin);
@@ -1484,7 +1484,7 @@ static void win_readev_fn(Event *event, void *data)
 		size = IOSIZE - p->w_pwin->p_inlen;
 		if (size <= 0) {
 			event->condpos = &const_IOSIZE;
-			event->condneg = (int *)&p->w_pwin->p_inlen;
+			event->condneg = &p->w_pwin->p_inlen;
 			return;
 		}
 	}
@@ -1563,7 +1563,7 @@ static void win_writeev_fn(Event *event, void *data)
 static void win_writeev_fn(Event *event, void *data)
 {
 	Window *p = (Window *)data;
-	size_t len;
+	int len;
 	if (p->w_inlen) {
 		if ((len = write(event->fd, p->w_inbuf, p->w_inlen)) <= 0)
 			len = p->w_inlen;	/* dead window */
@@ -1600,7 +1600,7 @@ static void pseu_readev_fn(Event *event, void *data)
 		size = IOSIZE - p->w_inlen;
 		if (size <= 0) {
 			event->condpos = &const_IOSIZE;
-			event->condneg = (int *)&p->w_inlen;
+			event->condneg = &p->w_inlen;
 			return;
 		}
 	}
@@ -1643,7 +1643,7 @@ static void pseu_writeev_fn(Event *event, void *data)
 {
 	Window *p = (Window *)data;
 	struct pseudowin *pw = p->w_pwin;
-	size_t len;
+	int len;
 
 	if (pw->p_inlen == 0)
 		return;
@@ -1683,10 +1683,10 @@ static void win_destroyev_fn(Event *event, void *data)
 	WindowDied(p, p->w_exitstatus, 1);
 }
 
-static int zmodem_parse(Window *p, char *bp, size_t len)
+static int zmodem_parse(Window *p, char *bp, int len)
 {
 	char *b2 = bp;
-	for (size_t i = 0; i < len; i++, b2++) {
+	for (int i = 0; i < len; i++, b2++) {
 		if (p->w_zauto == 0) {
 			for (; i < len; i++, b2++)
 				if (*b2 == 030)
@@ -1756,7 +1756,7 @@ static void zmodemFin(char *buf, size_t len, void *dat
 	}
 }
 
-static void zmodem_found(Window *p, int send, char *bp, size_t len)
+static void zmodem_found(Window *p, int send, char *bp, int len)
 {
 	char *s;
 	size_t n;
@@ -1792,7 +1792,7 @@ static void zmodem_found(Window *p, int send, char *bp
 		display = d;
 		evdeq(&D_blockedev);
 		D_readev.condpos = &const_IOSIZE;
-		D_readev.condneg = (int *)&p->w_inlen;
+		D_readev.condneg = &p->w_inlen;
 		ClearAll();
 		GotoPos(0, 0);
 		SetRendition(&mchar_blank);
