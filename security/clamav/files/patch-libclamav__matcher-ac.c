--- libclamav/matcher-ac.c.orig	Mon Apr  9 19:16:01 2007
+++ libclamav/matcher-ac.c	Mon Apr  9 19:25:18 2007
@@ -301,7 +301,7 @@
 
 int cli_ac_initdata(struct cli_ac_data *data, unsigned int partsigs, unsigned int tracklen)
 {
-	unsigned int i, j;
+	unsigned int i;
 
 
     if(!data) {
@@ -366,30 +366,26 @@
      * allocation in cli_ac_scanbuff()
      */
 
-    for(i = 0; i < partsigs; i++) {
-	data->partoff[i] = (unsigned int *) cli_calloc(tracklen, sizeof(unsigned int));
+    data->partoff[0] = (unsigned int *) cli_calloc(partsigs * tracklen, sizeof(unsigned int));
 
-	if(!data->partoff[i]) {
-	    for(j = 0; j < i; j++)
-		free(data->partoff[j]);
-
-	    free(data->partoff);
-	    free(data->partcnt);
-	    free(data->offcnt);
-	    free(data->offidx);
-	    free(data->maxshift);
-	    cli_errmsg("cli_ac_init(): unable to cli_calloc(%u, %u)\n", tracklen, sizeof(unsigned int));
-	    return CL_EMEM;
-	}
+    if(!data->partoff[0]) {
+	free(data->partoff);
+	free(data->partcnt);
+	free(data->offcnt);
+	free(data->offidx);
+	free(data->maxshift);
+	cli_errmsg("cli_ac_init(): unable to cli_calloc(%u, %u)\n", partsigs * tracklen, sizeof(unsigned int));
+	return CL_EMEM;
     }
 
+    for(i = 0; i < partsigs; i++)
+	data->partoff[i] = data->partoff[0] + tracklen * i;
+
     return CL_SUCCESS;
 }
 
 void cli_ac_freedata(struct cli_ac_data *data)
 {
-	unsigned int i;
-
 
     if(data && data->partsigs) {
 	free(data->partcnt);
@@ -397,9 +393,7 @@
 	free(data->offidx);
 	free(data->maxshift);
 
-	for(i = 0; i < data->partsigs; i++)
-	    free(data->partoff[i]);
-
+	free(data->partoff[0]);
 	free(data->partoff);
     }
 }
