--- wrt_him.c.orig	Sun Sep  7 22:57:06 2003
+++ wrt_him.c	Sun Sep  7 22:57:14 2003
@@ -141,7 +141,7 @@
 	    if (mywrt.wrt_last[0] == '\0')
 	    {
 		printf("No previous write or telegram.  Can't repeat\n");
-		log("FAIL: no previous");
+		_log("FAIL: no previous");
 		done(1);
 	    }
 	    strncpy(hisname,mywrt.wrt_last,UT_NAMESIZE);
@@ -170,13 +170,13 @@
 	    else if (rc == 1)
 	    {
 		printf("No such tty\n");
-		log("FAIL: no such tty");
+		_log("FAIL: no such tty");
 		done(1);
 	    }
 	    else
 	    {
 		printf("%s not logged onto %s\n",hisname,histty);
-		log("FAIL: not on tty");
+		_log("FAIL: not on tty");
 		done(1);
 	    }
 	}
@@ -253,7 +253,7 @@
 	/* didn't find any matches, trouble */
 	printf("%s is not logged on\n",hisname);
 	{
-	    log("FAIL: not on");
+	    _log("FAIL: not on");
 	    done(1);
 	}
     }
@@ -300,7 +300,7 @@
 	if (*ut->ut_name == '\0')
 	{
 	    printf("No one logged onto %s\n",histty);
-	    log("FAIL: empty tty");
+	    _log("FAIL: empty tty");
 	    done(1);
 	}
 	strncpy(hisname, ut->ut_name, UT_NAMESIZE);
@@ -344,7 +344,7 @@
     }
 
     printf("You are not being written\n");
-    log("FAIL: not written");
+    _log("FAIL: not written");
     done(0);
 }
 
@@ -444,14 +444,14 @@
 	{
 	    printf("Sorry, no helpers are available right now.\n");
 	    if (f_nohelp) type_help(f_nohelp);
-	    log("FAIL: no helpers");
+	    _log("FAIL: no helpers");
 	}
 	else
 	{
 	    printf("Sorry, all helpers currently available are busy.\n");
 	    if (f_nohelp) type_help(f_nohelp);
 	    printf("Try again later...\n");
-	    log("FAIL: help busy");
+	    _log("FAIL: help busy");
 	}
 	done(0);
     }
