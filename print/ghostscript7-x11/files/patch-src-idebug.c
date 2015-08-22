--- src/idebug.c.orig	2013-04-30 11:06:57.000000000 +0900
+++ src/idebug.c	2013-04-30 11:07:09.000000000 +0900
@@ -90,7 +90,7 @@
 	case t_fontID:
 	    goto strct;
 	case t_integer:
-	    dprintf1("int %ld", pref->value.intval);
+	    dprintf1("int %d", pref->value.intval);
 	    break;
 	case t_mark:
 	    dprintf("mark");
