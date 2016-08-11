--- main.c.orig	2006-06-28 18:33:53 UTC
+++ main.c
@@ -43,7 +43,7 @@ struct chtab {
 	long count;
 };
 
-static size_t getline(FILE *, char **);
+static size_t get_line(FILE *, char **);
 static void usage(const char *);
 static void reverse(char *s);
 static void itoa(const long num, char s[]);
@@ -235,7 +235,7 @@ int main(int argc, char *argv[])
 		}
 
 		/* reading stream */
-		while ((len = getline(fp, &line)) > 0) {
+		while ((len = get_line(fp, &line)) > 0) {
 			line_info(line, &trline, &ok,
 					  bullshit, &bn, &bstotal, flags);
 
@@ -289,7 +289,7 @@ static void usage(const char *name)
 		   prog_ver, name);
 }
 
-static size_t getline(FILE *stream, char **line)
+static size_t get_line(FILE *stream, char **line)
 {
 	size_t c, len=0, size=BUFSIZ;
 	char *p;
