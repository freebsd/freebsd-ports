--- src/sysdeps/freebsd.c.orig	2014-10-14 17:46:57.000000000 -0700
+++ src/sysdeps/freebsd.c	2017-03-21 00:00:48.928710000 -0700
@@ -701,9 +701,15 @@
 		     xig->xig_len > sizeof(struct xinpgen);
 		     xig = (struct xinpgen *)((char *)xig + xig->xig_len))
 			{
+#if __FreeBSD_version >= 1200026
+			struct xtcpcb *tp = (struct xtcpcb *)xig;
+			struct xinpcb *inp = &tp->xt_inp;
+			struct xsocket *so = &inp->xi_socket;
+#else
 			struct tcpcb *tp = &((struct xtcpcb *)xig)->xt_tp;
 			struct inpcb *inp = &((struct xtcpcb *)xig)->xt_inp;
 			struct xsocket *so = &((struct xtcpcb *)xig)->xt_socket;
+#endif
 
 			/* Ignore sockets for protocols other than tcp. */
 			if (so->xso_protocol != IPPROTO_TCP)
@@ -1441,7 +1447,9 @@
 		struct smbcmd cmd;
 
 		bzero(&cmd, sizeof(cmd));
+#if __FreeBSD_version < 1100070
 		cmd.data.byte_ptr = (char *)&byte;
+#endif
 		cmd.slave         = 0x5a;
 		cmd.cmd           = command;
 		if (ioctl(iodev, SMB_READB, (caddr_t)&cmd) == -1)
@@ -1449,6 +1457,9 @@
 			close(iodev);
 			return FALSE;
 			}
+#if __FreeBSD_version >= 1100070
+		byte = (u_char)cmd.rdata.byte;
+#endif
 		}
 #endif
 	else
