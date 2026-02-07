--- tools/ccopts.sh.orig	2023-07-11 00:09:58 UTC
+++ tools/ccopts.sh
@@ -603,7 +603,7 @@ if [ $ISCLANG -gt 0 ] && [ $ISSPECIAL -eq 0 ] ; then
 
 if [ $ISCLANG -gt 0 ] && [ $ISSPECIAL -eq 0 ] ; then
 	if [ $COMPILER_VER -ge 47 ] ; then
-		if [ "$OSNAME" = "Darwin" ] || [ "$OSNAME" = "OpenBSD" ] ; then
+		if [ "$OSNAME" = "Darwin" ] || [ "$OSNAME" = "OpenBSD" ] || [ "$OSNAME" = "FreeBSD" -a "$ARCH" = "arm" ] || [ "$OSNAME" = "FreeBSD" -a "$ARCH" = "powerpc" ]; then
 			# The versions of clang shipped with OS X or OpenBSD don't
 			# support -fsanitize=safe-stack even as late as clang 12, so
 			# there's not much that we can do.
