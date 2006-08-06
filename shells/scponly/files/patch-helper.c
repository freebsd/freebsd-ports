--- scponly-4.6/helper.c.orig	Tue Jan 31 22:04:16 2006
+++ scponly-4.6/helper.c	Thu Mar 23 00:53:01 2006
@@ -133,6 +133,78 @@
 	char		**tmpptr=av;
 	int			ch;
 	int			ac=0;
+	char		**av2 = NULL;
+
+	/*	
+	 *	first count the arguments in the vector
+	 */
+	tmpptr=av;
+	while (*tmpptr!=NULL)
+	{	
+		*tmpptr++;
+		ac++;
+	}
+
+#ifdef PROG_RSYNC
+	if (exact_match(PROG_RSYNC, av[0]))
+	{
+		/*
+		 *	these are the long opts (beginning "--") which we
+		 *	allow for rsync
+		 */
+		char *permitted_long_opts[] = {
+				"--server",
+				"--sender",
+				"--delete",
+				NULL	/* last element must be NULL */
+			};
+
+		/*
+		 *	make a copy of the args excluding any permitted long
+		 *	options
+		 */
+		int i, j;
+		av2 = malloc(ac * sizeof *av2);
+		av2[0] = av[0];
+		for (i = 1, j = 1; i < ac; ++i)
+		{
+			if (0 == strncmp(av[i], "--", 2))
+			{
+				char **p;
+				/*
+				 *	test against permitted opts
+				 */
+				for (p = permitted_long_opts; *p; ++p)
+				{
+					if (exact_match(av[i], *p))
+						break;
+				}
+				
+				if (*p)
+				{
+					/*
+					 *	permitted; skip this one
+					 */
+					continue;
+				}
+				else
+				{
+					/*
+					 *	no match
+					 */
+					syslog(LOG_ERR, "option %s is not permitted for use with %s (%s)",
+						av[i], cmdarg->name, logstamp());
+					return 1;
+				}
+			}
+			av2[j++] = av[i];
+			    
+		}
+		av2[j] = NULL;
+		ac = j;
+		av = av2;
+	}
+#endif /* PROG_RSYNC */
 
 	while (cmdarg != NULL)
 	{
@@ -151,15 +223,6 @@
 			 */
 			if (1 == cmdarg->getoptflag)
 			{
-				/*	
-				 *	first count the arguments in the vector
-				 */
-				tmpptr=av;
-				while (*tmpptr!=NULL)
-				{	
-					*tmpptr++;
-					ac++;
-				}
 				/* 
 				 *	now use getopt to look for our problem option
 				 */
