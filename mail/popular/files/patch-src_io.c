--- src/io.c.orig	2004-08-21 10:19:29 UTC
+++ src/io.c
@@ -307,7 +307,8 @@ io_sysread(struct io_ctx *ioc, char *buf, size_t count
 	 * A null byte was encountered in input from a network socket. This
 	 * can never happen in a normal POP3 connection. */
 	xlog_printf(xlog_adm, 0x0035, "null_byte_in_input ctx='%s' len=%d data='%s'", ioc->io_desc, len, buf);
-	errno = EPROTO;
+	/* Uh oh, nice to overload socket errcos for application level signalization */
+	errno = EPIPE;
 	return -1;
       }
     }
