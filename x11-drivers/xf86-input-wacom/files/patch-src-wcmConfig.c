--- src/wcmConfig.c~
+++ src/wcmConfig.c
@@ -307,7 +307,7 @@ out:
  */
 static void wcmSplitName(char* devicename, char *basename, char *subdevice, char *tool, size_t len)
 {
-	char *name = strdupa(devicename);
+	char *name = strdup(devicename);
 	char *a, *b;
 
 	*basename = *subdevice = *tool = '\0';
@@ -325,6 +325,7 @@ static void wcmSplitName(char* devicenam
 		strncat(tool, a+1, len-1);
 	}
 	strncat(basename, name, len-1);
+	free(name);
 }
 
 /**
