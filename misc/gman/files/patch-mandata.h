--- mandata.h.orig	Fri Mar 30 09:35:42 2001
+++ mandata.h	Fri Mar 30 09:35:56 2001
@@ -17,12 +17,12 @@
 	char *	path_name;
 	List *	section[MAX_MAN_SECTION]; //1:2:3:4:5:6:7:8:9:tcl:n:l:p:o
 private:
-	LoadManSubPath(char *);
+	int LoadManSubPath(char *);
 public:
 	int active;
 	ManPath(char * path_name);
 	~ManPath();
-	LoadManPath(char *);
+	int LoadManPath(char *);
 	const char * GetPath();
 	int GetSize(int section_ID);
 	int GetItems(int section_ID, ManItem **buffer);
