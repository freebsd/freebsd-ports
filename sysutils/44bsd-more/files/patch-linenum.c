--- linenum.c.orig	2011-09-08 01:09:35.000000000 +0800
+++ linenum.c	2011-09-08 01:11:21.000000000 +0800
@@ -134,7 +134,7 @@ clr_linenum()
 /*
  * Calculate the gap for an entry.
  */
-static
+static void
 calcgap(p)
 	register struct linenum *p;
 {
@@ -154,6 +154,7 @@ calcgap(p)
  * The specified position (pos) should be the file position of the
  * FIRST character in the specified line.
  */
+void
 add_lnum(line, pos)
 	int line;
 	off_t pos;
@@ -248,7 +249,7 @@ add_lnum(line, pos)
  * If we get stuck in a long loop trying to figure out the
  * line number, print a message to tell the user what we're doing.
  */
-static
+static void
 longloopmessage()
 {
 	ierror("Calculating line numbers");
@@ -264,6 +265,7 @@ longloopmessage()
  * Find the line number associated with a given position.
  * Return 0 if we can't figure it out.
  */
+int
 find_linenum(pos)
 	off_t pos;
 {
@@ -384,6 +386,7 @@ find_linenum(pos)
  * The argument "where" tells which line is to be considered
  * the "current" line (e.g. TOP, BOTTOM, MIDDLE, etc).
  */
+int
 currline(where)
 	int where;
 {
