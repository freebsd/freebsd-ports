
$FreeBSD$

--- enum.c.orig	Mon Sep  1 18:36:52 2003
+++ enum.c	Fri Oct 17 11:27:30 2003
@@ -380,9 +380,14 @@
 	struct enum_search *s = NULL;
 	int version = -1;
 	struct __res_state enumstate;
-	res_ninit(&enumstate);	
-	if (chan && ast_autoservice_start(chan) < 0)
+	static ast_mutex_t reslock = AST_MUTEX_INITIALIZER;
+
+	ast_mutex_lock(&reslock);
+	res_init();	
+	if (chan && ast_autoservice_start(chan) < 0) {
+		ast_mutex_unlock(&reslock);
 		return -1;
+	}
 
 	strncat(naptrinput, number, sizeof(naptrinput) - 2);
 
@@ -411,7 +416,7 @@
 		ast_mutex_unlock(&enumlock);
 		if (!s)
 			break;
-		res = res_nsearch(&enumstate, tmp, C_IN, T_NAPTR, answer, sizeof(answer));
+		res = res_search(tmp, C_IN, T_NAPTR, answer, sizeof(answer));
 		if (res > 0)
 			break;
 	}
@@ -429,7 +434,7 @@
 	}
 	if (chan)
 		ret |= ast_autoservice_stop(chan);
-	res_nclose(&enumstate);
+	ast_mutex_unlock(&reslock);
 	return ret;
 }
 
