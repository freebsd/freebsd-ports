[FDclone-users:00266]
  Properly expand globs like <"/usr/"*> and </usr\/*>.
--- pathname.c.orig	Sat Apr 24 05:25:17 2004
+++ pathname.c	Fri May 21 01:10:00 2004
@@ -147,13 +147,10 @@
 #else
 static int NEAR _regexp_exec __P_((char **, char *));
 #endif
-static char *NEAR catpath __P_((char *, char *, int *, int, int));
-#ifdef	NODIRLOOP
-static int NEAR _evalwild __P_((int, char ***, char *, char *, int));
-#else
-static int NEAR _evalwild __P_((int, char ***, char *, char *, int,
-		int, devino_t *));
-#endif
+static void NEAR addstrbuf __P_((strbuf_t *, char *, int));
+static void NEAR duplwild(wild_t *, wild_t *);
+static void NEAR freewild(wild_t *);
+static int NEAR _evalwild __P_((int, char ***, wild_t *));
 #ifndef	_NOUSEHASH
 static int NEAR calchash __P_((char *));
 static VOID NEAR inithash __P_((VOID_A));
@@ -1282,245 +1279,228 @@
 # endif		/* !USEREGCOMP */
 #endif		/* !USERE_COMP */
 
-static char *NEAR catpath(path, file, plenp, flen, isoverwrite)
-char *path, *file;
-int *plenp, flen, isoverwrite;
+static void NEAR addstrbuf(sp, s, len)
+strbuf_t *sp;
+char *s;
+int len;
 {
-	char *new;
-	int i, sc;
-
-#if	MSDOS || (defined (FD) && !defined (_NODOSDRIVE))
-	if (*plenp >= 2 && _dospath(path)) i = 2;
-	else
-#endif
-	i = 0;
+	sp -> s = c_realloc(sp -> s, sp -> len + len, &(sp -> size));
+	memcpy(&(sp -> s[sp -> len]), s, len);
+	sp -> len += len;
+	sp -> s[sp -> len] = '\0';
+}
 
-	if (*plenp <= i) sc = 0;
-	else {
-		sc = 1;
-		if (path[i] == _SC_) {
-			for (i++; i < *plenp; i++) if (path[i] != _SC_) break;
-			if (i >= *plenp) sc = 0;
-		}
-	}
+static void NEAR duplwild(dst, src)
+wild_t *dst, *src;
+{
+	memcpy(dst, src, sizeof(wild_t));
+	dst -> fixed.s = (char *)malloc2(src -> fixed.size);
+	memcpy(dst -> fixed.s, src -> fixed.s, src -> fixed.len + 1);
+	dst -> path.s = (char *)malloc2(src -> path.size);
+	memcpy(dst -> path.s, src -> path.s, src -> path.len + 1);
 
-	if (isoverwrite) new = realloc2(path, *plenp + sc + flen + 1);
-	else {
-		new = malloc2(*plenp + sc + flen + 1);
-		strncpy(new, path, *plenp);
+#ifndef	NODIRLOOP
+	if (src -> ino) {
+		dst -> ino = (devino_t *)malloc2(src -> nino
+			* sizeof(devino_t));
+		memcpy(dst -> ino, src -> ino, src -> nino * sizeof(devino_t));
 	}
-	if (sc) new[(*plenp)++] = _SC_;
-	strncpy2(&(new[*plenp]), file, flen);
-	*plenp += flen;
-	return(new);
+#endif	/* !NODIRLOOP */
 }
 
-#ifdef	NODIRLOOP
-static int NEAR _evalwild(argc, argvp, s, fixed, len)
-int argc;
-char ***argvp, *s, *fixed;
-int len;
-#else
-static int NEAR _evalwild(argc, argvp, s, fixed, len, nino, ino)
-int argc;
-char ***argvp, *s, *fixed;
-int len, nino;
-devino_t *ino;
-#endif
+static void NEAR freewild(wp)
+wild_t *wp;
 {
+	if (wp -> fixed.s) free(wp -> fixed.s);
+	if (wp -> path.s) free(wp -> path.s);
 #ifndef	NODIRLOOP
-	devino_t *dupino;
+	if (wp -> ino) free(wp -> ino);
 #endif
+}
+
+static int NEAR _evalwild(argc, argvp, wp)
+int argc;
+char ***argvp;
+wild_t *wp;
+{
 	DIR *dirp;
 	struct dirent *dp;
 	struct stat st;
 	reg_t *re;
+	wild_t dupl;
+	ALLOC_T flen, plen;
 	char *cp;
-	int i, n, l;
+	int i, n, w, pc, quote, isdir;
 
-	if (!*s) {
-		if (len) {
-			fixed = realloc2(fixed, len + 1 + 1);
-			fixed[len++] = _SC_;
-			fixed[len] = '\0';
-			*argvp = (char **)realloc2(*argvp,
-				(argc + 2) * sizeof(char *));
-			(*argvp)[argc++] = fixed;
+	if (!*(wp -> s)) return(argc);
+
+	flen = wp -> fixed.len;
+	plen = wp -> path.len;
+	quote = wp -> quote;
+
+	if (wp -> fixed.len) addstrbuf(&(wp -> path), _SS_, 1);
+
+	for (i = w = 0; wp -> s[i]; i++) {
+		pc = parsechar(&(wp -> s[i]), -1,
+			_SC_, 0, &(wp -> quote), NULL);
+		if (pc == PC_OPQUOTE || pc == PC_CLQUOTE) {
+			if (!(wp -> flags & EA_STRIPQ))
+				addstrbuf(&(wp -> fixed), &(wp -> s[i]), 1);
+			continue;
+		}
+		else if (pc == PC_WORD) {
+			addstrbuf(&(wp -> fixed), &(wp -> s[i]), 1);
+			addstrbuf(&(wp -> path), &(wp -> s[i]), 1);
+			i++;
+		}
+		else if (pc == PC_META) {
+			if (wp -> flags & EA_KEEPMETA)
+				addstrbuf(&(wp -> fixed), &(wp -> s[i]), 1);
+			if (wp -> s[i + 1] == _SC_) continue;
+
+			if (wp -> quote == '\''
+			|| (wp -> quote == '"'
+			&& !strchr(DQ_METACHAR, wp -> s[i + 1]))) {
+				if (!(wp -> flags & EA_KEEPMETA))
+					addstrbuf(&(wp -> fixed),
+						&(wp -> s[i]), 1);
+				addstrbuf(&(wp -> path), &(wp -> s[i]), 1);
+			}
+			i++;
+		}
+		else if (pc == _SC_) break;
+		else if (pc == PC_NORMAL && strchr("?*[", wp -> s[i])) {
+			if (w >= 0 && wp -> s[i] == '*') w++;
+			else w = -1;
 		}
-#ifndef	NODIRLOOP
-		if (ino) free(ino);
-#endif
-		return(argc);
-	}
 
-#if	MSDOS || (defined (FD) && !defined (_NODOSDRIVE))
-	if (!len && _dospath(s)) {
-		fixed = malloc2(2 + 1);
-		fixed[0] = *s;
-		fixed[1] = ':';
-		fixed[2] = '\0';
-# ifdef	NODIRLOOP
-		return(_evalwild(argc, argvp, &(s[2]), fixed, 2));
-# else
-		return(_evalwild(argc, argvp, &(s[2]), fixed, 2, nino, ino));
-# endif
+		addstrbuf(&(wp -> fixed), &(wp -> s[i]), 1);
+		addstrbuf(&(wp -> path), &(wp -> s[i]), 1);
 	}
-#endif
 
-	n = 0;
-	for (i = 0; s[i]; i++) {
-		if (s[i] == _SC_) break;
-		if (s[i] == '*' || s[i] == '?'
-		|| s[i] == '[' || s[i] == ']') n = 1;
-#ifdef	BSPATHDELIM
-		if (iskanji1(s, i)) i++;
-#endif
+	if (!(wp -> s[i])) isdir = 0;
+	else {
+		isdir = 1;
+		addstrbuf(&(wp -> fixed), _SS_, 1);
 	}
 
-	if (!i) {
-		fixed = realloc2(fixed, len + 1 + 1);
-		fixed[len++] = _SC_;
-		fixed[len] = '\0';
-#ifdef	NODIRLOOP
-		return(_evalwild(argc, argvp, &(s[1]), fixed, len));
-#else
-		return(_evalwild(argc, argvp, &(s[1]), fixed, len, nino, ino));
-#endif
-	}
+	if (!w) {
+		if (wp -> path.len <= plen) w++;
+		else if (Xstat(wp -> path.s, &st) < 0) return(argc);
 
-	if (!n) {
-		fixed = catpath(fixed, s, &len, i, 1);
-		if (Xstat(fixed, &st) < 0) free(fixed);
-		else if (s[i]) {
-			if ((st.st_mode & S_IFMT) != S_IFDIR) free(fixed);
-			else {
-#ifdef	NODIRLOOP
-				return(_evalwild(argc, argvp,
-					&(s[i + 1]), fixed, len));
-#else
-				ino = (devino_t *)realloc2(ino,
-					(nino + 1) * sizeof(devino_t));
-				ino[nino].dev = st.st_dev;
-				ino[nino++].ino = st.st_ino;
-				return(_evalwild(argc, argvp,
-					&(s[i + 1]), fixed, len, nino, ino));
-#endif
-			}
-		}
-		else {
-			*argvp = (char **)realloc2(*argvp,
-				(argc + 2) * sizeof(char *));
-			(*argvp)[argc++] = fixed;
+		wp -> s += i;
+		if (isdir) {
+			if (!w && (st.st_mode & S_IFMT) != S_IFDIR)
+				return(argc);
+			(wp -> s)++;
 		}
+
+		if (*(wp -> s)) {
 #ifndef	NODIRLOOP
-		if (ino) free(ino);
+			if (!w) {
+				wp -> ino = (devino_t *)realloc2(wp -> ino,
+					(wp -> nino + 1) * sizeof(devino_t));
+				wp -> ino[wp -> nino].dev = st.st_dev;
+				wp -> ino[(wp -> nino)++].ino = st.st_ino;
+			}
 #endif
+			return(_evalwild(argc, argvp, wp));
+		}
+
+		if (!(wp -> fixed.len)) return(argc);
+		*argvp = (char **)realloc2(*argvp,
+			(argc + 2) * sizeof(char *));
+		(*argvp)[argc++] = wp -> fixed.s;
+		wp -> fixed.s = NULL;
 		return(argc);
 	}
 
-	if (i == 2 && s[i] && s[0] == '*' && s[1] == '*') {
-#ifdef	NODIRLOOP
-		argc = _evalwild(argc, argvp, &(s[3]), strdup2(fixed), len);
-#else
-		if (!ino) dupino = NULL;
-		else {
-			dupino = (devino_t *)malloc2(nino * sizeof(devino_t));
-			for (n = 0; n < nino; n++) {
-				dupino[n].dev = ino[n].dev;
-				dupino[n].ino = ino[n].ino;
-			}
-		}
-		argc = _evalwild(argc, argvp,
-			&(s[3]), strdup2(fixed), len, nino, dupino);
-#endif
+	if (w != 2 || !isdir || strcmp(&(wp -> path.s[plen]), "**")) w = -1;
+	wp -> fixed.len = flen;
+	wp -> path.len = plen;
+	wp -> fixed.s[flen] = wp -> path.s[plen] = '\0';
+
+	if (w > 0) {
+		duplwild(&dupl, wp);
+		dupl.s += i + 1;
+		argc = _evalwild(argc, argvp, &dupl);
+		freewild(&dupl);
 		re = NULL;
 	}
-	else if (!(re = regexp_init(s, i))) {
-		if (fixed) free(fixed);
-#ifndef	NODIRLOOP
-		if (ino) free(ino);
-#endif
-		return(argc);
+	else {
+		cp = malloc2(i + 2);
+		n = 0;
+		if (quote) cp[n++] = quote;
+		memcpy(&(cp[n]), wp -> s, i);
+		n += i;
+		if (wp -> quote) cp[n++] = wp -> quote;
+		re = regexp_init(cp, n);
+		free(cp);
+		if (!re) return(argc);
+		wp -> s += i + 1;
 	}
-	if (!(dirp = Xopendir((len) ? fixed : "."))) {
+
+	if (wp -> path.len) cp = wp -> path.s;
+	else if (wp -> fixed.len) cp = _SS_;
+	else cp = ".";
+
+	if (!(dirp = Xopendir(cp))) {
 		regexp_free(re);
-		if (fixed) free(fixed);
-#ifndef	NODIRLOOP
-		if (ino) free(ino);
-#endif
 		return(argc);
 	}
+	addstrbuf(&(wp -> path), _SS_, 1);
 
 	while ((dp = Xreaddir(dirp))) {
 		if (isdotdir(dp -> d_name)) continue;
 
-		l = len;
-		cp = catpath(fixed, dp -> d_name, &l, strlen(dp -> d_name), 0);
-		if (s[i]) {
-			if (Xstat(cp, &st) < 0
+		duplwild(&dupl, wp);
+		n = strlen(dp -> d_name);
+		addstrbuf(&(dupl.fixed), dp -> d_name, n);
+		addstrbuf(&(dupl.path), dp -> d_name, n);
+
+		if (isdir) {
+			if (re) n = regexp_exec(re, dp -> d_name, 1);
+			else n = (*(dp -> d_name) == '.') ? 0 : 1;
+
+			if (!n || Xstat(dupl.path.s, &st) < 0
 			|| (st.st_mode & S_IFMT) != S_IFDIR) {
-				free(cp);
+				freewild(&dupl);
 				continue;
 			}
 
 #ifndef	NODIRLOOP
-			dupino = (devino_t *)malloc2((nino + 1)
-				* sizeof(devino_t));
-			for (n = 0; n < nino; n++) {
-				dupino[n].dev = ino[n].dev;
-				dupino[n].ino = ino[n].ino;
-			}
-			dupino[n].dev = st.st_dev;
-			dupino[n].ino = st.st_ino;
-#endif
 			if (!re) {
-				if (*(dp -> d_name) == '.') {
-					free(cp);
-#ifndef	NODIRLOOP
-					free(dupino);
-#endif
+				for (n = 0; n < dupl.nino; n++)
+					if (dupl.ino[n].dev == st.st_dev
+					&& dupl.ino[n].ino == st.st_ino)
+						break;
+				if (n < dupl.nino) {
+					freewild(&dupl);
 					continue;
 				}
-#ifdef	NODIRLOOP
-				argc = _evalwild(argc, argvp, s, cp, l);
-#else
-				for (n = 0; n < nino; n++)
-					if (ino[n].dev == st.st_dev
-					&& ino[n].ino == st.st_ino) break;
-				if (n < nino) {
-					free(cp);
-					free(dupino);
-				}
-				else argc = _evalwild(argc, argvp,
-						s, cp, l, nino + 1, dupino);
-#endif
-			}
-			else if (!regexp_exec(re, dp -> d_name, 1)) {
-				free(cp);
-#ifndef	NODIRLOOP
-				free(dupino);
-#endif
 			}
-#ifdef	NODIRLOOP
-			else argc = _evalwild(argc, argvp, &(s[i + 1]), cp, l);
-#else
-			else argc = _evalwild(argc, argvp,
-					&(s[i + 1]), cp, l, nino + 1, dupino);
+
+			dupl.ino = (devino_t *)realloc2(dupl.ino,
+				(dupl.nino + 1) * sizeof(devino_t));
+			dupl.ino[dupl.nino].dev = st.st_dev;
+			dupl.ino[(dupl.nino)++].ino = st.st_ino;
 #endif
+
+			addstrbuf(&(dupl.fixed), _SS_, 1);
+			argc = _evalwild(argc, argvp, &dupl);
 		}
-		else if (!re || !regexp_exec(re, dp -> d_name, 1)) free(cp);
-		else {
+		else if (regexp_exec(re, dp -> d_name, 1)) {
 			*argvp = (char **)realloc2(*argvp,
 				(argc + 2) * sizeof(char *));
-			(*argvp)[argc++] = cp;
+			(*argvp)[argc++] = dupl.fixed.s;
+			dupl.fixed.s = NULL;
 		}
+
+		freewild(&dupl);
 	}
 	Xclosedir(dirp);
 	regexp_free(re);
-	if (fixed) free(fixed);
-#ifndef	NODIRLOOP
-	if (ino) free(ino);
-#endif
+
 	return(argc);
 }
 
@@ -1531,18 +1511,29 @@
 	return(strpathcmp2(*((char **)vp1), *((char **)vp2)));
 }
 
-char **evalwild(s)
+char **evalwild(s, flags)
 char *s;
+int flags;
 {
+	wild_t w;
 	char **argv;
 	int argc;
 
 	argv = (char **)malloc2(1 * sizeof(char *));
-#ifdef	NODIRLOOP
-	argc = _evalwild(0, &argv, s, NULL, 0);
-#else
-	argc = _evalwild(0, &argv, s, NULL, 0, 0, NULL);
+	w.s = s;
+	w.fixed.s = c_realloc(NULL, 0, &(w.fixed.size));
+	w.path.s = c_realloc(NULL, 0, &(w.path.size));
+	w.fixed.len = w.path.len = (ALLOC_T)0;
+	w.quote = '\0';
+#ifndef	NODIRLOOP
+	w.nino = 0;
+	w.ino = NULL;
 #endif
+	w.flags = flags;
+
+	argc = _evalwild(0, &argv, &w);
+	freewild(&w);
+
 	if (!argc) {
 		free(argv);
 		return(NULL);
@@ -3188,60 +3179,29 @@
 char ***argvp;
 int flags;
 {
-	char *cp, **wild;
-	ALLOC_T size;
-	int i, j, n, pc, w, quote;
+	char **wild;
+	int i, n;
 
 	for (n = 0; n < argc; n++) {
-		cp = c_realloc(NULL, 0, &size);
-		for (i = j = w = 0, quote = '\0'; (*argvp)[n][i]; i++) {
-			cp = c_realloc(cp, j + 1, &size);
-			pc = parsechar(&((*argvp)[n][i]), -1,
-				'\0', 0, &quote, NULL);
-			if (pc == PC_OPQUOTE || pc == PC_CLQUOTE) {
-				if (flags & EA_STRIPQ) continue;
-			}
-			else if (pc == PC_WORD) cp[j++] = (*argvp)[n][i++];
-			else if (pc == PC_META) {
-				i++;
-				if (quote
-				&& !strchr(DQ_METACHAR, (*argvp)[n][i]))
-					cp[j++] = PMETA;
-			}
-			else if (pc != PC_NORMAL) /*EMPTY*/;
-			else if (!strchr("?*[", (*argvp)[n][i])) /*EMPTY*/;
-			else if ((wild = evalwild((*argvp)[n]))) {
-				w = countvar(wild);
-				if (w > 1) {
-					*argvp = (char **)realloc2(*argvp,
-						(argc + w) * sizeof(char *));
-					if (!*argvp) {
-						free(cp);
-						freevar(wild);
-						return(argc);
-					}
-					memmove((char *)(&((*argvp)[n + w])),
-						(char *)(&((*argvp)[n + 1])),
-						(argc - n) * sizeof(char *));
-					argc += w - 1;
-				}
-				free((*argvp)[n]);
-				free(cp);
-				memmove((char *)(&((*argvp)[n])),
-					(char *)wild, w * sizeof(char *));
-				free(wild);
-				n += w - 1;
-				break;
-			}
-
-			cp[j++] = (*argvp)[n][i];
+		if (!(wild = evalwild((*argvp)[n], flags))) {
+			stripquote((*argvp)[n], flags);
+			continue;
 		}
 
-		if (!w) {
-			cp[j] = '\0';
-			free((*argvp)[n]);
-			(*argvp)[n] = cp;
-		}
+		i = countvar(wild);
+		if (i > 1) {
+			*argvp = (char **)realloc2(*argvp,
+				(argc + i) * sizeof(char *));
+			memmove((char *)(&((*argvp)[n + i])),
+				(char *)(&((*argvp)[n + 1])),
+				(argc - n) * sizeof(char *));
+			argc += i - 1;
+		}
+		free((*argvp)[n]);
+		memmove((char *)(&((*argvp)[n])),
+			(char *)wild, i * sizeof(char *));
+		free(wild);
+		n += i - 1;
 	}
 	return(argc);
 }

[FDclone-users:00274]
  Complete the previous fix and make <'/usr/'*> work.
--- pathname.c.orig	Sun May 23 02:04:49 2004
+++ pathname.c	Sun May 23 02:14:10 2004
@@ -1340,9 +1340,9 @@

	if (wp -> fixed.len) addstrbuf(&(wp -> path), _SS_, 1);

-	for (i = w = 0; wp -> s[i]; i++) {
+	for (i = w = 0; wp -> s[i] && wp -> s[i] != _SC_; i++) {
		pc = parsechar(&(wp -> s[i]), -1,
-			_SC_, 0, &(wp -> quote), NULL);
+			'\0', 0, &(wp -> quote), NULL);
		if (pc == PC_OPQUOTE || pc == PC_CLQUOTE) {
			if (!(wp -> flags & EA_STRIPQ))
				addstrbuf(&(wp -> fixed), &(wp -> s[i]), 1);
@@ -1368,7 +1368,6 @@
			}
			i++;
		}
-		else if (pc == _SC_) break;
		else if (pc == PC_NORMAL && strchr("?*[", wp -> s[i])) {
			if (w >= 0 && wp -> s[i] == '*') w++;
			else w = -1;

[FDclone-users:00282]
  Fix the buggy fixes above and unbreak <*/...>.
--- pathname.c.orig	Sun May 23 02:14:10 2004
+++ pathname.c	Wed May 26 00:11:07 2004
@@ -1332,7 +1332,14 @@
 	char *cp;
 	int i, n, w, pc, quote, isdir;
 
-	if (!*(wp -> s)) return(argc);
+	if (!*(wp -> s)) {
+		if (!(wp -> fixed.len)) return(argc);
+		*argvp = (char **)realloc2(*argvp,
+			(argc + 2) * sizeof(char *));
+		(*argvp)[argc++] = wp -> fixed.s;
+		wp -> fixed.s = NULL;
+		return(argc);
+	}
 
 	flen = wp -> fixed.len;
 	plen = wp -> path.len;
@@ -1394,24 +1401,15 @@
 			(wp -> s)++;
 		}
 
-		if (*(wp -> s)) {
 #ifndef	NODIRLOOP
-			if (!w) {
-				wp -> ino = (devino_t *)realloc2(wp -> ino,
-					(wp -> nino + 1) * sizeof(devino_t));
-				wp -> ino[wp -> nino].dev = st.st_dev;
-				wp -> ino[(wp -> nino)++].ino = st.st_ino;
-			}
-#endif
-			return(_evalwild(argc, argvp, wp));
+		if (!w) {
+			wp -> ino = (devino_t *)realloc2(wp -> ino,
+				(wp -> nino + 1) * sizeof(devino_t));
+			wp -> ino[wp -> nino].dev = st.st_dev;
+			wp -> ino[(wp -> nino)++].ino = st.st_ino;
 		}
-
-		if (!(wp -> fixed.len)) return(argc);
-		*argvp = (char **)realloc2(*argvp,
-			(argc + 2) * sizeof(char *));
-		(*argvp)[argc++] = wp -> fixed.s;
-		wp -> fixed.s = NULL;
-		return(argc);
+#endif
+		return(_evalwild(argc, argvp, wp));
 	}
 
 	if (w != 2 || !isdir || strcmp(&(wp -> path.s[plen]), "**")) w = -1;
@@ -1447,7 +1445,8 @@
 		regexp_free(re);
 		return(argc);
 	}
-	addstrbuf(&(wp -> path), _SS_, 1);
+	if (wp -> path.len || wp -> fixed.len)
+		addstrbuf(&(wp -> path), _SS_, 1);
 
 	while ((dp = Xreaddir(dirp))) {
 		if (isdotdir(dp -> d_name)) continue;
