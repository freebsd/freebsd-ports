--- antivirus.c.orig	Tue Jul 15 21:27:14 2003
+++ antivirus.c	Fri Mar  5 07:56:07 2004
@@ -85,6 +85,7 @@
 static char *FORMAT=NULL;
 static sfsistat avfailcode=0;
 static int purgevirus=0;
+static int skipwords=0;
 static char *avargs[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
 
 /*
@@ -128,6 +129,12 @@
 #define FORMAT_SOPHOS ">>> Virus '%[^']s' found in file %*s"
 
 /*
+** This one is for clamav
+*/
+#define FORMAT_CLAMAV " %s FOUND"
+#define SCANARGS_CLAMAV "--disable-summary"
+
+/*
 ** this can be given on the command line
 */
 static char *configfile=NULL;
@@ -502,6 +509,7 @@
   int retval;
   int fd;
   int i;
+  char *word;
   char *p=NULL;
   char *av[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
 
@@ -558,7 +566,14 @@
       memset(viruses,0,sizeof(buf));
       while (fgets(buf,sizeof(buf),priv->childfp)!=NULL)
 	{
-	  if (sscanf(buf,format,tmp)==1)
+	  word = buf;
+          if (skipwords > 0 )
+	    {
+              word = strchr( word, ' ' );
+              if ( word == NULL )
+	        word = buf;
+	    }
+	  if (sscanf(word,format,tmp)==1)
 	    {
 	      if (viruses[0])
 		strncat(viruses," ",sizeof(viruses));
@@ -1211,6 +1226,7 @@
   if (AVFAILACTION==NULL) AVFAILACTION=CONF_AVFAILACTION;
   if (VIRUSACTION==NULL) VIRUSACTION=CONF_VIRUSACTION;
 
+  skipwords = 0;
   if (strcasecmp(AVPRODUCT,"mcafee")==0)
     {
       FORMAT=FORMAT_MCAFEE;
@@ -1225,10 +1241,16 @@
     {
       FORMAT=FORMAT_FSAV;
     }
+  else if (strcasecmp(AVPRODUCT,"clamav")==0)
+    {
+      FORMAT=FORMAT_CLAMAV;
+      AVSCANARGS=SCANARGS_CLAMAV;
+      skipwords = 1;
+    }
   else
     {
       fprintf(stderr,"init(): unrecognized AVPRODUCT %s\n",AVPRODUCT);
-      fprintf(stderr,"init(): valid values are: mcafee, fsva, sophos\n");
+      fprintf(stderr,"init(): valid values are: mcafee, fsva, sophos, clamav\n");
       return(-1);
     }
 
