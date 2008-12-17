--- bgpd/parse.y	2007-05-31 20:38:58.000000000 +0200
+++ bgpd/parse.y	2008-03-18 13:27:29.000000000 +0100
@@ -523,11 +523,16 @@
 			free($4);
 		}
 		| RTABLE number {
+#ifdef __FreeBSD__
+ 			yyerror("rtable id not supported in FreeBSD, yet");
+ 			YYERROR;
+#else
 			if ($2 > RT_TABLEID_MAX || $2 < 0) {
 				yyerror("invalid rtable id");
 				YYERROR;
 			}
 			conf->rtableid = $2;
+#endif
 		}
 		;
 
