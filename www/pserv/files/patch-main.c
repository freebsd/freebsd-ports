--- sources/main.c.orig	Mon May 16 23:13:18 2005
+++ sources/main.c	Sat May 28 10:42:47 2005
@@ -23,6 +23,7 @@
 char	    	defaultFileName[MAX_PATH_LEN+1];
 char	    	logFileName[MAX_PATH_LEN+1];
 char	    	mimeTypesFileName[MAX_PATH_LEN+1];
+char            phpFileName[MAX_PATH_LEN+1];
 char	    	cgiRoot[MAX_PATH_LEN+1]; /* root for CGI scripts exec */
 struct timeval	sockTimeVal;
 mimeData    	*mimeArray;  /* here we will hold all MIME data, inited once, never to be changed */
@@ -314,10 +315,13 @@
         reqStruct->keepAlive = YES;
     else if (!strncmp(reqArray[1], "Connection: keep-alive", strlen("Connection: keep-alive")))
         reqStruct->keepAlive = YES;
-    /* user-agent, content-length and else */
+    /* user-agent, content-length, content-type, cookie and else */
     i = 1;
     j = NO;
     reqStruct->userAgent[0] = '\0';
+    reqStruct->contentLength = -1;
+    reqStruct->contentType[0] = '\0';
+    reqStruct->cookie[0] = '\0';
     while (i < readLines)
     {
         if (!strncmp(reqArray[i], "User-Agent:", strlen("User-Agent:")))
@@ -332,6 +336,20 @@
 #ifdef PRINTF_DEBUG
 	    printf("content length %ld\n", reqStruct->contentLength);
 #endif
+        }
+        else if (!strncmp(reqArray[i], "Content-Type:", strlen("Content-type:")) || !strncmp(reqArray[i], "Content-type:", strlen("Content-type:")))
+        {
+            strncpy(reqStruct->contentType, &reqArray[i][strlen("Content-type: ")], CONTENT_TYPE_LEN - 1);
+#ifdef PRINTF_DEBUG
+            printf("content type %s\n", reqStruct->contentType);
+#endif
+        }
+        else if (!strncmp(reqArray[i], "Cookie:", strlen("Cookie:")))
+        {
+            strncpy(reqStruct->cookie, &reqArray[i][strlen("Cookie: ")], MAX_COOKIE_LEN - 1);
+#ifdef PRINTF_DEBUG
+            printf("cookie %s\n", reqStruct->cookie);
+#endif
 	}
         i++;
     }
@@ -442,18 +460,39 @@
                      * we append the default file name */
                     strcat(completeFilePath, defaultFileName);
                     analyzeExtension(mimeType, completeFilePath);
-                    dumpFile(sock, completeFilePath, mimeType, req);
+#ifdef PHP
+                    if (strncmp(mimeType, "application/x-httpd-php", 23))
+#endif
+                        dumpFile(sock, completeFilePath, mimeType, req);
+#ifdef PHP
+                    else
+                        phpHandler(port, sock, phpFileName, completeFilePath, req, NULL);
+#endif
                 }
 #else
                 /* we append the default file name */
                 strcat(completeFilePath, defaultFileName);
                 analyzeExtension(mimeType, completeFilePath);
-                dumpFile(sock, completeFilePath, mimeType, req);
+#ifdef PHP
+                if (strncmp(mimeType, "application/x-httpd-php", 23))
+#endif
+                    dumpFile(sock, completeFilePath, mimeType, req);
+#ifdef PHP
+                else
+                    phpHandler(port, sock, phpFileName, completeFilePath, req, NULL);
+#endif
 #endif
             } else
             { /* it is a plain file */
                 analyzeExtension(mimeType, completeFilePath);
-                dumpFile(sock, completeFilePath, mimeType, req);
+#ifdef PHP
+                if (strncmp(mimeType, "application/x-httpd-php", 23))
+#endif
+                    dumpFile(sock, completeFilePath, mimeType, req);
+#ifdef PHP
+                else
+                    phpHandler(port, sock, phpFileName, completeFilePath, req, NULL);
+#endif
             }
         }
     } else if (!strcmp(req.method, "HEAD"))
@@ -485,7 +524,14 @@
                 strcat(completeFilePath, defaultFileName);
             }
             analyzeExtension(mimeType, completeFilePath);
-            dumpHeader(sock, completeFilePath, mimeType, req);
+#ifdef PHP
+            if (strncmp(mimeType, "application/x-httpd-php", 23))
+#endif
+                dumpFile(sock, completeFilePath, mimeType, req);
+#ifdef PHP
+            else
+                phpHandler(port, sock, phpFileName, completeFilePath, req, NULL);
+#endif
         }
     } else if (!strcmp(req.method, "POST"))
     {
@@ -499,13 +545,6 @@
         int readFinished;
         
         printf("Handling of POST method\n");
-        /* first we check if the path contains the directory selected for cgi's and in case handle it */
-        if (strncmp(req.documentAddress, CGI_MATCH_STRING, strlen(CGI_MATCH_STRING)))
-        {
-            /* non cgi POST is not supported */
-            sayError(sock, UNHANDLED_METHOD, "", req);
-            return -1;
-        }
 #ifdef ENABLE_CGI
 #ifdef PRINTF_DEBUG
         printf ("begin of post handling\n");
@@ -522,7 +561,7 @@
             return -1;
         } else if (req.contentLength >= BUFFER_SIZE)
         {
-            sayError(sock, BUFFER_OVERFLOW, "", req);
+            sayError(sock, POST_BUFFER_OVERFLOW, "", req);
             return -1;
         }
         while (!readFinished)
@@ -601,7 +640,77 @@
 #ifdef PRINTF_DEBUG
             printf("buff: |%s|\n", buff);
 #endif
-            cgiHandler(port, sock, req, buff);
+            if (!strncmp(req.documentAddress, CGI_MATCH_STRING, strlen(CGI_MATCH_STRING)))
+            {
+                cgiHandler(port, sock, req, buff);
+            } else
+            {
+#ifdef PHP
+                strcpy(completeFilePath, homePath);
+                strcat(completeFilePath, req.documentAddress);
+                /* now we check if the given path tries to get out of the root */
+                {
+                    int i,j;
+                    int sL;
+                    char dirName[MAX_PATH_LEN+1];
+                    int depthCount = 0;
+
+                    sL = strlen(req.documentAddress);
+                    dirName[0] = '\0';
+                    if (sL > 3) {
+                        dirName[0] = req.documentAddress[1];
+                        dirName[1] = req.documentAddress[2];
+                        dirName[2] = req.documentAddress[3];
+                        dirName[3] ='\0';
+                        if (!strcmp(dirName, "../"))
+                        {
+                            sayError(sock, FORBIDDEN, req.documentAddress, req);
+                            return -1;
+                        }
+                    }
+                    j = 0;
+                    for (i = 1; i < sL; i++) {
+                        if (req.documentAddress[i] == '/')
+                        {
+                            dirName[j] = '\0';
+                            if (strcmp(dirName, ".."))
+                                depthCount ++;
+                            else
+                                depthCount--;
+                            j = 0;
+                        } else
+                            dirName[j++] = req.documentAddress[i];
+                    }
+                    if (depthCount < 0)
+                    {
+                        sayError(sock, FORBIDDEN, req.documentAddress, req);
+                        return -1;
+                    }
+                }
+                /* now we check if the given file is a directory or a plain file */
+                stat(completeFilePath, &fileStats);
+                if ((fileStats.st_mode & S_IFDIR) == S_IFDIR)
+                {
+                    /* if does not end with a slash, we get an error */
+                    if(completeFilePath[strlen(completeFilePath)-1] != '/')
+                    {
+                        sayError(sock, NOT_FOUND, req.documentAddress, req);
+                        return -1;
+                    }
+                    /* we append the default file name */
+                    strcat(completeFilePath, defaultFileName);
+                }
+                analyzeExtension(mimeType, completeFilePath);
+                if (strncmp(mimeType, "application/x-httpd-php", 23))
+                {
+#endif
+                    /* non cgi POST is not supported */
+                    sayError(sock, UNHANDLED_METHOD, "", req);
+                    return -1;
+#ifdef PHP
+                } else phpHandler(port, sock, phpFileName, completeFilePath, req, buff);
+#endif
+            }
         }
 #endif /* ENABLE_CGI */
 #ifndef ENABLE_CGI
@@ -637,7 +746,7 @@
     f = fopen(configFile, "r");
     if (f == NULL)
     {
-        printf("Error opening config file. Setting defaults.\n");
+        printf("Config file not found. Setting defaults.\n");
         *serverPort = DEFAULT_PORT;
         *maxChildren = DEFAULT_MAX_CHILDREN;
         strcpy(homePath, DEFAULT_DOCS_LOCATION);
@@ -646,7 +755,9 @@
         sockTimeVal.tv_usec = DEFAULT_USEC_TO;
         strcpy(logFileName, DEFAULT_LOG_FILE);
         strcpy(mimeTypesFileName, DEFAULT_MIME_FILE);
+        strcpy(phpFileName, DEFAULT_PHP_FILE);
         strcpy(cgiRoot, DEFAULT_CGI_ROOT);
+        initMimeTypes();
         return -1;
     }
     if (!feof(f)) fscanf(f, "%s %s", str1, str2);
@@ -747,11 +858,25 @@
         if (mimeTypesFileName == NULL)
         {
             strcpy(mimeTypesFileName, DEFAULT_MIME_FILE);
-            printf("Error reading mimeTypesFileName from file, setting default, %s\n", mimeTypesFileName);
+            printf("Error reading mimeTypesFile from file, setting default, %s\n", mimeTypesFileName);
         }
     } else {
         strcpy(mimeTypesFileName, DEFAULT_MIME_FILE);
-        printf("Error reading mimeTypesFileName from file, setting default, %s\n", mimeTypesFileName);
+        printf("Error reading mimeTypesFile from file, setting default, %s\n", mimeTypesFileName);
+    }
+    if (!feof(f)) fscanf(f, "%s %s", str1, str2);
+    if (str1 != NULL && str2 != NULL && !strcmp(str1, "phpFile"))
+    {
+        sscanf(str2, "%s", phpFileName);
+        if (logFileName == NULL)
+        {
+            strcpy(phpFileName, DEFAULT_LOG_FILE);
+            printf("Error reading phpFile from file, setting default, %s\n", phpFileName);
+        }
+    } else
+    {
+        strcpy(phpFileName, DEFAULT_PHP_FILE);
+        printf("Error reading phpFile from file, setting default, %s\n", phpFileName);
     }
     if (!feof(f)) fscanf(f, "%s %s", str1, str2);
     if (str1 != NULL && str2 != NULL && !strcmp(str1, "cgiRoot"))
