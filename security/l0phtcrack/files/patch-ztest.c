--- ztest.c.orig	2016-03-03 16:20:49 UTC
+++ ztest.c
@@ -144,7 +144,7 @@ int issame(char *, char *, int);
 
 char str_to_crypt[] = "\x4b\x47\x53\x21\x40\x23\x24\x25";
 
-void main(int argc, char **argv) {
+int main(int argc, char **argv) {
 	FILE *pwlist, *wordlist, *outlist;
 	char dict_word[MAX_WORD];
 	char *pwfile, *wordfile, *outfile;
