--- old/sources/dico.c	Thu Mar 27 14:57:57 1997
+++ new/sources/dico.c	Wed Oct 11 04:04:49 2000
@@ -19,8 +19,8 @@
     |                                                                       |
     +-----------------------------------------------------------------------+
 */
-#define LINUX
 
+#ifndef __FreeBSD__
 #ifndef LINUX
 #ifndef sony
 #ifndef MSDOS
@@ -28,6 +28,7 @@
 #endif
 #endif
 #endif
+#endif
 
 #ifdef sony                             /* Sony News WorkStations        */
 #define UNIX
@@ -42,6 +43,12 @@
 #define MYOS "LINUX" 
 #endif
 
+#ifdef __FreeBSD__                      /* FreeBSD Operating System        */ 
+#define UNIX
+#define ISO_CHARS
+#define MYOS "FreeBSD" 
+#endif
+
 #ifdef MSDOS                            /* Systeme d'operation de disque */
 #define MYOS "MSDOS"                    /* Microsoft :-)                 */
 #endif
@@ -51,8 +58,11 @@
 #define ISO_TERM    3
 #define COMMENT_CHAR 35                 /* '#' ligne de commentaire        */
 
-#define DICT_PATH "/usr/local/lib/dico"	 /* path par defaut unix/dos        */
+#ifndef MSDOS
+#define DICT_PATH "!!PREFIX!!/share/dico" /* path par defaut unix/dos        */
+#else
 #define DOS_PATH  "lexique"              /* path par defaut Dos uniquement  */
+#endif
 #define DICT_EXT ".dic"                  /* extension des fichiers dicos    */
 #define VERSION_FILE "version.dic"       /* fichier texte version dico      */
 
@@ -60,11 +70,13 @@
 #define OK    0
 #define MYVBUF 10240                     /* pour setvbuf() eventuel         */
 
+#ifndef __FreeBSD__
 #ifndef LINUX
 #ifndef sony
 #define MUST_HAVE_BUF                  /* Linux va moins vite avec setvbuf! */
 #endif
 #endif
+#endif
 
 typedef unsigned char byte;
 
@@ -147,7 +159,9 @@
     if(argv[1][0] =='-')                      /* option ligne commande?*/
         return   options( argv[1][1]  );
 
+#ifndef __FreeBSD__
     mybanner();                               /* on dit bonjour...     */
+#endif
 
     while( --argc)                            /* Allez, roulez !       */
     {
@@ -157,7 +171,9 @@
             lookfor( argv[argc] );
     }
 
+#ifndef __FreeBSD__
     fprintf(stderr,"\nTrouve %ld mot%s\n",count, count > 1 ? "s" :"" );
+#endif
 
        return OK ;
 }
@@ -369,7 +385,9 @@
     
     StrLwr( pattern );  /* passe en minuscules comme le dico */
     car = equival (pattern[0]);
+#ifndef __FreeBSD__
     fprintf(stderr, "Recherche %s dans la lettre %c... \n\n", pattern, car) ;
+#endif
 
     sprintf(fname, "%s%s%c%s", dict_path, sep, pattern[0], DICT_EXT ) ;
 
@@ -395,7 +413,11 @@
         if( fmatch(sbuf,pattern) )
         {
             translate( buf ); /* gere terminaux....   */
+#ifndef __FreeBSD__
             printf("\t%s\n", beautify(buf) );
+#else
+            printf("%s\n", beautify(buf) );
+#endif
             count ++ ;
         }
     }
@@ -451,8 +473,11 @@
             if( fmatch(sbuf,pattern) )
             { 
                 translate( buf ) ;
-                buf[0] = ToUpper( buf[0] ) ;  
+#ifndef __FreeBSD__
                 printf("\t%s\n", beautify (buf) );
+#else
+                printf("%s\n", beautify (buf) );
+#endif
                 count ++ ;
             } 
         }
@@ -474,7 +499,7 @@
 
 mybanner()
 {
-/*    printf("\nDICO V %s (%s) - R.Cougnenc 1992\n\n", __Version__, MYOS);*/
+    printf("\nDICO V %s (%s) - R.Cougnenc 1992\n\n", __Version__, MYOS);
 }
 /*--------------------------------------------------------------------------*/
 
@@ -526,7 +551,9 @@
    byte ville[50], code[6];
    byte *r = ville;
 
+/* #ifndef __FreeBSD__ */
    *str = ToUpper ( *str );                 /* Premiere lettre...     */
+/* #endif */
 
     if( ! strchr( str, '\t') )               /* Cas du nom commun      */
     {
