--- ospfd/parse.y.orig	2008-02-26 13:09:58.000000000 +0300
+++ ospfd/parse.y	2008-12-19 17:52:39.000000000 +0300
@@ -503,6 +503,11 @@
 
 areaoptsl	: interface
 		| DEMOTE STRING	demotecount {
+#ifdef __FreeBSD__ /* XXX: FreeBSD has no carp demotion support. */
+			yyerror("FreeBSD has no CARP demotion support");
+			free($2);
+			YYERROR;
+#else
 			if ($3 < 1 || $3 > 255) {
 				yyerror("demote count out of range (1-255)");
 				free($2);
@@ -523,6 +528,7 @@
 				    area->demote_group);
 				YYERROR;
 			}
+#endif
 		}
 		| defaults
 		;
@@ -599,6 +605,11 @@
 
 interfaceoptsl	: PASSIVE		{ iface->passive = 1; }
 		| DEMOTE STRING		{
+#ifdef __FreeBSD__ /* XXX: FreeBSD has no carp demotion support */
+			yyerror("FreeBSD has no CARP demotion support");
+			free($2);
+			YYERROR;
+#else
 			if (strlcpy(iface->demote_group, $2,
 			    sizeof(iface->demote_group)) >=
 			    sizeof(iface->demote_group)) {
@@ -613,6 +624,7 @@
 				    iface->demote_group);
 				YYERROR;
 			}
+#endif
 		}
 		| defaults
 		;
