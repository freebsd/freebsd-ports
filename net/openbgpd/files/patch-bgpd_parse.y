--- bgpd/parse.y.orig	2009-01-16 23:03:20.000000000 +0900
+++ bgpd/parse.y	2009-06-22 14:49:56.000000000 +0900
@@ -523,11 +523,16 @@
 			free($4);
 		}
 		| RTABLE NUMBER {
+#ifdef __FreeBSD__
+			yyerror("rtable id not supported in FreeBSD, yet");
+			YYERROR;
+#else
 			if ($2 > RT_TABLEID_MAX || $2 < 0) {
 				yyerror("invalid rtable id");
 				YYERROR;
 			}
 			conf->rtableid = $2;
+#endif /* __FreeBSD__ */
 		}
 		;
 
