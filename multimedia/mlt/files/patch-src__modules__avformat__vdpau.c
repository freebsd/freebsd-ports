--- ./src/modules/avformat/vdpau.c.orig	2011-10-31 18:26:04.000000000 +0100
+++ ./src/modules/avformat/vdpau.c	2011-11-02 03:11:43.887765075 +0100
@@ -65,6 +65,8 @@
 
 		if ( !object )
 			object = dlopen( "/usr/lib/libvdpau.so", flags );
+		if ( !object )
+			object = dlopen( "/usr/local/lib/libvdpau.so", flags );
 		if ( object )
 		{
 			VdpDeviceCreateX11 *create_device = dlsym( object, "vdp_device_create_x11" );
