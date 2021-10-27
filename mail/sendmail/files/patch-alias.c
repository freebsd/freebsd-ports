--- sendmail/alias.c.orig	2021-06-09 08:27:53 UTC
+++ sendmail/alias.c
@@ -817,10 +817,13 @@ readaliases(map, af, announcestats, logstats)
 				(void) sm_io_ungetc(af, SM_TIME_DEFAULT, c);
 			if (c != ' ' && c != '\t')
 				break;
+#if _FFR_8BITENVADDR
+			syserr("554 5.3.5 Continuation line currently not supported for USE_EAI nor _FFR_EIGHT_BIT_ADDR_OK");
+#endif
 
 			/* read continuation line */
 			if (sm_io_fgets(af, SM_TIME_DEFAULT, p,
-					sizeof(line) - (p-line)) < 0)
+					sizeof(lbuf) - (p-line)) < 0)
 				break;
 			LineNumber++;
 
