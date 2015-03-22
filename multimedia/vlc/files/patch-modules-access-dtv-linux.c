--- modules/access/dtv/linux.c.orig
+++ modules/access/dtv/linux.c
@@ -902,8 +902,12 @@ int dvb_set_dvbs2 (dvb_device_t *d, uint
     return dvb_set_props (d, 9, DTV_CLEAR, 0, DTV_DELIVERY_SYSTEM, SYS_DVBS2,
                           DTV_FREQUENCY, freq, DTV_MODULATION, mod,
                           DTV_SYMBOL_RATE, srate, DTV_INNER_FEC, fec,
-                          DTV_PILOT, pilot, DTV_ROLLOFF, rolloff,
-                          DTV_STREAM_ID, (uint32_t)sid);
+                          DTV_PILOT, pilot, DTV_ROLLOFF, rolloff
+/* XXX what to do with old dvb headers here? */
+#ifdef DTV_STREAM_ID
+                          , DTV_STREAM_ID, (uint32_t)sid
+#endif
+                          );
 }
 
 
