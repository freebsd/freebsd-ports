--- a/ttxtsubs.c
+++ b/ttxtsubs.c
@@ -119,6 +119,7 @@ class cPluginTtxtsubs : public cPlugin, 
 public:
   cPluginTtxtsubs(void);
   virtual ~cPluginTtxtsubs();
+  void Reload(void) { StopTtxt(); StartTtxtPlay(0x000); }
 
   // -- cPlugin
   virtual const char *Version(void) { return VERSION; }
@@ -566,7 +567,9 @@ cMenuSetupTtxtsubs::cMenuSetupTtxtsubs(c
 
 cMenuSetupTtxtsubs::~cMenuSetupTtxtsubs(void)
 {
-
+  if(mTtxtsubs) {
+    mTtxtsubs->Reload();
+  }
   if(mDoStore) {
     Store();
     //    Setup.Save(); // Can't get it to write to conf file, menu item disabled.
