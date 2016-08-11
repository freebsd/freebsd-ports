--- portfind.c.orig	2014-08-24 15:54:28 UTC
+++ portfind.c
@@ -103,20 +103,25 @@ int main(int argc, char **argv) {
 		return 0;
 	}
 
+	char *filename;
 	char *release = get_release();
+
 	if(!release) {
 		fprintf(stderr, "Could not determine release\n");
 		return 1;
 	}
 
-	char *filename = calloc(strlen(release) + strlen(INDEX_FILE) + 1, sizeof(char));
-	sprintf(filename, "%s%s", INDEX_FILE, release);
+	asprintf(&filename, INDEX_FILE "%s", release);
+	if (filename == NULL) {
+		fprintf(stderr, "Could not allocate memory for `filename`\n");
+		return 1;
+	}
 	free(release);
 
 	FILE *file = fopen(filename, "r");
 	free(filename);
 	if(!file) {
-		fprintf(stderr, "Could not open %s\n", INDEX_FILE);
+		fprintf(stderr, "Could not open %s\n", filename);
 		return 1;
 	}
 
@@ -435,25 +440,32 @@ char *get_installed_version(const char *
 	return version;
 }
 
-char *get_release() {
-	size_t length = 0;
-	sysctlbyname("kern.osrelease", NULL, &length, NULL, 0);
-	if(length == 0)
-		return NULL;
-	
-	char *release = calloc(length, sizeof(char));
-	char *version = calloc(length, sizeof(char));
-	char *tmp     = version;
-	sysctlbyname("kern.osrelease", release, &length, NULL, 0);
-	char c = *release;
-	while(c != '.' && c != '\0') {
-		*tmp++ = c;
-		c = *(++release);
-	}
+char *get_release(void) {
+	char *first_dot, *release;
+	size_t length;
 
+	release = NULL;
+
+	if (sysctlbyname("kern.osrelease", NULL, &length, NULL, 0) == -1)
+		goto fail;
+
+	if ((release = malloc(sizeof(char) * length)) == NULL)
+		goto fail;
+
+	if (sysctlbyname("kern.osrelease", release, &length, NULL, 0) == -1)
+		goto fail;
+
+	if ((first_dot = strchr(release, '.')) == NULL)
+		goto fail;
+
+	*first_dot = '\0';
+
+	return release;
+
+fail:
 	free(release);
 
-	return version;
+	return NULL;
 }
 
 void help(const char *program) {
