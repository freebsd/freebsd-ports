--- wmq3.c.orig	Sun Dec  9 18:34:46 2001
+++ wmq3.c	Sun Dec 30 01:56:37 2001
@@ -72,6 +72,7 @@
 int	TimerDivisor=60;
 int	WaveForm=0;
 int 	myStatus=0;
+char	*rcfilename = NULL;
 
 // serverstuff
 char server[100][10];
@@ -100,7 +101,7 @@
 void DrawStats(int *, int, int, int, int);
 int left(char *mleft, char *line,char limiter);
 void strip(char *line);
-int GetConfig();
+int GetConfig(char *config);
 void ButtonUp(int);
 void ButtonDown(int);
 void execute();
@@ -118,11 +119,15 @@
   if (strlen(ProgName) >= 4)
     ProgName += (strlen(ProgName) - 4);
 
-  if(GetConfig()<0)
-    {
-      printf("No servers in configfile\n");
-      exit(0);
-    }
+  if (!rcfilename)
+  {
+    char *homedir;
+    homedir = getenv("HOME");
+    rcfilename = calloc(1, strlen(homedir) + 9);
+    strcat(rcfilename, homedir);
+    strcat(rcfilename, "/.wmq3rc");
+  }
+  GetConfig(rcfilename);
   currserver=0;
   wmq3_routine(argc, argv);
   return 1;
@@ -476,7 +481,7 @@
   /*******************************************************************************
  read config
 ******************************************************************************/
-int GetConfig()
+int GetConfig(char *config)
 {
   FILE  *fh;
   char buffer[256];
@@ -487,8 +492,10 @@
   clickcall = (char **)malloc(30 * sizeof(char*));
 
   // read configfile
-  fh=fopen("/etc/wmq3rc","r");
+  fh=fopen(config,"r");
 
+ if(fh)
+ {
   memset(buffer,0,sizeof(buffer));
   clickparms=-1;
   while(fgets(buffer,255,fh))
@@ -549,6 +556,10 @@
 
   fclose(fh);
   return scount;
+ } else {
+   fprintf(stderr,"No config file found.\n");
+ }
+
 }
 void strip(char *line)
 {
