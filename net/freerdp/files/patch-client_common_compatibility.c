--- client/common/compatibility.c.orig
+++ client/common/compatibility.c
@@ -515,7 +515,7 @@
 				settings->PerformanceFlags = type;
 			}
 
-			fprintf(stderr, "-x %s -> /network ", arg->Value);
+			fprintf(stderr, "-x %s -> /network:", arg->Value);
 
 			if (type == CONNECTION_TYPE_MODEM)
 				fprintf(stderr, "modem");
