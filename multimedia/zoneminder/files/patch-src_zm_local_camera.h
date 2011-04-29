--- src/zm_local_camera.h.orig	2009-05-08 17:22:06.000000000 +0400
+++ src/zm_local_camera.h	2011-04-08 17:48:07.368805859 +0400
@@ -80,6 +80,14 @@ protected:
 protected:
 	static int				camera_count;
 	static int				channel_count;
+	static int				last_channel;
+static int                              m_cap_frame;
+static int                              m_cap_frame_active;
+static int                              m_sync_frame;
+static video_mbuf			m_vmb;
+static video_mmap			*m_vmm;
+static int				m_videohandle;
+static unsigned char			*m_buffer;
     static int              channels[VIDEO_MAX_FRAME];
     static int              standards[VIDEO_MAX_FRAME];
 
@@ -109,6 +117,7 @@ protected:
 
 public:
 	LocalCamera( int p_id, const std::string &device, int p_channel, int p_format, const std::string &p_method, int p_width, int p_height, int p_palette, int p_brightness, int p_contrast, int p_hue, int p_colour, bool p_capture );
+	LocalCamera( const char *p_device, int p_channel, int p_format, int p_width, int p_height, int p_palette, int p_brightness, int p_contrast, int p_hue, int p_colour, bool p_capture );
 	~LocalCamera();
 
 	void Initialise();
