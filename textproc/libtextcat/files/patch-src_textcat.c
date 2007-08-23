--- src/textcat.c.orig	Thu May 22 13:32:43 2003
+++ src/textcat.c	Thu Aug 23 22:47:07 2007
@@ -74,6 +74,7 @@
 typedef struct {
 
 	void **fprint;
+        char *fprint_disable;
 	uint4 size;
 	uint4 maxsize;
 
@@ -112,11 +113,21 @@
 		fp_Done( h->fprint[i] );
 	}
 	wg_free( h->fprint );
+        wg_free( h->fprint_disable );
 	wg_free( h );
 
 }
 
-extern void *textcat_Init( const char *conffile )
+/** Replaces older function */
+extern void *textcat_Init( const char *conffile ){
+    return special_textcat_Init( conffile, DEFAULT_FINGERPRINTS_PATH );
+}
+
+/**
+ * Originaly this function had only one parameter (conffile) it has been modified since OOo use
+ * Basicaly prefix is the directory path where fingerprints are stored
+ */
+extern void *special_textcat_Init( const char *conffile, const char *prefix )
 {
 	textcat_t *h;
 	char line[1024];
@@ -134,11 +145,13 @@
 	h->size = 0;
 	h->maxsize = 16;
 	h->fprint = (void **)wg_malloc( sizeof(void*) * h->maxsize );
+ h->fprint_disable = (char *)wg_malloc( sizeof(char*) * h->maxsize );   /*added to store the state of languages*/
 
 	while ( wg_getline( line, 1024, fp ) ) {
 		char *p;
 		char *segment[4];
-		int res;
+                char finger_print_file_name[512];
+                int res;
 
 		/*** Skip comments ***/
 #ifdef HAVE_STRCHR
@@ -156,17 +169,23 @@
 		/*** Ensure enough space ***/
 		if ( h->size == h->maxsize ) {
 			h->maxsize *= 2;
-			h->fprint = (void *)wg_realloc( h->fprint, sizeof(void*) * h->maxsize );
+			h->fprint = (void **)wg_realloc( h->fprint, sizeof(void*) * h->maxsize );
+                        h->fprint_disable = (char *)wg_realloc( h->fprint_disable, sizeof(char*) * h->maxsize );
 		}
 
 		/*** Load data ***/
 		if ((h->fprint[ h->size ] = fp_Init( segment[1] ))==NULL) {
 			goto ERROR;
 		}
-		if ( fp_Read( h->fprint[h->size], segment[0], 400 ) == 0 ) {
+                finger_print_file_name[0] = '\0';
+                strcat(finger_print_file_name, prefix);
+                strcat(finger_print_file_name, segment[0]);
+
+                if ( fp_Read( h->fprint[h->size], finger_print_file_name, 400 ) == 0 ) {
 			textcat_Done(h);
 			goto ERROR;
-		}		
+		}
+                h->fprint_disable[h->size] = 0xF0;  /*0xF0 is the code for enabled languages, 0x0F is for disabled*/
 		h->size++;
 	}
 
@@ -203,11 +222,18 @@
 		result = _TEXTCAT_RESULT_SHORT;
 		goto READY;
 	}
-	
+
 	/*** Calculate the score for each category. ***/
 	for (i=0; i<h->size; i++) {
-		int score = fp_Compare( h->fprint[i], unknown, threshold );
-		candidates[i].score = score;
+                int score;
+                if(h->fprint_disable[i] & 0x0F){    /*if this language is disabled*/
+                    score = MAXSCORE;
+                }
+                else{
+                    score = fp_Compare( h->fprint[i], unknown, threshold );
+                    /*printf("Score for %s : %i\n", fp_Name(h->fprint[i]), score);*/
+                }
+                candidates[i].score = score;
 		candidates[i].name = fp_Name( h->fprint[i] );
 		if ( score < minscore ) {
 			minscore = score;
