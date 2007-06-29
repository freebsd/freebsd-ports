--- resource.hh.orig	Sat Aug 21 05:41:11 1999
+++ resource.hh	Thu Jun  7 03:32:31 2007
@@ -81,8 +81,8 @@
 {
 
 public:
-    Resource::Resource(ToolWindow *);
-    Resource::~Resource(void);
+    Resource(ToolWindow *);
+    ~Resource(void);
 
     struct FRAME frame;
     struct LABEL label;
