--- request.c.orig	2004-12-31 08:59:54 UTC
+++ request.c
@@ -49,7 +49,7 @@
 
 static int      read_header(int, struct req *);
 static char     sgetc(int);
-static size_t   getline(int, char[], int);
+static size_t   get_line(int, char[], int);
 static int      do_request(int, struct req *);
 
 void
@@ -63,7 +63,7 @@ keep_alive:
 	(void) memset(&r, 0, sizeof(r));
 	r.cl = clinfo;
 
-	if (getline(cl, buf, sizeof(buf)) < 1)
+	if (get_line(cl, buf, sizeof(buf)) < 1)
 		*buf = '\0';
 
 	if ((http_url(&r, buf)) == 0) {
@@ -189,7 +189,7 @@ read_header(int cl, struct req * r)
 	char           *b, *p;
 
 	i = 0;
-	while ((len = getline(cl, buf, sizeof(buf))) > 0 && i < sizeof(r->header) - 1) {
+	while ((len = get_line(cl, buf, sizeof(buf))) > 0 && i < sizeof(r->header) - 1) {
 		b = buf;
 		while (isspace((int) *b) && *(b++) != '\0');
 		if (*b == '\0')
@@ -228,7 +228,7 @@ sgetc(int s)
 }
 
 static          size_t
-getline(int s, char buf[], int len)
+get_line(int s, char buf[], int len)
 {
 	int             c;
 	size_t          i;
@@ -493,7 +493,7 @@ do_request(int cl, struct req * r)
 	}
 	if (r->type != CONNECT) {
 		i = 0;
-		while ((len = getline(s, buf, sizeof(buf))) > 0 && i < sizeof(r->header) - 1) {
+		while ((len = get_line(s, buf, sizeof(buf))) > 0 && i < sizeof(r->header) - 1) {
 			DEBUG(("do_request() => got remote header line: (%s)", buf));
 			r->header[i] = (char *) my_alloc(len + 1);
 			(void) strcpy(r->header[i++], buf);
