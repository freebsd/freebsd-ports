--- main.c.orig	Mon Sep 22 10:39:24 2003
+++ main.c	Thu Oct 16 14:00:02 2003
@@ -23,6 +23,7 @@
 char defaultFileName[MAX_PATH_LEN+1];
 char logFileName[MAX_PATH_LEN+1];
 char mimeTypesFileName[MAX_PATH_LEN+1];
+char phpFileName[MAX_PATH_LEN+1];
 char cgiRoot[MAX_PATH_LEN+1]; /* root for CGI scripts exec */
 struct timeval sockTimeVal;
 mimeData *mimeArray; /* here we will hold all MIME data, inited once, never to be changed */
@@ -206,10 +207,10 @@
     int reqSize;
     int readLines;
     int tokenEnd;
-   
-    /* we copy the header lines to an array for easier parsing */ 
+
+    /* we copy the header lines to an array for easier parsing */
     /* but first we make sure that our string has a newline and an end */
-    req[BUFFER_SIZE] = '\0';    
+    req[BUFFER_SIZE] = '\0';
     reqSize = strlen(req);
     req[reqSize] = '\n';
     reqSize++;
@@ -230,7 +231,7 @@
     for (k = 0; k < readLines; k++)
         printf("%d - |%s|\n", k, reqArray[k]);
 #endif
-    
+
     /* first line: method, path and protocol version */
     /* we copy to a temporary buffer to be more secure against overflows */
     i = j = 0;
@@ -246,7 +247,7 @@
     else
         tokenEnd = NO;
     i++;
-    
+
     /* we look for the document address */
     j = 0;
     reqStruct->documentAddress[0] = '\0';
@@ -259,14 +260,14 @@
         else
             token[j] = '\0';      /* to make sure we have a string */
         /* now we need to convert some escapings from the path like %20 */
-	convertPercents(token, j);
+        convertPercents(token, j);
         strcpy(reqStruct->documentAddress, token);  /* copy back */
         if (reqArray[0][i] == '\0')
             tokenEnd = YES;
         else
             tokenEnd = NO;
         i++;
-    
+
         /* we need now to separate path from query string ("?" separated) */
         if (reqArray[0][i-1] == '?')
         {
@@ -282,7 +283,7 @@
             i++;
         }
     }
-    
+
     /* we analyze the HTTP protocol version */
     /* default is 0.9 since that version didn't report itself */
     strcpy(reqStruct->protocolVersion, "HTTP/0.9");
@@ -306,10 +307,13 @@
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
@@ -317,14 +321,28 @@
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
 #ifdef PRINTF_DEBUG
-	    printf("content length %ld\n", reqStruct->contentLength);
+            printf("content length %ld\n", reqStruct->contentLength);
 #endif
-	}
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
+        }
         i++;
     }
     /* if we didn't find a User-Aget we fill in a (N)ot(R)ecognized */
@@ -414,18 +432,39 @@
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
@@ -494,7 +533,14 @@
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
@@ -507,13 +553,6 @@
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
 
@@ -523,9 +562,15 @@
         totalRead = 0;
         stuckCounter = 0;
         timeOutCounter = 0;
-        while (!readFinished)
-        {
-            howMany = recv(newSocket, tempBuff, BUFFER_SIZE, 0);
+
+        /* SECURITY: Avoid malicious Content-Length -- check \r\n\r\n\0 also */
+        if (req.contentLength < 0 || req.contentLength >= BUFFER_SIZE-5) {
+                sayError(sock, 500, "", req);
+                return -1;
+        }
+
+        /* SECURITY: Remove loop to prevent buffer overflow */
+            howMany = recv(newSocket, tempBuff, req.contentLength+5, 0);
 	    tempBuff[howMany] = '\0'; /* seems that some Unices need this */
 #ifdef PRINTF_DEBUG
         printf ("read: %d\n%s\n", howMany, tempBuff);
@@ -579,16 +624,15 @@
 	    	if (howMany == req.contentLength)
 		    readFinished = YES;
             }
-    }
 #ifdef PRINTF_DEBUG
-    printf("total read %d\n", totalRead);
+        printf("total read %d\n", totalRead);
 #endif
-    if (totalRead == 0)
-    {
-        printf("Request read error\n");
-    } else
-    {
-        if (buff[totalRead - 1] != '\n') /* we need a trailing \n or the script will wait forever */
+        if (totalRead == 0)
+        {
+            printf("Request read error\n");
+        } else
+        {
+            if (buff[totalRead - 1] != '\n') /* we need a trailing \n or the script will wait forever */
             {
                 buff[totalRead++] = '\n';
                 buff[totalRead] = '\0';
@@ -596,7 +640,77 @@
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
@@ -625,7 +739,7 @@
     f = fopen(configFile, "r");
     if (f == NULL)
     {
-        printf("Error opening config file. Setting defaults.\n");
+        printf("Config file not found. Setting defaults.\n");
         *serverPort = DEFAULT_PORT;
         *maxChildren = DEFAULT_MAX_CHILDREN;
         strcpy(homePath, DEFAULT_DOCS_LOCATION);
@@ -634,7 +748,9 @@
         sockTimeVal.tv_usec = DEFAULT_USEC_TO;
         strcpy(logFileName, DEFAULT_LOG_FILE);
         strcpy(mimeTypesFileName, DEFAULT_MIME_FILE);
+        strcpy(phpFileName, DEFAULT_PHP_FILE);
         strcpy(cgiRoot, DEFAULT_CGI_ROOT);
+        initMimeTypes();
         return -1;
     }
     if (!feof(f)) fscanf(f, "%s %s", str1, str2);
@@ -735,11 +851,25 @@
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
@@ -775,6 +905,7 @@
     int readFinished;
     struct request gottenReq;
     int isKeepAlive;
+    int bool;
     struct sockaddr_in listenName;           /* data struct for the listen port */
     struct sockaddr_in acceptedSockStruct;   /* sockaddr for the internetworking */
     int acceptedSocketLen;                   /* size of the structure */
@@ -808,9 +939,16 @@
         printf("socket creation error occoured\n");
         return -1;
     }
+    bool = 1;
+    error = setsockopt (theSocket, SOL_SOCKET, SO_REUSEADDR, &bool, sizeof(bool));
+    if (error == -1)
+    {   if (errno == EADDRINUSE)
+        printf("set socket option error occoured\n");
+        return -1;
+    }
     error = bind (theSocket, (struct sockaddr*)  &listenName, sizeof(listenName));
     if (error == -1)
-    {
+    {   if (errno == EADDRINUSE)
         printf("socket binding error occoured\n");
         return -2;
     }
