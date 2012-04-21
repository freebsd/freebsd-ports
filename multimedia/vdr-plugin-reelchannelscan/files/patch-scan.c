--- a/scan.c
+++ b/scan.c
@@ -197,7 +197,17 @@ bool cScan::StartScanning(cScanParameter
 
 #ifndef DEVICE_ATTRIBUTES
     char buffer[265];
-    snprintf(buffer, sizeof(buffer), "/dev/dvb/adapter%d/frontend0", cardnr);
+#if APIVERSNUM > 10723
+    int Adapter = -1, Frontend = -1;
+    if (!cPluginChannelscan::GetAdapterFrontend(cDevice::GetDevice(cardnr)->CardIndex(), Adapter, Frontend)) {
+       esyslog("GetAdapterFrontend() failed");
+       cMenuChannelscan::scanState = ssDeviceFailure;
+       return false;
+    }
+    snprintf(buffer, sizeof(buffer), "/dev/dvb/adapter%d/frontend%d", Adapter, Frontend);
+#else
+    snprintf(buffer, sizeof(buffer), "/dev/dvb/adapter%d/frontend0", cDevice::GetDevice(cardnr)->CardIndex());
+#endif
 
     fd_frontend = open(buffer, O_RDONLY | O_NONBLOCK);
     if (fd_frontend <= 0) {
@@ -932,12 +942,12 @@ void cScan::Action()
               char *strDate;
               asprintf(&strDate,"%s", asctime(localtime(&tt)));
               strDate[strlen(strDate)-1] = 0;
-              fprintf(fp,"\n\n%s tp=%4d, %6d(%d) TV:%4d Radio:%4d in %3d sec",strDate,i , frequency, !alreadyScanned, tvChannelNames.size()-ntv, radioChannelNames.size()-nradio, (int)difftime(t_out,t_in) );
+              fprintf(fp,"\n\n%s tp=%4d, %6d(%d) TV:%4ld Radio:%4ld in %3d sec",strDate,i , frequency, !alreadyScanned, tvChannelNames.size()-ntv, radioChannelNames.size()-nradio, (int)difftime(t_out,t_in) );
               fclose(fp);
 
               fp = fopen("/tmp/tScan.log","a");
               //fprintf(fp,"\n\n%s tp=%4d, %6d/%2d/%5d TV:%4d Radio:%4d in %3dsec",strDate,i , frequency,(*tp)->Modulation(), (*tp)->Symbolrate(), tvChannelNames.size()-ntv, radioChannelNames.size()-nradio, (int)difftime(t_out,t_in) );
-              fprintf(fp,"\n\ntp=%4d, %6d/%2d/%5d TV:%4d Radio:%4d in %3dsec new:%3d",i , frequency,(*tp)->Modulation(), (*tp)->Symbolrate(), tvChannelNames.size()-ntv, radioChannelNames.size()-nradio, (int)difftime(t_out,t_in),tvChannelNames.size()-ntv+ radioChannelNames.size()-nradio );
+              fprintf(fp,"\n\ntp=%4d, %6d/%2d/%5d TV:%4ld Radio:%4ld in %3dsec new:%3ld",i , frequency,(*tp)->Modulation(), (*tp)->Symbolrate(), tvChannelNames.size()-ntv, radioChannelNames.size()-nradio, (int)difftime(t_out,t_in),tvChannelNames.size()-ntv+ radioChannelNames.size()-nradio );
               fclose(fp);
 
               free(strDate);
