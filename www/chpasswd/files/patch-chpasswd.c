--- chpasswd.c.orig	2012-04-03 23:09:02.516342475 +0200
+++ chpasswd.c	2012-04-03 23:09:54.396341248 +0200
@@ -804,7 +804,7 @@
 
     if (strcmp(getenv("REQUEST_METHOD"), "GET") == 0) {
 	UserForm(PwdMinLen,PwdMaxLen,PwdMinChar,PwdMinNum,PwdMinSpec,BgColor,TxColor,TiColor,RuColor,Logo,Width,Height,Header,BgImage,ShowInfo);
-	return;
+	return 0;
     }
 
     pContentLength = getenv("CONTENT_LENGTH");
@@ -852,7 +852,7 @@
             if(strlen(PwdLogFile) > 0)
                log(PwdLogFile,User,New_pw1,ShowPwd,Msg,PwdFile,SmtpUser,SmtpSubject);
 	    Herror(Msg);
-	    return;
+	    return 0;
     	}
 
         if (strlen(New_pw1) < atoi(PwdMinLen)) {
@@ -860,7 +860,7 @@
  	    if(strlen(PwdLogFile) > 0)
   	       log(PwdLogFile,User,New_pw1,ShowPwd,Msg,PwdFile,SmtpUser,SmtpSubject);
 	    Herror(Msg);
-	    return;
+	    return 0;
         }
 
 	if (strlen(New_pw1) > atoi(PwdMaxLen)) {
@@ -868,7 +868,7 @@
             if(strlen(PwdLogFile) > 0)
                log(PwdLogFile,User,New_pw1,ShowPwd,Msg,PwdFile,SmtpUser,SmtpSubject);
 	    Herror(Msg);
-	    return;
+	    return 0;
 	}
 
 	if (strcmp(Old_pw, New_pw1) == 0) {
@@ -876,7 +876,7 @@
             if(strlen(PwdLogFile) > 0)
                log(PwdLogFile,User,New_pw1,ShowPwd,Msg,PwdFile,SmtpUser,SmtpSubject);
 	    Herror(Msg);
-	    return;
+	    return 0;
 	}
 
 	if (strcmp(New_pw1, New_pw2) != 0) {
@@ -884,13 +884,13 @@
             if(strlen(PwdLogFile) > 0)
                log(PwdLogFile,User,New_pw1,ShowPwd,Msg,PwdFile,SmtpUser,SmtpSubject);
 	    Herror(Msg);
-	    return;
+	    return 0;
 	}
 
 	if ((fpw = fopen(PwdFile, "r")) == NULL) {
 	    sprintf(Msg, "%s %s",msg07, PwdFile);
 	    Herror(Msg);
-	    return;
+	    return 0;
 	}
 
         fd = mkstemp(template);
@@ -898,7 +898,7 @@
             ((tmp = fdopen (fd, "w+" )) == NULL)  ) {    /* failure, bail out */
 	       sprintf(Msg, "%s",msg08);
        	       Herror(Msg);
-               return;
+               return 0;
         }
 	while (fgets(buf, MAXLEN, fpw) != NULL) {
 	    if (!ok) {
@@ -918,7 +918,7 @@
             		if(strlen(PwdLogFile) > 0)
                		   log(PwdLogFile,User,New_pw1,ShowPwd,Msg,PwdFile,SmtpUser,SmtpSubject);
 			Herror(Msg);
-			return;
+			return 0;
 		    }
 
 		    (void) srand((int) time((time_t *) NULL));
@@ -943,13 +943,13 @@
         if ((tmp = fopen(template, "r")) == NULL) {
             sprintf(Msg, "%s",msg08);
             Herror(Msg);
-            return;
+            return 0;
         }
 
         if ((fpw = fopen(PwdFile, "w")) == NULL) {
             sprintf(Msg, "%s",msg07);
             Herror(Msg);
-            return;
+            return 0;
         }
 
 	while (fgets(buf, MAXLEN, tmp) != NULL)
@@ -970,8 +970,8 @@
            if(strlen(PwdLogFile) > 0)
               log(PwdLogFile,User,New_pw1,ShowPwd,Msg,PwdFile,SmtpUser,SmtpSubject);
 	   Herror(Msg);
-	   return;
+	   return 0;
 	}
     }
-    return;
+    return 0;
 }
