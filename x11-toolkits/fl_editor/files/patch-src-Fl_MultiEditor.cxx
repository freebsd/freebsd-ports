--- src/Fl_MultiEditor.cxx.orig	Thu Jan 23 12:35:36 2003
+++ src/Fl_MultiEditor.cxx	Thu Jan 23 12:35:56 2003
@@ -102,7 +102,7 @@
 		sinf->Caption = new wString;
 		sinf->SessionName = new wString;
 		sinf->SessionNumber = ++SessionCount;
-		const char *temp = name ? filename_name(name) : NULL;
+		const char *temp = name ? fl_filename_name(name) : NULL;
 		if(temp)
             *sinf->SessionName = temp;
 		else
@@ -243,7 +243,7 @@
 			fclose(out);
 		}
 		*CurrentSession->FileName = filename;
-		const char *temp = filename_name(fn);
+		const char *temp = fl_filename_name(fn);
 		if(!temp)
 			temp = fn;
 		if(temp)
