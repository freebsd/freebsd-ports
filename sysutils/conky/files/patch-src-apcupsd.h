--- src/apcupsd.h.orig
+++ src/apcupsd.h
@@ -49,6 +49,6 @@ typedef struct apcupsd_s {
 } APCUPSD_S, *PAPCUPSD_S;
 
 /* Service routine for the conky main thread */
-void update_apcupsd(void);
+int update_apcupsd(void);
 
 #endif /*APCUPSD_H_*/
