--- src/idebug.c.orig	2003-01-17 00:49:04 UTC
+++ src/idebug.c
@@ -90,7 +90,7 @@ debug_print_full_ref(const ref * pref)
 	case t_fontID:
 	    goto strct;
 	case t_integer:
-	    dprintf1("int %ld", pref->value.intval);
+	    dprintf1("int %d", pref->value.intval);
 	    break;
 	case t_mark:
 	    dprintf("mark");
