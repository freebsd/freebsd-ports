--- sources/handlers.c.orig	2005-06-01 12:36:18.000000000 +0200
+++ sources/handlers.c	2008-09-03 14:25:41.000000000 +0200
@@ -25,6 +25,7 @@
 #endif
 
 extern char cgiRoot[MAX_PATH_LEN+1];         /* root for CGI scripts exec */
+extern char homePath[MAX_PATH_LEN+1];        /* root for PHP scripts exec */
 extern int  port;                            /* server port */
 extern char defaultFileName[MAX_PATH_LEN+1]; /* default name for index, default or similar file */
 
@@ -261,6 +262,17 @@
         
         i = 0;
 	/* beware of not overfilling this array, check MAX_ENVP_LEN */
+        if (req.contentLength != -1)
+        {
+            newEnvp[i] = (char *) calloc(35, sizeof(char));
+            sprintf(newEnvp[i++], "CONTENT_LENGTH=%ld", req.contentLength);
+            newEnvp[i] = (char *) calloc(CONTENT_TYPE_LEN + 14, sizeof(char));
+            strcpy(newEnvp[i], "CONTENT_TYPE=");
+            strcat(newEnvp[i++], req.contentType);
+        }
+        newEnvp[i] = (char *) calloc(strlen(DEFAULT_SERVER_NAME) + 13, sizeof(char));
+        strcpy(newEnvp[i], "SERVER_NAME=");
+        strcat(newEnvp[i++], DEFAULT_SERVER_NAME);
         newEnvp[i] = (char *) calloc(128, sizeof(char));
         strcpy(newEnvp[i], "SERVER_SOFTWARE=");
         strcat(newEnvp[i], SERVER_SOFTWARE_STR);
@@ -293,6 +305,12 @@
 	completedPath[MAX_PATH_LEN]='\0';
 	strcpy(newEnvp[i], "SCRIPT_FILENAME=");
 	strcat(newEnvp[i++], completedPath);
+        if (req.cookie[0] != '\0') 	 
+        { 	 
+            newEnvp[i] = (char *) calloc(MAX_COOKIE_LEN+13, sizeof(char));
+            strcpy(newEnvp[i], "HTTP_COOKIE="); 	 
+            strcat(newEnvp[i++], req.cookie); 	 
+        }
 
         /* extracting PATH env variable */
         envPath = getenv("PATH");
@@ -333,8 +351,236 @@
 }
 #endif /* ENABLE_CGI */
 
+#ifdef PHP
+int phpHandler(port, sock, phpFileName, completedPath, req, postStr)
+int port;
+int sock;
+char *phpFileName;
+char *completedPath;
+struct request req;
+char *postStr;
+{
+    char *envPath; /* pointer to the envrionment PATH variable */
+    char *relativePath;
+    char scriptWorkingDir[2*MAX_PATH_LEN+1];
+    char **newArgv;
+    char **newEnvp;
+    int i;
+    int outStdPipe[2]; /* we will redirect the script output to a pipe so we can read it */
+    int inStdPipe[2];  /* we will redirect the script input to a pipe so we can read it */
+    int pid;           /* we fork and execute inside the child the script */
+    char pipeReadBuf[PIPE_READ_BUF+1];
+    int howMany;
+    int totalSentFromPipe; /* ampunt of bytes sucked from the pipe and pushed in to the socket */
+    int fatal;
+
+    relativePath = strrchr(completedPath, '/');
+    strncpy(scriptWorkingDir, completedPath, strlen(completedPath) - strlen(relativePath));
+    scriptWorkingDir[strlen(completedPath) - strlen(relativePath)] = '\0';
+
+    /* first we create the pipes needed for stdout redirection */
+    if (pipe(outStdPipe))
+    {
+        DBGPRINTF(("Pipe creation error\n"));
+        return -1;
+    }
+    if (pipe(inStdPipe))
+    {
+        DBGPRINTF(("Pipe creation error\n"));
+        return -1;
+    }
+
+
+    /* now we fork to subsequently execve */
+    pid = fork();
+    if (pid)
+    { /* this is the parent process */
+        if (pid < 0)
+        { /* we check for creation error */
+            DBGPRINTF(("Forking error during cgi exec: %d\n", errno));
+            return -1;
+        }
+        /* we close the unused end of the pipe */
+        close(outStdPipe[WRITE]);
+        close(inStdPipe[READ]);
+
+        if (req.method[0]=='P' && req.method[1]=='O' && req.method[2]=='S' && req.method[3]=='T' && req.method[4]=='\0')
+        {
+            /* we have to feed the stdin of the script */
+            if(!strlen(postStr))
+            {
+                DBGPRINTF(("cannot post empty data\n"));
+                return -1;
+            }
+            howMany = write(inStdPipe[WRITE], postStr, strlen(postStr));
+            if (howMany < 0)
+                DBGPRINTF(("Error during script pipe read (POST).\n"));
+        }
+        totalSentFromPipe = 0;
+        fatal = NO;
+        howMany = 1;
+        while (howMany > 0 && !fatal)
+        {
+            howMany = read(outStdPipe[READ], pipeReadBuf, PIPE_READ_BUF);
+            if (howMany > 0)
+            {
+                if (sendChunk(sock, pipeReadBuf, howMany) < 0)
+                    fatal = YES;
+                else
+                    totalSentFromPipe += howMany;
+            } else
+                fatal = YES; /* it may be EOF too */
+        }
+        /* now we finished and we clean up */
+        wait(&i);
+        if (i) /* check if execution exited cleanly or with code */
+            logWriter(LOG_CGI_FAILURE, NULL, 0, req, i);
+        else
+            logWriter(LOG_CGI_SUCCESS, NULL, totalSentFromPipe, req, 0);
+        close(outStdPipe[READ]);
+        close(inStdPipe[WRITE]);
+    } else
+    { /* this is the child process */
+        /* now we do some environment setup work */
+        newArgv = (char **)calloc(MAX_ARGV_LEN + 1, sizeof(char*));
+        for (i = 0; i < MAX_ARGV_LEN + 1; i++)
+        {
+            newArgv[i] = (char *)calloc(MAX_PATH_LEN, sizeof(char));
+        }
+
+        newEnvp = (char **)calloc(MAX_ENVP_LEN + 1, sizeof(char*));
+
+        i = 0;
+        strcpy(newArgv[i++], phpFileName);     /* here we should pass the phppath */
+        strcpy(newArgv[i++], completedPath);  /* here we should pass the scriptpath */
+        if (strlen(req.queryString))
+        {
+            int toParse;
+            int j, k;
+
+            toParse = YES;
+            j = strlen(req.queryString);
+            while (toParse && j > 0)
+            {
+                if (req.queryString[j] == '=')
+                    toParse = NO;
+                j--;
+            }
+            if (toParse)
+            {
+                j = 0;
+                k = 0;
+                howMany = strlen(req.queryString);
+                while (j < howMany)
+                {
+                    if (req.queryString[j] == '+')
+                    {
+                        newArgv[i++][k] = '\0';
+                        k = 0;
+                    } else
+                        newArgv[i][k++] = req.queryString[j];
+                    j++;
+                }
+                i++; /* after all we will have at least one argument! */
+            }
+        }
+        newArgv[i] = NULL; /* we correctly terminate argv */
+
+        i = 0;
+        /* beware of not overfilling this array, check MAX_ENVP_LEN */
+        if (req.contentLength != -1)
+        {
+            newEnvp[i] = (char *) calloc(35, sizeof(char));
+            sprintf(newEnvp[i++], "CONTENT_LENGTH=%ld", req.contentLength);
+            newEnvp[i] = (char *) calloc(CONTENT_TYPE_LEN + 14, sizeof(char));
+            strcpy(newEnvp[i], "CONTENT_TYPE=");
+            strcat(newEnvp[i++], req.contentType);
+        }
+        newEnvp[i] = (char *) calloc(strlen(DEFAULT_SERVER_NAME) + 13, sizeof(char));
+        strcpy(newEnvp[i], "SERVER_NAME=");
+        strcat(newEnvp[i++], DEFAULT_SERVER_NAME);
+        newEnvp[i] = (char *) calloc(128, sizeof(char));
+        strcpy(newEnvp[i], "SERVER_SOFTWARE=");
+        strcat(newEnvp[i], SERVER_SOFTWARE_STR);
+        strcat(newEnvp[i], "/");
+        strcat(newEnvp[i++], SERVER_VERSION_STR);
+        newEnvp[i] = (char *) calloc(METHOD_LEN+16, sizeof(char));
+        strcpy(newEnvp[i], "REQUEST_METHOD=");
+        strcat(newEnvp[i++], req.method);
+        newEnvp[i] = (char *) calloc(MAX_PATH_LEN+16, sizeof(char));
+        strcpy(newEnvp[i], "SCRIPT_NAME=");
+        strcat(newEnvp[i++], req.documentAddress);
+        newEnvp[i] = (char *) calloc(32, sizeof(char));
+        strcpy(newEnvp[i], "GATEWAY_INTERFACE=");
+        strcat(newEnvp[i++], CGI_VERSION);
+        newEnvp[i] = (char *) calloc(18, sizeof(char));
+        sprintf(newEnvp[i++], "SERVER_PORT=%d", port);
+        newEnvp[i] = (char *) calloc(MAX_QUERY_STRING_LEN+16, sizeof(char));
+        strcpy(newEnvp[i], "QUERY_STRING=");
+        strcat(newEnvp[i++], req.queryString);
+        newEnvp[i] = (char *) calloc(PROTOCOL_LEN+17, sizeof(char));
+        strcpy(newEnvp[i], "SERVER_PROTOCOL=");
+        strcat(newEnvp[i++], req.protocolVersion);
+        newEnvp[i] = (char *) calloc(ADDRESS_LEN+13, sizeof(char));
+        strcpy(newEnvp[i], "REMOTE_ADDR=");
+        strcat(newEnvp[i++], req.address);
+        newEnvp[i] = (char *) calloc(USER_AGENT_LEN+17, sizeof(char));
+        strcpy(newEnvp[i], "HTTP_USER_AGENT=");
+        strcat(newEnvp[i++], req.userAgent);
+        newEnvp[i] = (char *) calloc(MAX_PATH_LEN+17, sizeof(char));
+        completedPath[MAX_PATH_LEN]='\0';
+        strcpy(newEnvp[i], "SCRIPT_FILENAME=");
+        strcat(newEnvp[i++], completedPath);
+        if (req.cookie[0] != '\0')
+        {
+            newEnvp[i] = (char *) calloc(MAX_COOKIE_LEN+13, sizeof(char));
+            strcpy(newEnvp[i], "HTTP_COOKIE=");
+            strcat(newEnvp[i++], req.cookie);
+        }
+
+        /* extracting PATH env variable */
+        envPath = getenv("PATH");
+        /* we get the path from the env itself so we assume it safe */
+        newEnvp[i] = (char *) calloc(MAX_PATH_LEN+16, sizeof(char));
+        strcpy(newEnvp[i], "PATH=");
+        strcat(newEnvp[i++], envPath);
+
+        /* terminate the array */
+        newEnvp[i] = NULL;
+
+        /* we change the current working directory to the scripts one */
+        if(chdir(scriptWorkingDir))
+        {
+            DBGPRINTF(("error while changing PWD in script execution: %d\n", errno));
+        }
+
+        close(outStdPipe[READ]);    /* we close the unused end*/
+        dup2(outStdPipe[WRITE], 1); /* we duplicate the pipe to the stdout */
+        close(outStdPipe[WRITE]);   /* we close the pipe, since we use the duplicate */
+
+        close(inStdPipe[WRITE]);    /* we close the unused end*/
+        dup2(inStdPipe[READ], 0);   /* we duplicate the pipe to the stdin */
+        close(inStdPipe[READ]);     /* we close the pipe, since we use the duplicate */
+
+
+        /* generate a reduced mimeHeader, no type, no size, etc */
+        generateMimeHeader(sock, 200, "", NULL, req.protocolVersion, CGI_ONLY_HEADER);
+
+        /* now we execute the script replacing the current child */
+        execve(phpFileName, newArgv, newEnvp);
+        /* we reach this line only if an execution error occoured */
+        /* logging will happen in the father */
+        printf("\n<HTML><HEAD><TITLE>PHP Error</TITLE></HEAD><BODY><H1>PHP Exec error</H1></BODY></HTML>\n");
+        exit(-1);
+    }
+    return 0;
+}
+#endif
+
+
 /* generate a full header for a given file */
-int dumpHeader(sock, filePath, mimeType, req)
+int dumpHeader(port, sock, filePath, mimeType, req)
+int port;
 int sock;
 char filePath[];
 char mimeType[];
