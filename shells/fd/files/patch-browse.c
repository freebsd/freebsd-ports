diff -urNP ../FD-1.03r/browse.c ./browse.c
--- ../FD-1.03r/browse.c	Tue Apr  3 00:00:00 2001
+++ ./browse.c	Tue Apr 10 00:00:00 2001
@@ -1305,6 +1305,7 @@
 				}
 				else if (_chdir2(cp) >= 0) strcpy(tmp, cp);
 				else {
+					*fullpath = '\0';
 					warning(-1, cp);
 					def = NULL;
 					strcpy(fullpath, origpath);
