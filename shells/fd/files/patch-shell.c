diff -urNP ../FD-1.03r/shell.c ./shell.c
--- ../FD-1.03r/shell.c	Tue Apr  3 00:00:00 2001
+++ ./shell.c	Tue Apr 10 00:00:00 2001
@@ -240,7 +240,7 @@
 		if (flags & (F_NOEXT | F_TOSFN));
 		else if (c == '%') c = command[++i];
 		else {
-			line[j++] = c;
+			line[j++] = command[i];
 #if	!MSDOS
 			if (command[i] == META && command[i + 1]
 			&& uneval != '\'')
