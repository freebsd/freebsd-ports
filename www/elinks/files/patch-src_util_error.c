--- src/util/error.c.orig	2022-07-31 10:16:29 UTC
+++ src/util/error.c
@@ -301,26 +301,6 @@ dump_backtrace(FILE *f, int trouble)
 		fprintf(f, "[%p] %s\n", stack[i], strings[i]);
 
 	free(strings);
-
-#else
-	/* User torturation. */
-	/* You are worried about what you see here? You don't see anything in
-	 * the first place. Also, be assured that we know what are we doing. */
-	/* (We are killing the user, obviously.) */
-
-	/* TODO: Gettextify? Er, better not. More people (translators) could
-	 * find out what are we doing... ;-) --pasky */
-	/* TODO: Be more cruel when in trouble? ;-) --pasky */
-
-	fputs(	"Wheeeeeeeeeee! You played with the config.h by hand, didn't you?\n"
-		"Of _COURSE_ you did! Is that how a nice .. creature behaves like?\n"
-		"Of _COURSE_ it isn't! I feel offended and thus I will revenge now!\n"
-		"You will _suffer_ >:).\n"
-		"\n"
-		"CPU burning sequence initiated...\n", f);
-
-	/* TODO: Include cpuburn.c here. --pasky */
-	while (1);
 #endif
 	fflush(f);
 }
