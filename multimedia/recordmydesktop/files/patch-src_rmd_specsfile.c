--- src/rmd_specsfile.c.orig	2008-12-14 00:15:34.000000000 +0800
+++ src/rmd_specsfile.c	2009-03-09 15:51:46.000000000 +0800
@@ -51,9 +51,9 @@
         fprintf(fp,"NoSound = %d\n",pdata->args.nosound);
         fprintf(fp,"Frequency = %d\n",pdata->args.frequency);
         fprintf(fp,"Channels = %d\n",pdata->args.channels);
-        fprintf(fp,"BufferSize = %lu\n",pdata->args.buffsize);
+        fprintf(fp,"BufferSize = %lu\n",(unsigned long)pdata->args.buffsize);
         fprintf(fp,"SoundFrameSize = %d\n",pdata->sound_framesize);
-        fprintf(fp,"PeriodSize = %lu\n",pdata->periodsize);
+        fprintf(fp,"PeriodSize = %lu\n",(unsigned long)pdata->periodsize);
         fprintf(fp,"UsedJack = %d\n",pdata->args.use_jack);
         fprintf(fp,"v_bitrate = %d\n",pdata->args.v_bitrate);
         fprintf(fp,"v_quality = %d\n",pdata->args.v_quality);
@@ -119,7 +119,8 @@
             fprintf(stderr,"Error reading Channels attribute!!!\n");
             return 1;
         }
-        if(fscanf(fp,"BufferSize = %lu\n",&pdata->args.buffsize)!=1){
+        if(fscanf(fp,"BufferSize = %lu\n",
+	    (unsigned long *)&pdata->args.buffsize)!=1){
             fprintf(stderr,"Error reading BufferSize attribute!!!\n");
             return 1;
         }
@@ -127,7 +128,8 @@
             fprintf(stderr,"Error reading SoundFrameSize attribute!!!\n");
             return 1;
         }
-        if(fscanf(fp,"PeriodSize = %lu\n",&pdata->periodsize)!=1){
+        if(fscanf(fp,"PeriodSize = %lu\n",
+	    (unsigned long *)&pdata->periodsize)!=1){
             fprintf(stderr,"Error reading PeriodSize attribute!!!\n");
             return 1;
         }
