--- src/core.c.orig	2023-04-02 10:14:25 UTC
+++ src/core.c
@@ -2249,12 +2249,11 @@ static int cputab_temp_fallback(Labels *data)
 		}
 	}
 #else /* __linux__ */
-	/* Tested on FreeBSD 12: https://github.com/TheTumultuousUnicornOfDarkness/CPU-X/issues/121#issuecomment-575985765 */
-	char temp[MAXSTR];
-	size_t len = sizeof(temp);
+	int dK;
+	size_t len = sizeof(dK);
 
-	if(!(err = sysctlbyname(format("dev.cpu.%i.temperature", data->current_core_id), temp, &len, NULL, 0)))
-		casprintf(&data->tab_cpu[VALUE][TEMPERATURE], true, "%s", temp);
+	if(!(err = sysctlbyname(format("dev.cpu.%i.temperature", data->current_core_id), &dK, &len, NULL, 0)))
+		casprintf(&data->tab_cpu[VALUE][TEMPERATURE], true, "%.1f°C", (dK - 2731) / 10.);
 #endif /* __linux__ */
 
 	if(err)
