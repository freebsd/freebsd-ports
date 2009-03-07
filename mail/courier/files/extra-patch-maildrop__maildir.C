--- maildrop/maildir.C.orig	Thu Jan 15 04:12:13 2004
+++ maildrop/maildir.C	Thu Jul  5 00:09:38 2007
@@ -137,7 +137,6 @@
 			tmpname=createInfo.tmpname;
 			newname=createInfo.newname;
 			tmpname += '\0';
-			newname += '\0';
 			maildir_tmpcreate_free(&createInfo);
 
 			file.fd(f);
@@ -181,6 +180,22 @@
 {
 	if (is_open)
 	{
+		Buffer b;
+
+		b="MFLAGS";
+
+		const char *f=GetVarStr(b);
+
+		if (f && strlen(f) > 0)
+		{
+			newname += ':';
+			newname += '2';
+			newname += ',';
+			newname += f;
+		}
+
+		newname += '\0';
+
 		Buffer keywords;
 
 		keywords="KEYWORDS";
