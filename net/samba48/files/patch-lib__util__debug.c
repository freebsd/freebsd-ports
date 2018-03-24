--- lib/util/debug.c.orig	2017-09-17 19:15:34 UTC
+++ lib/util/debug.c
@@ -750,12 +750,21 @@ static void debug_dump_status(int level)
 	}
 }
 
+static void debug_set_all_levels(int level)
+{
+	int i;
+	/* Array is debug_num_classes long */
+	for (i = DBGC_ALL; i < debug_num_classes; i++) {
+		DEBUGLEVEL_CLASS[i] = level;
+	}
+}
+
 static bool debug_parse_param(char *param)
 {
 	char *class_name;
 	char *class_level;
 	char *saveptr = NULL;
-	int ndx;
+	int ndx, level;
 
 	class_name = strtok_r(param, ":", &saveptr);
 	if (class_name == NULL) {
@@ -772,7 +781,13 @@ static bool debug_parse_param(char *para
 		return false;
 	}
 
-	DEBUGLEVEL_CLASS[ndx] = atoi(class_level);
+	level = atoi(class_level);
+
+	if(ndx == DBGC_ALL) {
+		debug_set_all_levels(level);
+	} else {
+		DEBUGLEVEL_CLASS[ndx] = level;
+	}
 
 	return true;
 }
@@ -788,7 +803,7 @@ bool debug_parse_levels(const char *para
 	size_t str_len = strlen(params_str);
 	char str[str_len+1];
 	char *tok, *saveptr;
-	int i;
+	int level = 0;
 
 	/* Just in case */
 	debug_init();
@@ -804,16 +819,11 @@ bool debug_parse_levels(const char *para
 	 * v.s. "all:10", this is the traditional way to set DEBUGLEVEL
 	 */
 	if (isdigit(tok[0])) {
-		DEBUGLEVEL_CLASS[DBGC_ALL] = atoi(tok);
+		level = atoi(tok);
 		tok = strtok_r(NULL, LIST_SEP, &saveptr);
-	} else {
-		DEBUGLEVEL_CLASS[DBGC_ALL] = 0;
 	}
 
-	/* Array is debug_num_classes long */
-	for (i = DBGC_ALL+1; i < debug_num_classes; i++) {
-		DEBUGLEVEL_CLASS[i] = DEBUGLEVEL_CLASS[DBGC_ALL];
-	}
+	debug_set_all_levels(level);
 
 	while (tok != NULL) {
 		bool ok;
