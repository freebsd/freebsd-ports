--- util.c.orig	Mon Jul  7 20:41:29 2003
+++ util.c	Fri Apr 16 01:28:16 2004
@@ -1,9 +1,9 @@
 /*
  * util.c - utility functions for rssh
- * 
+ *
  * Copyright 2003 Derek D. Martin ( code at pizzashack dot org ).
  *
- * This program is licensed under a BSD-style license, as follows: 
+ * This program is licensed under a BSD-style license, as follows:
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions
@@ -66,10 +66,10 @@
 extern char *username;
 extern char *progname;
 
-/* 
+/*
  * build_arg_vector() - return a pointer to a vector of strings which
  *                      represent the arguments of the command to execv().
- */                 
+ */
 char **build_arg_vector( char *str, size_t reserve )
 {
 
@@ -77,18 +77,18 @@
 	int		retc;
 
 	result.we_offs = reserve;
-	if ( (retc = wordexp(str, &result, WRDE_NOCMD|WRDE_DOOFFS)) ){
+	if ( (retc = wordexp(str, &result, WRDE_NOCMD|WRDE_DOOFS)) ){
 		log_set_priority(LOG_ERR);
 		switch( retc ){
 		case WRDE_BADCHAR:
 		case WRDE_CMDSUB:
-			fprintf(stderr, "%s: bad characters in arguments\n", 
+			fprintf(stderr, "%s: bad characters in arguments\n",
 				progname);
 			log_msg("user %s used bad chars in command",
 				username);
 			break;
 		default:
-			fprintf(stderr, "%s: error expanding arguments\n", 
+			fprintf(stderr, "%s: error expanding arguments\n",
 				progname);
 			log_msg("error expanding arguments for user %s",
 				username);
@@ -105,7 +105,7 @@
 
 	log_set_priority(LOG_ERR);
 	/* determine which commands are usable for error message */
-	if ( (flags & (RSSH_ALLOW_SCP | RSSH_ALLOW_SFTP)) == 
+	if ( (flags & (RSSH_ALLOW_SCP | RSSH_ALLOW_SFTP)) ==
 			(RSSH_ALLOW_SCP | RSSH_ALLOW_SFTP) )
 		cmd = " to scp or sftp";
 	else if ( flags & RSSH_ALLOW_SCP )
@@ -147,7 +147,7 @@
 	len = strlen(PATH_SFTP_SERVER);
 	if ( cl_len < len ) len = cl_len;
 	/* check to see if cl starts with an allowed command */
-	if ( !(strncmp(cl, PATH_SFTP_SERVER, len)) && 
+	if ( !(strncmp(cl, PATH_SFTP_SERVER, len)) &&
 			(isspace(cl[len]) || cl[len] == '\0') &&
 			opts->shell_flags & RSSH_ALLOW_SFTP )
 		return PATH_SFTP_SERVER;
@@ -155,7 +155,7 @@
 	len = 3;
 	/* if cl_len is less than 3, then it's not a valid command */
 	if ( cl_len < 3 ) return NULL;
-	if ( !(strncmp(cl, "scp", len)) && 
+	if ( !(strncmp(cl, "scp", len)) &&
 			(isspace(cl[len])) &&
 			opts->shell_flags & RSSH_ALLOW_SCP ){
 		return PATH_SCP;
@@ -183,7 +183,7 @@
 		len--;
 	}
 	if ( (strncmp(root, path, len)) ) return NULL;
-	
+
 	/*
 	 * path[len] is the first character of path which is not part of root.
 	 * If it is not '/' then we chopped path off in the middle of a path
@@ -223,7 +223,7 @@
  *                     them.  Returns the bits in the bool pointers of the
  *                     same name, and returns FALSE if the bits are not valid
  */
-int validate_access( const char *temp, bool *allow_sftp, 
+int validate_access( const char *temp, bool *allow_sftp,
 		     bool *allow_scp )
 {
 	char	scp[2];
