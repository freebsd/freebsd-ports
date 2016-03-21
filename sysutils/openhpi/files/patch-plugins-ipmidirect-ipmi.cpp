--- plugins/ipmidirect/ipmi.cpp.orig	2015-09-14 22:48:31 UTC
+++ plugins/ipmidirect/ipmi.cpp
@@ -275,13 +275,11 @@ VerifySelAndEnter( void *hnd, SaHpiResou
 
 // new plugin_loader
 extern "C" {
+#pragma GCC visibility push(hidden)
 
 // ABI Interface functions
 
-static void *
-IpmiOpen( GHashTable *, unsigned int, oh_evt_queue * ) __attribute__((used));
-
-static void *
+void *
 IpmiOpen( GHashTable *handler_config, unsigned int hid, oh_evt_queue *eventq )
 {
   // open log
@@ -387,10 +385,7 @@ IpmiOpen( GHashTable *handler_config, un
 }
 
 
-static void
-IpmiClose( void * ) __attribute__((used));
-
-static void
+void
 IpmiClose( void *hnd )
 {
   dbg( "IpmiClose" );
@@ -435,10 +430,7 @@ IpmiClose( void *hnd )
 }
 
 
-static SaErrorT
-IpmiGetEvent( void * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetEvent( void *hnd )
 {
   cIpmi *ipmi = VerifyIpmi( hnd );
@@ -457,10 +449,7 @@ IpmiGetEvent( void *hnd )
 }
 
 
-static SaErrorT
-IpmiDiscoverResources( void * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiDiscoverResources( void *hnd )
 {
   cIpmi *ipmi = VerifyIpmi( hnd );
@@ -478,10 +467,7 @@ IpmiDiscoverResources( void *hnd )
 }
 
 
-static SaErrorT
-IpmiSetResourceTag( void *, SaHpiResourceIdT, SaHpiTextBufferT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetResourceTag( void *hnd, SaHpiResourceIdT id, SaHpiTextBufferT *tag )
 {
   cIpmi *ipmi = 0;
@@ -498,10 +484,7 @@ IpmiSetResourceTag( void *hnd, SaHpiReso
 }
 
 
-static SaErrorT
-IpmiSetResourceSeverity( void *, SaHpiResourceIdT, SaHpiSeverityT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetResourceSeverity( void *hnd, SaHpiResourceIdT id, SaHpiSeverityT sev )
 {
   cIpmi *ipmi = 0;
@@ -518,14 +501,7 @@ IpmiSetResourceSeverity( void *hnd, SaHp
 }
 
 
-static SaErrorT
-IpmiGetSensorReading( void *,
-                   SaHpiResourceIdT id,
-                   SaHpiSensorNumT num,
-                   SaHpiSensorReadingT *data,
-                   SaHpiEventStateT *state ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetSensorReading( void *hnd,
                    SaHpiResourceIdT id,
                    SaHpiSensorNumT num,
@@ -546,13 +522,7 @@ IpmiGetSensorReading( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetSensorThresholds( void *hnd,
-                         SaHpiResourceIdT,
-                         SaHpiSensorNumT,
-                         SaHpiSensorThresholdsT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetSensorThresholds( void                   *hnd,
                          SaHpiResourceIdT        id,
                          SaHpiSensorNumT         num,
@@ -577,13 +547,7 @@ IpmiGetSensorThresholds( void           
 }
 
 
-static SaErrorT
-IpmiSetSensorThresholds( void *,
-                         SaHpiResourceIdT,
-                         SaHpiSensorNumT,
-                         const SaHpiSensorThresholdsT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetSensorThresholds( void *hnd,
                          SaHpiResourceIdT id,
                          SaHpiSensorNumT  num,
@@ -608,13 +572,7 @@ IpmiSetSensorThresholds( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetSensorEnable( void *,
-                     SaHpiResourceIdT,
-                     SaHpiSensorNumT,
-                     SaHpiBoolT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetSensorEnable( void *hnd,
                      SaHpiResourceIdT id,
                      SaHpiSensorNumT  num,
@@ -634,13 +592,7 @@ IpmiGetSensorEnable( void *hnd,
 }
 
 
-static SaErrorT
-IpmiSetSensorEnable( void *,
-                     SaHpiResourceIdT,
-                     SaHpiSensorNumT,
-                     SaHpiBoolT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetSensorEnable( void *hnd,
                      SaHpiResourceIdT id,
                      SaHpiSensorNumT  num,
@@ -660,13 +612,7 @@ IpmiSetSensorEnable( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetSensorEventEnables( void *,
-                           SaHpiResourceIdT,
-                           SaHpiSensorNumT,
-                           SaHpiBoolT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetSensorEventEnables( void *hnd,
                            SaHpiResourceIdT id,
                            SaHpiSensorNumT  num,
@@ -686,13 +632,7 @@ IpmiGetSensorEventEnables( void *hnd,
 }
 
 
-static SaErrorT
-IpmiSetSensorEventEnables( void *,
-                           SaHpiResourceIdT,
-                           SaHpiSensorNumT,
-                           SaHpiBoolT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetSensorEventEnables( void *hnd,
                            SaHpiResourceIdT id,
                            SaHpiSensorNumT  num,
@@ -712,14 +652,7 @@ IpmiSetSensorEventEnables( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetSensorEventMasks( void *,
-                           SaHpiResourceIdT,
-                           SaHpiSensorNumT,
-                           SaHpiEventStateT *,
-                           SaHpiEventStateT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetSensorEventMasks( void *hnd,
                            SaHpiResourceIdT id,
                            SaHpiSensorNumT  num,
@@ -741,15 +674,7 @@ IpmiGetSensorEventMasks( void *hnd,
 }
 
 
-static SaErrorT
-IpmiSetSensorEventMasks( void *,
-                           SaHpiResourceIdT,
-                           SaHpiSensorNumT,
-                           SaHpiSensorEventMaskActionT,
-                           SaHpiEventStateT,
-                           SaHpiEventStateT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetSensorEventMasks( void *hnd,
                            SaHpiResourceIdT id,
                            SaHpiSensorNumT  num,
@@ -772,13 +697,7 @@ IpmiSetSensorEventMasks( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetControlState( void *, SaHpiResourceIdT,
-                     SaHpiCtrlNumT,
-                     SaHpiCtrlModeT *,
-                     SaHpiCtrlStateT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetControlState( void *hnd, SaHpiResourceIdT id,
                      SaHpiCtrlNumT num,
                      SaHpiCtrlModeT *mode,
@@ -798,13 +717,7 @@ IpmiGetControlState( void *hnd, SaHpiRes
 }
 
 
-static SaErrorT
-IpmiSetControlState( void *, SaHpiResourceIdT,
-                     SaHpiCtrlNumT,
-                     SaHpiCtrlModeT,
-                     SaHpiCtrlStateT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetControlState( void *hnd, SaHpiResourceIdT id,
                      SaHpiCtrlNumT num,
                      SaHpiCtrlModeT mode,
@@ -824,13 +737,7 @@ IpmiSetControlState( void *hnd, SaHpiRes
 }
 
 
-static SaErrorT
-IpmiGetIdrInfo( void *,
-                SaHpiResourceIdT,
-                SaHpiIdrIdT,
-                SaHpiIdrInfoT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetIdrInfo( void *hnd,
                 SaHpiResourceIdT id,
                 SaHpiIdrIdT idrid,
@@ -850,16 +757,7 @@ IpmiGetIdrInfo( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetIdrAreaHeader( void *,
-                      SaHpiResourceIdT,
-                      SaHpiIdrIdT,
-                      SaHpiIdrAreaTypeT,
-                                  SaHpiEntryIdT,
-                      SaHpiEntryIdT *,
-                      SaHpiIdrAreaHeaderT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetIdrAreaHeader( void *hnd,
                       SaHpiResourceIdT id,
                       SaHpiIdrIdT idrid,
@@ -882,14 +780,7 @@ IpmiGetIdrAreaHeader( void *hnd,
 }
 
 
-static SaErrorT
-IpmiAddIdrArea( void *,
-                SaHpiResourceIdT,
-                SaHpiIdrIdT,
-                SaHpiIdrAreaTypeT,
-                            SaHpiEntryIdT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiAddIdrArea( void *hnd,
                 SaHpiResourceIdT id,
                 SaHpiIdrIdT idrid,
@@ -910,13 +801,7 @@ IpmiAddIdrArea( void *hnd,
 }
 
 
-static SaErrorT
-IpmiDelIdrArea( void *,
-                SaHpiResourceIdT,
-                SaHpiIdrIdT,
-                            SaHpiEntryIdT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiDelIdrArea( void *hnd,
                 SaHpiResourceIdT id,
                 SaHpiIdrIdT idrid,
@@ -936,17 +821,7 @@ IpmiDelIdrArea( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetIdrField( void *,
-                 SaHpiResourceIdT,
-                 SaHpiIdrIdT,
-                 SaHpiEntryIdT,
-                 SaHpiIdrFieldTypeT,
-                 SaHpiEntryIdT,
-                             SaHpiEntryIdT *,
-                 SaHpiIdrFieldT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetIdrField( void *hnd,
                  SaHpiResourceIdT id,
                  SaHpiIdrIdT idrid,
@@ -970,13 +845,7 @@ IpmiGetIdrField( void *hnd,
 }
 
 
-static SaErrorT
-IpmiAddIdrField( void *,
-                 SaHpiResourceIdT,
-                 SaHpiIdrIdT,
-                 SaHpiIdrFieldT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiAddIdrField( void *hnd,
                  SaHpiResourceIdT id,
                  SaHpiIdrIdT idrid,
@@ -996,13 +865,7 @@ IpmiAddIdrField( void *hnd,
 }
 
 
-static SaErrorT
-IpmiSetIdrField( void *,
-                 SaHpiResourceIdT,
-                 SaHpiIdrIdT,
-                 SaHpiIdrFieldT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetIdrField( void *hnd,
                  SaHpiResourceIdT id,
                  SaHpiIdrIdT idrid,
@@ -1022,14 +885,7 @@ IpmiSetIdrField( void *hnd,
 }
 
 
-static SaErrorT
-IpmiDelIdrField( void *,
-                 SaHpiResourceIdT,
-                 SaHpiIdrIdT,
-                 SaHpiEntryIdT,
-                 SaHpiEntryIdT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiDelIdrField( void *hnd,
                  SaHpiResourceIdT id,
                  SaHpiIdrIdT idrid,
@@ -1050,12 +906,7 @@ IpmiDelIdrField( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetSelInfo( void *,
-                SaHpiResourceIdT,
-                SaHpiEventLogInfoT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetSelInfo( void *hnd,
                 SaHpiResourceIdT id,
                 SaHpiEventLogInfoT   *info )
@@ -1074,10 +925,7 @@ IpmiGetSelInfo( void *hnd,
 }
 
 
-static SaErrorT
-IpmiSetSelTime( void *, SaHpiResourceIdT, SaHpiTimeT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetSelTime( void *hnd, SaHpiResourceIdT id, SaHpiTimeT t )
 {
   cIpmi *ipmi = 0;
@@ -1094,11 +942,7 @@ IpmiSetSelTime( void *hnd, SaHpiResource
 }
 
 
-static SaErrorT
-IpmiAddSelEntry( void *, SaHpiResourceIdT,
-                 const SaHpiEventT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiAddSelEntry( void *hnd, SaHpiResourceIdT id,
                  const SaHpiEventT *Event )
 {
@@ -1116,11 +960,7 @@ IpmiAddSelEntry( void *hnd, SaHpiResourc
 }
 
 #ifdef NOTUSED
-static SaErrorT
-IpmiDelSelEntry( void *, SaHpiResourceIdT,
-                 SaHpiEventLogEntryIdT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiDelSelEntry( void *hnd, SaHpiResourceIdT id,
                  SaHpiEventLogEntryIdT sid )
 {
@@ -1139,15 +979,7 @@ IpmiDelSelEntry( void *hnd, SaHpiResourc
 #endif
 
 
-static SaErrorT
-IpmiGetSelEntry( void *hnd, SaHpiResourceIdT,
-                 SaHpiEventLogEntryIdT,
-                 SaHpiEventLogEntryIdT *, SaHpiEventLogEntryIdT *,
-                 SaHpiEventLogEntryT *,
-                 SaHpiRdrT *,
-                 SaHpiRptEntryT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetSelEntry( void *hnd, SaHpiResourceIdT id,
                  SaHpiEventLogEntryIdT current,
                  SaHpiEventLogEntryIdT *prev, SaHpiEventLogEntryIdT *next,
@@ -1169,10 +1001,7 @@ IpmiGetSelEntry( void *hnd, SaHpiResourc
 }
 
 
-static SaErrorT
-IpmiClearSel( void *, SaHpiResourceIdT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiClearSel( void *hnd, SaHpiResourceIdT id )
 {
   cIpmi *ipmi = 0;
@@ -1188,11 +1017,7 @@ IpmiClearSel( void *hnd, SaHpiResourceId
   return rv;
 }
 
-static SaErrorT
-IpmiHotswapPolicyCancel( void *, SaHpiResourceIdT,
-                         SaHpiTimeoutT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiHotswapPolicyCancel( void *hnd, SaHpiResourceIdT id,
                          SaHpiTimeoutT timeout)
 {
@@ -1209,10 +1034,7 @@ IpmiHotswapPolicyCancel( void *hnd, SaHp
   return rv;
 }
 
-static SaErrorT
-IpmiSetAutoInsertTimeout( void *, SaHpiTimeoutT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetAutoInsertTimeout( void *hnd, SaHpiTimeoutT  timeout)
 {
   cIpmi *ipmi = VerifyIpmi( hnd );
@@ -1227,11 +1049,7 @@ IpmiSetAutoInsertTimeout( void *hnd, SaH
   return rv;
 }
 
-static SaErrorT
-IpmiGetAutoExtractTimeout( void *, SaHpiResourceIdT,
-                           SaHpiTimeoutT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetAutoExtractTimeout( void *hnd, SaHpiResourceIdT id,
                            SaHpiTimeoutT *timeout )
 {
@@ -1248,11 +1066,7 @@ IpmiGetAutoExtractTimeout( void *hnd, Sa
   return rv;
 }
 
-static SaErrorT
-IpmiSetAutoExtractTimeout( void *, SaHpiResourceIdT,
-                           SaHpiTimeoutT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetAutoExtractTimeout( void *hnd, SaHpiResourceIdT id,
                            SaHpiTimeoutT timeout )
 {
@@ -1269,11 +1083,7 @@ IpmiSetAutoExtractTimeout( void *hnd, Sa
   return rv;
 }
 
-static SaErrorT
-IpmiGetHotswapState( void *, SaHpiResourceIdT ,
-                     SaHpiHsStateT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetHotswapState( void *hnd, SaHpiResourceIdT id,
                      SaHpiHsStateT *state )
 {
@@ -1291,11 +1101,7 @@ IpmiGetHotswapState( void *hnd, SaHpiRes
 }
 
 
-static SaErrorT
-IpmiSetHotswapState( void *, SaHpiResourceIdT,
-                     SaHpiHsStateT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetHotswapState( void *hnd, SaHpiResourceIdT id,
                      SaHpiHsStateT state )
 {
@@ -1313,11 +1119,7 @@ IpmiSetHotswapState( void *hnd, SaHpiRes
 }
 
 
-static SaErrorT
-IpmiRequestHotswapAction( void *, SaHpiResourceIdT,
-                          SaHpiHsActionT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiRequestHotswapAction( void *hnd, SaHpiResourceIdT id,
                           SaHpiHsActionT act )
 {
@@ -1335,11 +1137,7 @@ IpmiRequestHotswapAction( void *hnd, SaH
 }
 
 
-static SaErrorT
-IpmiGetPowerState( void *, SaHpiResourceIdT,
-                   SaHpiPowerStateT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetPowerState( void *hnd, SaHpiResourceIdT id,
                    SaHpiPowerStateT *state )
 {
@@ -1357,11 +1155,7 @@ IpmiGetPowerState( void *hnd, SaHpiResou
 }
 
 
-static SaErrorT
-IpmiSetPowerState( void *, SaHpiResourceIdT,
-                   SaHpiPowerStateT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetPowerState( void *hnd, SaHpiResourceIdT id,
                    SaHpiPowerStateT state )
 {
@@ -1379,11 +1173,7 @@ IpmiSetPowerState( void *hnd, SaHpiResou
 }
 
 
-static SaErrorT
-IpmiGetIndicatorState( void *, SaHpiResourceIdT,
-                       SaHpiHsIndicatorStateT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetIndicatorState( void *hnd, SaHpiResourceIdT id,
                        SaHpiHsIndicatorStateT *state )
 {
@@ -1401,11 +1191,7 @@ IpmiGetIndicatorState( void *hnd, SaHpiR
 }
 
 
-static SaErrorT
-IpmiSetIndicatorState( void *, SaHpiResourceIdT,
-                       SaHpiHsIndicatorStateT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetIndicatorState( void *hnd, SaHpiResourceIdT id,
                        SaHpiHsIndicatorStateT state )
 {
@@ -1423,12 +1209,7 @@ IpmiSetIndicatorState( void *hnd, SaHpiR
 }
 
 
-static SaErrorT
-IpmiControlParm( void *,
-                 SaHpiResourceIdT,
-                 SaHpiParmActionT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiControlParm( void *hnd,
                  SaHpiResourceIdT id,
                  SaHpiParmActionT act )
@@ -1447,11 +1228,7 @@ IpmiControlParm( void *hnd,
 }
 
 
-static SaErrorT
-IpmiGetResetState( void *, SaHpiResourceIdT,
-                   SaHpiResetActionT * ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetResetState( void *hnd, SaHpiResourceIdT id,
                    SaHpiResetActionT *act )
 {
@@ -1469,12 +1246,7 @@ IpmiGetResetState( void *hnd, SaHpiResou
 }
 
 
-static SaErrorT
-IpmiSetResetState( void *,
-                   SaHpiResourceIdT,
-                   SaHpiResetActionT ) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetResetState( void *hnd,
                    SaHpiResourceIdT id,
                    SaHpiResetActionT act )
@@ -1492,13 +1264,7 @@ IpmiSetResetState( void *hnd,
   return rv;
 }
 
-static SaErrorT
-IpmiGetWatchdogInfo(void *,
-                    SaHpiResourceIdT,
-                    SaHpiWatchdogNumT,
-                    SaHpiWatchdogT *) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiGetWatchdogInfo(void *hnd,
                     SaHpiResourceIdT  id,
                     SaHpiWatchdogNumT num,
@@ -1513,13 +1279,7 @@ IpmiGetWatchdogInfo(void *hnd,
   return rv; 
 }
 
-static SaErrorT
-IpmiSetWatchdogInfo(void *,
-                    SaHpiResourceIdT,
-                    SaHpiWatchdogNumT,
-                    SaHpiWatchdogT *) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiSetWatchdogInfo(void *hnd,
                     SaHpiResourceIdT  id,
                     SaHpiWatchdogNumT num,
@@ -1534,12 +1294,7 @@ IpmiSetWatchdogInfo(void *hnd,
   return rv; 
 }
 
-static SaErrorT
-IpmiResetWatchdog(void *,
-                  SaHpiResourceIdT,
-                  SaHpiWatchdogNumT) __attribute__((used));
-
-static SaErrorT
+SaErrorT
 IpmiResetWatchdog(void *hnd,
                   SaHpiResourceIdT  id,
                   SaHpiWatchdogNumT num)
@@ -1554,6 +1309,7 @@ IpmiResetWatchdog(void *hnd,
 }
 
 
+#pragma GCC visibility pop
 } // new plugin_loader
 
 extern "C" {
