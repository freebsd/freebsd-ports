--- cmd.c	Wed Mar  7 20:38:30 2001
+++ cmd.c	Mon Dec  6 13:16:58 2004
@@ -452,7 +452,7 @@
 	VClear ();
 	VSync ();
 	VRestore ();
-	runl (0, ABSSHELL, SHELL, "-i", 0);
+	runl (0, ABSSHELL, SHELL, "-i", NULL);
 	VReopen ();
 	VClear ();
 	setdir (cur == &left ? &right : &left, 0);
@@ -551,7 +551,7 @@
 			error ("%s is a directory", buf);
 			return;
 		}
-		if (runl (1, "/bin/cp", "cp", "-f", "-p", p->name, name, 0)) {
+		if (runl (1, "/bin/cp", "cp", "-f", "-p", p->name, name, NULL)) {
 			error ("Cannot copy %s to %s", p->name, name);
 			return;
 		}
@@ -624,7 +624,7 @@
 			error ("%s is a directory", buf);
 			return;
 		}
-		if (runl (1, "/bin/ln", "ln", "-f", p->name, name, 0)) {
+		if (runl (1, "/bin/ln", "ln", "-f", p->name, name, NULL)) {
 			error ("Cannot link %s to %s", p->name, name);
 			return;
 		}
@@ -698,7 +698,7 @@
 			error ("%s is a directory", buf);
 			return;
 		}
-		if (runl (1, "/bin/ln", "ln", "-s", "-f", p->name, name, 0)) {
+		if (runl (1, "/bin/ln", "ln", "-s", "-f", p->name, name, NULL)) {
 			error ("Cannot symlink %s to %s", p->name, name);
 			return;
 		}
@@ -779,7 +779,7 @@
 			error ("Directory %s exists", buf);
 			return;
 		}
-		if (runl (1, "/bin/mv", "mv", "-f", p->name, name, 0)) {
+		if (runl (1, "/bin/mv", "mv", "-f", p->name, name, NULL)) {
 			error ("Cannot move %s to %s", p->name, name);
 			return;
 		}
@@ -801,7 +801,7 @@
 			error ("%s is a directory", buf);
 			return;
 		}
-		if (runl (1, "/bin/mv", "mv", "-f", p->name, name, 0)) {
+		if (runl (1, "/bin/mv", "mv", "-f", p->name, name, NULL)) {
 			error ("Cannot move %s to %s", p->name, name);
 			return;
 		}
@@ -827,7 +827,7 @@
 		error ("Directory %s already exists", p);
 		break;
 	case 0:
-		if (runl (1, "/bin/mkdir", "mkdir", p, 0)) {
+		if (runl (1, "/bin/mkdir", "mkdir", p, NULL)) {
 			error ("Cannot create directory %s", p);
 			break;
 		}
@@ -863,7 +863,7 @@
 		if (getchoice (0, " Delete ", "Do you wish to delete directory",
 		    p->name, " Delete ", " Cancel ", 0))
 			return;
-		if (runl (1, "/bin/rmdir", "rmdir", p->name, 0)) {
+		if (runl (1, "/bin/rmdir", "rmdir", p->name, NULL)) {
 			error ("Cannot delete directory %s", p->name);
 			return;
 		}
@@ -1037,9 +1037,9 @@
 
 	if (metas (s)) {
 		if (usecshell)
-			runl (0, cshabsname, cshname, "-f", "-c", s, 0);
+			runl (0, cshabsname, cshname, "-f", "-c", s, NULL);
 		else
-			runl (0, shabsname, shname, "-c", s, 0);
+			runl (0, shabsname, shname, "-c", s, NULL);
 		return;
 	}
 	status = doexec (s);
