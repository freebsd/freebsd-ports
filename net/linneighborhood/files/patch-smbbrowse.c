--- src/smbbrowse.c.orig	Sun Jun  9 09:58:43 2002
+++ src/smbbrowse.c	Thu Apr 10 15:39:19 2003
@@ -716,8 +716,8 @@
   browsedat->browse_state=search_head;
   browsedat->lasttab=0;
   if (*user==0){    
-    strcpy(browsedat->userpasswdstr,"-U%"); 
-    strcpy(browsedat->userdummystr,"-U%"); 
+    strcpy(browsedat->userpasswdstr,"-N"); 
+    strcpy(browsedat->userdummystr,"-N"); 
   }
   else
   {
@@ -829,6 +829,12 @@
      dup2(browsedat->fd[1],STDOUT_FILENO);
      
      cArg[argcount++] = "nmblookup";
+     cArg[argcount++] = "-S";
+     cArg[argcount++] = "-d1";
+     for ( loop = 0; loop < add_argcount; loop++ )
+     {
+       cArg[argcount++] = cAddArg[loop];
+     }
      if ( *wins_name )
      {
        cArg[argcount++] = "-U";
@@ -841,12 +847,6 @@
        cArg[argcount++] = "-M";
        cArg[argcount++] = group_name;
      }
-     cArg[argcount++] = "-S";
-     cArg[argcount++] = "-d1";
-     for ( loop = 0; loop < add_argcount; loop++ )
-     {
-       cArg[argcount++] = cAddArg[loop];
-     }
      cArg[argcount++] = NULL;
            
      execvp(pref_get_nmblookup_exe(), cArg);
@@ -870,15 +870,16 @@
     }
     else
     {
-     if (*wins_name)
-       sprintf(logstr,"GetSMBGroups:%s -U %s -R %s -S -d1",pref_get_nmblookup_exe(),wins_name,group_type);
-     else
-       sprintf(logstr,"GetSMBGroups:%s -M %s -S -d1",pref_get_nmblookup_exe(),group_name);
+     sprintf(logstr,"GetSMBGroups:%s -S -d1",pref_get_nmblookup_exe());
      for ( loop = 0; loop < add_argcount; loop++ )
      {
        string_ncat(logstr, " ", MAXLOGSTRLEN);
        string_ncat(logstr, cAddArg[loop], MAXLOGSTRLEN);
      }
+     if (*wins_name)
+       sprintf(logstr+strlen(logstr)," -U %s -R %s",wins_name,group_type);
+     else
+       sprintf(logstr+strlen(logstr)," -M %s",group_name);
      gui_log_window_insert_string(logstr,1);
      close(browsedat->fd[1]);   
      browsedat->group_master.group_name[MAXGROUPNAMEL]=0;
@@ -1028,7 +1029,7 @@
   }
   browsedat=g_malloc(sizeof(HBROWSE_STRUCT));
   if (*user==0)
-    strcpy(commandstr,"-U%"); 
+    strcpy(commandstr,"-N"); 
   else
     sprintf(commandstr,"-U%s%%%s",user,passwd);
    
@@ -1274,7 +1275,7 @@
   }
   
   if (*user==0)
-    strcpy(commandstr,"-U%"); 
+    strcpy(commandstr,"-N"); 
   else
     sprintf(commandstr,"-U%s%%%s",user,passwd);
   argv[++argnr]="smbclient";
