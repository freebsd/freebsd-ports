
$FreeBSD$

--- main/frame.c
+++ main/frame.c
@@ -1260,7 +1260,7 @@
 
 	switch(type) {
 	case TYPE_DONTSEND:
-		return 0;
+		return 2;
 		break;
 	case TYPE_SILENCE:
 		return 4;
