Index: kdc/main.c
===================================================================
RCS file: /cvs/krbdev/krb5/src/kdc/main.c,v
retrieving revision 5.99.4.1
diff -u -r5.99.4.1 main.c
--- kdc/main.c	2001/09/26 00:46:11	5.99.4.1
+++ kdc/main.c	2002/10/15 23:32:45
@@ -559,7 +559,7 @@
 usage(name)
 char *name;
 {
-    fprintf(stderr, "usage: %s [-d dbpathname] [-r dbrealmname] [-R replaycachename ]\n\t[-m] [-k masterenctype] [-M masterkeyname] [-p port] [-4 v4mode] [-n]\n", name);
+    fprintf(stderr, "usage: %s [-d dbpathname] [-r dbrealmname] [-R replaycachename ]\n\t[-m] [-k masterenctype] [-M masterkeyname] [-p port] [-4 v4mode] [-X] [-n]\n", name);
     return;
 }
 
@@ -611,7 +611,7 @@
      * Loop through the option list.  Each time we encounter a realm name,
      * use the previously scanned options to fill in for defaults.
      */
-    while ((c = getopt(argc, argv, "r:d:mM:k:R:e:p:s:n4:3")) != -1) {
+    while ((c = getopt(argc, argv, "r:d:mM:k:R:e:p:s:n4:X3")) != -1) {
 	switch(c) {
 	case 'r':			/* realm name for db */
 	    if (!find_realm_data(optarg, (krb5_ui_4) strlen(optarg))) {
@@ -661,6 +661,11 @@
 	    v4mode = strdup(optarg);
 #endif
 	    break;
+	case 'X':
+#ifdef KRB5_KRB4_COMPAT
+		enable_v4_crossrealm(argv[0]);
+#endif
+		break;
 	case '3':
 #ifdef ATHENA_DES3_KLUDGE
 	    if (krb5_enctypes_list[krb5_enctypes_length-1].etype
