
$FreeBSD$

--- e-util/e-pilot-util.c	2001/12/14 12:11:21	1.1
+++ e-util/e-pilot-util.c	2001/12/14 12:12:08
@@ -36,7 +36,7 @@
 	if (!string)
 		return NULL;
 	
-	res = convert_ToPilotChar ("UTF8", string, strlen (string), &pstring);
+	res = convert_ToPilotChar ("UTF-8", string, strlen (string), &pstring);
 
 	if (res != 0)
 		pstring = strdup (string);
@@ -53,7 +53,7 @@
 	if (!string)
 		return NULL;
 	
-	res = convert_FromPilotChar ("UTF8", string, strlen (string), &ustring);
+	res = convert_FromPilotChar ("UTF-8", string, strlen (string), &ustring);
 	
 	if (res != 0)
 		ustring = strdup (string);
