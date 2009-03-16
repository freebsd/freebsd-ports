Honor lots of limits - convert sprintf() to snprintf(), use the correct
limit size, etc.
Check a couple more calls for errors.
Wait for the correct child process - waitpid() instead of wait().
Add two closedir()'s to fix file descriptor leaks.
Look for the arguments properly if progname should ever containing spaces.

--- a/vlistlib.c
+++ b/vlistlib.c
@@ -193,26 +193,26 @@
 
     if( DomainOnly ) {    //   Have domain
         if ( strstr( Address, "@") != NULL ) return(4);
-        snprintf( LI->Name,   MAX_FILE_NAME, "%s", "" );
-        snprintf( LI->Domain, MAX_FILE_NAME, "%s", Address );
+        snprintf( LI->Name,   sizeof(LI->Name), "%s", "" );
+        snprintf( LI->Domain, sizeof(LI->Domain), "%s", Address );
     }
 
     else {                //   Have mail list
         if ( strstr( Address, "@") == NULL ) return(1);
-        if ( parse_email( Address, LI->Name, LI->Domain, MAX_BUFF) != 0 )  return(2);
+        if ( parse_email( Address, LI->Name, LI->Domain, sizeof(LI->Domain)) != 0 )  return(2);
     }
 
 //    printf( "before GetDomainEntries\n" );
 
     if(( LI->entry = get_domain_entries( LI->Domain )) == NULL ) return(3);
 
-    snprintf( LI->OwnerEmail,   MAX_FILE_NAME, "postmaster@%s", LI->Domain ); 
-    snprintf( LI->ReplyTo_Addr, MAX_FILE_NAME, "%s", "" );
-    snprintf( LI->SQLBase,      MAX_FILE_NAME, "ezmlm" );
-    snprintf( LI->SQLHost,      MAX_FILE_NAME, "localhost" );
-    snprintf( LI->SQLPass,      MAX_FILE_NAME, "dbpass" );
-    snprintf( LI->SQLTable,     MAX_FILE_NAME, "ezmlm" );
-    snprintf( LI->SQLUser,      MAX_FILE_NAME, "dbUser" );
+    snprintf( LI->OwnerEmail,   sizeof(LI->OwnerEmail), "postmaster@%s", LI->Domain ); 
+    snprintf( LI->ReplyTo_Addr, sizeof(LI->ReplyTo_Addr), "%s", "" );
+    snprintf( LI->SQLBase,      sizeof(LI->SQLBase), "ezmlm" );
+    snprintf( LI->SQLHost,      sizeof(LI->SQLHost), "localhost" );
+    snprintf( LI->SQLPass,      sizeof(LI->SQLPass), "dbpass" );
+    snprintf( LI->SQLTable,     sizeof(LI->SQLTable), "ezmlm" );
+    snprintf( LI->SQLUser,      sizeof(LI->SQLUser), "dbUser" );
 
 //    printf( "before make name\n" );
 
@@ -228,12 +228,12 @@
 //    printf( "before Dir\n" );
 
     //   Build Dir Parm
-    sprintf( LI->Dir, "%s/%s", LI->entry->path, QmailName );
+    snprintf( LI->Dir, sizeof(LI->Dir), "%s/%s", LI->entry->path, QmailName );
 
 //    printf( "before Dot\n" );
 
     //   Build Dot Parm
-    sprintf( LI->Dot, "%s/.qmail-%s", LI->entry->path, QmailName );
+    snprintf( LI->Dot, sizeof(LI->Dot), "%s/.qmail-%s", LI->entry->path, QmailName );
 
     LI->ReplyTo = REPLYTO_SENDER;
 
@@ -278,21 +278,18 @@
     char *end;
     char *arg;
 
-
 //    printf( "\nget_ezmlmidz_line_arguments\nline: %sprogram: %s\nargument: %c\n", line, program, argument );
 
     // does line contain program name?
-    if ((strstr(line, program)) != NULL) {
-        // find the options
-        begin=strchr(line, ' ');
-        begin++;
-        if (*begin == '-') {
-            end=strchr(begin, ' ');
-            arg=strchr(begin, argument);
-            // if arg is found && it's in the options (before the trailing space), return 1
-            if (arg && (arg < end)) return 1;
-        }       
-    }       
+    begin = strstr(line, program);
+    if (begin == NULL)
+	return (0);
+    begin=strchr(begin, ' ');
+    if (begin == NULL || begin[1] != '-')
+	return (0);
+    end=strchr(begin + 2, ' ');
+    arg=strchr(begin + 2, argument);
+    if (arg != NULL && (end == NULL || arg < end)) return 1;
     return 0;
 }
 
@@ -431,7 +428,6 @@
     int  BlockArchive = 0;
     int  GuardArchive = 0;
     char TmpBuf2[MAX_BUFF];
-    int  i;
 
 
     /*
@@ -442,7 +438,7 @@
     LI->Requests = LI->RemoteText = LI->RemoteSub = LI->UnsubConf = LI->SubConf = GuardArchive = 0;
 
     // figure out some options in the -default file
-    sprintf(TmpBuf, "%s-default", LI->Dot);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s-default", LI->Dot);
 
     if( (fs=fopen(TmpBuf, "r")) !=NULL ) {
         while(fgets(TmpBuf2, sizeof(TmpBuf2), fs)) {
@@ -461,7 +457,7 @@
     LI->Indexed = OtherReject = UserPostOnly = LI->Indexed = 0;
 
     // figure out some options in the -accept-default file
-    sprintf(TmpBuf, "%s-accept-default", LI->Dot );
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s-accept-default", LI->Dot );
     if( (fs=fopen(TmpBuf, "r")) !=NULL ) {
         while(fgets(TmpBuf2, sizeof(TmpBuf2), fs)) {
             if(strstr(TmpBuf2, "ezmlm-archive") !=0) LI->Indexed = 1;
@@ -470,7 +466,7 @@
     }   //  if fopen
 
     // figure out some options in the qmail file
-    sprintf(TmpBuf, "%s", LI->Dot);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s", LI->Dot);
     if( (fs=fopen(TmpBuf, "r")) !=NULL ) {
         while(fgets(TmpBuf2, sizeof(TmpBuf2), fs)) {
             if((ezmlm_getArgs(TmpBuf2, "ezmlm-store", 'P')) > 0) OtherReject = 1;
@@ -482,7 +478,7 @@
 
 
     // figure out some options in the sql file
-    sprintf(TmpBuf, "%s/sql", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/sql", LI->Dir);
     if( file_exists( TmpBuf )) {
         LI->SQLSupport = 1;
         if( (fs=fopen(TmpBuf, "r")) !=NULL ) {
@@ -490,8 +486,7 @@
                 Tmp = strtok( TmpBuf2, ":" );
                 printf( "    First Token: %s Len: %d\n", Tmp, strlen( Tmp ));
                 if( NULL != Tmp ) { 
-                   for(i=0; i<strlen(Tmp); i++) LI->SQLHost[i] = Tmp[i];
-                   LI->SQLHost[i] = (char) 0;
+		   snprintf(LI->SQLHost, sizeof(LI->SQLHost), "%s", Tmp);
                    Tmp = strtok( NULL, ":" );
                 }
                 if( NULL != Tmp ) { 
@@ -499,23 +494,19 @@
                    Tmp = strtok( NULL, ":" );
                 }
                 if( NULL != Tmp ) { 
-                   for(i=0; i<strlen(Tmp); i++) LI->SQLUser[i] = Tmp[i];
-                   LI->SQLUser[i] = (char) 0;
+		   snprintf(LI->SQLUser, sizeof(LI->SQLUser), "%s", Tmp);
                    Tmp = strtok( NULL, ":" );
                 }
                 if( NULL != Tmp ) { 
-                   for(i=0; i<strlen(Tmp); i++) LI->SQLPass[i] = Tmp[i];
-                   LI->SQLPass[i] = (char) 0;
+		   snprintf(LI->SQLPass, sizeof(LI->SQLPass), "%s", Tmp);
                    Tmp = strtok( NULL, ":" );
                 }
                 if( NULL != Tmp ) { 
-                   for(i=0; i<strlen(Tmp); i++) LI->SQLBase[i] = Tmp[i];
-                   LI->SQLBase[i] = (char) 0;
+		   snprintf(LI->SQLBase, sizeof(LI->SQLBase), "%s", Tmp);
                    Tmp = strtok( NULL, ":\n" );
                 }
                 if( NULL != Tmp ) { 
-                   for(i=0; i<strlen(Tmp); i++) LI->SQLTable[i] = Tmp[i];
-                   LI->SQLTable[i] = (char) 0;
+		   snprintf(LI->SQLTable, sizeof(LI->SQLTable), "%s", Tmp);
                 }
 
             }
@@ -526,32 +517,32 @@
 
 
     //  figure out a number of options based on file_exists()
-    sprintf(TmpBuf, "%s-accept-default", LI->Dot);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s-accept-default", LI->Dot);
     Moderation = file_exists(TmpBuf);
 
-    sprintf(TmpBuf, "%s/archived", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/archived", LI->Dir);
     LI->Archive = file_exists(TmpBuf);
   
-    sprintf(TmpBuf, "%s/digest/bouncer", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/digest/bouncer", LI->Dir);
     LI->Digest = file_exists(TmpBuf);
   
-    sprintf(TmpBuf, "%s/prefix", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/prefix", LI->Dir);
     LI->Prefix = file_exists(TmpBuf);
 
-    sprintf(TmpBuf, "%s/public", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/public", LI->Dir);
     LI->Public = file_exists(TmpBuf);
   
-    sprintf(TmpBuf, "%s/remote", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/remote", LI->Dir);
     LI->Remote = file_exists(TmpBuf);
   
-    sprintf(TmpBuf, "%s/modsub", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/modsub", LI->Dir);
     LI->SubMod = file_exists(TmpBuf);
   
-    sprintf(TmpBuf, "%s/text/trailer", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/text/trailer", LI->Dir);
     LI->Trailer = file_exists(TmpBuf);
 
    if( LI->Prefix ) {  //  get prefix value
-      sprintf( TmpBuf, "%s/prefix", LI->Dir );
+      snprintf( TmpBuf, sizeof(TmpBuf), "%s/prefix", LI->Dir );
       fs=fopen( TmpBuf , "r" );
       if( fs ) {
          fgets( LI->PrefixText, sizeof(LI->PrefixText), fs );
@@ -562,7 +553,7 @@
 
     // analyze Reply-To
     LI->ReplyTo = REPLYTO_SENDER;
-    sprintf(TmpBuf, "%s/headeradd", LI->Dir);
+    snprintf(TmpBuf, sizeof(TmpBuf), "%s/headeradd", LI->Dir);
     if( (fs=fopen(TmpBuf, "r")) !=NULL ) {
         while(fgets(TmpBuf2, sizeof(TmpBuf2), fs)) {
             if(strstr(TmpBuf2, "Reply-To:") !=0)  {
@@ -571,10 +562,8 @@
                 } else {
                     LI->ReplyTo = REPLYTO_ADDRESS;
                     //  Copy just email address
-                    for( i=0; i<(strlen(TmpBuf2)-11); i++){
-                        LI->ReplyTo_Addr[i] = TmpBuf2[i+10];
-                    }
-                    LI->ReplyTo_Addr[i] = (char) 0;
+		    snprintf(LI->ReplyTo_Addr, sizeof(LI->ReplyTo_Addr), "%s",
+		        TmpBuf2 + 10);
                 }
             }
         }   //  while fgets
@@ -693,7 +682,7 @@
 int ezmlm_make ( listInfoType *LI )
 {
 //    FILE *file;
-    int pid;
+    int pid, stat;
 //    int I;
 //    char TmpBuf[MAX_BUFF];
     char ProgramPath[MAX_BUFF];
@@ -713,13 +702,13 @@
 
     //   Program path and name
     snprintf(ProgramPath, MAX_BUFF, "%s/ezmlm-make", EZMLMDIR);
-    snprintf( OwnerEmail, MAX_BUFF, "-5 %s", LI->OwnerEmail );
 
     //  Start with owner email
     snprintf( OwnerEmail, MAX_BUFF, "-5 %s", LI->OwnerEmail );
 
     //  Get the list options in EZMLM terms
-    ezmlm_encode( LI, Options, MAX_OPTIONS );
+    if (ezmlm_encode( LI, Options, MAX_OPTIONS ) != 0)
+	return (-1);
 
     //  If SQL selected, setup all the sql data into a single subfield
     if( LI->SQLSupport ) {
@@ -750,7 +739,9 @@
         execv(ProgramPath, arguments);
         exit(127);
     } else {
-        wait(&pid);
+        if (waitpid(pid, &stat, 0) < 0 ||
+	    !WIFEXITED( stat ) || WEXITSTATUS( stat ) != 0 )
+	    return (-1);
     }
 
     return( 0 );
@@ -818,8 +809,8 @@
 
     pipe(handles);
 
-    sprintf(ProgramPath, "%s/ezmlm-list", EZMLMDIR );
-    status = ezmlm_path( LI, mode, MAX_BUFF, ListPath );
+    snprintf(ProgramPath, sizeof(ProgramPath), "%s/ezmlm-list", EZMLMDIR );
+    status = ezmlm_path( LI, mode, sizeof(ListPath), ListPath );
     if( status < 0 ) return( status );
    
     pid=fork();
@@ -841,7 +832,9 @@
     }
 
     fclose(fs); close(handles[0]);
-    wait(&pid);
+    if (waitpid(pid, &status, 0) < 0 ||
+        !WIFEXITED(status) || WEXITSTATUS(status) != 0)
+	return (-1);
 
 //    printf( "after load of data\n" );
 
@@ -861,7 +854,7 @@
 char **listSubsList( listInfoType *LI, int mode, int page, int perPage ) {
   
     FILE *fs;
-    int handles[2],pid,z = 0,subuser_count = 0; 
+    int handles[2],pid,status,z = 0,subuser_count = 0; 
     char ProgramPath[MAX_BUFF];
     char ListPath[MAX_BUFF];
     char buf[256];
@@ -871,8 +864,8 @@
 
     pipe(handles);
 
-    sprintf(ProgramPath, "%s/ezmlm-list", EZMLMDIR);
-    ezmlm_path( LI, mode, MAX_BUFF, ListPath );
+    snprintf(ProgramPath, sizeof(ProgramPath), "%s/ezmlm-list", EZMLMDIR);
+    ezmlm_path( LI, mode, sizeof(ListPath), ListPath );
 
     pid=fork();
     if (pid==0) {
@@ -887,9 +880,11 @@
 
         /* Load subscriber/moderator list */
 
-        sort_init();
+        if (sort_init() != 0)
+	    return (NULL);
         while( (fgets(buf, sizeof(buf), fs)!= NULL)) {
-            sort_add_entry (buf, '\n');   /* don't copy newline */
+            if (sort_add_entry (buf, '\n') != 0)  /* don't copy newline */
+		return (NULL);
             subuser_count++;
         }
 
@@ -903,7 +898,9 @@
     sort_cleanup();
 
     fclose(fs); close(handles[0]);
-    wait(&pid);
+    if (waitpid(pid, &status, 0) < 0 ||
+        !WIFEXITED(status) || WEXITSTATUS(status) != 0)
+	return (NULL);
 
 return( 0 );
 }
@@ -919,12 +916,12 @@
   */
 
 int listSubsAdd( listInfoType *LI, int mode, char *email ){
-    int pid;
+    int pid, status;
     char ProgramPath[MAX_BUFF];
     char ListPath[MAX_BUFF];
 
-    sprintf(ProgramPath, "%s/ezmlm-sub", EZMLMDIR);
-    ezmlm_path( LI, mode, MAX_BUFF, ListPath );
+    snprintf(ProgramPath, sizeof(ProgramPath), "%s/ezmlm-sub", EZMLMDIR);
+    ezmlm_path( LI, mode, sizeof(ListPath), ListPath );
 //    printf( "  subscriberListPath %d  %s\n", mode, ListPath );
 //    printf( "about to exec %s with parms %s\n", ProgramPath, ListPath );
 
@@ -932,10 +929,10 @@
     if (pid==0) {
         execl(ProgramPath, "ezmlm-sub", ListPath, email, NULL);
         exit(127);
-    } else wait(&pid);
-
-    /* need to check exit code for failure somehow */
-
+    }
+    if (waitpid(pid, &status, 0) < 0 ||
+        !WIFEXITED(status) || WEXITSTATUS(status) != 0)
+	return (-1);
     return(0);
 }
 
@@ -948,12 +945,12 @@
   */
 
 int listSubsDel( listInfoType *LI, int mode, char *email ){
-    int pid;
+    int pid, status;
     char ProgramPath[MAX_BUFF];
     char ListPath[MAX_BUFF];
 
-    sprintf(ProgramPath, "%s/ezmlm-unsub", EZMLMDIR);
-    ezmlm_path( LI, mode, MAX_BUFF, ListPath );
+    snprintf(ProgramPath, sizeof(ProgramPath), "%s/ezmlm-unsub", EZMLMDIR);
+    ezmlm_path( LI, mode, sizeof(ListPath), ListPath );
 //    printf( "  subscriberListPath %d  %s  %s\n", mode, ListPath, TmpBuf );
 //    printf( "about to exec %s with parms %s\n", ProgramPath, ListPath );
 
@@ -961,10 +958,10 @@
     if (pid==0) {
         execl(ProgramPath, "ezmlm-unsub", ListPath, email, NULL);
         exit(127);
-    } else wait(&pid);
-
-    /* need to check exit code for failure somehow */
-
+    }
+    if (waitpid(pid, &status, 0) < 0 ||
+        !WIFEXITED(status) || WEXITSTATUS(status) != 0)
+	return (-1);
     return(0);
 }
 
@@ -1031,7 +1028,8 @@
         return( NULL );
     }
 
-    sort_init();
+    if (sort_init() != 0)
+	return (NULL);
 
     /* Now, display each list */
     while( (mydirent=readdir(mydir)) != NULL ) {
@@ -1045,8 +1043,10 @@
             fgets(TmpBuf2, sizeof(TmpBuf2), fs);
             fclose(fs);
 
-            if ( strstr( TmpBuf2, "ezmlm-reject") != 0 ) {
-               sort_add_entry (&mydirent->d_name[7], 0);
+            if ( strstr( TmpBuf2, "ezmlm-reject") != 0 ||
+                strstr( TmpBuf2, "ezmlm-send") != 0 ) {
+               if (sort_add_entry (&mydirent->d_name[7], 0) != 0)
+		   return (NULL);
             }
         }
     }
@@ -1058,6 +1058,8 @@
     buffSize = perPage * sizeof( *Buff );
 
     Buff = malloc( perPage * sizeof( *Buff ));
+    if (Buff == NULL)
+	return (NULL);
 
     for ( i = 0; i<perPage; ++i) {
         J = (( page - 1 ) * perPage ) + i;
@@ -1066,16 +1068,15 @@
             break;
         }
         
-        fflush( stdout );
-
         addr = (char *)sort_get_entry(J);
         str_replace (addr, ':', '.');
         buffSize = strlen( addr ) + 1;
 
         if( ( Buff[i] = malloc( buffSize ))) {
-            fflush( stdout );
             strncpy( Buff[i], addr, buffSize );
-        }
+        } else {
+	    return (NULL);
+	}
     }
 
     sort_cleanup();
@@ -1129,14 +1130,15 @@
         return(7);
     }
  
-    sprintf( MainName,   ".qmail-%s",  LI->Dot );
-    sprintf( SecondName, ".qmail-%s-", LI->Dot );
+    snprintf( MainName, sizeof(MainName), ".qmail-%s",  LI->Dot );
+    snprintf( SecondName, sizeof(SecondName), ".qmail-%s-", LI->Dot );
     while( (mydirent=readdir(mydir)) != NULL ) {
 
         /* delete the main .qmail-"list" file */
         if ( strcmp(MainName, mydirent->d_name) == 0 ) {
             snprintf( TargetName, MAX_FILE_NAME, "%s/%s", LI->entry->path, mydirent->d_name);
             if ( unlink(TargetName) != 0 ) {
+		closedir(mydir);
                 return(9);
             }
 
@@ -1144,13 +1146,14 @@
         } else if ( strncmp(SecondName, mydirent->d_name, strlen(SecondName)) == 0 ) {
             snprintf( TargetName, MAX_FILE_NAME, "%s/%s", LI->entry->path, mydirent->d_name);
             if ( unlink(TargetName) != 0 ) {
+		closedir(mydir);
                 return(10);
             }
         }
     }
     closedir(mydir);
 
-    sprintf(TargetName, "%s/%s", LI->entry->path, LI->Name);
+    snprintf(TargetName, sizeof(TargetName), "%s/%s", LI->entry->path, LI->Name);
     vdelfiles(TargetName);
 
     return(0);
