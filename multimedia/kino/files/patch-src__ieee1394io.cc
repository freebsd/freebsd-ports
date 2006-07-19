--- src/ieee1394io.cc.orig	Mon May 22 00:16:33 2006
+++ src/ieee1394io.cc	Tue Jul 18 23:29:20 2006
@@ -64,9 +64,11 @@
 #include <time.h>
 #include <sys/time.h>
 
+#if 0
 #include <libavc1394/avc1394.h>
 #include <libavc1394/avc1394_vcr.h>
 #include <libavc1394/rom1394.h>
+#endif
 
 #include "ieee1394io.h"
 #include "preferences.h"
@@ -388,6 +390,7 @@
 
 bool iec61883Reader::Open( int port )
 {
+#if 0
 	bool success;
 
 	assert( !m_handle );
@@ -409,6 +412,8 @@
 		success = false;
 	}
 	return success;
+#endif
+	return true;
 }
 
 
@@ -494,6 +499,7 @@
 
 	return 0;
 }
+#endif
 
 
 /** The thread responsible for polling the raw1394 interface.
@@ -502,14 +508,19 @@
     but only in the pthread_testcancel() function.
  
 */
+#ifdef HAVE_IEC61883
 void* iec61883Reader::ThreadProxy( void* arg )
 {
+#if 0
 	iec61883Reader* self = static_cast< iec61883Reader* >( arg );
 	return self->Thread();
+#endif
+	return NULL;
 }
 
 void* iec61883Reader::Thread()
 {
+#if 0
 	struct pollfd raw1394_poll;
 	int result;
 
@@ -531,6 +542,7 @@
 		        || ( raw1394_poll.revents & POLLPRI ) ) )
 			result = raw1394_loop_iterate( m_handle );
 	}
+#endif
 	return NULL;
 }
 #endif
@@ -617,6 +629,7 @@
 
 bool dv1394Reader::Open( int port )
 {
+#if 0
 	int n_frames = DV1394_MAX_FRAMES / 4;
 	struct dv1394_init init =
 	    {
@@ -647,6 +660,8 @@
 	}
 
 	return true;
+#endif
+	return false;
 }
 
 
@@ -655,6 +670,7 @@
 */
 void dv1394Reader::Close()
 {
+#if 0
 	if ( m_dv1394_fd != -1 )
 	{
 		if ( m_dv1394_map != NULL )
@@ -663,11 +679,13 @@
 		m_dv1394_map = NULL;
 		m_dv1394_fd = -1;
 	}
+#endif
 }
 
 
 bool dv1394Reader::StartReceive()
 {
+#if 0
 	/* Starting iso receive */
 	if ( ioctl( m_dv1394_fd, DV1394_START_RECEIVE, NULL ) )
 	{
@@ -675,6 +693,8 @@
 		return false;
 	}
 	return true;
+#endif
+	return false;
 }
 
 
@@ -683,6 +703,7 @@
 
 bool dv1394Reader::Handler( int handle )
 {
+#if 0
 	struct dv1394_status dvst;
 	struct pollfd pol;
 	int result;
@@ -769,6 +790,8 @@
 
 	}
 	return true;
+#endif
+	return false;
 }
 
 
@@ -805,6 +828,7 @@
 
 AVC::AVC( void ) : port( -1 ), totalPorts( 0 )
 {
+#if 0
 	pthread_mutex_init( &avc_mutex, NULL );
 	avc_handle = NULL;
 	struct raw1394_portinfo pinf[ 16 ];
@@ -825,6 +849,7 @@
 		avc_handle = NULL;
 		cerr << exc << endl;
 	}
+#endif
 	return;
 }
 
@@ -835,6 +860,7 @@
 
 AVC::~AVC()
 {
+#if 0
 	if ( avc_handle != NULL )
 	{
 		pthread_mutex_lock( &avc_mutex );
@@ -842,11 +868,13 @@
 		avc_handle = NULL;
 		pthread_mutex_unlock( &avc_mutex );
 	}
+#endif
 }
 
 
 extern KinoCommon *common;
 
+#if 0
 int AVC::ResetHandler( raw1394handle_t handle, unsigned int generation )
 {
 	cerr << "Reset Handler received" << endl;
@@ -854,7 +882,7 @@
 	common->getPageCapture()->driver_locked = true;
 	return 0;
 }
-
+#endif
 
 /** See if a node_id is still valid and pointing to an AV/C Recorder.
  
@@ -870,6 +898,7 @@
 int AVC::isPhyIDValid( int phyID )
 {
 	int value = -1;
+#if 0
 	int currentNode, nodeCount;
 	rom1394_directory rom1394_dir;
 
@@ -934,6 +963,7 @@
 	if ( value == -1 )
 		port = -1;
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return value;
 }
 
@@ -942,6 +972,7 @@
 */
 void AVC::Noop( void )
 {
+#if 0
 	struct pollfd raw1394_poll;
 	raw1394_poll.fd = raw1394_get_fd( avc_handle );
 	raw1394_poll.events = POLLIN | POLLPRI;
@@ -952,11 +983,13 @@
 		        || ( raw1394_poll.revents & POLLPRI ) )
 			raw1394_loop_iterate( avc_handle );
 	}
+#endif
 }
 
 
 int AVC::Play( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -968,12 +1001,14 @@
 		}
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 
 int AVC::Pause( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -990,12 +1025,14 @@
 	    };
 	nanosleep( &t, NULL );
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 
 int AVC::Stop( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1008,12 +1045,14 @@
 	    };
 	nanosleep( &t, NULL );
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 
 int AVC::Rewind( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1021,12 +1060,14 @@
 			avc1394_vcr_rewind( avc_handle, phyID );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 
 int AVC::FastForward( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1034,11 +1075,13 @@
 			avc1394_vcr_forward( avc_handle, phyID );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 int AVC::Forward( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1046,11 +1089,13 @@
 			avc1394_vcr_next( avc_handle, phyID );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 int AVC::Back( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1058,11 +1103,13 @@
 			avc1394_vcr_previous( avc_handle, phyID );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 int AVC::NextScene( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1070,11 +1117,13 @@
 			avc1394_vcr_next_index( avc_handle, phyID );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 int AVC::PreviousScene( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1082,11 +1131,13 @@
 			avc1394_vcr_previous_index( avc_handle, phyID );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 int AVC::Record( int phyID )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1094,11 +1145,13 @@
 			avc1394_vcr_record( avc_handle, phyID );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 int AVC::Shuttle( int phyID, int speed )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1106,12 +1159,14 @@
 			avc1394_vcr_trick_play( avc_handle, phyID, speed );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return 0;
 }
 
 unsigned int AVC::TransportStatus( int phyID )
 {
 	quadlet_t val = 0;
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1119,11 +1174,13 @@
 			val = avc1394_vcr_status( avc_handle, phyID );
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return val;
 }
 
 bool AVC::Timecode( int phyID, char* timecode )
 {
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1151,12 +1208,14 @@
 
 	}
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return true;
 }
 
 int AVC::getNodeId( const char *guid )
 {
 	int value = -1;
+#if 0
 	pthread_mutex_lock( &avc_mutex );
 	if ( avc_handle != NULL )
 	{
@@ -1198,6 +1257,7 @@
 	if ( value == -1 )
 		port = -1;
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return value;
 }
 
@@ -1321,6 +1381,7 @@
 int iec61883Writer::HandlerProxy( unsigned char *data, int n_dif_blocks,
 	unsigned int dropped, void *callback_data)
 {
+#if 0
 	if ( callback_data )
 	{
 		iec61883Writer* writer = static_cast< iec61883Writer* >( callback_data );
@@ -1330,6 +1391,8 @@
 	{
 		return -1;
 	}
+#endif
+	return -1;
 }
 
 
