--- setstate.c.orig	1997-05-12 14:42:06 UTC
+++ setstate.c
@@ -509,7 +509,7 @@ void assign_help_files()
 	}
 	
 	if(found_label == FALSE)
-		strcpy(help_location,"/usr/local/xldlas/help/");
+		strcpy(help_location, PREFIX "/share/xldlas/help/");
 	strcpy(searcher,"test -r ");
 	strcat(searcher, help_location);
 	strcat(searcher,"general.help");
