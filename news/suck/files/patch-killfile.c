--- killfile.c.orig	Tue Aug 28 01:55:03 2001
+++ killfile.c	Sun Oct 14 20:03:03 2001
@@ -55,7 +55,6 @@
 void print_debug(PKillStruct, const char *);
 void debug_one_kill(POneKill);
 void add_to_linkedlist(pmy_regex *, pmy_regex);
-const char *strnstr(const char *, const char *);
 pmy_regex regex_scan(char *, char, int, int, char);
 int regex_check(char *, pmy_regex, int);
 
