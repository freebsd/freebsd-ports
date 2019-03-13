--- helper.c.orig	2010-09-08 05:58:11 UTC
+++ helper.c
@@ -323,16 +323,22 @@ int valid_arg_vector(char **av)
 char *substitute_known_path(char *request)
 {
 	cmd_t	*cmd=commands;
-	char *stripped_req=strdup(basename(request));
+	char *mrequest=strdup(request);
+	char *stripped_req=strdup(basename(mrequest));
+	free(mrequest);
 	while (cmd != NULL)
 	{
+		char *mname;
 		if (cmd->name == NULL)
 			break;
-		if (exact_match(basename(cmd->name),stripped_req))
+		mname = strdup(cmd->name);
+		if (exact_match(basename(mname),stripped_req))
 		{
 			free(stripped_req); /* discard old pathname */
+			free(mname);
 			return (strdup(cmd->name));
 		}
+		free(mname);
 		cmd++;
 	}
 	return (stripped_req);
