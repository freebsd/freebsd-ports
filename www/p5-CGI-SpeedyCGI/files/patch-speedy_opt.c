--- src/speedy_opt.c	Mon Sep 30 07:19:54 2002
+++ /tmp/speedy_opt.c	Tue May 20 11:11:28 2003
@@ -165,6 +165,8 @@ static void cmdline_split(
 		    ++p;
 	    if (*p)
 		strlist_append(doing_speedy_opts ? speedy_opts : perl_args, *p);
+	    else
+		break;
 	}
 
 	if (*p) {
@@ -422,7 +424,7 @@ const char * const *speedy_opt_script_ar
 }
 
 SPEEDY_INLINE const char *speedy_opt_script_fname(void) {
-    return exec_argv.ptrs[script_argv_loc];
+    return exec_argv.len > script_argv_loc ? exec_argv.ptrs[script_argv_loc] : NULL;
 }
 
 #ifdef SPEEDY_BACKEND
