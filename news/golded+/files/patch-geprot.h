--- golded3/geprot.h.orig	Tue May 16 16:49:29 2006
+++ golded3/geprot.h	Thu Nov 23 11:11:14 2006
@@ -19,7 +19,7 @@
 //  Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 //  MA 02111-1307 USA
 //  ------------------------------------------------------------------
-//  $Id: geprot.h,v 1.45 2006/05/14 14:33:21 stas_degteff Exp $
+//  $Id: geprot.h,v 1.48 2006/11/22 08:25:52 stas_degteff Exp $
 //  ------------------------------------------------------------------
 //  Collective header for GE*.CPP source files.
 //  ------------------------------------------------------------------
@@ -210,19 +210,6 @@
 
 
 //  ------------------------------------------------------------------
-//  GEMLST prototypes
-
-void MsgThreadlist();
-
-
-//  ------------------------------------------------------------------
-//  GEMRKS prototypes
-
-void MarkMsgs(GMsg* msg);
-int NextMarkedmsg(int direction, GMsg* msg);
-
-
-//  ------------------------------------------------------------------
 //  GEMSGS prototypes
 
 void TokenXlat(int mode, std::string &input, GMsg* msg, GMsg* oldmsg, int origarea);
@@ -235,6 +222,70 @@
 int DoCarboncopy(GMsg* msg, GMsg** carbon);
 void DoCrosspost(GMsg* msg, std::vector<int> &postareas);
 char* ParseInternetAddr(char* __string, char* __name, char* __addr, bool detect_charset = true);
+
+
+//  ------------------------------------------------------------------
+//  GEMLST prototypes
+
+void MsgThreadlist();
+
+//  ------------------------------------------------------------------
+
+class ThreadEntry {
+
+public:
+  uint32_t msgno;
+  uint32_t replyto;
+  uint32_t reply1st;
+  uint32_t replynext;
+  uint32_t replytoindex;
+  uint32_t level;
+};
+
+//  ------------------------------------------------------------------
+
+class GThreadlist : public gwinpick {
+
+private:
+
+  gwindow     window;
+  GMsg        msg;
+  ThreadEntry t;
+
+  std::vector<ThreadEntry>  list;
+  std::vector<std::string>  tree;
+
+  dword m_OldMsgno;
+  uint m_OldTags;
+  std::string m_OldEchoId;
+
+  void BuildThreadIndex(dword msgno);
+  void recursive_build(uint32_t msgn, uint32_t rn, uint32_t level, uint32_t index);
+  void GenTree(int idx);
+  void update_title();
+  bool NextThread(bool next);
+
+public:
+
+  void open();                        // Called after window is opened
+  void close();                       // Called after window is closed
+  void print_line(uint idx, uint pos, bool isbar);
+  void do_delayed();
+  bool handle_key();                  // Handles keypress
+
+  void Run();
+  bool GoNextUnread(bool reader);
+
+  GThreadlist() { memset(&msg, 0, sizeof(GMsg)); replylinkfloat = CFG->replylinkfloat; };
+  ~GThreadlist() { ResetMsg(&msg); };
+};
+
+
+//  ------------------------------------------------------------------
+//  GEMRKS prototypes
+
+void MarkMsgs(GMsg* msg);
+int NextMarkedmsg(int direction, GMsg* msg);
 
 
 //  ------------------------------------------------------------------
