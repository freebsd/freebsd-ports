[FDclone-users:00313]

diff -u ../old/FD-2.05g/system.c ./system.c
--- ../old/FD-2.05g/system.c	Wed Jul  7 00:00:00 2004
+++ ./system.c	Fri Jul 16 18:54:34 2004
@@ -151,7 +151,7 @@
 
 #ifdef	FD
 #include "term.h"
-extern VOID main_fd __P_((char *));
+extern VOID main_fd __P_((char **));
 extern int sigvecset __P_((int));
 #ifndef	_NOCUSTOMIZE
 extern VOID saveorigenviron __P_((VOID_A));
@@ -9316,7 +9316,7 @@
 		ttyiomode(0);
 		mode = termmode(1);
 		shellmode = 0;
-		main_fd((trp -> comm) -> argv[1]);
+		main_fd(&((trp -> comm) -> argv[1]));
 		shellmode = 1;
 		termmode(mode);
 		stdiomode();
