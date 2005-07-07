--- antivirus.c.orig	Tue Jul 15 21:27:14 2003
+++ antivirus.c	Mon Jun 20 17:45:16 2005
@@ -85,6 +85,8 @@
 static char *FORMAT=NULL;
 static sfsistat avfailcode=0;
 static int purgevirus=0;
+static int skipwords=0;
+static int ignorerror2=0;
 static char *avargs[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
 
 /*
@@ -128,6 +130,12 @@
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
@@ -502,6 +510,7 @@
   int retval;
   int fd;
   int i;
+  char *word;
   char *p=NULL;
   char *av[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
 
@@ -552,13 +561,26 @@
 	     (int)ctx, retval,priv->workdir);
     }
 
+  if (ignorerror2 > 0 )
+    {
+	if ( retval == 2 )
+		retval = 0;
+    }
+
   if (retval>0)
     {
       fseek(priv->childfp,0,SEEK_SET);
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
@@ -572,10 +594,8 @@
       if (viruses[0])
 	priv->viruses=strdup(viruses);
       else
-	priv->viruses=strdup("please contact postmaster");
-
-      if ((priv->viruses)==NULL)
 	{
+	  priv->viruses=strdup("please contact postmaster");
 	  return(avfailcode);
 	}
       return(SMFIS_REJECT);
@@ -1211,6 +1231,7 @@
   if (AVFAILACTION==NULL) AVFAILACTION=CONF_AVFAILACTION;
   if (VIRUSACTION==NULL) VIRUSACTION=CONF_VIRUSACTION;
 
+  skipwords = 0;
   if (strcasecmp(AVPRODUCT,"mcafee")==0)
     {
       FORMAT=FORMAT_MCAFEE;
@@ -1225,10 +1246,17 @@
     {
       FORMAT=FORMAT_FSAV;
     }
+  else if (strcasecmp(AVPRODUCT,"clamav")==0)
+    {
+      FORMAT=FORMAT_CLAMAV;
+      AVSCANARGS=SCANARGS_CLAMAV;
+      skipwords = 1;
+      ignorerror2 = 1;
+    }
   else
     {
       fprintf(stderr,"init(): unrecognized AVPRODUCT %s\n",AVPRODUCT);
-      fprintf(stderr,"init(): valid values are: mcafee, fsva, sophos\n");
+      fprintf(stderr,"init(): valid values are: mcafee, fsva, sophos, clamav\n");
       return(-1);
     }
 
