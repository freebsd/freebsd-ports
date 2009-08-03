$FreeBSD$
--- parse.y.orig	2009-08-01 20:29:44.000000000 +0200
+++ parse.y	2009-08-01 21:17:58.000000000 +0200
@@ -200,6 +200,7 @@ main		: LISTEN ON address	{
 			free($2);
 		}
 		| SENSOR STRING	sensor_opts {
+#ifdef HAVE_SENSORS
 			struct ntp_conf_sensor	*s;
 
 			s = new_sensor($2);
@@ -208,6 +209,9 @@ main		: LISTEN ON address	{
 			s->refstr = $3.refstr;
 			free($2);
 			TAILQ_INSERT_TAIL(&conf->ntp_conf_sensors, s, entry);
+#else
+			yyerror("sensor devices not supported");
+#endif
 		}
 		;
 
