--- variables.c.orig	Tue Aug 26 10:55:14 2003
+++ variables.c	Thu Nov  2 13:35:27 2006
@@ -39,8 +39,8 @@
 static char buf[BUFSIZ];
 static char *strbuf = NULL;
 
-static char *obj_states[2] = {
-	"UP", "DOWN" };
+static char *obj_states[4] = {
+	"UP", "DOWN","DEGRADED","WARNING" };
 static char *if_states[5] = {
 	"UP", "DOWN", "TESTING", "UNKNOWN", "DORMANT" };
 static char *bgp_states[6] = {
@@ -52,7 +52,7 @@
 	int size;
 	char **name;
 } states[4] = {
-	{ 2, obj_states },
+	{ 4, obj_states },
 	{ 5, if_states },
 	{ 6, bgp_states },
 	{ 5, env_states },
@@ -69,7 +69,7 @@
 
 	sp = &states[what];
 	if (!state)
-		cp = "NONE";
+		cp = "UNKNOWN";
 	else if (state > 0 && state <= sp->size)
 		cp = sp->name[state-1];
 	else	cp = "ERROR";
@@ -1511,6 +1511,7 @@
 		}
 		memcpy(var, vb, len);
 		var[len] = '\0';
+		
 		len = 0;
 		next = var;
 		while ((vb = my_strsep(&next, "!")) != NULL) {
