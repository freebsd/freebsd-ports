--- tools/getlibs.sh.orig	Mon Nov 13 08:18:56 2006
+++ tools/getlibs.sh	Mon Nov 13 08:19:14 2006
@@ -92,7 +92,7 @@
 		echo "" ;;
 
 	'FreeBSD'|'NetBSD')
-		echo "-lpthread" ;;
+		echo "%%PTHREAD_LIBS%%" ;;
 
 	'HP-UX')
 		case `uname -r | sed 's/^[A-Z].//' | cut -f 1 -d '.'` in
