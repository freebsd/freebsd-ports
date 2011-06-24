--- smb_auth.c.orig	1999-09-28 21:31:26.000000000 +0200
+++ smb_auth.c	2011-06-24 19:33:54.000000000 +0200
@@ -29,11 +29,11 @@
 {
 	char				*name;			/* domain name */
 	char				*sname;			/* match this with user input */
-	char				*passthrough;	/* pass-through authentication */
-	char				*nmbaddr;		/* name service address */
+	const char				*passthrough;	/* pass-through authentication */
+	const char				*nmbaddr;		/* name service address */
 	int					nmbcast;		/* broadcast or unicast */
 	char				*authshare;		/* share name of auth file */
-	char				*authfile;		/* pathname of auth file */
+	const char				*authfile;		/* pathname of auth file */
 	struct SMBDOMAIN	*next;			/* linked list */
 };
 
@@ -73,7 +73,7 @@
 	}
 }
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
 	int					i;
 	char				buf[BUFSIZE];
@@ -84,11 +84,11 @@
 	char				*domname;
 	FILE				*p;
 	int					debug = 0;
-	char				*shcmd;
+	const char				*shcmd;
 
 	/* make standard output line buffered */
 	if (setvbuf(stdout, NULL, _IOLBF, 0) != 0)
-		return;
+		return 1;
 
 	/* parse command line arguments */
 	for (i = 1; i < argc; i++)
@@ -106,13 +106,13 @@
 		if (strcmp(argv[i], "-W") == 0)
 		{
 			if ((dom = (struct SMBDOMAIN *) malloc(sizeof(struct SMBDOMAIN))) == NULL)
-				return;
+				return 1;
 
 			dom->name = dom->sname = argv[++i];
 			dom->passthrough = "";
 			dom->nmbaddr = "";
 			dom->nmbcast = NMB_BROADCAST;
-			dom->authshare = "NETLOGON";
+			dom->authshare = strdup( "NETLOGON" );
 			dom->authfile = "proxyauth";
 			dom->next = NULL;
 
@@ -165,7 +165,7 @@
 			if (lastdom != NULL)
 			{
 				if ((lastdom->authshare = strdup(argv[++i])) == NULL)
-					return;
+					return 1;
 
 				/* convert backslashes to forward slashes */
 				for (s = lastdom->authshare; *s != '\0'; s++)
@@ -190,7 +190,7 @@
 
 	/* pass to helper script */
     if (putenv("SAMBAPREFIX=" SAMBAPREFIX) != 0)
-    	return;
+    	return 1;
 
 	while (1)
 	{
@@ -258,4 +258,5 @@
 			(void) printf("ERR\n");
 
 	} /* while (1) */
+	return 1;
 }
