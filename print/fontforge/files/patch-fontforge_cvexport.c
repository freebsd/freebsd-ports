--- fontforge/cvexport.c.orig	2014-11-27 00:40:08 UTC
+++ fontforge/cvexport.c
@@ -213,20 +213,7 @@ int _ExportPDF(FILE *pdf,SplineChar *sc,
     fprintf( pdf, "    /CreationDate (D:%04d%02d%02d%02d%02d%02d",
 	    1900+tm->tm_year, tm->tm_mon+1, tm->tm_mday,
 	    tm->tm_hour, tm->tm_min, tm->tm_sec );
-#ifdef _NO_TZSET
     fprintf( pdf, "Z)\n" );
-#else
-    tzset();
-    if ( timezone==0 )
-	fprintf( pdf, "Z)\n" );
-    else {
-	if ( timezone<0 ) /* fprintf bug - this is a kludge to print +/- in front of a %02d-padded value */
-	    fprintf( pdf, "-" );
-	else
-	    fprintf( pdf, "+" );
-	fprintf( pdf, "%02d'%02d')\n", (int)(timezone/3600),(int)(timezone/60-(timezone/3600)*60) );
-    }
-#endif
     fprintf( pdf, "    /Title (%s from %s)\n", sc->name, sc->parent->fontname );
     if ( author!=NULL )
 	fprintf( pdf, "    /Author (%s)\n", author );
