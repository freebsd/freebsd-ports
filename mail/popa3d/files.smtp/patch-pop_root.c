--- pop_root.c.neu.orig	Mon Jul 16 11:55:05 2001
+++ pop_root.c	Tue Jul 17 11:45:22 2001
@@ -210,6 +210,7 @@
 	sem=sem_attach(0x50413453);
 	sem_enter(sem);
 	db=dbopen("/etc/mail/popauth.db",O_RDWR,0664,DB_HASH,0 );
+	if ( db != NULL ) {
 	key.data=client_addr(1);
 	key.size=strlen(key.data);
 	sprintf(ts,"%d",(int)time(0));
@@ -233,6 +234,7 @@
 		ret=db->seq(db,&key,&data,R_NEXT);
 	}
 	db->close(db);
+	}
 	sem_leave(sem);
 #endif
 
