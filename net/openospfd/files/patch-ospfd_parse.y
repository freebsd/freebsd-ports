--- ospfd/parse.y.orig	2008-02-07 18:34:22.000000000 +0300
+++ ospfd/parse.y	2008-02-07 18:37:46.000000000 +0300
@@ -485,6 +485,11 @@
 
 areaoptsl	: interface
 		| DEMOTE STRING	demotecount {
+#ifdef __FreeBSD__ /* XXX: FreeBSD has no carp demotion support. */
+			yyerror("FreeBSD has no CARP demotion support");
+			free($2);
+			YYERROR;
+#else
 			if ($3 > 255) {
 				yyerror("demote count too big: max 255");
 				free($2);
@@ -505,6 +510,7 @@
 				    area->demote_group);
 				YYERROR;
 			}
+#endif
 		}
 		| defaults
 		;
@@ -581,6 +587,11 @@
 
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
@@ -595,6 +606,7 @@
 				    iface->demote_group);
 				YYERROR;
 			}
+#endif
 		}
 		| defaults
 		;
