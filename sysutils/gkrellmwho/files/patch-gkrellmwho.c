
$FreeBSD$

--- gkrellmwho.c.orig	Thu Aug  2 05:42:49 2001
+++ gkrellmwho.c	Tue Aug 13 15:04:21 2002
@@ -65,7 +65,7 @@
 
 #define MAX_USERS	10	/* set this statically to avoid realloc() */
 #define USERS_LEN	MAX_USERS*MAX_USER_LEN + 1
-#define COMMAND		"w -hs | sort | grep -v $LOGNAME"
+#define COMMAND		"w -h | sort | grep -v $LOGNAME"
 #define DEF_NONE_MSG	"no users"
 static gchar users[USERS_LEN];	// list of users
 static int users_xoff;		// length of users string in pixels
