--- killfile.c.orig	2018-08-01 13:54:24 UTC
+++ killfile.c
@@ -55,7 +55,6 @@ int check_a_group(PMaster, POneKill, cha
 void print_debug(PKillStruct, const char *);
 void debug_one_kill(POneKill);
 void add_to_linkedlist(pmy_regex *, pmy_regex);
-const char *strnstr(const char *, const char *);
 pmy_regex regex_scan(char *, char, int, int, char);
 int regex_check(char *, pmy_regex, int);
 
