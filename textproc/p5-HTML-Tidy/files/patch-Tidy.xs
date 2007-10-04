$Id$
--- Tidy.xs.orig	2007-09-24 11:36:19.000000000 +0200
+++ Tidy.xs	2007-09-24 11:37:42.000000000 +0200
@@ -55,6 +55,7 @@ _tidy_messages(input, configfile, tidy_o
         const char* newline;
         int rc = 0;
     PPCODE:
+        tidyBufInit(&errbuf);
         rc = ( tidyOptSetValue( tdoc, TidyCharEncoding, "utf8" ) ? rc : -1 );
 
         if ( (rc >= 0 ) && configfile && *configfile ) {
@@ -117,6 +118,8 @@ _tidy_clean(input, configfile, tidy_opti
         const char* newline;
         int rc = 0;
     PPCODE:
+        tidyBufInit(&output);
+        tidyBufInit(&errbuf);
         /* Set our default first. */
         /* Don't word-wrap */
         rc = ( tidyOptSetInt( tdoc, TidyWrapLen, 0 ) ? rc : -1 );
