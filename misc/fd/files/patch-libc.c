diff -u ../old/FD-1.03u/libc.c ./libc.c
--- ../old/FD-1.03u/libc.c	Tue Dec 18 00:00:00 2001
+++ ./libc.c	Tue Jan  8 12:06:14 2002
@@ -165,7 +165,8 @@
 				buf[i] = '\0';
 				if (*buf == _SC_) strcpy(resolved, buf);
 				else {
-					*(cp - 1) = '\0';
+					if (cp - 1 > resolved) cp--;
+					*cp = '\0';
 					_realpath2(buf, resolved, rdlink);
 				}
 			}
