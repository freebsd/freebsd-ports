diff -u -r8.928 deliver.c
--- sendmail/deliver.c	2002/01/10 03:23:29	8.928
+++ sendmail/deliver.c	2002/02/04 23:32:05
@@ -5141,11 +5141,17 @@
 		}
 		(void) sm_strlcpy(targetfile, SafeFileEnv, sizeof targetfile);
 		realfile = targetfile + len;
-		if (targetfile[len - 1] != '/')
-			(void) sm_strlcat(targetfile, "/", sizeof targetfile);
 		if (*filename == '/')
 			filename++;
-		(void) sm_strlcat(targetfile, filename, sizeof targetfile);
+		if (*filename != '\0')
+		{
+			/* paranoia: trailing / should be removed in readcf */
+			if (targetfile[len - 1] != '/')
+				(void) sm_strlcat(targetfile,
+						  "/", sizeof targetfile);
+			(void) sm_strlcat(targetfile, filename,
+					  sizeof targetfile);
+		}
 	}
 	else if (mailer->m_rootdir != NULL)
 	{
@@ -5388,6 +5394,9 @@
 
 		if (realfile != targetfile)
 		{
+			char save;
+
+			save = *realfile;
 			*realfile = '\0';
 			if (tTd(11, 20))
 				sm_dprintf("mailfile: chroot %s\n", targetfile);
@@ -5397,7 +5406,7 @@
 				       targetfile);
 				RETURN(EX_CANTCREAT);
 			}
-			*realfile = '/';
+			*realfile = save;
 		}
 
 		if (tTd(11, 40))
--- sendmail/readcf.c	2002/01/30 19:56:37	8.595
+++ sendmail/readcf.c	2002/02/04 23:32:05
@@ -2950,6 +2950,17 @@
 		break;
 
 	  case O_SAFEFILEENV:	/* chroot() environ for writing to files */
+		if (*val == '\0')
+			break;
+
+		/* strip trailing slashes */
+		p = val + strlen(val) - 1;
+		while (p >= val && *p == '/')
+			*p-- = '\0';
+
+		if (*val == '\0')
+			break;
+
 		SafeFileEnv = newstr(val);
 		break;
 

