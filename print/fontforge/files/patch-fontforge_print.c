--- fontforge/print.c.orig	2019-04-13 07:38:39 UTC
+++ fontforge/print.c
@@ -1164,19 +1164,7 @@ static void dump_pdfprologue(PI *pi) {
     }
     fprintf( pi->out, "    /CreationDate (D:%04d%02d%02d%02d%02d%02d",
 	    tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec );
-#ifdef _NO_TZSET
     fprintf( pi->out, "Z)\n" );
-#else
-    if ( timezone==0 || getenv("SOURCE_DATE_EPOCH") )
-	fprintf( pi->out, "Z)\n" );
-    else {
-	if ( timezone<0 ) /* fprintf bug - this is a kludge to print +/- in front of a %02d-padded value */
-	    fprintf( pi->out, "-" );
-	else
-	    fprintf( pi->out, "+" );
-	fprintf( pi->out, "%02d'%02d')\n", (int)(timezone/3600),(int)(timezone/60-(timezone/3600)*60) );
-    }
-#endif
     if ( author!=NULL )
 	fprintf( pi->out, "  /Author (%s)\n", author );
     fprintf( pi->out, ">>\n" );
