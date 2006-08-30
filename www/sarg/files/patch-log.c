--- log.c	Tue Aug 29 14:09:32 2006
+++ log.c	Wed Aug 30 01:34:18 2006
@@ -772,7 +772,7 @@
       while( fgets(bufz,sizeof(bufz),fp_in) != NULL ) recs1++;
       rewind(fp_in);
 
-      printf("SARG: Records in file: %d, reading: %3.2f%%\r",recs1,(float) 0);
+      printf("SARG: Records in file: %lli, reading: %3.2f%%\r",recs1,(float) 0);
       fflush( stdout ) ;
    }
    
@@ -781,7 +781,7 @@
 	if( bool_ShowReadStatistics && ! --OutputNonZero) {
            perc = recs2 * 100 ;
            perc = perc / recs1 ;
-   	   printf("SARG: Records in file: %d, reading: %3.2f%%\r",recs1,perc);
+   	   printf("SARG: Records in file: %lli, reading: %3.2f%%\r",recs1,perc);
            fflush (stdout);
            OutputNonZero = REPORT_EVERY_X_LINES ;
         }
@@ -1267,7 +1267,7 @@
         }
       }
       if( bool_ShowReadStatistics )
-        printf("SARG: Records in file: %d, reading: %3.2f%%\n",recs1, (float) 100 );
+        printf("SARG: Records in file: %lli, reading: %3.2f%%\n",recs1, (float) 100 );
    }
 
    if ( fp_Download_Unsort ) 


