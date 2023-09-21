--- hashing.c.orig	2023-02-27 19:18:52 UTC
+++ hashing.c
@@ -102,7 +102,7 @@ static void initHashLibs()
 			LibMhash = 0;
 		}
 	}
-	LibRhash = dlopen("librhash.so.0",RTLD_NOW);
+	LibRhash = dlopen("librhash.so",RTLD_NOW);
 	if (LibRhash) {
 		debugmsg("found librhash\n");
 		void (*rhash_library_init)() = (void (*)(void)) dlsym(LibRhash,"rhash_library_init");
