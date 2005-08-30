--- src/io.c.orig	Sat Aug 21 12:19:29 2004
+++ src/io.c	Mon Jul 11 16:16:50 2005
@@ -307,7 +307,8 @@
 	 * A null byte was encountered in input from a network socket. This
 	 * can never happen in a normal POP3 connection. */
 	xlog_printf(xlog_adm, 0x0035, "null_byte_in_input ctx='%s' len=%d data='%s'", ioc->io_desc, len, buf);
-	errno = EPROTO;
+	/* Uh oh, nice to overload socket errcos for application level signalization */
+	errno = EPIPE;
 	return -1;
       }
     }
