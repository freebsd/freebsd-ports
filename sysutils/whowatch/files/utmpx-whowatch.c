--- whowatch.c.orig	2000-06-06 03:21:44.000000000 -0700
+++ whowatch.c	2010-02-02 19:56:37.081269004 -0800
@@ -119,21 +119,17 @@
 /* 
  * Create new user structure and fill it
  */
-struct user_t *allocate_user(struct utmp *entry)
+struct user_t *allocate_user(struct utmpx *entry)
 {
 	struct user_t *u;
 	int ppid;
 	u = calloc(1, sizeof *u);
 	if(!u) errx(1, "Cannot allocate memory.");
-	strncpy(u->name, entry->ut_user, UT_NAMESIZE);
-	strncpy(u->tty, entry->ut_line, UT_LINESIZE);
-	strncpy(u->host, entry->ut_host, UT_HOSTSIZE);
+	strncpy(u->name, entry->ut_user, sizeof(entry->ut_user));
+	strncpy(u->tty, entry->ut_line, sizeof(entry->ut_line));
+	strncpy(u->host, entry->ut_host, sizeof(entry->ut_host));
 	
-#ifdef HAVE_UTPID		
 	u->pid = entry->ut_pid;
-#else
-	u->pid = get_login_pid(u->tty);
-#endif
 
  	if((ppid = get_ppid(u->pid)) == -1)
 		strncpy(u->parent, "can't access", sizeof u->parent);
@@ -192,34 +188,24 @@
  */
 void read_utmp()		
 {
-	int fd, i;
-	static struct utmp entry;
+	static struct utmpx *entry;
 	struct user_t *u;
+
+	while ((entry = getutxent()) != NULL) {
 	
-	if ((fd = open(UTMP_FILE ,O_RDONLY)) == -1){
-		curses_end();
-		errx(1, "Cannot open " UTMP_FILE);
-	}
-	while((i = read(fd, &entry,sizeof entry)) > 0) {
-		if(i != sizeof entry) errx(1, "Error reading " UTMP_FILE );
-#ifdef HAVE_USER_PROCESS
-		if(entry.ut_type != USER_PROCESS) continue;
-#else
-		if(!entry.ut_name[0]) continue;
-#endif
-		u = allocate_user(&entry);
+		if(entry->ut_type != USER_PROCESS) continue;
+		u = allocate_user(entry);
 		print_user(u);
 		update_nr_users(u->parent, &u->prot, LOGIN);
 		how_many ++;
 		users_list.d_lines = how_many;		
 		addto_list(u, users);
 	}
-	close(fd);
 	wnoutrefresh(users_list.wd);
 	return;
 }
 
-struct user_t* new_user(struct utmp *newone)
+struct user_t* new_user(struct utmpx *newone)
 {
 	struct user_t *u;
 	u = allocate_user(newone);
@@ -246,7 +232,7 @@
 void check_wtmp()
 {
 	struct user_t *u;
-	struct utmp entry;
+	struct utmpx entry;
 	int i;
 
 	while((i = read(wtmp_fd, &entry, sizeof entry)) > 0){ 
@@ -256,25 +242,17 @@
 			errx(1, "Error reading " WTMP_FILE );
 		}
 		/* user just logged in */
-#ifdef HAVE_USER_PROCESS
 		if(entry.ut_type == USER_PROCESS) {
-#else
-		if(entry.ut_user[0]) {
-#endif
 			u = new_user(&entry);
 			print_user(u);
 			wrefresh(users_list.wd);
 			print_info();
 			continue;
 		}
-#ifdef HAVE_DEAD_PROCESS
 		if(entry.ut_type != DEAD_PROCESS) continue;
-#else
-//		if(entry.ut_line[0]) continue;
-#endif
 	/* user just logged out */
 		for_each(u, users) {
-			if(strncmp(u->tty, entry.ut_line, UT_LINESIZE)) 
+			if(strncmp(u->tty, entry.ut_line, sizeof(entry.ut_line))) 
 				continue;
 			if (state == USERS_LIST) 
 				delete_line(&users_list, u->line);
