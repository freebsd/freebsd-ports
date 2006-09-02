--- src/ieee1394io.cc.orig	Sun Jul  2 22:52:08 2006
+++ src/ieee1394io.cc	Sat Sep  2 19:32:07 2006
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
@@ -842,12 +868,14 @@
 		avc_handle = NULL;
 		pthread_mutex_unlock( &avc_mutex );
 	}
+#endif
 }
 
 extern "C" {
 	extern KinoCommon *common;
 }
 
+#if 0
 int AVC::ResetHandler( raw1394handle_t handle, unsigned int generation )
 {
 	cerr << "Reset Handler received" << endl;
@@ -855,7 +883,7 @@
 	common->getPageCapture()->driver_locked = true;
 	return 0;
 }
-
+#endif
 
 /** See if a node_id is still valid and pointing to an AV/C Recorder.
  
@@ -871,6 +899,7 @@
 int AVC::isPhyIDValid( int phyID )
 {
 	int value = -1;
+#if 0
 	int currentNode, nodeCount;
 	rom1394_directory rom1394_dir;
 
@@ -935,6 +964,7 @@
 	if ( value == -1 )
 		port = -1;
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return value;
 }
 
@@ -943,6 +973,7 @@
 */
 void AVC::Noop( void )
 {
+#if 0
 	struct pollfd raw1394_poll;
 	raw1394_poll.fd = raw1394_get_fd( avc_handle );
 	raw1394_poll.events = POLLIN | POLLPRI;
@@ -953,11 +984,13 @@
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
@@ -969,12 +1002,14 @@
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
@@ -991,12 +1026,14 @@
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
@@ -1009,12 +1046,14 @@
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
@@ -1022,12 +1061,14 @@
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
@@ -1035,11 +1076,13 @@
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
@@ -1047,11 +1090,13 @@
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
@@ -1059,11 +1104,13 @@
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
@@ -1071,11 +1118,13 @@
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
@@ -1083,11 +1132,13 @@
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
@@ -1095,11 +1146,13 @@
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
@@ -1107,12 +1160,14 @@
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
@@ -1120,11 +1175,13 @@
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
@@ -1152,12 +1209,14 @@
 
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
@@ -1199,6 +1258,7 @@
 	if ( value == -1 )
 		port = -1;
 	pthread_mutex_unlock( &avc_mutex );
+#endif
 	return value;
 }
 
@@ -1322,6 +1382,7 @@
 int iec61883Writer::HandlerProxy( unsigned char *data, int n_dif_blocks,
 	unsigned int dropped, void *callback_data)
 {
+#if 0
 	if ( callback_data )
 	{
 		iec61883Writer* writer = static_cast< iec61883Writer* >( callback_data );
@@ -1331,6 +1392,8 @@
 	{
 		return -1;
 	}
+#endif
+	return -1;
 }
 
 
