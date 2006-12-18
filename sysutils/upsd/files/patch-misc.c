--- misc.c.orig	Sat Aug  3 01:44:24 1996
+++ misc.c	Mon Dec 18 21:03:19 2006
@@ -27,7 +27,7 @@
 		    pathname);
 		return -1;
 	}
-	fprintf(f, "%ld\n", getpid());
+	fprintf(f, "%u\n", getpid());
 	fclose(f);
 	umask(oldmask);
 	return 0;
@@ -60,7 +60,7 @@
 {
 	register char *p;
 	if((p = malloc(size)) == NULL) {
-		syslog(LOG_ERR, "xalloc: cannot allocate %ls bytes: %m", size);
+		syslog(LOG_ERR, "xalloc: cannot allocate %u bytes: %m", size);
 		return NULL;
 	}
 	return p;
@@ -105,7 +105,7 @@
 		if(((struct ident *)list)->id == 0) {
 			return NULL;
 		}
-		(char *)list += size;
+		list += size;
 	}
 	return list;
 }
@@ -122,7 +122,7 @@
 	register void *list;
 	register size_t size;
 {
-	for(;((struct ident *)list)->id != 0;(char *)list += size) {
+	for(;((struct ident *)list)->id != 0;list += size) {
 		if(((struct ident *)list)->name == name) {
 			return list;
 		}
@@ -255,7 +255,7 @@
 int
 getcurrenttime(void)
 {
-	if(time(&current_time) == NULL) {
+	if(time(&current_time) == -1) {
 		syslog(LOG_ERR, "cannot get current time: %m");
 		return -1;
 	}
