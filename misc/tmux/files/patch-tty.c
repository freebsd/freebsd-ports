--- tty.c.orig	2008-07-03 07:48:22.000000000 +0800
+++ tty.c	2008-07-03 07:48:46.000000000 +0800
@@ -85,9 +85,9 @@
 	if (tcgetattr(tty->fd, &tty->tio) != 0)
 		fatal("tcgetattr failed");
 	memcpy(&tio, &tty->tio, sizeof tio);
-	tio.c_iflag &= ~(IXON|IXOFF|ICRNL|INLCR|IGNCR|IMAXBEL|IUCLC|ISTRIP);
+	tio.c_iflag &= ~(IXON|IXOFF|ICRNL|INLCR|IGNCR|IMAXBEL|ISTRIP);
 	tio.c_iflag |= IGNBRK;
-	tio.c_oflag &= ~(OPOST|ONLCR|OCRNL|ONLRET|OLCUC);
+	tio.c_oflag &= ~(OPOST|ONLCR|OCRNL|ONLRET);
 	tio.c_lflag &= ~(IEXTEN|ICANON|ECHO|ECHOE|ECHONL|ECHOCTL|ECHOPRT|ECHOKE|ECHOCTL|ISIG);
 	tio.c_cc[VMIN] = 1;
         tio.c_cc[VTIME] = 0;
