--- wmping.c.orig	2004-02-09 09:27:38 UTC
+++ wmping.c
@@ -237,7 +237,7 @@ void readconf()
 		    if(strcmp(tokens[1],"="))
 		    {
 			sprintf(str_err, "Not correct format of configuration file ( %s ): line %u", cfgfile, lineN);
-			fprintf(stderr, str_err);
+			fprintf(stderr, "%s\n", str_err);
                         exit(-1);
 		    }
 
@@ -288,7 +288,7 @@ void readconf()
 		else
 		{
 		    sprintf(str_err, "Not correct format of configuration file ( %s ): line %u", cfgfile, lineN);
-		    fprintf(stderr, str_err);
+		    fprintf(stderr, "%s\n", str_err);
 		    exit(-1);
 
 		}
@@ -297,7 +297,7 @@ void readconf()
         else
 	{
 	    sprintf(str_err, "Error open configuration file ( %s ): %s", cfgfile, strerror(errno));
-	    fprintf(stderr, str_err);
+	    fprintf(stderr, "%s\n", str_err);
 	    fprintf(stderr, "\n Create default configuration file\n");
 	    createDefaultCfg(cfgfile);
 	}
@@ -305,7 +305,7 @@ void readconf()
     else
     {
 	sprintf(str_err, "Error open configuration file ( %s ): %s", cfgfile, strerror(errno));
-	fprintf(stderr, str_err);
+	fprintf(stderr, "%s\n", str_err);
 	fprintf(stderr, "\n Create default configuration file\n");
 	createDefaultCfg(cfgfile);
     }
