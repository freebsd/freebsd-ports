--- globals.c.old	Sun Mar 25 01:19:51 2001
+++ globals.c	Sun Mar 25 01:20:58 2001
@@ -69,9 +69,9 @@
 	anchor->pty=anchor->tty=anchor->peer=anchor->server=anchor->ping=
 		anchor->serial=anchor->lock=-1;
 	anchor->speed=B115200;
-	anchor->conffile="/etc/vpnd.conf";
+	anchor->conffile=ETC_DIR "/vpnd.conf";
 	anchor->randomdev="/dev/random";
-	anchor->keyfile="/etc/vpnd.key";
+	anchor->keyfile=ETC_DIR "/vpnd.key";
 	anchor->lkeyfile="vpnd.lcl.key";
 	anchor->rkeyfile="vpnd.rmt.key";
 	anchor->cipher=BLOWFISH;
