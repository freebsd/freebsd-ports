--- ./src/mainwin.h.orig	2006-06-29 22:29:34.000000000 -0700
+++ ./src/mainwin.h	2008-01-26 13:26:47.532687040 -0800
@@ -22,7 +22,7 @@
 	TEXT_WIN_PATTERN_NOT_FOUND,
 	TEXT_WIN_TIPS, // when the word entry is empty,it will show tip
 	TEXT_WIN_INFO,
-	TEXT_WIN_TREEDICT,
+	TEXT_WIN_TREEDICT
 };
 
 enum ListWinListWordType {
@@ -68,8 +68,6 @@
 	static void on_main_menu_about_activate(GtkMenuItem *menuitem, TopWin *oTopWin);
 	static void on_main_menu_quit_activate(GtkMenuItem *menuitem, TopWin *oTopWin);
 
-	static void ClipboardReceivedCallback(GtkClipboard *clipboard, const gchar *text, gpointer data);
-
 	void LoadHistory(void);
 	void SaveHistory(void);
 public:
@@ -79,6 +77,8 @@
 	TopWin();
 	~TopWin();
 
+	static void ClipboardReceivedCallback(GtkClipboard *clipboard, const gchar *text, gpointer data);
+
 	void Create(GtkWidget *vbox);
 	void Destroy(void);
 	void SetText(const gchar *word, bool notify=true);
