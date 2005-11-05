--- capplets/about-me/gnome-about-me.c.orig	Wed Jul 27 13:45:17 2005
+++ capplets/about-me/gnome-about-me.c	Wed Jul 27 13:47:09 2005
@@ -258,12 +258,10 @@
 static char *
 get_user_login (void)
 {
-	char buf[LINE_MAX * 4];
-	struct passwd pwd, *err;
+	struct passwd *pwd;
 
-	int i;
-	i = getpwuid_r(getuid(), &pwd, buf, sizeof(buf), &err);
-	return ((i == 0) && (err == &pwd)) ? g_strdup(pwd.pw_name) : NULL;
+	pwd = getpwuid(getuid());
+	return (pwd != NULL) ? g_strdup(pwd->pw_name) : NULL;
 }
 
 /*
@@ -664,6 +662,7 @@
 	struct passwd *pwent;
 	char *user = NULL;
 	gchar *str;
+	gchar **tok;
 
 	me = g_new0 (GnomeAboutMe, 1);
 
@@ -733,7 +732,6 @@
 				_("Unknown login ID, the user database might be corrupted"));
 		return ;
 	}
-	gchar **tok;
 	tok = g_strsplit (pwent->pw_gecos, ",", 0);
 
 	/************************************************/
