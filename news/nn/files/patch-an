--- nntp.c.orig	Tue Apr 19 16:06:51 2005
+++ nntp.c	Sat Jul  7 00:30:15 2007
@@ -76,6 +76,7 @@
 static int      connect_server(void);
 static void     debug_msg(char *prefix, char *str);
 static void     find_server(void);
+static char    *find_domain(const char *domainFile);
 static int      get_server_line(char *string, int size);
 static int      get_server(char *string, int size);
 static int      get_socket(void);
@@ -233,6 +234,50 @@
     sys_error("Failed to find name of NNTP server!");
 }
 
+
+/*
+ * find_domain		Get the domain name for posting from a named file.
+ *			Handle blank lines and comments.
+ *
+ *	Parameters:	"file" is the name of the file to read.
+ *
+ *	Returns:	Pointer to static data area containing the
+ *			first non-blank/comment line in the file.
+ *			NULL on error (or lack of entry in file).
+ *
+ *	Side effects:	None.
+ */
+
+static char *
+find_domain(const char *domainFile)
+{
+    register FILE  *fp;
+    register char  *cp;
+    static char     buf[MAXHOSTNAMELEN];
+    char           *index();
+
+    if (domainFile == NULL)
+	return (NULL);
+
+    fp = fopen(domainFile, "r");
+    if (fp == NULL)
+	return (NULL);
+
+    while (fgets(buf, sizeof (buf), fp) != NULL) {
+	if (*buf == '\n' || *buf == '#')
+	    continue;
+	cp = index(buf, '\n');
+	if (cp)
+	    *cp = '\0';
+	(void) fclose(fp);
+	return (buf);
+    }
+
+    (void) fclose(fp);
+    return (NULL);
+}
+
+
 /*
  * get_server_line: get a line from the server.
  *
@@ -848,6 +893,16 @@
 
 #else				/* DOMAIN */
 
+    /*
+     * if domain is defined in DOMAIN_FILE, use it
+     */
+    cp = find_domain(DOMAIN_FILE);
+    if (cp) {
+	strncpy(domain, cp, MAXHOSTNAMELEN);
+	domain[MAXHOSTNAMELEN-1] = 0;	/* ensure nul-terminated */
+	return;
+    }
+
     domain[0] = '\0';
 
     cp = index(host_name, '.');
@@ -882,6 +937,7 @@
 #endif
     }
 #endif				/* DOMAIN */
+    domain[MAXHOSTNAMELEN-1] = 0;	/* ensure nul-terminated */
 }
 
 /*
