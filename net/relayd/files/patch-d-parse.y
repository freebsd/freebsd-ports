--- relayd/parse.y.orig	Tue Jun  5 20:12:20 2007
+++ relayd/parse.y	Tue Jun  5 20:12:51 2007
@@ -1561,7 +1561,7 @@
 	hints.ai_family = PF_UNSPEC;
 	hints.ai_socktype = SOCK_DGRAM; /* DUMMY */
 	error = getaddrinfo(s, NULL, &hints, &res0);
-	if (error == EAI_AGAIN || error == EAI_NODATA || error == EAI_NONAME)
+	if (error == EAI_AGAIN || error == EAI_NONAME)
 		return (0);
 	if (error) {
 		log_warnx("host_dns: could not parse \"%s\": %s", s,
