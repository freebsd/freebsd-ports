--- fontforge/cvexport.c.orig	2019-04-13 07:38:39 UTC
+++ fontforge/cvexport.c
@@ -232,20 +232,7 @@ int _ExportPDF(FILE *pdf,SplineChar *sc,int layer) {
     fprintf( pdf, "    /CreationDate (D:%04d%02d%02d%02d%02d%02d",
 	    1900+tm->tm_year, tm->tm_mon+1, tm->tm_mday,
 	    tm->tm_hour, tm->tm_min, tm->tm_sec );
-#ifdef _NO_TZSET
     fprintf( pdf, "Z)\n" );
-#else
-    tzset();
-    if ( timezone==0  || getenv("SOURCE_DATE_EPOCH") )
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
