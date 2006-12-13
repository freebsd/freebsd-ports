--- ./libMG/src/libMG.h.orig	Tue Dec 13 13:56:16 2005
+++ ./libMG/src/libMG.h	Fri Dec  8 17:13:00 2006
@@ -57,6 +57,7 @@
 #define	KEY_a		97
 #define	CLASS_TYPE_DB	1
 #define	CLASS_TYPE_DIR	2
+#define	CLASS_TYPE_MEM	3
 #define	CR		13
 #define	DEBUG_MGdb	0
 #define	DEBUG_MGdir	0
@@ -77,15 +78,15 @@
 #define	SINGLE_LINES	"------------------------------------------------------------------------"
 #define	DOUBLE_LINES	"========================================================================"
 
-		char**		MGm__command;
-		int		MGm__forkStatus;
-		pid_t		MGm__pid;
-struct		stat		fstatBuf;
-struct		stat		lstatBuf;
-typedef	struct 	classDb		classDb; 
-typedef	struct 	classDir	classDir; 
-unsigned	int		MGm__bufferSize;
-unsigned	int		MGm__stringSize;
+			char**		MGm__command;
+			int		MGm__forkStatus;
+			pid_t		MGm__pid;
+	struct		stat		fstatBuf;
+	struct		stat		lstatBuf;
+	unsigned	int		MGm__bufferSize;
+	unsigned	int		MGm__stringSize;
+typedef	struct 		classDb		classDb; 
+typedef	struct 		classDir	classDir; 
 
 #define	MAXSTRINGSIZE	0x1ff
 #define	MAXBUFFERSIZE	0xffff
@@ -270,7 +271,7 @@
 int			MGrInStringSwap( char* originalString, char* oldString, char* newString );
 int			MGrStripComment( char*, char );
 unsigned	int	MGrBufferlen( char* buffer, unsigned int maxBufferSize );
-unsigned	int	MGrStrlen( char* string );
+unsigned	int	MGrStrlen( char* String );
 unsigned long	int	MGrFileTime( char* );
 
 #endif
