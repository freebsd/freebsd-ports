--- camel/camel-mime-utils.c.orig	Mon Oct  7 22:44:40 2002
+++ camel/camel-mime-utils.c	Mon Dec  2 02:34:31 2002
@@ -3387,6 +3387,8 @@
 		return 0;
 	}
 
+	tm.tm_isdst = -1;
+
 	d(printf ("\ndecoding date '%s'\n", inptr));
 
 	memset (&tm, 0, sizeof(tm));
@@ -3739,8 +3741,6 @@
 	/* X-Mailing-List: gnome-hackers */
 	/* X-Mailing-List: <gnome-hackers> */
 	{ "X-Mailing-List", "[ \t]*<?([^@>]+)@?([^ \n\t\r>]*)" },
-	/* X-Loop: gnome-hackers@gnome.org */
-	{ "X-Loop", "[ \t]*([^@]+)@?([^ \n\t\r>]*)" },
 	/* List-Id: GNOME stuff <gnome-hackers.gnome.org> */
 	/* List-Id: <gnome-hackers.gnome.org> */
 	/* List-Id: <gnome-hackers> */
@@ -3756,6 +3756,8 @@
 	/* X-List: gnome-hackers */
 	/* X-List: gnome-hackers@gnome.org */
 	{ "X-List", "[ \t]*([^@]+)@?([^ \n\t\r>]*)" },	
+	/* X-Loop: gnome-hackers@gnome.org */
+	{ "X-Loop", "[ \t]*([^@]+)@?([^ \n\t\r>]*)" },
 	/* Sender: owner-gnome-hackers@gnome.org */
 	/* Sender: owner-gnome-hacekrs */
 	{ "Sender", "[ \t]*owner-([^@]+)@?([^ @\n\t\r>]*)" },
