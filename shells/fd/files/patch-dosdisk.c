This is a patch taken from [FDclone-users:00927].

diff -u ../old/FD-3.00j/dosdisk.c ./dosdisk.c
--- ../old/FD-3.00j/dosdisk.c	Sat Sep 25 00:00:00 2010
+++ ./dosdisk.c	Sun Sep 26 00:05:47 2010
@@ -2269,7 +2269,7 @@
 {
 	time_t mt;
 	u_short date, time;
-	int isnow;
+	int sec, isnow;
 
 	mt = (time_t)0;
 	isnow = 0;
@@ -2277,9 +2277,12 @@
 		t = Xtime(&mt);
 		isnow++;
 	}
-	getdostime(&date, &time, t);
+	sec = getdostime(&date, &time, t);
 
-	if (!time && isnow) time = 0x0001;
+	if (isnow) {
+		if (!time) time = 0x0001;
+		mt += (sec & 0x01) * 1000L;
+	}
 	buf[0] = time & 0xff;
 	buf[1] = (time >> 8) & 0xff;
 	buf[2] = date & 0xff;
diff -u ../old/FD-3.00j/sysemu.c ./sysemu.c
--- ../old/FD-3.00j/sysemu.c	Sat Sep 25 00:00:00 2010
+++ ./sysemu.c	Sun Sep 26 00:03:20 2010
@@ -720,7 +720,7 @@
 	return(attr);
 }
 
-VOID getdostime(dp, tp, t)
+int getdostime(dp, tp, t)
 u_short *dp, *tp;
 time_t t;
 {
@@ -733,6 +733,8 @@
 	*tp = ((tm -> tm_hour & 0x1f) << 11)
 		+ ((tm -> tm_min & 0x3f) << 5)
 		+ ((tm -> tm_sec & 0x3e) >> 1);
+
+	return(tm -> tm_sec);
 }
 #endif	/* DEP_DOSPATH */
 
diff -u ../old/FD-3.00j/sysemu.h ./sysemu.h
--- ../old/FD-3.00j/sysemu.h	Sat Sep 25 00:00:00 2010
+++ ./sysemu.h	Sat Sep 25 23:59:47 2010
@@ -58,7 +58,7 @@
 extern u_int getunixmode __P_((u_int));
 extern time_t getunixtime __P_((u_int, u_int));
 extern u_short getdosmode __P_((u_int));
-extern VOID getdostime __P_((u_short *, u_short *, time_t));
+extern int getdostime __P_((u_short *, u_short *, time_t));
 #endif
 #if	defined (DEP_DIRENT)
 extern DIR *Xopendir __P_((CONST char *));
