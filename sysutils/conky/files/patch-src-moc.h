--- src/moc.h.orig
+++ src/moc.h
@@ -40,7 +40,7 @@ struct moc_s {
 };
 extern struct moc_s moc;
 
-void update_moc(void);
+int update_moc(void);
 void free_moc(void);
 
 #endif /* MOC_H_ */
