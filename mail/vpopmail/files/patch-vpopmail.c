diff -urN -x .svn ../../vendor/vpopmail/vpopmail.c ./vpopmail.c
--- ../../vendor/vpopmail/vpopmail.c	2007-10-07 23:44:14.000000000 +0300
+++ ./vpopmail.c	2007-10-08 11:53:36.000000000 +0300
@@ -1559,7 +1559,7 @@
    i++;
    }
 
-k = strlen(s) - i - 1; 
+k = strlen(s) - i; 
 
 if( i>0 ) {
    for( j=0; j<k; j++ )  {
@@ -1571,7 +1571,7 @@
 
 //  trim spaces and tabs from end
 i = strlen(s) - 1;
-while(( s[i] == ' ' ) || ( s[i] == '\t' )) {
+while(i >= 0 && ( s[i] == ' ' ) || ( s[i] == '\t' )) {
    i--;
    }
 
@@ -4127,11 +4127,19 @@
 	}
 	else if ( pid > 0 )
 	{
-		wait(&rv);
-		return(rv);
+		if (waitpid ( pid, &rv, 0 ) < 0 ||
+		    !WIFEXITED( rv ) || WEXITSTATUS( rv ) != 0 ) {
+			fprintf(stderr,
+			    "ONCHANGE script %s did not exit gracefully.\n",
+			    path);
+			return(rv);
+		}
+		return(0);
 	}
 
-	fprintf(stderr, "ONCHANGE script %s unable to fork.\n", path);
-	return(0);
+	rv = errno;
+	fprintf(stderr, "ONCHANGE script %s unable to fork: %s\n", path,
+	    strerror(rv));
+	return(rv);
 }
 #endif
