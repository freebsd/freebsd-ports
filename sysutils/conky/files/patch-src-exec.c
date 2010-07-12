--- src/exec.c.orig
+++ src/exec.c
@@ -140,7 +140,8 @@ static inline double get_barnum(char *buf)
 	return barnum;
 }
 
-static inline void read_exec(const char *data, char *buf, const int size)
+static inline void read_exec(const char *data, char *buf, const int size, const
+		char use_alarm)
 {
 	FILE *fp;
 
@@ -149,7 +150,7 @@ static inline void read_exec(const char *data, char *buf, const int size)
 	if (!data)
 		return;
 
-	alarm(update_interval);
+	if (use_alarm) alarm(update_interval);
 	fp = pid_popen(data, "r", &childpid);
 	if(fp) {
 		int length;
@@ -163,7 +164,7 @@ static inline void read_exec(const char *data, char *buf, const int size)
 	} else {
 		buf[0] = '\0';
 	}
-	alarm(0);
+	if (use_alarm) alarm(0);
 }
 
 static void *threaded_exec(void *) __attribute__((noreturn));
@@ -176,7 +177,7 @@ static void *threaded_exec(void *arg)
 
 	while (1) {
 		buff = malloc(text_buffer_size);
-		read_exec(ed->cmd, buff, text_buffer_size);
+		read_exec(ed->cmd, buff, text_buffer_size, 0);
 		p2 = buff;
 		while (*p2) {
 			if (*p2 == '\001') {
@@ -216,7 +217,7 @@ void scan_pre_exec_arg(struct text_object *obj, const char *arg)
 	char buf[2048];
 
 	obj->type = OBJ_text;
-	read_exec(arg, buf, sizeof(buf));
+	read_exec(arg, buf, sizeof(buf), 1);
 	obj->data.s = strndup(buf, text_buffer_size);
 }
 
@@ -258,7 +259,7 @@ void scan_execgraph_arg(struct text_object *obj, const char *arg)
 
 void print_exec(struct text_object *obj, char *p, int p_max_size)
 {
-	read_exec(obj->data.s, p, p_max_size);
+	read_exec(obj->data.s, p, p_max_size, 1);
 	remove_deleted_chars(p);
 }
 
@@ -271,7 +272,7 @@ void print_execp(struct text_object *obj, char *p, int p_max_size)
 	buf = malloc(text_buffer_size);
 	memset(buf, 0, text_buffer_size);
 
-	read_exec(obj->data.s, buf, text_buffer_size);
+	read_exec(obj->data.s, buf, text_buffer_size, 1);
 
 	tmp_info = malloc(sizeof(struct information));
 	memcpy(tmp_info, &info, sizeof(struct information));
@@ -292,7 +293,7 @@ void print_execi(struct text_object *obj, char *p, int p_max_size)
 	if (time_to_update(ed)) {
 		if (!ed->buffer)
 			ed->buffer = malloc(text_buffer_size);
-		read_exec(ed->cmd, ed->buffer, text_buffer_size);
+		read_exec(ed->cmd, ed->buffer, text_buffer_size, 1);
 		ed->last_update = current_update_time;
 	}
 	snprintf(p, p_max_size, "%s", ed->buffer);
@@ -365,7 +366,7 @@ void print_execgauge(struct text_object *obj, char *p, int p_max_size)
 {
 	double barnum;
 
-	read_exec(obj->data.s, p, p_max_size);
+	read_exec(obj->data.s, p, p_max_size, 1);
 	barnum = get_barnum(p); /*using the same function*/
 
 	if (barnum >= 0.0) {
@@ -383,7 +384,7 @@ void print_execgraph(struct text_object *obj, char *p, int p_max_size)
 	if (!ed)
 		return;
 
-	read_exec(ed->cmd, p, p_max_size);
+	read_exec(ed->cmd, p, p_max_size, 1);
 	barnum = get_barnum(p);
 
 	if (barnum > 0) {
@@ -401,7 +402,7 @@ void print_execigraph(struct text_object *obj, char *p, int p_max_size)
 	if (time_to_update(ed)) {
 		double barnum;
 
-		read_exec(ed->cmd, p, p_max_size);
+		read_exec(ed->cmd, p, p_max_size, 1);
 		barnum = get_barnum(p);
 
 		if (barnum >= 0.0) {
@@ -423,7 +424,7 @@ void print_execigauge(struct text_object *obj, char *p, int p_max_size)
 	if (time_to_update(ed)) {
 		double barnum;
 
-		read_exec(ed->cmd, p, p_max_size);
+		read_exec(ed->cmd, p, p_max_size, 1);
 		barnum = get_barnum(p);
 
 		if (barnum >= 0.0) {
@@ -437,7 +438,7 @@ void print_execigauge(struct text_object *obj, char *p, int p_max_size)
 void print_execbar(struct text_object *obj, char *p, int p_max_size)
 {
 	double barnum;
-	read_exec(obj->data.s, p, p_max_size);
+	read_exec(obj->data.s, p, p_max_size, 1);
 	barnum = get_barnum(p);
 
 	if (barnum >= 0.0) {
@@ -455,7 +456,7 @@ void print_execibar(struct text_object *obj, char *p, int p_max_size)
 		return;
 
 	if (time_to_update(ed)) {
-		read_exec(ed->cmd, p, p_max_size);
+		read_exec(ed->cmd, p, p_max_size, 1);
 		barnum = get_barnum(p);
 
 		if (barnum >= 0.0) {
