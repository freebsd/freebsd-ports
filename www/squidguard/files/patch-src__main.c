--- src/main.c.orig	2008-08-30 10:27:41 UTC
+++ src/main.c
@@ -114,7 +114,11 @@ int main(argc, argv, envp)
       globalUpdate = 1;
       break;
     case 'v':
+#if DB_VERSION_MAJOR * 10 + DB_VERSION_MINOR == 42
+      fprintf(stderr, "SquidGuard: %s %s\n", VERSION,db_version_4002(NULL,NULL,NULL));
+#else
       fprintf(stderr, "SquidGuard: %s %s\n", VERSION,db_version(NULL,NULL,NULL));
+#endif
       exit(0);
       break;
     case 't':
@@ -175,7 +179,7 @@ int main(argc, argv, envp)
 	sgReloadConfig();
       }
       if(failsafe_mode) {
-	puts("");
+	puts("ERR message=\"squidGuard failsafe mode\"");
 	fflush(stdout);
 	if(sig_hup){
           sgReloadConfig();
@@ -184,7 +188,7 @@ int main(argc, argv, envp)
       }
       if(parseLine(buf,&squidInfo) != 1){
 	sgLogError("Error parsing squid line: %s",buf);
-	puts("");
+	puts("BH message=\"squidGuard error parsing squid line\"");
       }
         else {
 	src = Source;
@@ -196,14 +200,14 @@ int main(argc, argv, envp)
 	  acl = sgAclCheckSource(src);
 	  if((redirect = sgAclAccess(src,acl,&squidInfo)) == NULL){
 	    if(src == NULL || src->cont_search == 0){
-	      puts(""); 
+	      puts("ERR"); 
 	      break;
 	    } else
 	      if(src->next != NULL){
 		src = src->next;
 		continue;
 	      } else {
-		puts("");
+		puts("ERR");
 		break;
 	      }
 	  } else {
@@ -215,9 +219,10 @@ int main(argc, argv, envp)
 	      squidInfo.ident[0] = '-';
 	      squidInfo.ident[1] = '\0';
 	    }
-	    fprintf(stdout,"%s %s/%s %s %s\n",redirect,squidInfo.src,
-		    squidInfo.srcDomain,squidInfo.ident,
-		    squidInfo.method);
+            if (isdigit(redirect[0]) && isdigit(redirect[1]) && isdigit(redirect[2]) && redirect[3]==':') {
+              fprintf(stdout,"OK status=%c%c%c url=\"%s\"\n", redirect[0], redirect[1], redirect[2], &redirect[4]);
+            } else
+              fprintf(stdout,"OK rewrite-url=\"%s\"\n",redirect);
             /* sgLogError("%s %s/%s %s %s\n",redirect,squidInfo.src,squidInfo.srcDomain,squidInfo.ident,squidInfo.method);  */
 	    break;
 	  }
