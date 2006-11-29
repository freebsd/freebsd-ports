--- golded3/gemlst.cpp.orig	Wed Oct 25 21:54:37 2006
+++ golded3/gemlst.cpp	Tue Nov 21 08:20:53 2006
@@ -19,7 +19,7 @@
 //  Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 //  MA 02111-1307 USA
 //  ------------------------------------------------------------------
-//  $Id: gemlst.cpp,v 1.58 2006/09/30 06:45:34 ssianky Exp $
+//  $Id: gemlst.cpp,v 1.60 2006/11/20 15:41:40 stas_degteff Exp $
 //  ------------------------------------------------------------------
 //  Message lister.
 //  ------------------------------------------------------------------
@@ -708,55 +708,7 @@
 
 //  ------------------------------------------------------------------
 
-class ThreadEntry {
-
-public:
-  uint32_t msgno;
-  uint32_t replyto;
-  uint32_t reply1st;
-  uint32_t replynext;
-  uint32_t replytoindex;
-  uint32_t level;
-};
-
-#define MAX_LEVEL 20
-
-class GThreadlist : public gwinpick {
-
-private:
-
-  gwindow     window;
-  GMsg        msg;
-  ThreadEntry t;
-
-  std::vector<ThreadEntry>  list;
-  std::vector<std::string>  tree;
-
-  dword m_OldMsgno;
-  uint m_OldTags;
-  std::string m_OldEchoId;
-
-  void BuildThreadIndex(dword msgno);
-  void recursive_build(uint32_t msgn, uint32_t rn, uint32_t level, uint32_t index);
-  void GenTree(int idx);
-  void update_title();
-  bool NextThread(bool next);
-
-public:
-
-  void open();                        // Called after window is opened
-  void close();                       // Called after window is closed
-  void print_line(uint idx, uint pos, bool isbar);
-  void do_delayed();
-  bool handle_key();                  // Handles keypress
-
-  void Run();
-  bool GoNextUnread(bool reader);
-
-  GThreadlist() { memset(&msg, 0, sizeof(GMsg)); replylinkfloat = CFG->replylinkfloat; };
-  ~GThreadlist() { ResetMsg(&msg); };
-};
-
+//#define MAX_LEVEL 20
 
 //  ------------------------------------------------------------------
 
