--- src/apachetop.cc.orig	2005-10-15 16:23:31 UTC
+++ src/apachetop.cc
@@ -271,7 +271,7 @@ int main(int argc, char *argv[])
 	hm->create(cf.circle_size);
 	/* }}} */
 
-	memset(&gstats, (char) NULL, sizeof(gstats));
+	memset(&gstats, 0, sizeof(gstats));
 	gstats.start = time(NULL);
 
 	signal(SIGINT, &catchsig);
@@ -465,7 +465,7 @@ int main(int argc, char *argv[])
 					continue;
 				}
 
-				*nextline = (char) NULL;
+				*nextline = '\0';
 				++nextline;
 
 				/* which parser? */
