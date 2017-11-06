Avoid hang of serprog under FreeBSD

Use case is flashrom+serprog to read SPI flash (MX25L6406) via Arduino
Nano V3.  Actual command is:

/usr/local/bin/flashrom -p serprog:dev=/dev/cuaU0:57600 -c MX25L6406E/MX25L6408E -r tcw770.dump

Using flashrom 0.9.9 it hangs after 5 seconds on read from tty ("ttyin").
The problem is that kernel method "ttydisc_rint" ignore same bytes.  It
happens due to enabled IEXTEN local flag of termios.  TTY cuts few bytes,
Arduino reads 11264 bytes, but flashrom gets 11244 bytes (corrupted) and
waits for remaining 20 bytes.

The fix is simple: turn off IEXTEN local flag.

https://patchwork.coreboot.org/patch/4498/

--- serial.c.orig	2016-11-18 19:39:55 UTC
+++ serial.c
@@ -203,7 +203,7 @@ int serialport_config(fdtype fd, int bau
 	}
 	wanted.c_cflag &= ~(PARENB | CSTOPB | CSIZE | CRTSCTS);
 	wanted.c_cflag |= (CS8 | CLOCAL | CREAD);
-	wanted.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
+	wanted.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG | IEXTEN);
 	wanted.c_iflag &= ~(IXON | IXOFF | IXANY | ICRNL | IGNCR | INLCR);
 	wanted.c_oflag &= ~OPOST;
 	if (tcsetattr(fd, TCSANOW, &wanted) != 0) {
