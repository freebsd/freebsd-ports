--- src/IGBheader.cc.orig	Tue Oct 15 02:15:19 2002
+++ src/IGBheader.cc	Tue Oct 15 02:15:44 2002
@@ -17,8 +17,11 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 #include<stdlib.h>
+#include <iostream>
 #include "IGBheader.h"
 
+using namespace std;
+
 /* -------------- Bits de statut pour Header_Read et Header_Write ------ */
 
 #define     MOT_CLEF_INV    2
@@ -756,7 +759,7 @@
 	if (bool_comment) {
 		comment = v_comment;
 		while (*comment != NULL) {
-			n_car = gzprintf(file, "#%.80s\r\n", *comment++); 
+			n_car = gzprintf((gzFile)file, "#%.80s\r\n", *comment++); 
 			if (n_car==0) { 
 				if (!Header_Quiet) {
 					fprintf(stderr, "\nHeader_Write: Erreur a l'ecriture \n");
@@ -861,7 +864,7 @@
 			}
 
 			/* --- lit le caractere suivant --- */
-			in = gzgetc( file ) ;
+			in = gzgetc( (gzFile)file ) ;
 
 			/* --- (EOF dans l'entete) --> erreur --- */
 			if ( in == -1 ) {
@@ -1318,8 +1321,8 @@
 		}
 	}
 
-	if (gztell(file)!=1024) { 
-	    gzseek( file, 1024, SEEK_SET );
+	if (gztell((gzFile)file)!=1024) { 
+	    gzseek( (gzFile)file, 1024, SEEK_SET );
 		if (!Header_Quiet) {
 			fprintf(stderr,
 					"\nATTENTION: etiquette de grandeur non-standard \n");
@@ -1335,7 +1338,7 @@
 
 	if (bool_vect_z) {
 		v_vect_z = (float *)malloc(v_z*sizeof(float));
-		gzread(file, v_vect_z, sizeof(float)*v_z);
+		gzread((gzFile)file, v_vect_z, sizeof(float)*v_z);
 	}
 
 	return( statut ) ;
