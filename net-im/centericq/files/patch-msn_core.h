--- blip-0.1/msn_core.h.orig	Sat Dec 14 07:58:06 2002
+++ blip-0.1/msn_core.h	Thu Oct 23 20:02:19 2003
@@ -24,6 +24,49 @@
   ~char_data() { if(c!=NULL) { delete c; } }
 };
 
+class callback_data
+{};
+
+class callback : public llist_data
+{
+  public:
+  int trid;
+  void (*func)(struct msnconn * conn, int trid, char ** args, int numargs, callback_data * data);
+  callback_data * data; // just gets passed
+};
+
+// Intermediate steps in synchronisation
+class syncinfo : public callback_data
+{
+  public:
+
+  llist * fl;
+  llist * rl;
+  llist * al;
+  llist * bl;
+
+  unsigned int complete;
+
+  int serial;
+  int nContacts;
+  int nGroups;
+  int nFound;
+
+  char *last_user_handled;
+
+  char blp;
+  char gtc;
+
+  syncinfo() { nFound = 0; nContacts = 0; blp='A'; gtc='A'; fl=rl=al=bl=NULL; complete=0; serial=0; }
+  ~syncinfo()
+  {
+    if(fl!=NULL) { delete fl; }
+    if(rl!=NULL) { delete rl; }
+    if(al!=NULL) { delete al; }
+    if(bl!=NULL) { delete bl; }
+  }
+};
+
 class message : public llist_data // This class encapsulates all that you need to know (tm) about a MSG
 {
   public:
@@ -81,14 +124,17 @@
   public:
   int sock; // Socket (durr...)
   int type; // one of the #defines below
+  int sync; // syncing
   int ready;
+
+  syncinfo *sync_info;
   llist * users; // Users in this session - only for SB connections
   llist * invitations_out; // invitations extended but not responded to
   llist * invitations_in; // invitations received but not responded to
   llist * callbacks;
   authdata * auth;
 
-  msnconn() { users=NULL; callbacks=NULL; invitations_out=NULL; invitations_in=NULL; }
+  msnconn() { sync = 0; users=NULL; callbacks=NULL; invitations_out=NULL; invitations_in=NULL; }
   ~msnconn()
   {
     if(users!=NULL) { delete users; }
@@ -177,17 +223,6 @@
 #define MSNFTP_SEND 1
 #define MSNFTP_RECV 2
 
-class callback_data
-{};
-
-class callback : public llist_data
-{
-  public:
-  int trid;
-  void (*func)(struct msnconn * conn, int trid, char ** args, int numargs, callback_data * data);
-  callback_data * data; // just gets passed
-};
-
 
 extern llist * connections;
 extern int next_trid;
@@ -224,33 +259,6 @@
 
 #define COMPLETE_BLP 16
 #define COMPLETE_GTC 32
-
-// Intermediate steps in synchronisation
-class syncinfo : public callback_data
-{
-  public:
-
-  llist * fl;
-  llist * rl;
-  llist * al;
-  llist * bl;
-
-  unsigned int complete;
-
-  int serial;
-
-  char blp;
-  char gtc;
-
-  syncinfo() { blp='A'; gtc='A'; fl=rl=al=bl=NULL; complete=0; serial=0; }
-  ~syncinfo()
-  {
-    if(fl!=NULL) { delete fl; }
-    if(rl!=NULL) { delete rl; }
-    if(al!=NULL) { delete al; }
-    if(bl!=NULL) { delete bl; }
-  }
-};
 
 void msn_set_friendlyname(msnconn * conn, const char * friendlyname);
 
