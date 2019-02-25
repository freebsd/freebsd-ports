--- helper.c.orig	2010-09-08 05:58:11 UTC
+++ helper.c
@@ -323,16 +323,20 @@ int valid_arg_vector(char **av)
 char *substitute_known_path(char *request)
 {
 	cmd_t	*cmd=commands;
-	char *stripped_req=strdup(basename(request));
+	char *stripped_req=strdup(request);
+	stripped_req=basename(stripped_req);
 	while (cmd != NULL)
 	{
+		char *nname;
 		if (cmd->name == NULL)
 			break;
-		if (exact_match(basename(cmd->name),stripped_req))
+		nname = strdup(cmd->name);
+		if (exact_match(basename(nname),stripped_req))
 		{
 			free(stripped_req); /* discard old pathname */
-			return (strdup(cmd->name));
+			return (nname);
 		}
+		free(nname);
 		cmd++;
 	}
 	return (stripped_req);
