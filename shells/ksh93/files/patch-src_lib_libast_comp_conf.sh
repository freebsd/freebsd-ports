
$FreeBSD$

--- src/lib/libast/comp/conf.sh.orig	Fri Jul 19 03:26:02 2002
+++ src/lib/libast/comp/conf.sh	Fri Jul 19 03:26:45 2002
@@ -627,6 +627,7 @@
 			cat <<!
 	printf("#undef	${macro}\n");
 	printf("#define ${macro}	${fmt}\n", ${var});
+
 !
 			case $minmax in
 			"")	cat <<!
