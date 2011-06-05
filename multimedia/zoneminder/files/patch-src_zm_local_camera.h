--- src/zm_local_camera.h.orig	2011-02-16 00:59:06.000000000 +0300
+++ src/zm_local_camera.h	2011-05-05 18:31:35.024175230 +0400
@@ -83,6 +83,14 @@ protected:
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
 
@@ -114,6 +122,7 @@ protected:
 
 public:
 	LocalCamera( int p_id, const std::string &device, int p_channel, int p_format, const std::string &p_method, int p_width, int p_height, int p_palette, int p_brightness, int p_contrast, int p_hue, int p_colour, bool p_capture );
+	LocalCamera( const char *p_device, int p_channel, int p_format, int p_width, int p_height, int p_palette, int p_brightness, int p_contrast, int p_hue, int p_colour, bool p_capture );
 	~LocalCamera();
 
 	void Initialise();
