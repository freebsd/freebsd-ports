--- getarg.c.orig	Sun Nov 24 04:04:44 2002
+++ getarg.c	Thu May  9 04:30:09 2002
@@ -110,7 +110,7 @@
 
 	/* Copy the arguments, ignoring the first argument (the program name) */
 	for(i = 1; i < argc; i++) {
-		len = strlen(argv[i]);
+		len = strlen(argv[i]) + 1;
 		if(!(state->argv[i - 1] = malloc(len))) {
 			/* It failed, so free the list and return */
 			while(i-- > 1) free(state->argv[i]);
@@ -199,7 +199,6 @@
 					return(state->realargv[i + 2]);
 				} else continue;
 			}
-			
 
 			/* For each character until the terminating zero */
 			for(p = &state->argv[i][1]; *p; p++) {
@@ -235,7 +234,7 @@
 					if((!*++p)&&(p = next_arg(state, i))) {
 						*p = GETARG_USEDFLAG;
 						return(state->realargv[i + 2]);
-					} else continue;
+					} else return NULL;
 				}
 			}
 
