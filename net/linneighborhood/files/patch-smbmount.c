--- src/smbmount.c.orig	Sun Jun  9 09:58:43 2002
+++ src/smbmount.c	Fri Apr 11 16:55:26 2003
@@ -16,6 +16,9 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/param.h>
+#include <errno.h>
+#include <poll.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -70,6 +73,9 @@
 } UMOUNT_STRUCT;
 static GSList *umountlist = NULL;
 
+void split_arguments(char * arguments, char * argv[], int * argnr, GSList ** strlist);
+char * storeInBuffer(const char * s, GSList ** strlist);
+void execvp_with_password(const char * path, char * const argv[], const char * passwd, GSList * strlist);
 
 char suprompt[] = "Passw";
 
@@ -322,6 +328,7 @@
  int  pipe2_nok,pipe3_nok=1;
  int  sumount,argnr=-1,passw_lf;
  char commandstr[MAXMNTCOMMANDL],commandstr1[MAXMNTCOMMANDL];
+ char num1[10], num2[10], num3[10], num4[10], tmp[MAXMNTCOMMANDL];
  char opt_group[MAXMNTCOMMANDL];
  char dummysmbpasswd[64];
 /*#ifdef LINUX2_0 */
@@ -345,6 +352,7 @@
  sumount=(supasswd!=NULL); 
  passw_lf=(*smbpasswd==0) && !linux2_0; /*smbmount 2.0.3 always waits for password, 
                                     even if called with -Uuser% or -N if server is in user level security*/
+ passw_lf=1;
  if (sumount|| passw_lf)
   if (pipe(fdstdin))
    {
@@ -418,96 +426,53 @@
   else
   {
     /* no sumount */
-    if(linux2_0)
     {
-      argv[++argnr]="smbmount";
-      argv[++argnr]=servicename;
-      argv[++argnr]=mount_point;
-      argv[++argnr]="-c";
-      argv[++argnr]=clientname;
-      argv[++argnr]="-I";
-      argv[++argnr]=ipaddr;
-      if (*group_name)
+      // bugfix: mount command might consist of more than one word (example: sudo mount_smbfs)
+      split_arguments(pref_get_smbmount_exe(), argv, &argnr, &strlist);
       {
-        argv[++argnr]="-D";
-        argv[++argnr]=group_name;
-      }
-      argv[++argnr]="-U";
-      argv[++argnr]=smbuser;
-      argv[++argnr]="-f";sprintf(filemodestr,"%d",filemode);
-      argv[++argnr]=filemodestr;
-      argv[++argnr]="-d";sprintf(dirmodestr,"%d",dirmode);
-      argv[++argnr]=dirmodestr;
-      argv[++argnr]="-u";sprintf(uidstr,"%d",uid);
-      argv[++argnr]=uidstr;
-      argv[++argnr]="-g";sprintf(gidstr,"%d",gid);
-      argv[++argnr]=gidstr;
-      if (*smbpasswd==0)
-        argv[++argnr]="-n";
-      else
-      {
-        argv[++argnr]="-P";
-        argv[++argnr]=smbpasswd;
-      }
-      argv[++argnr]=NULL;
-    }
-    else
-    {
-      /* linux 2.2/2.4 */
-      argv[++argnr]=pref_get_smbmount_exe();
-      argv[++argnr]=servicename;
-      if (pref.v.smbmount_version>SMBMOUNT_204) argv[++argnr]=mount_point;
-      if (pref.v.smbmount_version<SMBMOUNT_206)
-      {
-        /* 2.04/2.05 */
+        sprintf(num1,"%d", filemode);
+        sprintf(num2,"%d", dirmode);
+        sprintf(num3,"%d", uid);
+        sprintf(num4,"%d", gid);
+        strcpy(commandstr1, "//");
+        if (strlen(smbuser))
+        {
+          strcat(commandstr1, smbuser);
+          strcat(commandstr1, "@");
+        }
+        if (strlen(servicename) > 2)
+          strcat(commandstr1, servicename+2);
+        argv[++argnr]="-f";
+        argv[++argnr]=num1;
+        argv[++argnr]="-d";
+        argv[++argnr]=num2;
+        argv[++argnr]="-u";
+        argv[++argnr]=num3;
+        argv[++argnr]="-g";
+        argv[++argnr]=num4;
         argv[++argnr]="-I";
-        argv[++argnr]=ipaddr;
+        strcpy(tmp, ipaddr);
+        argv[++argnr]=tmp;
         if (*group_name)
         {
           argv[++argnr]="-W";
-          argv[++argnr]=group_name;
-        }
-        sprintf(userpasswd,"-U%s%%%s",smbuser,smbpasswd);
-        argv[++argnr]=userpasswd;
-        argv[++argnr]="-d0";
-        if (pref.v.smbmount_version <SMBMOUNT_205)
-        {
-         argv[++argnr]="-c";
-         argv[++argnr]=commandstr;
-         sprintf(commandstr,"mount %s -f %d -d %d -u %d -g %d",
-                /*escape_str_smbmnt(*/mount_point/*,&strlist)*/,filemode,dirmode,uid,gid);
-        }
-        if ( !is_empty_string(pref.v.smbmount_arg) )
-        {
-        }
-      }
-      else /*>=SMBMOUNT_206*/
-      {
-        argv[++argnr]="-o";
-        argv[++argnr]=commandstr;
-        sprintf(commandstr,"username=%s%%%s,fmask=%d,dmask=%d,uid=%d,gid=%d,ip=%s,debug=0",
-           smbuser,smbpasswd,filemode,dirmode,uid,gid,ipaddr);
-        if (*group_name)
-        {
-          strcat(commandstr,",workgroup=");
-          strcat(commandstr,escape_str(group_name,&strlist));
+          argv[++argnr]= escape_str(group_name,&strlist);
         }
         if ( (port >= 0) && (port < 65536) )
         {
-          string_ncat(commandstr, ",port=", MAXMNTCOMMANDL);
-          string_ncat(commandstr, port_str, MAXMNTCOMMANDL);
+          strcat(tmp, ":");
+          strcat(tmp, port_str);
         }
         if ( !is_empty_string(pref.v.smbmount_arg) )
         {
-          if ( pref.v.smbmount_arg[0] != ',' )
-           string_ncat(commandstr, ",", MAXMNTCOMMANDL);
-          string_ncat(commandstr, escape_str(pref.v.smbmount_arg,&strlist), MAXMNTCOMMANDL);
+          split_arguments(pref.v.smbmount_arg, argv, &argnr, &strlist);
         }
        }
+       argv[++argnr]=commandstr1;
+       argv[++argnr]=mount_point;
        argv[++argnr]=NULL;
       }
   }
-  slist_free_with_data(&strlist);
   mountdat=g_malloc(sizeof(MOUNT_STRUCT));
   if((pipe2_nok=pipe(fdstdout))|| (pipe3_nok=pipe(fdstderr))||
         (mountdat->childpid =fork())== -1)   
@@ -521,7 +486,6 @@
     g_print(_("smbmount pipe,fork error\n"));
     return;
   } 
-  
   if (!mountdat->childpid)
   {
    close(fdstdout[0]);   
@@ -536,7 +500,7 @@
    if (sumount)
      execvp("su",argv);
    else
-     execvp(pref_get_smbmount_exe(),argv);
+     execvp_with_password(argv[0], argv, smbpasswd, strlist);
    write(STDERR_FILENO,notfound,sizeof(notfound)-1); 
    _exit(0);
   }
@@ -547,9 +511,9 @@
   else
   {
     i=0;
-    while(argv[i+1]) 
+    while(argv[i]) 
     {
-      mountdat->arglist[i]=g_strdup(argv[i+1]);
+      mountdat->arglist[i]=g_strdup(argv[i]);
       i++;
     }
     mountdat->arglist[i]=NULL;
@@ -611,46 +575,9 @@
   } 
   else
   {
-    if(linux2_0)
-    {
-      if (*smbpasswd!=0) argv[argnr-1]=dummysmbpasswd;
-    }
-    else
-    { 
-      if (pref.v.smbmount_version<SMBMOUNT_206)
-        sprintf(userpasswd,"-U%s%%%s",smbuser,dummysmbpasswd);
-      else
-      {
-       sprintf(commandstr,"username=%s%%%s,fmask=%d,dmask=%d,uid=%d,gid=%d,ip=%s,debug=0",
-          smbuser,dummysmbpasswd,filemode,dirmode,uid,gid,ipaddr);
-       if (*group_name){
-         strcat(commandstr,",workgroup=");
-         strcat(commandstr,group_name);
-       }
-       if ( (port >= 0) && (port < 65536) )
-       {
-         string_ncat(commandstr, ",port=", MAXMNTCOMMANDL);
-         string_ncat(commandstr, port_str, MAXMNTCOMMANDL);
-       }
-       if ( !is_empty_string(pref.v.smbmount_arg) )
-       {
-         if ( pref.v.smbmount_arg[0] != ',' )
-          string_ncat(commandstr, ",", MAXMNTCOMMANDL);
-         string_ncat(commandstr, escape_str(pref.v.smbmount_arg,&strlist), MAXMNTCOMMANDL);
-       }
-      }
-      if (passw_lf)
-      {
-       usleep(50000);
-       close(fdstdin[0]);
-       if (!waitpid(mountdat->childpid,NULL,WNOHANG))
-          write(fdstdin[1], "\n",1);
+    log_execvp_str(argv[0],argv);
        close(fdstdin[1]);
       }
-    }
-    
-    log_execvp_str(pref_get_smbmount_exe(),argv);
-  }
   mountlist=g_slist_append(mountlist,mountdat);
   mountdat->linepos=0;  mountdat->linepos2=0;
   mountdat->linenum=0;
@@ -901,17 +828,13 @@
   }
   else
   {
-    argv[0]=smb ? "smbumount":"umount";
-    argv[1]=mount_point;
+    // bugfix: mount command might consist of more than one word (example: sudo mount_smbfs)
+    int argnr = -1;
+    split_arguments(pref_get_smbumount_exe(), argv, &argnr, &strlist);
     if ( !is_empty_string(pref.v.smbumount_arg) )
-    {
-      argv[2] = pref.v.smbumount_arg;
-      argv[3] = NULL;
-    }
-    else
-    {
-      argv[2]=NULL;
-    }
+      split_arguments(pref.v.smbumount_arg, argv, &argnr, &strlist);
+    argv[++argnr]=mount_point;
+    argv[++argnr] = NULL;
   }
   if((pipe2_nok=pipe(fdstdout))|| (pipe3_nok=pipe(fdstderr))||
         (childpid =fork())== -1)   
@@ -938,7 +861,7 @@
      execvp("su",argv);
    }  
    else
-     execvp(smb ? pref_get_smbumount_exe():"umount",argv);
+     execvp_with_password(argv[0], argv, "", strlist); 
    write(STDERR_FILENO,notfound,sizeof(notfound)-1); 
    _exit(0);
   }
@@ -958,7 +881,7 @@
         gui_log_window_insert_string("*",0);
    } 
    else
-     log_execvp_str(smb ? pref_get_smbumount_exe():"umount",argv);
+     log_execvp_str(argv[0], argv);
    mountdat=g_malloc(sizeof(UMOUNT_STRUCT));
    umountlist=g_slist_append(umountlist,mountdat);
    mountdat->childpid=childpid;
@@ -1015,6 +938,198 @@
   slist_free_with_data(&umountlist);
 }
 
+void split_arguments(char * arguments, char * argv[], int * argnr, GSList ** strlist)
+{
+      char * c = argv[++*argnr] = storeInBuffer(arguments, strlist);
+      while(c = strchr(c, ' '))
+      {
+        char *d = c+1;
+        while(*d && *d == ' ')
+          d++;
+        *c = 0;
+        c = d;
+        if (!*c)
+          break;
+        argv[++*argnr] = storeInBuffer(c, strlist);
+      }
+}
+
+char * storeInBuffer(const char * s, GSList ** strlist)
+{
+  int n;
+  char * ss;
+  
+  if (*s==0) return 0;
+  n = strlen(s);
+  ss=g_malloc(n+1);
+  strcpy(ss, s);
+  *strlist=g_slist_append(*strlist,ss);
+  return ss;
+}
+
+
+// this looks like a global variable. But each forked execvp_with_password
+// process has one copy of it. So it as a process local varible storing the
+// process ID of the forked child process, which actaully execs mount_smbfs
+int _childPid = 0;
+
+// called, if the child proces is killed. Kills its child process as well
+void stopMountSignalHandler (int sig)
+{
+  kill(_childPid, SIGINT);
+  waitpid(_childPid, 0, WUNTRACED);
+  _exit(0);
+}
+
+// replaces execvp to call mount_smbfs. If mount smbfs asks for a password, it is provided.
+// This can not be sent to stdin, because BSD gets the password directly from the terminal.
+// Therfore another process with a pseudo terminal is created.
+void execvp_with_password(const char * path, char * const argv[], const char * passwd, GSList *strlist)
+{
+  int master, i;
+  char  terminal[MAXPATHLEN] = "";
+  char * pw = NULL;
+  int slave;
+  char password[1024], result[1024];
+  char * passwordText = "password:";
+  int passwordTextLen = strlen(passwordText);
+  char * resp_pos = result;
+  int fdstderr[2];
+  
+  // create a pipe to the child process for stderr. For stdout the pseudo terminal is used
+  if(pipe(fdstderr))
+  {
+    fdstderr[0] = 0;
+    fdstderr[1] = 0;
+  }
+  
+  // create the child process and the pseudo terminal
+  _childPid = forkpty(&master, terminal, NULL, NULL);
+
+  if (_childPid < 0)
+  {
+    if (errno == ENOENT)
+      printf("Error: Out of ptys\n");
+    else
+      printf(result, "Error: Forkpty\n");
+    _exit(1);
+  }
+  else if (_childPid == 0)
+  {
+    // prepare stderr pipe
+    if (fdstderr[0])
+    {
+      close(fdstderr[0]);
+      dup2(fdstderr[1], STDERR_FILENO);
+    }
+    
+    // prepare the pseudo terminal
+    close(master);
+    slave = open(terminal, O_RDWR);
+    if (slave < 0)
+    {
+      printf("open() failed: %s", strerror(errno));
+      kill(_childPid, SIGINT);
+      waitpid(_childPid, 0, WUNTRACED);
+      _exit(1);
+    }
 
+    // launch application (mount_smbfs)
+    execvp(path, argv);
+    printf("error: %d (%s)\n", errno, strerror(errno));
+  }
+  else
+  {
+    // prepare the stderr pipe
+    if (fdstderr[1])
+      close(fdstderr[1]);
 
+    // install the SIGIN (ctrl-c) handler
+    if (signal(SIGINT, stopMountSignalHandler) == SIG_ERR)
+      printf("error: can not install SIGINT handler\n");
+    errno = 0;
+    *resp_pos = 0;
+    
+    // main loop: wait for childs response
+    while (!errno)
+    {
+      // prepare a poll, wich waits for output from the pseudo terminal and from stderr
+      int pollnum = 1;
+      struct pollfd polldat[2];
+      polldat[0].fd = master;
+      polldat[0].events = POLLIN | POLLRDNORM | POLLRDBAND | POLLPRI;
+      if (fdstderr[0])
+      {
+        pollnum = 2;
+        polldat[1].fd = fdstderr[0];
+        polldat[1].events = POLLIN | POLLRDNORM | POLLRDBAND | POLLPRI;
+      }
+
+      // sleep until the child terminates or sends something
+      if (poll(polldat, pollnum, 1000) < 0)
+        break;
 
+      // response from childs stderr?
+      if (pollnum == 2 && polldat[1].revents)
+      {
+        // read response and send it to this process' stderr. It is connected
+        // with another pipe with the main process!
+        char s[1024];
+        int i = read(fdstderr[0], s, 1024);
+        if (errno)
+          break;
+        if (i > 0)
+        {
+          s[i] = 0;
+          write(STDERR_FILENO, s, i);
+        }
+      }
+
+      // response from childs stdout?
+      if (polldat[0].revents)
+      {
+        // read response and send it to this process' stdout. It is connected
+        // with another pipe with the main process. If the string 'password'
+       // was send, provide the password
+        char c;
+        if (read(master, &c, 1) <= 0 || errno)
+          break;
+        if (resp_pos - result < sizeof(result))
+          *resp_pos++ = c;
+        *resp_pos = 0;
+        if (c == '\n')
+        {
+          printf("%s", result);
+          resp_pos = result;
+        }
+        *resp_pos = 0;
+        if (resp_pos - result >= passwordTextLen && !strcasecmp(resp_pos-passwordTextLen, passwordText))
+        {
+          // prepare the password and send it through the pseudo terminal
+          strcpy(password, passwd);
+          strcat(password, "\n");
+          resp_pos = result;
+          *resp_pos = 0;
+          write(master, password, strlen(password));
+        }
+      }
+      // if the child is dead, end main loop
+      if (waitpid(_childPid,NULL,WNOHANG))
+        break;
+    }
+    
+    // if there is unsend response, send it to the main process
+    printf("%s", result);
+    
+    // free resources
+    if (fdstderr[0])
+      close(fdstderr[0]);
+    close(master);
+    slist_free_with_data(&strlist);
+    
+    // get childs return code to avoid zombies
+    waitpid(_childPid, 0, WUNTRACED);
+    _exit(0);
+  }
+  _exit(-1); // can not be reached
+}
