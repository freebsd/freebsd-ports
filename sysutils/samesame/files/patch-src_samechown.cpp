--- src/samechown.cpp.orig	2018-04-12 08:29:19.856800000 +0200
+++ src/samechown.cpp	2018-04-12 08:30:19.550031000 +0200
@@ -47,7 +47,7 @@
 	value = strtoul(name, &end, 10);
 	if (errno)
 		err(1, "%s", name);
-	if (*end = '\0')
+	if (*end == '\0')
 		errx(1, "%s: illegal %s name", name, type);
 	return value;
 }
@@ -76,7 +76,7 @@
 	}
 	{
 		char *s = argv[argi];
-		if (argv[argi] != '\0')	// Argument was not: ...:gid
+		if (*argv[argi] != '\0')	// Argument was not: ...:gid
 		{
 			struct passwd *pw = getpwnam(argv[argi]);
 			owner = pw != NULL ? pw->pw_uid : id(s, "user");
