--- sort.c.orig	Fri Apr 28 22:35:13 1995
+++ sort.c	Fri Apr 16 01:30:09 1999
@@ -43,6 +43,29 @@
  *	before MATCH_?? (t, a, b) is used.
  */
 
+#ifdef HAVE_WORKING_COLLATE
+
+#ifdef HAVE_8BIT_CTYPE
+#define MATCH_DROP(table, c) !isprint(c)
+#else
+#define MATCH_DROP(table, c) ( c & 0200 || !isprint(c) )
+#endif
+#define MATCH_EQ(table, a, b) ( a == b || table(a, b) == 0 )
+#define MATCH_LS_EQ(table, a, b) ( a == b || table(a, b) <= 0 )
+#define MATCH_LS(table, a, b) ( table(a, b) < 0 )
+#define MATCH_CMP(table, a, b) table(a, b)
+
+static int match_subject(a, b)
+char a, b;
+{
+	static char aa[2], bb[2];
+
+	aa[0] = a; bb[0] = b;
+	return strcoll(aa, bb);
+}
+
+#else
+
 #define	MATCH_DROP(table, c) ( c & 0200 || table[c] == 0 )
 #define MATCH_EQ(table, a, b) ( a == b || table[a] == table[b] )
 #define MATCH_LS_EQ(table, a, b) ( a <= b || table[a] <= table[b] )
@@ -77,6 +100,7 @@
     26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 00, 00
 };
 
+#endif /* HAVE_WORKING_COLLATE */
 
 static int
 order_subj_date(ah1, ah2)
