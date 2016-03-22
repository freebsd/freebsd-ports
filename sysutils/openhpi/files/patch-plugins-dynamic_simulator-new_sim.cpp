--- plugins/dynamic_simulator/new_sim.cpp.orig	2015-09-14 22:48:28 UTC
+++ plugins/dynamic_simulator/new_sim.cpp
@@ -411,11 +411,8 @@ static NewSimulatorDimi *VerifyDimiAndEn
 //@{
 // new plugin_loader
 extern "C" {
+#pragma GCC visibility push(hidden)
 
-/**
- * Alias for @ref öh_open(), implemented by @ref NewSimulatorOpen().
- **/
-static void * NewSimulatorOpen( GHashTable *, unsigned int, oh_evt_queue * ) __attribute__((used));
 
 /**
  * @fn NewSimulatorOpen( GHashTable *handler_config, unsigned int hid, 
@@ -431,7 +428,7 @@ static void * NewSimulatorOpen( GHashTab
  * 
  * @return pointer on handler if everything works successfully.  
  **/
-static void * NewSimulatorOpen( GHashTable *handler_config, unsigned int hid, 
+void * NewSimulatorOpen( GHashTable *handler_config, unsigned int hid, 
                                   oh_evt_queue *eventq ) {
    // open log
    const char  *logfile = 0;
@@ -528,17 +525,12 @@ static void * NewSimulatorOpen( GHashTab
 }
 
 /**
- * Alias for @ref öh_close(), implemented by @ref NewSimulatorClose().
- **/
-static void NewSimulatorClose( void * ) __attribute__((used));
-
-/**
  * @relate NewSimulatorClose
  * Close the plugin and clean up the allocated memory. 
  *  
  * @param hnd pointer on handler
  **/
-static void NewSimulatorClose( void *hnd ) {
+void NewSimulatorClose( void *hnd ) {
   dbg( "NewSimulatorClose" );
 
   NewSimulator *newsim = VerifyNewSimulator( hnd );
@@ -585,9 +577,7 @@ static void NewSimulatorClose( void *hnd
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetEvent( void * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetEvent( void *hnd ) {
+SaErrorT NewSimulatorGetEvent( void *hnd ) {
    dbg( "NewSimulatorGetEvent" );
    
    NewSimulator *newsim = VerifyNewSimulator( hnd );
@@ -613,9 +603,7 @@ static SaErrorT NewSimulatorGetEvent( vo
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorDiscoverResources( void * ) __attribute__((used));
-
-static SaErrorT NewSimulatorDiscoverResources( void *hnd ) {
+SaErrorT NewSimulatorDiscoverResources( void *hnd ) {
    dbg( "NewSimulatorDiscoverResources" );
    NewSimulator *newsim = VerifyNewSimulator( hnd );
 
@@ -641,9 +629,7 @@ static SaErrorT NewSimulatorDiscoverReso
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetResourceTag( void *, SaHpiResourceIdT, SaHpiTextBufferT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetResourceTag( void *hnd, SaHpiResourceIdT id, 
+SaErrorT NewSimulatorSetResourceTag( void *hnd, SaHpiResourceIdT id, 
                                              SaHpiTextBufferT *tag ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -669,9 +655,7 @@ static SaErrorT NewSimulatorSetResourceT
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetResourceSeverity( void *, SaHpiResourceIdT, SaHpiSeverityT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetResourceSeverity( void *hnd, SaHpiResourceIdT id, 
+SaErrorT NewSimulatorSetResourceSeverity( void *hnd, SaHpiResourceIdT id, 
                                                   SaHpiSeverityT sev ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -699,13 +683,7 @@ static SaErrorT NewSimulatorSetResourceS
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetSensorReading( void *,
-                                               SaHpiResourceIdT id,
-                                               SaHpiSensorNumT num,
-                                               SaHpiSensorReadingT *data,
-                                               SaHpiEventStateT *state ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSensorReading( void *hnd,
+SaErrorT NewSimulatorGetSensorReading( void *hnd,
                                                SaHpiResourceIdT id,
                                                SaHpiSensorNumT num,
                                                SaHpiSensorReadingT *data,
@@ -735,12 +713,7 @@ static SaErrorT NewSimulatorGetSensorRea
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetSensorThresholds( void *hnd,
-                                          SaHpiResourceIdT,
-                                          SaHpiSensorNumT,
-                                          SaHpiSensorThresholdsT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSensorThresholds( void *hnd,
+SaErrorT NewSimulatorGetSensorThresholds( void *hnd,
                                                   SaHpiResourceIdT id,
                                                   SaHpiSensorNumT  num,
                                                   SaHpiSensorThresholdsT *thres ) {
@@ -774,12 +747,7 @@ static SaErrorT NewSimulatorGetSensorThr
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetSensorThresholds( void *,
-                                                  SaHpiResourceIdT,
-                                                  SaHpiSensorNumT,
-                                                  const SaHpiSensorThresholdsT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetSensorThresholds( void *hnd,
+SaErrorT NewSimulatorSetSensorThresholds( void *hnd,
                                                   SaHpiResourceIdT id,
                                                   SaHpiSensorNumT  num,
                                                   const SaHpiSensorThresholdsT *thres ) {
@@ -812,12 +780,7 @@ static SaErrorT NewSimulatorSetSensorThr
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetSensorEnable( void *,
-                                              SaHpiResourceIdT,
-                                              SaHpiSensorNumT,
-                                              SaHpiBoolT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSensorEnable( void *hnd,
+SaErrorT NewSimulatorGetSensorEnable( void *hnd,
                                               SaHpiResourceIdT id,
                                               SaHpiSensorNumT  num,
                                               SaHpiBoolT       *enable ) {
@@ -846,12 +809,7 @@ static SaErrorT NewSimulatorGetSensorEna
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetSensorEnable( void *,
-                                              SaHpiResourceIdT,
-                                              SaHpiSensorNumT,
-                                              SaHpiBoolT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetSensorEnable( void *hnd,
+SaErrorT NewSimulatorSetSensorEnable( void *hnd,
                                               SaHpiResourceIdT id,
                                               SaHpiSensorNumT  num,
                                               SaHpiBoolT       enable ) {
@@ -880,12 +838,7 @@ static SaErrorT NewSimulatorSetSensorEna
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetSensorEventEnables( void *,
-                                                    SaHpiResourceIdT,
-                                                    SaHpiSensorNumT,
-                                                    SaHpiBoolT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSensorEventEnables( void *hnd,
+SaErrorT NewSimulatorGetSensorEventEnables( void *hnd,
                                                     SaHpiResourceIdT id,
                                                     SaHpiSensorNumT  num,
                                                     SaHpiBoolT       *enables ) {
@@ -913,12 +866,7 @@ static SaErrorT NewSimulatorGetSensorEve
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetSensorEventEnables( void *,
-                                                    SaHpiResourceIdT,
-                                                    SaHpiSensorNumT,
-                                                    SaHpiBoolT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetSensorEventEnables( void *hnd,
+SaErrorT NewSimulatorSetSensorEventEnables( void *hnd,
                                                     SaHpiResourceIdT id,
                                                     SaHpiSensorNumT  num,
                                                     SaHpiBoolT       enables ) {
@@ -948,13 +896,7 @@ static SaErrorT NewSimulatorSetSensorEve
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetSensorEventMasks( void *,
-                                                  SaHpiResourceIdT,
-                                                  SaHpiSensorNumT,
-                                                  SaHpiEventStateT *,
-                                                  SaHpiEventStateT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSensorEventMasks( void *hnd,
+SaErrorT NewSimulatorGetSensorEventMasks( void *hnd,
                                                   SaHpiResourceIdT id,
                                                   SaHpiSensorNumT  num,
                                                   SaHpiEventStateT *AssertEventMask,
@@ -985,14 +927,7 @@ static SaErrorT NewSimulatorGetSensorEve
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetSensorEventMasks( void *,
-                                                  SaHpiResourceIdT,
-                                                  SaHpiSensorNumT,
-                                                  SaHpiSensorEventMaskActionT,
-                                                  SaHpiEventStateT,
-                                                  SaHpiEventStateT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetSensorEventMasks( void *hnd,
+SaErrorT NewSimulatorSetSensorEventMasks( void *hnd,
                                                   SaHpiResourceIdT id,
                                                   SaHpiSensorNumT  num,
                                                   SaHpiSensorEventMaskActionT act,
@@ -1023,12 +958,7 @@ static SaErrorT NewSimulatorSetSensorEve
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetControlState( void *, SaHpiResourceIdT,
-                                              SaHpiCtrlNumT,
-                                              SaHpiCtrlModeT *,
-                                              SaHpiCtrlStateT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetControlState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetControlState( void *hnd, SaHpiResourceIdT id,
                                               SaHpiCtrlNumT num,
                                               SaHpiCtrlModeT *mode,
                                               SaHpiCtrlStateT *state ) {
@@ -1058,12 +988,7 @@ static SaErrorT NewSimulatorGetControlSt
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetControlState( void *, SaHpiResourceIdT,
-                                              SaHpiCtrlNumT,
-                                              SaHpiCtrlModeT,
-                                              SaHpiCtrlStateT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetControlState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorSetControlState( void *hnd, SaHpiResourceIdT id,
                                               SaHpiCtrlNumT num,
                                               SaHpiCtrlModeT mode,
                                               SaHpiCtrlStateT *state ) {
@@ -1094,14 +1019,7 @@ static SaErrorT NewSimulatorSetControlSt
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetNextAnnouncement(void *, 
-                                       SaHpiResourceIdT, 
-                                       SaHpiAnnunciatorNumT, 
-                                       SaHpiSeverityT, 
-                                       SaHpiBoolT, 
-                                       SaHpiAnnouncementT *) __attribute__((used));
- 
-static SaErrorT NewSimulatorGetNextAnnouncement(void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetNextAnnouncement(void *hnd, SaHpiResourceIdT id,
                                        SaHpiAnnunciatorNumT num,
                                        SaHpiSeverityT       severity,
                                        SaHpiBoolT           unAckOnly,
@@ -1132,12 +1050,7 @@ static SaErrorT NewSimulatorGetNextAnnou
  * 
  * @return HPI error code
  **/                                    
-static SaErrorT NewSimulatorGetAnnouncement(void *, SaHpiResourceIdT, 
-                                       SaHpiAnnunciatorNumT, 
-                                       SaHpiEntryIdT, 
-                                       SaHpiAnnouncementT *) __attribute__((used));
- 
-static SaErrorT NewSimulatorGetAnnouncement(void *hnd, SaHpiResourceIdT id, 
+SaErrorT NewSimulatorGetAnnouncement(void *hnd, SaHpiResourceIdT id, 
                                        SaHpiAnnunciatorNumT  num, 
                                        SaHpiEntryIdT         entryId, 
                                        SaHpiAnnouncementT    *ann) {
@@ -1168,12 +1081,7 @@ static SaErrorT NewSimulatorGetAnnouncem
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorAckAnnouncement(void *, SaHpiResourceIdT, 
-                                       SaHpiAnnunciatorNumT, 
-                                       SaHpiEntryIdT, 
-                                       SaHpiSeverityT) __attribute__((used));
- 
-static SaErrorT NewSimulatorAckAnnouncement(void *hnd, SaHpiResourceIdT id, 
+SaErrorT NewSimulatorAckAnnouncement(void *hnd, SaHpiResourceIdT id, 
                                        SaHpiAnnunciatorNumT  num, 
                                        SaHpiEntryIdT         entryId, 
                                        SaHpiSeverityT        severity) {
@@ -1203,11 +1111,7 @@ static SaErrorT NewSimulatorAckAnnouncem
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorAddAnnouncement(void *, SaHpiResourceIdT, 
-                                       SaHpiAnnunciatorNumT, 
-                                       SaHpiAnnouncementT *) __attribute__((used));
-
-static SaErrorT NewSimulatorAddAnnouncement(void *hnd, SaHpiResourceIdT id, 
+SaErrorT NewSimulatorAddAnnouncement(void *hnd, SaHpiResourceIdT id, 
                                        SaHpiAnnunciatorNumT  num, 
                                        SaHpiAnnouncementT    *ann) {
    NewSimulator *newsim;
@@ -1236,12 +1140,7 @@ static SaErrorT NewSimulatorAddAnnouncem
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorDelAnnouncement(void *, SaHpiResourceIdT, 
-                                       SaHpiAnnunciatorNumT, 
-                                       SaHpiEntryIdT, 
-                                       SaHpiSeverityT) __attribute__((used));
-
-static SaErrorT NewSimulatorDelAnnouncement(void *hnd, SaHpiResourceIdT id, 
+SaErrorT NewSimulatorDelAnnouncement(void *hnd, SaHpiResourceIdT id, 
                                        SaHpiAnnunciatorNumT  num, 
                                        SaHpiEntryIdT         entryId, 
                                        SaHpiSeverityT        severity) {
@@ -1271,11 +1170,7 @@ static SaErrorT NewSimulatorDelAnnouncem
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetAnnMode(void *, SaHpiResourceIdT, 
-                                       SaHpiAnnunciatorNumT,
-                                       SaHpiAnnunciatorModeT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetAnnMode(void *hnd, SaHpiResourceIdT id, 
+SaErrorT NewSimulatorGetAnnMode(void *hnd, SaHpiResourceIdT id, 
                                        SaHpiAnnunciatorNumT  num, 
                                        SaHpiAnnunciatorModeT *mode) {
                                        	
@@ -1304,11 +1199,7 @@ static SaErrorT NewSimulatorGetAnnMode(v
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetAnnMode(void *, SaHpiResourceIdT, 
-                                       SaHpiAnnunciatorNumT,
-                                       SaHpiAnnunciatorModeT) __attribute__((used));
-
-static SaErrorT NewSimulatorSetAnnMode(void *hnd, SaHpiResourceIdT id, 
+SaErrorT NewSimulatorSetAnnMode(void *hnd, SaHpiResourceIdT id, 
                                        SaHpiAnnunciatorNumT  num,
                                        SaHpiAnnunciatorModeT mode) {
                                        	
@@ -1337,12 +1228,7 @@ static SaErrorT NewSimulatorSetAnnMode(v
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorGetIdrInfo( void *,
-                                         SaHpiResourceIdT,
-                                         SaHpiIdrIdT,
-                                         SaHpiIdrInfoT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetIdrInfo( void *hnd,
+SaErrorT NewSimulatorGetIdrInfo( void *hnd,
                                          SaHpiResourceIdT id,
                                          SaHpiIdrIdT idrid,
                                          SaHpiIdrInfoT *idrinfo ) {
@@ -1374,15 +1260,7 @@ static SaErrorT NewSimulatorGetIdrInfo( 
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorGetIdrAreaHeader( void *,
-                                               SaHpiResourceIdT,
-                                               SaHpiIdrIdT,
-                                               SaHpiIdrAreaTypeT,
-                                               SaHpiEntryIdT,
-                                               SaHpiEntryIdT *,
-                                               SaHpiIdrAreaHeaderT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetIdrAreaHeader( void *hnd,
+SaErrorT NewSimulatorGetIdrAreaHeader( void *hnd,
                                                SaHpiResourceIdT id,
                                                SaHpiIdrIdT idrid,
                                                SaHpiIdrAreaTypeT areatype,
@@ -1415,13 +1293,7 @@ static SaErrorT NewSimulatorGetIdrAreaHe
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorAddIdrArea( void *,
-                                         SaHpiResourceIdT,
-                                         SaHpiIdrIdT,
-                                         SaHpiIdrAreaTypeT,
-                                         SaHpiEntryIdT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorAddIdrArea( void *hnd,
+SaErrorT NewSimulatorAddIdrArea( void *hnd,
                                          SaHpiResourceIdT id,
                                          SaHpiIdrIdT idrid,
                                          SaHpiIdrAreaTypeT areatype,
@@ -1452,13 +1324,7 @@ static SaErrorT NewSimulatorAddIdrArea( 
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorAddIdrAreaById( void *,
-                                         SaHpiResourceIdT,
-                                         SaHpiIdrIdT,
-                                         SaHpiIdrAreaTypeT,
-                                         SaHpiEntryIdT ) __attribute__((used));
-
-static SaErrorT NewSimulatorAddIdrAreaById( void *hnd,
+SaErrorT NewSimulatorAddIdrAreaById( void *hnd,
                                          SaHpiResourceIdT id,
                                          SaHpiIdrIdT idrid,
                                          SaHpiIdrAreaTypeT areatype,
@@ -1487,12 +1353,7 @@ static SaErrorT NewSimulatorAddIdrAreaBy
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorDelIdrArea( void *,
-                                         SaHpiResourceIdT,
-                                         SaHpiIdrIdT,
-                                         SaHpiEntryIdT ) __attribute__((used));
-
-static SaErrorT NewSimulatorDelIdrArea( void *hnd,
+SaErrorT NewSimulatorDelIdrArea( void *hnd,
                                          SaHpiResourceIdT id,
                                          SaHpiIdrIdT idrid,
                                          SaHpiEntryIdT areaid ) {
@@ -1525,16 +1386,7 @@ static SaErrorT NewSimulatorDelIdrArea( 
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorGetIdrField( void *,
-                                          SaHpiResourceIdT,
-                                          SaHpiIdrIdT,
-                                          SaHpiEntryIdT,
-                                          SaHpiIdrFieldTypeT,
-                                          SaHpiEntryIdT,
-                                          SaHpiEntryIdT *,
-                                          SaHpiIdrFieldT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetIdrField( void *hnd,
+SaErrorT NewSimulatorGetIdrField( void *hnd,
                                           SaHpiResourceIdT id,
                                           SaHpiIdrIdT idrid,
                                           SaHpiEntryIdT areaid,
@@ -1567,12 +1419,7 @@ static SaErrorT NewSimulatorGetIdrField(
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorAddIdrField( void *,
-                                          SaHpiResourceIdT,
-                                          SaHpiIdrIdT,
-                                          SaHpiIdrFieldT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorAddIdrField( void *hnd,
+SaErrorT NewSimulatorAddIdrField( void *hnd,
                                           SaHpiResourceIdT id,
                                           SaHpiIdrIdT idrid,
                                           SaHpiIdrFieldT *field ) {
@@ -1601,12 +1448,7 @@ static SaErrorT NewSimulatorAddIdrField(
  * 
  * @return HPI error code
  **/             
-static SaErrorT NewSimulatorAddIdrFieldById( void *,
-                                          SaHpiResourceIdT,
-                                          SaHpiIdrIdT,
-                                          SaHpiIdrFieldT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorAddIdrFieldById( void *hnd,
+SaErrorT NewSimulatorAddIdrFieldById( void *hnd,
                                           SaHpiResourceIdT id,
                                           SaHpiIdrIdT idrid,
                                           SaHpiIdrFieldT *field ) {
@@ -1634,12 +1476,7 @@ static SaErrorT NewSimulatorAddIdrFieldB
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorSetIdrField( void *,
-                                          SaHpiResourceIdT,
-                                          SaHpiIdrIdT,
-                                          SaHpiIdrFieldT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetIdrField( void *hnd,
+SaErrorT NewSimulatorSetIdrField( void *hnd,
                                           SaHpiResourceIdT id,
                                           SaHpiIdrIdT idrid,
                                           SaHpiIdrFieldT *field ) {
@@ -1668,13 +1505,7 @@ static SaErrorT NewSimulatorSetIdrField(
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorDelIdrField( void *,
-                                          SaHpiResourceIdT,
-                                          SaHpiIdrIdT,
-                                          SaHpiEntryIdT,
-                                          SaHpiEntryIdT ) __attribute__((used));
-
-static SaErrorT NewSimulatorDelIdrField( void *hnd,
+SaErrorT NewSimulatorDelIdrField( void *hnd,
                                           SaHpiResourceIdT id,
                                           SaHpiIdrIdT idrid,
                                           SaHpiEntryIdT areaid,
@@ -1702,11 +1533,7 @@ static SaErrorT NewSimulatorDelIdrField(
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorGetSelInfo( void *,
-                                         SaHpiResourceIdT,
-                                         SaHpiEventLogInfoT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSelInfo( void *hnd,
+SaErrorT NewSimulatorGetSelInfo( void *hnd,
                                          SaHpiResourceIdT id,
                                          SaHpiEventLogInfoT   *info ) {
 
@@ -1736,9 +1563,7 @@ static SaErrorT NewSimulatorGetSelInfo( 
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorSetSelTime( void *, SaHpiResourceIdT, SaHpiTimeT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetSelTime( void *hnd, SaHpiResourceIdT id, SaHpiTimeT t ) {
+SaErrorT NewSimulatorSetSelTime( void *hnd, SaHpiResourceIdT id, SaHpiTimeT t ) {
    SaErrorT rv = SA_ERR_HPI_INTERNAL_ERROR;
    
    NewSimulator *newsim = VerifyNewSimulator( hnd );
@@ -1766,9 +1591,7 @@ static SaErrorT NewSimulatorSetSelTime( 
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorAddSelEntry( void *, SaHpiResourceIdT, const SaHpiEventT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorAddSelEntry( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorAddSelEntry( void *hnd, SaHpiResourceIdT id,
                                           const SaHpiEventT *Event ) {
 
    SaErrorT rv = SA_ERR_HPI_INTERNAL_ERROR;
@@ -1803,15 +1626,7 @@ static SaErrorT NewSimulatorAddSelEntry(
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorGetSelEntry( void *hnd, SaHpiResourceIdT,
-                                          SaHpiEventLogEntryIdT,
-                                          SaHpiEventLogEntryIdT *, 
-                                          SaHpiEventLogEntryIdT *,
-                                          SaHpiEventLogEntryT *,
-                                          SaHpiRdrT *,
-                                          SaHpiRptEntryT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSelEntry( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetSelEntry( void *hnd, SaHpiResourceIdT id,
                                           SaHpiEventLogEntryIdT current,
                                           SaHpiEventLogEntryIdT *prev, 
                                           SaHpiEventLogEntryIdT *next,
@@ -1844,9 +1659,7 @@ static SaErrorT NewSimulatorGetSelEntry(
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorClearSel( void *, SaHpiResourceIdT ) __attribute__((used));
-
-static SaErrorT NewSimulatorClearSel( void *hnd, SaHpiResourceIdT id ) {
+SaErrorT NewSimulatorClearSel( void *hnd, SaHpiResourceIdT id ) {
    SaErrorT rv = SA_ERR_HPI_INTERNAL_ERROR;
    
    NewSimulator *newsim = VerifyNewSimulator( hnd );
@@ -1874,10 +1687,7 @@ static SaErrorT NewSimulatorClearSel( vo
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorSetSelState(void *, SaHpiResourceIdT, 
-                                         SaHpiBoolT) __attribute__((used));
-
-static SaErrorT NewSimulatorSetSelState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorSetSelState( void *hnd, SaHpiResourceIdT id,
                                           SaHpiBoolT state ) {
    SaErrorT rv = SA_ERR_HPI_INTERNAL_ERROR;
    
@@ -1906,10 +1716,7 @@ static SaErrorT NewSimulatorSetSelState(
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorGetSelState(void *, SaHpiResourceIdT, 
-                                         SaHpiBoolT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSelState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetSelState( void *hnd, SaHpiResourceIdT id,
                                           SaHpiBoolT *state ) {
    SaErrorT rv = SA_ERR_HPI_INTERNAL_ERROR;
    
@@ -1938,10 +1745,7 @@ static SaErrorT NewSimulatorGetSelState(
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorGetSelCapability(void *, SaHpiResourceIdT, 
-                             SaHpiEventLogCapabilitiesT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetSelCapability( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetSelCapability( void *hnd, SaHpiResourceIdT id,
                                           SaHpiEventLogCapabilitiesT *caps ) {
    SaErrorT rv = SA_ERR_HPI_INTERNAL_ERROR;
    
@@ -1969,10 +1773,7 @@ static SaErrorT NewSimulatorGetSelCapabi
  * 
  * @return HPI error code
  **/ 
-static SaErrorT NewSimulatorResetSelOverflow(void *, SaHpiResourceIdT) 
-                                                           __attribute__((used));
-
-static SaErrorT NewSimulatorResetSelOverflow( void *hnd, SaHpiResourceIdT id ) {
+SaErrorT NewSimulatorResetSelOverflow( void *hnd, SaHpiResourceIdT id ) {
 
    SaErrorT rv = SA_ERR_HPI_INTERNAL_ERROR;
    
@@ -2001,10 +1802,7 @@ static SaErrorT NewSimulatorResetSelOver
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorHotswapPolicyCancel( void *, SaHpiResourceIdT,
-                                                  SaHpiTimeoutT ) __attribute__((used));
-
-static SaErrorT NewSimulatorHotswapPolicyCancel( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorHotswapPolicyCancel( void *hnd, SaHpiResourceIdT id,
                                                   SaHpiTimeoutT timeout) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -2031,10 +1829,7 @@ static SaErrorT NewSimulatorHotswapPolic
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetHotswapState( void *, SaHpiResourceIdT ,
-                                              SaHpiHsStateT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetHotswapState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetHotswapState( void *hnd, SaHpiResourceIdT id,
                                               SaHpiHsStateT *state ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -2062,10 +1857,7 @@ static SaErrorT NewSimulatorGetHotswapSt
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetHotswapState( void *, SaHpiResourceIdT,
-                                              SaHpiHsStateT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetHotswapState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorSetHotswapState( void *hnd, SaHpiResourceIdT id,
                                               SaHpiHsStateT state ) {
    SaErrorT rv = SA_OK;
    NewSimulator *newsim = 0;
@@ -2104,10 +1896,7 @@ static SaErrorT NewSimulatorSetHotswapSt
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorRequestHotswapAction( void *, SaHpiResourceIdT,
-                                                   SaHpiHsActionT ) __attribute__((used));
-
-static SaErrorT NewSimulatorRequestHotswapAction( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorRequestHotswapAction( void *hnd, SaHpiResourceIdT id,
                                                    SaHpiHsActionT act ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -2136,12 +1925,7 @@ static SaErrorT NewSimulatorRequestHotsw
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetWatchdogInfo(void *,
-                                             SaHpiResourceIdT,
-                                             SaHpiWatchdogNumT,
-                                             SaHpiWatchdogT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetWatchdogInfo(void *hnd,
+SaErrorT NewSimulatorGetWatchdogInfo(void *hnd,
                                              SaHpiResourceIdT  id,
                                              SaHpiWatchdogNumT num,
                                              SaHpiWatchdogT    *watchdog) {
@@ -2167,12 +1951,7 @@ static SaErrorT NewSimulatorGetWatchdogI
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetWatchdogInfo(void *,
-                                             SaHpiResourceIdT,
-                                             SaHpiWatchdogNumT,
-                                             SaHpiWatchdogT *) __attribute__((used));
-
-static SaErrorT NewSimulatorSetWatchdogInfo(void *hnd,
+SaErrorT NewSimulatorSetWatchdogInfo(void *hnd,
                                              SaHpiResourceIdT  id,
                                              SaHpiWatchdogNumT num,
                                              SaHpiWatchdogT    *watchdog) {
@@ -2197,11 +1976,7 @@ static SaErrorT NewSimulatorSetWatchdogI
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorResetWatchdog(void *,
-                                           SaHpiResourceIdT,
-                                           SaHpiWatchdogNumT) __attribute__((used));
-
-static SaErrorT NewSimulatorResetWatchdog(void *hnd,
+SaErrorT NewSimulatorResetWatchdog(void *hnd,
                                            SaHpiResourceIdT  id,
                                            SaHpiWatchdogNumT num) {
    NewSimulator *newsim = 0;
@@ -2226,12 +2001,7 @@ static SaErrorT NewSimulatorResetWatchdo
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetFumiSpec(void *, 
-                                         SaHpiResourceIdT, 
-                                         SaHpiFumiNumT, 
-                                         SaHpiFumiSpecInfoT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetFumiSpec(void *hnd, 
+SaErrorT NewSimulatorGetFumiSpec(void *hnd, 
                                          SaHpiResourceIdT    id, 
                                          SaHpiFumiNumT       num, 
                                          SaHpiFumiSpecInfoT *spec) {
@@ -2257,12 +2027,7 @@ static SaErrorT NewSimulatorGetFumiSpec(
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetFumiServImpact(void *, 
-                                               SaHpiResourceIdT, 
-                                               SaHpiFumiNumT, 
-                                               SaHpiFumiServiceImpactDataT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetFumiServImpact(void *hnd, 
+SaErrorT NewSimulatorGetFumiServImpact(void *hnd, 
                                                SaHpiResourceIdT            id, 
                                                SaHpiFumiNumT               num, 
                                                SaHpiFumiServiceImpactDataT *impact) {
@@ -2290,13 +2055,7 @@ static SaErrorT NewSimulatorGetFumiServI
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetFumiSource(void *, 
-                                           SaHpiResourceIdT, 
-                                           SaHpiFumiNumT, 
-                                           SaHpiBankNumT, 
-                                           SaHpiTextBufferT *) __attribute__((used));
-                                           
-static SaErrorT NewSimulatorSetFumiSource(void             *hnd, 
+SaErrorT NewSimulatorSetFumiSource(void             *hnd, 
                                            SaHpiResourceIdT  id, 
                                            SaHpiFumiNumT     num, 
                                            SaHpiBankNumT     bank, 
@@ -2324,12 +2083,7 @@ static SaErrorT NewSimulatorSetFumiSourc
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorValidateFumiSource(void *, 
-                                                SaHpiResourceIdT, 
-                                                SaHpiFumiNumT, 
-                                                SaHpiBankNumT) __attribute__((used));
-
-static SaErrorT NewSimulatorValidateFumiSource(void            *hnd, 
+SaErrorT NewSimulatorValidateFumiSource(void            *hnd, 
                                                 SaHpiResourceIdT id, 
                                                 SaHpiFumiNumT    num, 
                                                 SaHpiBankNumT    bank) {
@@ -2357,13 +2111,7 @@ static SaErrorT NewSimulatorValidateFumi
  * 
  * @return HPI error code
  **/           
-static SaErrorT NewSimulatorGetFumiSource(void *, 
-                                           SaHpiResourceIdT, 
-                                           SaHpiFumiNumT, 
-                                           SaHpiBankNumT, 
-                                           SaHpiFumiSourceInfoT *) __attribute__((used));
-                                           
-static SaErrorT NewSimulatorGetFumiSource(void                *hnd, 
+SaErrorT NewSimulatorGetFumiSource(void                *hnd, 
                                            SaHpiResourceIdT     id, 
                                            SaHpiFumiNumT        num, 
                                            SaHpiBankNumT        bank, 
@@ -2394,15 +2142,7 @@ static SaErrorT NewSimulatorGetFumiSourc
  * 
  * @return HPI error code
  **/                                         
-static SaErrorT NewSimulatorGetFumiSourceComponent(void *, 
-                             SaHpiResourceIdT, 
-                             SaHpiFumiNumT, 
-                             SaHpiBankNumT, 
-                             SaHpiEntryIdT, 
-                             SaHpiEntryIdT *, 
-                             SaHpiFumiComponentInfoT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetFumiSourceComponent(void            *hnd, 
+SaErrorT NewSimulatorGetFumiSourceComponent(void            *hnd, 
                                                     SaHpiResourceIdT id, 
                                                     SaHpiFumiNumT    num, 
                                                     SaHpiBankNumT    bank, 
@@ -2433,13 +2173,7 @@ static SaErrorT NewSimulatorGetFumiSourc
  * 
  * @return HPI error code
  **/                                               
-static SaErrorT NewSimulatorGetFumiTarget(void *, 
-                                           SaHpiResourceIdT, 
-                                           SaHpiFumiNumT, 
-                                           SaHpiBankNumT, 
-                                           SaHpiFumiBankInfoT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetFumiTarget(void              *hnd, 
+SaErrorT NewSimulatorGetFumiTarget(void              *hnd, 
                                            SaHpiResourceIdT   id, 
                                            SaHpiFumiNumT      num, 
                                            SaHpiBankNumT      bank, 
@@ -2470,15 +2204,7 @@ static SaErrorT NewSimulatorGetFumiTarge
  * 
  * @return HPI error code
  **/                                      
-static SaErrorT NewSimulatorGetFumiTargetComponent(void *, 
-                                                    SaHpiResourceIdT, 
-                                                    SaHpiFumiNumT, 
-                                                    SaHpiBankNumT, 
-                                                    SaHpiEntryIdT, 
-                                                    SaHpiEntryIdT *, 
-                                                    SaHpiFumiComponentInfoT *) __attribute__((used));
-                                                    
- static SaErrorT NewSimulatorGetFumiTargetComponent(void                  *hnd, 
+SaErrorT NewSimulatorGetFumiTargetComponent(void                  *hnd, 
                                                     SaHpiResourceIdT        id, 
                                                     SaHpiFumiNumT           num, 
                                                     SaHpiBankNumT           bank, 
@@ -2508,12 +2234,7 @@ static SaErrorT NewSimulatorGetFumiTarge
  * 
  * @return HPI error code
  **/                                                                                                      
-static SaErrorT NewSimulatorGetFumiLogicalTarget(void *, 
-                                                  SaHpiResourceIdT, 
-                                                  SaHpiFumiNumT, 
-                                                  SaHpiFumiLogicalBankInfoT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetFumiLogicalTarget(void            *hnd, 
+SaErrorT NewSimulatorGetFumiLogicalTarget(void            *hnd, 
                                                   SaHpiResourceIdT id,
                                                   SaHpiFumiNumT    num, 
                                          SaHpiFumiLogicalBankInfoT *trg) {
@@ -2542,14 +2263,7 @@ static SaErrorT NewSimulatorGetFumiLogic
  * 
  * @return HPI error code
  **/                                                                                                   
-static SaErrorT NewSimulatorGetFumiLogicalTargetComponent(void *, 
-                      SaHpiResourceIdT, 
-                      SaHpiFumiNumT, 
-                      SaHpiEntryIdT, 
-                      SaHpiEntryIdT *, 
-                      SaHpiFumiLogicalComponentInfoT *) __attribute__((used));
-                                                           
-static SaErrorT NewSimulatorGetFumiLogicalTargetComponent(void         *hnd, 
+SaErrorT NewSimulatorGetFumiLogicalTargetComponent(void         *hnd, 
                                                          SaHpiResourceIdT id, 
                                                          SaHpiFumiNumT  num, 
                                                          SaHpiEntryIdT  comp, 
@@ -2577,11 +2291,7 @@ static SaErrorT NewSimulatorGetFumiLogic
  * 
  * @return HPI error code
  **/                  
-static SaErrorT NewSimulatorStartFumiBackup(void *, 
-                                             SaHpiResourceIdT, 
-                                             SaHpiFumiNumT) __attribute__((used));
-                                             
-static SaErrorT NewSimulatorStartFumiBackup(void            *hnd, 
+SaErrorT NewSimulatorStartFumiBackup(void            *hnd, 
                                              SaHpiResourceIdT id, 
                                              SaHpiFumiNumT    num) {
 
@@ -2608,13 +2318,7 @@ static SaErrorT NewSimulatorStartFumiBac
  * 
  * @return HPI error code
  **/                                            
-static SaErrorT NewSimulatorSetFumiBankOrder(void *, 
-                                              SaHpiResourceIdT, 
-                                              SaHpiFumiNumT, 
-                                              SaHpiBankNumT, 
-                                              SaHpiUint32T) __attribute__((used));
-
-static SaErrorT NewSimulatorSetFumiBankOrder(void            *hnd, 
+SaErrorT NewSimulatorSetFumiBankOrder(void            *hnd, 
                                               SaHpiResourceIdT id, 
                                               SaHpiFumiNumT    num, 
                                               SaHpiBankNumT    bank, 
@@ -2643,13 +2347,7 @@ static SaErrorT NewSimulatorSetFumiBankO
  * 
  * @return HPI error code
  **/                                              
-static SaErrorT NewSimulatorStartFumiBankCopy(void *, 
-                                               SaHpiResourceIdT, 
-                                               SaHpiFumiNumT, 
-                                               SaHpiBankNumT, 
-                                               SaHpiBankNumT) __attribute__((used));
-                                               
-static SaErrorT NewSimulatorStartFumiBankCopy(void             *hnd, 
+SaErrorT NewSimulatorStartFumiBankCopy(void             *hnd, 
                                                SaHpiResourceIdT  id, 
                                                SaHpiFumiNumT     num, 
                                                SaHpiBankNumT     bank, 
@@ -2677,12 +2375,7 @@ static SaErrorT NewSimulatorStartFumiBan
  * 
  * @return HPI error code
  **/                                                                                         
-static SaErrorT NewSimulatorStartFumiInstall(void *, 
-                                              SaHpiResourceIdT, 
-                                              SaHpiFumiNumT, 
-                                              SaHpiBankNumT) __attribute__((used));
-                                              
-static SaErrorT NewSimulatorStartFumiInstall(void             *hnd, 
+SaErrorT NewSimulatorStartFumiInstall(void             *hnd, 
                                               SaHpiResourceIdT  id, 
                                               SaHpiFumiNumT     num, 
                                               SaHpiBankNumT     bank) {
@@ -2710,13 +2403,7 @@ static SaErrorT NewSimulatorStartFumiIns
  * 
  * @return HPI error code
  **/       
-static SaErrorT NewSimulatorGetFumiStatus(void *, 
-                                           SaHpiResourceIdT, 
-                                           SaHpiFumiNumT, 
-                                           SaHpiBankNumT, 
-                                           SaHpiFumiUpgradeStatusT *) __attribute__((used));
-                                           
-static SaErrorT NewSimulatorGetFumiStatus(void                   *hnd, 
+SaErrorT NewSimulatorGetFumiStatus(void                   *hnd, 
                                            SaHpiResourceIdT        id, 
                                            SaHpiFumiNumT           num, 
                                            SaHpiBankNumT           bank, 
@@ -2744,12 +2431,7 @@ static SaErrorT NewSimulatorGetFumiStatu
  * 
  * @return HPI error code
  **/                                           
-static SaErrorT NewSimulatorStartFumiVerification(void *, 
-                                                   SaHpiResourceIdT, 
-                                                   SaHpiFumiNumT, 
-                                                   SaHpiBankNumT) __attribute__((used));
-                                                   
-static SaErrorT NewSimulatorStartFumiVerification(void            *hnd, 
+SaErrorT NewSimulatorStartFumiVerification(void            *hnd, 
                                                    SaHpiResourceIdT id, 
                                                    SaHpiFumiNumT    num, 
                                                    SaHpiBankNumT    bank) {
@@ -2774,11 +2456,7 @@ static SaErrorT NewSimulatorStartFumiVer
  * 
  * @return HPI error code
  **/                             
-static SaErrorT NewSimulatorStartFumiVerificationMain(void *, 
-                                                       SaHpiResourceIdT, 
-                                                       SaHpiFumiNumT) __attribute__((used));
-
-static SaErrorT NewSimulatorStartFumiVerificationMain(void            *hnd, 
+SaErrorT NewSimulatorStartFumiVerificationMain(void            *hnd, 
                                                        SaHpiResourceIdT id, 
                                                        SaHpiFumiNumT    num) {
 
@@ -2804,12 +2482,7 @@ static SaErrorT NewSimulatorStartFumiVer
  * 
  * @return HPI error code
  **/                                          
-static SaErrorT NewSimulatorCancelFumiUpgrade(void *, 
-                                               SaHpiResourceIdT, 
-                                               SaHpiFumiNumT, 
-                                               SaHpiBankNumT) __attribute__((used));
-                                               
-static SaErrorT NewSimulatorCancelFumiUpgrade(void            *hnd, 
+SaErrorT NewSimulatorCancelFumiUpgrade(void            *hnd, 
                                                SaHpiResourceIdT id, 
                                                SaHpiFumiNumT    num, 
                                                SaHpiBankNumT    bank) {
@@ -2835,12 +2508,7 @@ static SaErrorT NewSimulatorCancelFumiUp
  * 
  * @return HPI error code
  **/  
-static SaErrorT NewSimulatorGetFumiRollback(void *, 
-                                             SaHpiResourceIdT, 
-                                             SaHpiFumiNumT, 
-                                             SaHpiBoolT *) __attribute__((used));
-                                             
-static SaErrorT NewSimulatorGetFumiRollback(void            *hnd, 
+SaErrorT NewSimulatorGetFumiRollback(void            *hnd, 
                                              SaHpiResourceIdT id, 
                                              SaHpiFumiNumT    num, 
                                              SaHpiBoolT       *rollb) {
@@ -2867,12 +2535,7 @@ static SaErrorT NewSimulatorGetFumiRollb
  * 
  * @return HPI error code
  **/                                           
-static SaErrorT NewSimulatorSetFumiRollback(void *, 
-                                             SaHpiResourceIdT, 
-                                             SaHpiFumiNumT, 
-                                             SaHpiBoolT) __attribute__((used));
-
-static SaErrorT NewSimulatorSetFumiRollback(void            *hnd, 
+SaErrorT NewSimulatorSetFumiRollback(void            *hnd, 
                                              SaHpiResourceIdT id, 
                                              SaHpiFumiNumT    num, 
                                              SaHpiBoolT       rollb) {
@@ -2898,11 +2561,7 @@ static SaErrorT NewSimulatorSetFumiRollb
  * 
  * @return HPI error code
  **/                          
-static SaErrorT NewSimulatorStartFumiRollback(void *, 
-                                               SaHpiResourceIdT, 
-                                               SaHpiFumiNumT) __attribute__((used));
-
-static SaErrorT NewSimulatorStartFumiRollback(void            *hnd, 
+SaErrorT NewSimulatorStartFumiRollback(void            *hnd, 
                                              SaHpiResourceIdT id, 
                                              SaHpiFumiNumT    num) {
 
@@ -2927,11 +2586,7 @@ static SaErrorT NewSimulatorStartFumiRol
  * 
  * @return HPI error code
  **/                         
-static SaErrorT NewSimulatorActivateFumi(void *, 
-                                          SaHpiResourceIdT, 
-                                          SaHpiFumiNumT) __attribute__((used));
-
-static SaErrorT NewSimulatorActivateFumi(void            *hnd, 
+SaErrorT NewSimulatorActivateFumi(void            *hnd, 
                                           SaHpiResourceIdT id, 
                                           SaHpiFumiNumT    num) {
 
@@ -2957,12 +2612,7 @@ static SaErrorT NewSimulatorActivateFumi
  * 
  * @return HPI error code
  **/        
-static SaErrorT NewSimulatorStartFumiActivation(void *, 
-                                                 SaHpiResourceIdT, 
-                                                 SaHpiFumiNumT, 
-                                                 SaHpiBoolT) __attribute__((used));
-
-static SaErrorT NewSimulatorStartFumiActivation(void            *hnd, 
+SaErrorT NewSimulatorStartFumiActivation(void            *hnd, 
                                                  SaHpiResourceIdT id, 
                                                  SaHpiFumiNumT    num,
                                                  SaHpiBoolT       log) {
@@ -2989,12 +2639,7 @@ static SaErrorT NewSimulatorStartFumiAct
  * 
  * @return HPI error code
  **/                    
-static SaErrorT NewSimulatorCleanupFumi(void *, 
-                                         SaHpiResourceIdT, 
-                                         SaHpiFumiNumT, 
-                                         SaHpiBankNumT) __attribute__((used));
-                                         
-static SaErrorT NewSimulatorCleanupFumi(void            *hnd, 
+SaErrorT NewSimulatorCleanupFumi(void            *hnd, 
                                          SaHpiResourceIdT id, 
                                          SaHpiFumiNumT    num,
                                          SaHpiBankNumT    bank) {
@@ -3020,12 +2665,7 @@ static SaErrorT NewSimulatorCleanupFumi(
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetDimiInfo( void *, 
-                                          SaHpiResourceIdT, 
-                                          SaHpiDimiNumT, 
-                                          SaHpiDimiInfoT *)  __attribute__((used));
-
-static SaErrorT NewSimulatorGetDimiInfo( void            *hnd, 
+SaErrorT NewSimulatorGetDimiInfo( void            *hnd, 
                                           SaHpiResourceIdT id, 
                                           SaHpiDimiNumT    num, 
                                           SaHpiDimiInfoT   *info) {
@@ -3053,13 +2693,7 @@ static SaErrorT NewSimulatorGetDimiInfo(
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetDimiTestInfo( void *, 
-                                      SaHpiResourceIdT, 
-                                      SaHpiDimiNumT,
-                                      SaHpiDimiTestNumT, 
-                                      SaHpiDimiTestT *)  __attribute__((used));
-                                      
-static SaErrorT NewSimulatorGetDimiTestInfo( void     *hnd, 
+SaErrorT NewSimulatorGetDimiTestInfo( void     *hnd, 
                                       SaHpiResourceIdT  id, 
                                       SaHpiDimiNumT     num,
                                       SaHpiDimiTestNumT tnum, 
@@ -3088,13 +2722,7 @@ static SaErrorT NewSimulatorGetDimiTestI
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetDimiTestReadiness( void *, 
-                                     SaHpiResourceIdT, 
-                                     SaHpiDimiNumT,
-                                     SaHpiDimiTestNumT, 
-                                     SaHpiDimiReadyT *)  __attribute__((used));
-
-static SaErrorT NewSimulatorGetDimiTestReadiness( void *hnd, 
+SaErrorT NewSimulatorGetDimiTestReadiness( void *hnd, 
                                      SaHpiResourceIdT    id, 
                                      SaHpiDimiNumT       num,
                                      SaHpiDimiTestNumT   tnum, 
@@ -3124,14 +2752,7 @@ static SaErrorT NewSimulatorGetDimiTestR
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorStartDimiTest( void *, 
-                        SaHpiResourceIdT, 
-                        SaHpiDimiNumT, 
-                        SaHpiDimiTestNumT,
-                        SaHpiUint8T, 
-                        SaHpiDimiTestVariableParamsT *)  __attribute__((used));
-
-static SaErrorT NewSimulatorStartDimiTest( void    *hnd, 
+SaErrorT NewSimulatorStartDimiTest( void    *hnd, 
                         SaHpiResourceIdT             id, 
                         SaHpiDimiNumT                num, 
                         SaHpiDimiTestNumT            tnum,
@@ -3160,12 +2781,7 @@ static SaErrorT NewSimulatorStartDimiTes
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorCancelDimiTest( void *, 
-                                      SaHpiResourceIdT, 
-                                      SaHpiDimiNumT, 
-                                      SaHpiDimiTestNumT) __attribute__((used));
-
-static SaErrorT NewSimulatorCancelDimiTest( void      *hnd, 
+SaErrorT NewSimulatorCancelDimiTest( void      *hnd, 
                                       SaHpiResourceIdT  id, 
                                       SaHpiDimiNumT     num, 
                                       SaHpiDimiTestNumT tnum) {
@@ -3194,14 +2810,7 @@ static SaErrorT NewSimulatorCancelDimiTe
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetDimiTestStatus( void *, 
-                              SaHpiResourceIdT, 
-                              SaHpiDimiNumT, 
-                              SaHpiDimiTestNumT, 
-                              SaHpiDimiTestPercentCompletedT *,
-                              SaHpiDimiTestRunStatusT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetDimiTestStatus( void        *hnd, 
+SaErrorT NewSimulatorGetDimiTestStatus( void        *hnd, 
                               SaHpiResourceIdT               id, 
                               SaHpiDimiNumT                  num, 
                               SaHpiDimiTestNumT              tnum, 
@@ -3230,13 +2839,7 @@ static SaErrorT NewSimulatorGetDimiTestS
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetDimiTestResults( void *, 
-                                SaHpiResourceIdT, 
-                                SaHpiDimiNumT, 
-                                SaHpiDimiTestNumT, 
-                                SaHpiDimiTestResultsT *) __attribute__((used));
-
-static SaErrorT NewSimulatorGetDimiTestResults( void *hnd, 
+SaErrorT NewSimulatorGetDimiTestResults( void *hnd, 
                                 SaHpiResourceIdT       id, 
                                 SaHpiDimiNumT          num, 
                                 SaHpiDimiTestNumT      tnum, 
@@ -3262,10 +2865,7 @@ static SaErrorT NewSimulatorGetDimiTestR
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetAutoInsertTimeout( void *, 
-                                         SaHpiTimeoutT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetAutoInsertTimeout( void *hnd, SaHpiTimeoutT  timeout) {
+SaErrorT NewSimulatorSetAutoInsertTimeout( void *hnd, SaHpiTimeoutT  timeout) {
    NewSimulator *newsim = VerifyNewSimulator( hnd );
 
    if ( !newsim ) {
@@ -3288,10 +2888,7 @@ static SaErrorT NewSimulatorSetAutoInser
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetAutoExtractTimeout( void *, SaHpiResourceIdT,
-                                                    SaHpiTimeoutT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetAutoExtractTimeout( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetAutoExtractTimeout( void *hnd, SaHpiResourceIdT id,
                                                     SaHpiTimeoutT *timeout ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -3318,10 +2915,7 @@ static SaErrorT NewSimulatorGetAutoExtra
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetAutoExtractTimeout( void *, SaHpiResourceIdT,
-                                                    SaHpiTimeoutT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetAutoExtractTimeout( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorSetAutoExtractTimeout( void *hnd, SaHpiResourceIdT id,
                                                     SaHpiTimeoutT timeout ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -3349,10 +2943,7 @@ static SaErrorT NewSimulatorSetAutoExtra
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetPowerState( void *, SaHpiResourceIdT,
-                                            SaHpiPowerStateT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetPowerState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetPowerState( void *hnd, SaHpiResourceIdT id,
                                             SaHpiPowerStateT *state ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -3381,10 +2972,7 @@ static SaErrorT NewSimulatorGetPowerStat
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetPowerState( void *, SaHpiResourceIdT,
-                                            SaHpiPowerStateT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetPowerState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorSetPowerState( void *hnd, SaHpiResourceIdT id,
                                             SaHpiPowerStateT state ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -3413,10 +3001,7 @@ static SaErrorT NewSimulatorSetPowerStat
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetIndicatorState( void *, SaHpiResourceIdT,
-                                                SaHpiHsIndicatorStateT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetIndicatorState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetIndicatorState( void *hnd, SaHpiResourceIdT id,
                                                 SaHpiHsIndicatorStateT *state ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -3445,10 +3030,7 @@ static SaErrorT NewSimulatorGetIndicator
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetIndicatorState( void *, SaHpiResourceIdT,
-                                                SaHpiHsIndicatorStateT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetIndicatorState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorSetIndicatorState( void *hnd, SaHpiResourceIdT id,
                                                 SaHpiHsIndicatorStateT state ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -3477,11 +3059,7 @@ static SaErrorT NewSimulatorSetIndicator
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorControlParm( void *,
-                                          SaHpiResourceIdT,
-                                          SaHpiParmActionT ) __attribute__((used));
-
-static SaErrorT NewSimulatorControlParm( void *hnd,
+SaErrorT NewSimulatorControlParm( void *hnd,
                                           SaHpiResourceIdT id,
                                           SaHpiParmActionT act ) {
    NewSimulator *newsim = 0;
@@ -3511,10 +3089,7 @@ static SaErrorT NewSimulatorControlParm(
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorGetResetState( void *, SaHpiResourceIdT,
-                                            SaHpiResetActionT * ) __attribute__((used));
-
-static SaErrorT NewSimulatorGetResetState( void *hnd, SaHpiResourceIdT id,
+SaErrorT NewSimulatorGetResetState( void *hnd, SaHpiResourceIdT id,
                                             SaHpiResetActionT *act ) {
    NewSimulator *newsim = 0;
    NewSimulatorResource *res = VerifyResourceAndEnter( hnd, id, newsim );
@@ -3543,11 +3118,7 @@ static SaErrorT NewSimulatorGetResetStat
  * 
  * @return HPI error code
  **/
-static SaErrorT NewSimulatorSetResetState( void *,
-                                            SaHpiResourceIdT,
-                                            SaHpiResetActionT ) __attribute__((used));
-
-static SaErrorT NewSimulatorSetResetState( void *hnd,
+SaErrorT NewSimulatorSetResetState( void *hnd,
                                             SaHpiResourceIdT id,
                                             SaHpiResetActionT act ) {
    NewSimulator *newsim = 0;
@@ -3563,6 +3134,7 @@ static SaErrorT NewSimulatorSetResetStat
    return rv;
 }
 
+#pragma GCC visibility pop
 } // new plugin_loader
 //@}
 
