--- chrome/renderer/pepper/ppb_pdf_impl.cc.orig	2012-02-01 21:17:28.000000000 +0200
+++ chrome/renderer/pepper/ppb_pdf_impl.cc	2012-02-01 21:18:02.000000000 +0200
@@ -43,7 +43,7 @@
 
 namespace chrome {
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class PrivateFontFile : public ppapi::Resource {
  public:
   PrivateFontFile(PP_Instance instance, int fd) : Resource(instance), fd_(fd) {
@@ -187,7 +187,7 @@
     PP_Instance instance_id,
     const PP_FontDescription_Dev* description,
     PP_PrivateFontCharset charset) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Validate the instance before using it below.
   if (!HostGlobals::Get()->GetInstance(instance_id))
     return 0;
@@ -219,7 +219,7 @@
                                     uint32_t table,
                                     void* output,
                                     uint32_t* output_length) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ppapi::Resource* resource =
       PpapiGlobals::Get()->GetResourceTracker()->GetResource(font_file);
   if (!resource)
