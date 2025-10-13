--- libde265/image-io.h.orig	2025-04-26 20:58:45 UTC
+++ libde265/image-io.h
@@ -30,17 +30,17 @@ class ImageSource
 class ImageSource
 {
  public:
-  LIBDE265_API ImageSource();
-  virtual LIBDE265_API ~ImageSource();
+  ImageSource();
+  virtual ~ImageSource();
 
   //enum ImageStatus { Available, Waiting, EndOfVideo };
 
   //virtual ImageStatus  get_status() = 0;
-  virtual LIBDE265_API de265_image* get_image(bool block=true) = 0;
-  virtual LIBDE265_API void skip_frames(int n) = 0;
+  virtual de265_image* get_image(bool block=true) = 0;
+  virtual void skip_frames(int n) = 0;
 
-  virtual LIBDE265_API int get_width() const = 0;
-  virtual LIBDE265_API int get_height() const = 0;
+  virtual int get_width() const = 0;
+  virtual int get_height() const = 0;
 };
 
 
@@ -48,17 +48,17 @@ class ImageSource_YUV : public ImageSource
 class ImageSource_YUV : public ImageSource
 {
  public:
-  LIBDE265_API ImageSource_YUV();
-  virtual LIBDE265_API ~ImageSource_YUV();
+  ImageSource_YUV();
+  virtual ~ImageSource_YUV();
 
-  bool LIBDE265_API set_input_file(const char* filename, int w,int h);
+  bool set_input_file(const char* filename, int w,int h);
 
   //virtual ImageStatus  get_status();
-  virtual LIBDE265_API de265_image* get_image(bool block=true);
-  virtual LIBDE265_API void skip_frames(int n);
+  virtual de265_image* get_image(bool block=true);
+  virtual void skip_frames(int n);
 
-  virtual LIBDE265_API int get_width() const;
-  virtual LIBDE265_API int get_height() const;
+  virtual int get_width() const;
+  virtual int get_height() const;
 
  private:
   FILE* mFH;
@@ -74,20 +74,20 @@ class ImageSink
 class ImageSink
 {
  public:
-  virtual LIBDE265_API ~ImageSink();
+  virtual ~ImageSink();
 
-  virtual LIBDE265_API void send_image(const de265_image* img) = 0;
+  virtual void send_image(const de265_image* img) = 0;
 };
 
 class ImageSink_YUV : public ImageSink
 {
  public:
-  LIBDE265_API ImageSink_YUV();
-  LIBDE265_API ~ImageSink_YUV();
+  ImageSink_YUV();
+  ~ImageSink_YUV();
 
-  bool LIBDE265_API set_filename(const char* filename);
+  bool set_filename(const char* filename);
 
-  virtual LIBDE265_API void send_image(const de265_image* img);
+  virtual void send_image(const de265_image* img);
 
  private:
   FILE* mFH;
@@ -98,21 +98,21 @@ class PacketSink
 class PacketSink
 {
  public:
-  virtual LIBDE265_API ~PacketSink();
+  virtual ~PacketSink();
 
-  virtual LIBDE265_API void send_packet(const uint8_t* data, int n) = 0;
+  virtual void send_packet(const uint8_t* data, int n) = 0;
 };
 
 
 class PacketSink_File : public PacketSink
 {
  public:
-  LIBDE265_API PacketSink_File();
-  virtual LIBDE265_API ~PacketSink_File();
+  PacketSink_File();
+  virtual ~PacketSink_File();
 
-  LIBDE265_API void set_filename(const char* filename);
+  void set_filename(const char* filename);
 
-  virtual LIBDE265_API void send_packet(const uint8_t* data, int n);
+  virtual void send_packet(const uint8_t* data, int n);
 
  private:
   FILE* mFH;
