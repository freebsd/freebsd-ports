--- check_varnish.c.orig	2016-10-26 07:20:18 UTC
+++ check_varnish.c
@@ -326,7 +326,7 @@ main(int argc, char **argv)
 	VSC_Setup(vd);
 #endif
 
-	while ((opt = getopt(argc, argv, VSC_ARGS "c:hn:p:vw:")) != -1) {
+	while ((opt = getopt(argc, argv, "f:n:N:c:hn:p:vw:")) != -1) {
 		switch (opt) {
 		case 'c':
 			if (parse_range(optarg, &critical) != 0)
