--- sources/main.c.orig	Sat Dec 20 11:16:21 2003
+++ sources/main.c	Thu Jan  8 12:27:13 2004
@@ -23,6 +23,7 @@
 char defaultFileName[MAX_PATH_LEN+1];
 char logFileName[MAX_PATH_LEN+1];
 char mimeTypesFileName[MAX_PATH_LEN+1];
+char phpFileName[MAX_PATH_LEN+1];
 char cgiRoot[MAX_PATH_LEN+1]; /* root for CGI scripts exec */
 struct timeval sockTimeVal;
 mimeData *mimeArray; /* here we will hold all MIME data, inited once, never to be changed */
@@ -316,10 +317,13 @@
         reqStruct->keepAlive = YES;
     else if (!strncmp(reqArray[1], "Connection: Keep-Alive", strlen("Connection: keep-alive")))
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
@@ -327,14 +331,28 @@
             strncpy(reqStruct->userAgent, &reqArray[i][strlen("User-Agent: ")], USER_AGENT_LEN - 1);
             reqStruct->userAgent[USER_AGENT_LEN] = '\0';
         }
-	else if (!strncmp(reqArray[i], "Content-Length:", strlen("Content-length:")) || !strncmp(reqArray[i], "Content-length:", strlen("Content-length:")))
-    	{
-	    strcpy(token, &reqArray[i][strlen("Content-length: ")]);
-	    sscanf(token, "%ld", &(reqStruct->contentLength));
+        else if (!strncmp(reqArray[i], "Content-Length:", strlen("Content-length:")) || !strncmp(reqArray[i], "Content-length:", strlen("Content-length:")))
+        {
+            strcpy(token, &reqArray[i][strlen("Content-length: ")]);
+            sscanf(token, "%ld", &(reqStruct->contentLength));
+#ifdef PRINTF_DEBUG
+            printf("content length %ld\n", reqStruct->contentLength);
+#endif
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
 #ifdef PRINTF_DEBUG
-	    printf("content length %ld\n", reqStruct->contentLength);
+            printf("cookie %s\n", reqStruct->cookie);
 #endif
-	}
+        }
         i++;
     }
     /* if we didn't find a User-Agent we fill in a (N)ot(R)ecognized */
@@ -431,18 +449,39 @@
                     /* we append the default file name */
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
@@ -511,7 +550,14 @@
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
@@ -525,13 +571,6 @@
         int readFinished;
         
         printf("Handling of POST method\n");
-        /* first we check if the path contains the directory selected for cgi's and in case handle it */
-        if (strncmp(req.documentAddress, CGI_MATCH_STRING, strlen(CGI_MATCH_STRING)))
-        {
-            /* non cgi POST is not supported */
-            sayError(sock, UNHANDLED_METHOD, "", req);
-            return -1;
-        }
 #ifdef PRINTF_DEBUG
         printf ("begin of post handling\n");
 
@@ -625,7 +664,77 @@
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
     } else
     {
@@ -654,7 +763,7 @@
     f = fopen(configFile, "r");
     if (f == NULL)
     {
-        printf("Error opening config file. Setting defaults.\n");
+        printf("Config file not found. Setting defaults.\n");
         *serverPort = DEFAULT_PORT;
         *maxChildren = DEFAULT_MAX_CHILDREN;
         strcpy(homePath, DEFAULT_DOCS_LOCATION);
@@ -663,7 +772,9 @@
         sockTimeVal.tv_usec = DEFAULT_USEC_TO;
         strcpy(logFileName, DEFAULT_LOG_FILE);
         strcpy(mimeTypesFileName, DEFAULT_MIME_FILE);
+        strcpy(phpFileName, DEFAULT_PHP_FILE);
         strcpy(cgiRoot, DEFAULT_CGI_ROOT);
+        initMimeTypes();
         return -1;
     }
     if (!feof(f)) fscanf(f, "%s %s", str1, str2);
@@ -764,11 +875,25 @@
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
