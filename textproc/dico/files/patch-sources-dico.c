--- sources/dico.c.orig	Sat Oct 24 16:16:30 1992
+++ sources/dico.c	Fri Mar 12 22:01:31 2004
@@ -19,6 +19,7 @@
     |                                                                       |
     +-----------------------------------------------------------------------+
 */
+#ifndef __FreeBSD__
 #ifndef LINUX
 #ifndef sony
 #ifndef MSDOS
@@ -26,6 +27,7 @@
 #endif
 #endif
 #endif
+#endif
 
 #ifdef sony                             /* Sony News WorkStations        */
 #define UNIX
@@ -40,6 +42,12 @@
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
@@ -49,7 +57,7 @@
 #define ISO_TERM    3
 #define COMMENT_CHAR 35                 /* '#' ligne de commentaire        */
 
-#define DICT_PATH "/usr/local/lib/dico"  /* path par defaut unix/dos        */
+#define DICT_PATH "%%PREFIX%%/share/dico" /* path par defaut unix/dos      */
 #define DOS_PATH  "lexique"              /* path par defaut Dos uniquement  */
 #define DICT_EXT ".dic"                  /* extension des fichiers dicos    */
 #define VERSION_FILE "version.dic"       /* fichier texte version dico      */
@@ -58,11 +66,13 @@
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
 
@@ -78,14 +88,28 @@
 byte *StrUpr ( byte *str);
 byte *StrLwr ( byte *str);
 byte *StrAscii( byte *str);
+void translate( byte *str );
 byte equival( byte c  );
-byte *beautify( byte  *str);
-void lookfor();
-void lookall();
+char *beautify(char *);
+void lookfor(byte *);
+void lookall(byte *);
 #ifdef MSDOS
 void GetDosPath(char *path);
 void TakePath  (char *path);
 #endif
+void file_usage(void);
+int usage(void);
+int options(int);
+int isjoker(int);
+void mybanner(void);
+int countwords(void);
+void nolf(char *);
+int fmatch(char *_fname, char *_pat);
+int match(char *_fname, char *_pat);
+void StrIBM(byte *);
+void StrISO(byte *);
+void iso2ibm(unsigned char *);
+void ibm2iso(unsigned char *);
 
 #ifdef MSDOS
     char *sep = "\\";
@@ -111,7 +135,7 @@
 /*
  *           Code...
  */
-
+int
 main( int argc, char **argv )
 {
  char *dic,*term ;
@@ -145,17 +169,21 @@
     if(argv[1][0] =='-')                      /* option ligne commande?*/
         return   options( argv[1][1]  );
 
+#ifndef __FreeBSD__
     mybanner();                               /* on dit bonjour...     */
+#endif
 
     while( --argc)                            /* Allez, roulez !       */
     {
         if( isjoker (argv[argc][0] ) )
-            lookall( argv[argc] );
+            lookall( (byte *)argv[argc] );
         else
-            lookfor( argv[argc] );
+            lookfor( (byte *)argv[argc] );
     }
 
+#ifndef __FreeBSD__
     fprintf(stderr,"\nTrouve %ld mot%s\n",count, count > 1 ? "s" :"" );
+#endif
 
        return OK ;
 }
@@ -169,7 +197,7 @@
  *
  *
  */
-
+void
 file_usage()
 {
 #ifndef MSDOS        /* Cas normal */
@@ -211,6 +239,7 @@
  *
  *
  */
+int
 usage()
 {
     fprintf(stderr,"\n\nDico - R.Cougnenc 1992 - Recherche dans lexique ");
@@ -251,13 +280,14 @@
  *              Pour l'instant, il n'y en que deux :-)
  *
  */
-options( char *c )
+int
+options( int c )
 {
  char fname[127] ;
  char buf[80];
  FILE *fp ;
 
-    switch ( (int) c )
+    switch ( c )
     {
         case 'v': /* Affiche la date mise a jour dico, fichier version.dic */
 
@@ -296,6 +326,7 @@
  *
  *
  */
+ int
  countwords()
  {
     char fname[127];
@@ -357,17 +388,20 @@
  *           de l'expression pattern.
  */
 void
-lookfor ( char *pattern )
+lookfor ( byte *pattern )
 {
  FILE *fp ;
  char fname[127];
  char buf[80];
  char sbuf[80];
- byte car ;
-    
+#ifndef __FreeBSD__
+ byte car;
+#endif
     StrLwr( pattern );  /* passe en minuscules comme le dico */
+#ifndef __FreeBSD__
     car = equival (pattern[0]);
     fprintf(stderr, "Recherche %s dans la lettre %c... \n\n", pattern, car) ;
+#endif
 
     sprintf(fname, "%s%s%c%s", dict_path, sep, pattern[0], DICT_EXT ) ;
 
@@ -389,11 +423,15 @@
             continue ;
         nolf( buf );             /* supprime le line-feed */
         strcpy( sbuf, buf );     /* No accent sensitive   */
-        StrAscii( sbuf);
+        StrAscii((byte *)sbuf);
         if( fmatch(sbuf,pattern) )
         {
-            translate( buf ); /* gere terminaux....   */
+            translate( (byte *)buf ); /* gere terminaux....   */
+#ifndef __FreeBSD__
             printf("\t%s\n", beautify(buf) );
+#else
+            printf("%s\n", beautify(buf) );
+#endif
             count ++ ;
         }
     }
@@ -410,7 +448,7 @@
  *
  */
 void
-lookall ( char *pattern )
+lookall ( byte *pattern )
 {
  FILE *fp ;
  char fname[127];
@@ -445,12 +483,15 @@
                 continue ;
             nolf( buf );              /* supprime le line-feed */
             strcpy( sbuf, buf);       /* no accent sensitive  */
-            StrAscii( sbuf);
+            StrAscii((byte *)sbuf);
             if( fmatch(sbuf,pattern) )
             { 
-                translate( buf ) ;
-                buf[0] = ToUpper( buf[0] ) ;  
+                translate( (byte *)buf ) ;
+#ifndef __FreeBSD__
                 printf("\t%s\n", beautify (buf) );
+#else
+                printf("%s\n", beautify (buf) );
+#endif
                 count ++ ;
             } 
         }
@@ -469,7 +510,7 @@
  *
  *
  */
-
+void
 mybanner()
 {
     printf("\nDICO V %s (%s) - R.Cougnenc 1992\n\n", __Version__, MYOS);
@@ -484,7 +525,8 @@
  *                   et modifie buf en consequence.
  *
  */
-translate( char * buf)
+void
+translate( byte * buf)
 {
     switch ( myterm )
     {
@@ -517,14 +559,16 @@
  *                      STATIQUE, ecrasee a chaque appel, contenant le
  *                      joli resultat :-)
  */
-byte *
-beautify ( byte * str )
+char *
+beautify ( char * str )
 {
-   static byte result[ 80 ];
-   byte ville[50], code[6];
-   byte *r = ville;
+   static char result[ 80 ];
+   char ville[50], code[6];
+   char *r = ville;
 
+#ifndef __FreeBSD__
    *str = ToUpper ( *str );                 /* Premiere lettre...     */
+#endif
 
     if( ! strchr( str, '\t') )               /* Cas du nom commun      */
     {
@@ -559,6 +603,7 @@
  *            un debut d'expressions regulieres.
  *
  */
+int
 isjoker( int c ) 
 {
     switch( c )
@@ -580,6 +625,7 @@
  * nolf: Supprime un line feed a la fin d'une chaine.
  *
  */
+void
 nolf( char *str) 
 {
     while( *str )
@@ -604,7 +650,6 @@
 
 
 #define MATCH   1
-int match(char *_fname, char *_pat);
 
 int fmatch(char *_fname, char *_pat)
 {
@@ -627,7 +672,7 @@
         return(match(fname, pat + -1));
 }
 
-
+int
 match(char *_fname, char *_pat)
 {
     register char *pat, *fname;
@@ -766,6 +811,7 @@
  *
  *
  */
+void
 StrIBM ( byte *str )
 {
     while ( *str )
@@ -782,6 +828,7 @@
  *
  *
  */
+void
 StrISO ( byte *str )
 {
     while ( *str )
@@ -862,11 +909,13 @@
   0xb2,0xa4,0x20
 };
 
+void
 iso2ibm( unsigned char *c )
 {
     *c = IsoTable[ *c ] ;
 }
 
+void
 ibm2iso( unsigned char *c )
 {
     *c = TableIso[ *c ] ;
@@ -965,9 +1014,9 @@
 {
   byte *p = str ;
  
-    while (*str)
+    for (;*str;str++)
     {
-               *str = EquivalTable[ *str++ ] ;
+               *str = EquivalTable[ *str ] ;
     }
 
  return p ;
