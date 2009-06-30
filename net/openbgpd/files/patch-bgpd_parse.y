Index: bgpd/parse.y
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/parse.y,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/parse.y	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/parse.y	30 Jun 2009 06:40:07 -0000	1.2
@@ -523,11 +523,16 @@ conf_main	: AS as4number		{
 			free($4);
 		}
 		| RTABLE NUMBER {
+#if defined(__FreeBSD__)	/* FreeBSD does not support RTABLE */
+			yyerror("rtable id not supported in FreeBSD, yet");
+			YYERROR;
+#else
 			if ($2 > RT_TABLEID_MAX || $2 < 0) {
 				yyerror("invalid rtable id");
 				YYERROR;
 			}
 			conf->rtableid = $2;
+#endif /* defined(__FreeBSD__) */
 		}
 		;
 
