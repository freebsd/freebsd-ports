--- Src/Zle/zle_main.c.orig	Fri May 18 00:56:13 2001
+++ Src/Zle/zle_main.c	Thu May  9 07:53:36 2002
@@ -141,6 +141,163 @@
 static int delayzsetterm;
 #endif
 
+#ifdef ZSH_EUC
+/**/
+mod_export int locale_is_euc;
+
+#  if defined(__uxps__) || defined(sgi)  || defined(aix) || defined(__CYGWIN__) || defined(linux)
+char STRLANGEUCJP[]	= { 'j', 'a', '_', 'J', 'P', '.', 'E', 'U', 'C', '\0' };
+char STRLANGEUCKR[]	= { 'k', 'o', '_', 'K', 'R', '.', 'E', 'U', 'C', '\0' };
+#   if defined(__uxps__)
+char STRLANGEUCJPB[]	= { 'j', 'a', 'p', 'a', 'n', '\0' };
+char STRLANGEUCKRB[]	= { 'k', 'o', 'r', 'e', 'a', '\0' };
+#   elif defined(linux)
+char STRLANGEUCJPB[]	= { 'j', 'a', '_', 'J', 'P', '.', 'u', 'j', 'i', 's',
+			    '\0' };
+char STRLANGEUCKRB[]	= { 'k', 'o', '_', 'K', 'R', '.', 'e', 'u', 'c', '\0' };
+#   elif defined(aix)
+char STRLANGEUCJPB[]	= { 'j', 'a', '_', 'J', 'P', '\0' };
+char STRLANGEUCKRB[]	= { 'k', 'o', '_', 'K', 'R', '\0' };
+#   else
+char STRLANGEUCJPB[]	= { '\0' };
+char STRLANGEUCKRB[]	= { '\0' };
+#   endif
+char STRLANGSJIS[]	= { 'j', 'a', '_', 'J', 'P', '.', 'S', 'J', 'I', 'S',
+			    '\0' };
+char STRLANGSJISB[]	= { '\0' };
+char STRLANGBIG5[]	= { 'z', 'h', '_', 'T', 'W', '.', 'B', 'i', 'g', '5',
+			    '\0' };
+char STRLANGEUCZH[]	= { '\0' };
+char STRLANGEUCZHB[]	= { '\0' };
+#  elif defined(__FreeBSD__)
+char STRLANGEUCJP[]	= { 'j', 'a', '_', 'J', 'P', '.', 'e', 'u', 'c', 'J',
+			    'P', '\0' };
+char STRLANGEUCJPB[]	= { 'j', 'a', '_', 'J', 'P', '.', 'E', 'U', 'C', '\0' };
+char STRLANGEUCKR[]	= { 'k', 'o', '_', 'K', 'R', '.', 'e', 'u', 'c', 'K',
+			    'R', '\0' };
+char STRLANGEUCKRB[]	= { 'k', 'o', '_', 'K', 'R', '.', 'E', 'U', 'C', '\0' };
+char STRLANGEUCZH[]	= { 'z', 'h', '_', 'C', 'N', '.', 'e', 'u', 'c', 'C',
+			    'N', '\0' };
+char STRLANGEUCZHB[]	= { 'z', 'h', '_', 'C', 'N', '.', 'E', 'U', 'C', '\0' };
+char STRLANGSJIS[]	= { 'j', 'a', '_', 'J', 'P', '.', 'S', 'J', 'I', 'S',
+			    '\0' };
+char STRLANGSJISB[]	= { 'j', 'a', '_', 'J', 'P', '.', 'S', 'h', 'i', 'f',
+			    't', '_', 'J', 'I', 'S', '\0' };
+char STRLANGBIG5[]	= { 'z', 'h', '_', 'T', 'W', '.', 'B', 'i', 'g', '5',
+			    '\0' };
+#  elif defined(__uxpm__)
+char STRLANGEUCJP[]	= { 'j', 'a', 'p', 'a', 'n', '\0' };
+char STRLANGEUCKR[]	= { 'k', 'o', 'r', 'e', 'a', '\0' };
+char STRLANGEUCZH[]	= { '\0' };
+char STRLANGEUCJPB[]	= { '\0' };
+char STRLANGEUCKRB[]	= { '\0' };
+char STRLANGEUCZHB[]	= { '\0' };
+char STRLANGSJIS[]	= { '\0' };
+char STRLANGSJISB[]	= { '\0' };
+char STRLANGBIG5[]	= { '\0' };
+#  elif defined(SOLARIS2)
+char STRLANGEUCJP[]	= { 'j', 'a', '\0' };
+char STRLANGEUCKR[]	= { 'k', 'o', '\0' };
+char STRLANGEUCZH[]	= { '\0' };
+char STRLANGEUCJPB[]	= { 'j', 'a', 'p', 'a', 'n', 'e', 's', 'e', '\0' };
+char STRLANGEUCKRB[]	= { 'k', 'o', 'r', 'e', 'a', 'n', '\0' };
+char STRLANGEUCZHB[]	= { '\0' };
+char STRLANGSJIS[]	= { '\0' };
+char STRLANGSJISB[]	= { '\0' };
+char STRLANGBIG5[]	= { '\0' };
+#  elif defined(hpux)
+char STRLANGEUCJP[]	= { 'j', 'a', '_', 'J', 'P', '.', 'e', 'u', 'c', 'J', 'P' };
+char STRLANGEUCKR[]	= { 'k', 'o', '_', 'K', 'R', '.', 'e', 'u', 'c', 'K', 'R' };
+char STRLANGEUCZH[]	= { '\0' };
+char STRLANGEUCJPB[]	= { '\0' };
+char STRLANGEUCKRB[]	= { '\0' };
+char STRLANGEUCZHB[]	= { '\0' };
+char STRLANGSJIS[]	= { '\0' };
+char STRLANGSJISB[]	= { '\0' };
+char STRLANGBIG5[]	= { '\0' };
+#  else
+char STRLANGEUCJP[]	= { '\0' };
+char STRLANGEUCKR[]	= { '\0' };
+char STRLANGEUCZH[]	= { '\0' };
+char STRLANGEUCJPB[]	= { '\0' };
+char STRLANGEUCKRB[]	= { '\0' };
+char STRLANGEUCZHB[]	= { '\0' };
+char STRLANGSJIS[]	= { '\0' };
+char STRLANGSJISB[]	= { '\0' };
+char STRLANGBIG5[]	= { '\0' };
+#  endif
+
+/**/
+mod_export unsigned char _mbmap_euc[256] = {
+/* first byte	0x8e,0xa0 - 0xf4 */
+/* second byte 	0xa0 - 0xfe */
+/* 0 - 7f all 0 */
+    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
+    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
+    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
+    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
+/*  80		81		82		83 */
+    0,		0,		0,		0,
+/*  84		85		86		87 */
+    0,		0,		0,		0,
+/*  88		89		8a		8b */
+    0,		0,		0,		0,
+/*  8c		8d		8e		8f */
+    0,		0,		_MB1,		0,
+/* 90 - 9f all 0 */
+    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
+/*  a0		a1		a2		a3 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  a4		a5		a6		a7 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  a8		a9		aa		ab */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  ac		ad		ae		af */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  b0		b1		b2		b3 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  b4		b5		b6		b7 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  b8		b9		ba		bb */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  bc		bd		be		bf */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  c0		c1		c2		c3 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  c4		c5		c6		c7 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  c8		c9		ca		cb */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  cc		cd		ce		cf */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  d0		d1		d2		d3 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  d4		d5		d6		d7 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  d8		d9		da		db */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  dc		dd		de		df */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  e0		e1		e2		e3 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  e4		e5		e6		e7 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  e8		e9		ea		eb */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  ec		ed		ee		ef */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  f0		f1		f2		f3 */
+    _MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,	_MB1|_MB2,
+/*  f4		f5		f6		f7 */
+    _MB1|_MB2,	_MB2,		_MB2,		_MB2,
+/*  f8		f9		fa		fb */
+    _MB2,	_MB2,		_MB2,		_MB2,
+/*  fc		fd		fe		ff */
+    _MB2,	_MB2,		_MB2,		0,
+};
+
+#endif
+
 /* set up terminal */
 
 /**/
@@ -1117,6 +1274,32 @@
 int
 setup_(Module m)
 {
+#ifdef ZSH_EUC
+    char *euc_locales[] = {
+	STRLANGEUCJP,
+	STRLANGEUCKR,
+	STRLANGEUCZH,
+	STRLANGEUCJPB,
+	STRLANGEUCKRB,
+	STRLANGEUCZHB,
+	NULL
+    };
+    char **p;
+    char *tcp;
+
+    locale_is_euc = 0;
+
+    if ((tcp = setlocale("LC_CTYPE", NULL)) != NULL ||
+      (tcp = getenv("LANG")) != NULL) {
+	for (p = euc_locales; *p != NULL; p++) {
+	    if (strcmp(tcp, *p) == 0) {
+		locale_is_euc = 1;
+		break;
+	    }
+	}
+    }
+#endif
+
     /* Set up editor entry points */
     trashzleptr = trashzle;
     refreshptr = zrefresh;
