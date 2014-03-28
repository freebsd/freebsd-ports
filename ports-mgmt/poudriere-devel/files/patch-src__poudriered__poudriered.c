--- ./src/poudriered/poudriered.c.orig	2014-03-23 11:01:01.147420893 -0500
+++ ./src/poudriered/poudriered.c	2014-03-23 11:01:25.271419416 -0500
@@ -669,8 +669,8 @@
 		    dateformat == NULL)
 			continue;
 
-		if (strftime_l(datestr, BUFSIZ, ucl_object_tostring(dateformat),
-		    now, NULL) <= 0)
+		if (strftime(datestr, BUFSIZ, ucl_object_tostring(dateformat),
+		    now) <= 0)
 			continue;
 
 		if (!strcmp(datestr, ucl_object_tostring(when))) {
