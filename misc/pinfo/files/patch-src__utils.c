--- src/utils.c.orig	Thu Mar 16 23:14:30 2006
+++ src/utils.c	Fri Mar 17 16:04:57 2006
@@ -553,6 +553,10 @@
 int
 check_node_name( const char * const node_name, const char * const node_header)
 {
+	size_t header_len;
+	char *header, *str_start, *c;
+	int res;
+
 	/* if either one of node_name or node_header is NULL or a zero 
 	 * sized string, we have nothing to check, so return success */
 	if ( (node_name==NULL) || (node_header==NULL) 
@@ -561,15 +565,15 @@
 		return 1;
 	}
 
-	size_t header_len = strlen(node_header);
+	header_len = strlen(node_header);
 	
 	/* copy node_header to a local string which can be mutilated */
 	/* don't use strdup here, as xmalloc handles all errors */
-	char *header = xmalloc( header_len + 1 );
+	header = xmalloc( header_len + 1 );
 	strcpy(header, node_header);
 
 	/* search for "Node: foobar," in node_header */
-	char *str_start = strstr(header, "Node: ");
+	str_start = strstr(header, "Node: ");
 	if (str_start==NULL) /* no match */
 	{
 		return 0;
@@ -577,14 +581,14 @@
 	/* advance str_start to the start of the node name */
 	str_start += strlen("Node: ");
 	/* and search for the next comma, tab, or newline */
-	char *c = str_start;
+	c = str_start;
 	while ( (*c!=',') && (*c!='\t') && (*c!='\n') && (*c!='\0') ) c++;
 	*c = '\0';
 	
 	/* so, now str_start point to a \0-terminated string containing the 
 	 * node name from the header.
 	 * Let's compare it with the node_name we're looking for */
-	int res = strcmp(str_start, node_name);
+	res = strcmp(str_start, node_name);
 
 	/* we're done, so free alloc'ed vars */
 	xfree(header);
@@ -637,20 +641,22 @@
 int
 width_of_string( const char * const mbs, const int len)
 {
+	int width;
+	char *str;
+	wchar_t *wstr;
+
 	if (len<0) return -1;
 	if (len==0) return 0;
 
-	int width;
-
 	/* copy the string to a local buffer, because we only want to 
 	 * compare the first len bytes */
-	char *str = xmalloc(len+1);
+	str = xmalloc(len+1);
 	memcpy(str, mbs, len);
 	
 #ifdef USE_WCHAR
 
 	/* allocate a widestring */
-	wchar_t *wstr = xmalloc( (len+1)*sizeof(wchar_t) );
+	wstr = xmalloc( (len+1)*sizeof(wchar_t) );
 	
 	mbstowcs(wstr, str, len);
 	width = wcswidth(wstr, len);
