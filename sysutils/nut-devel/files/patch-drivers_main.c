diff --git drivers/main.c drivers/main.c
old mode 100755
new mode 100644
index f53322e2..0b6759dd
--- drivers/main.c
+++ drivers/main.c
@@ -607,9 +607,9 @@ int main(int argc, char **argv)
 
 	become_user(new_uid);
 
-	/* Only switch to statepath if we're not powering off or just dumping data, for discovery */
+	/* Only switch to statepath if we're not powering off */
 	/* This avoid case where ie /var is umounted */
-	if ((!do_forceshutdown) && (dump_data < 0) && (chdir(dflt_statepath())))
+	if ((!do_forceshutdown) && (chdir(dflt_statepath())))
 		fatal_with_errno(EXIT_FAILURE, "Can't chdir to %s", dflt_statepath());
 
 	/* Setup signals to communicate with driver once backgrounded. */
@@ -642,11 +642,8 @@ int main(int argc, char **argv)
 			sleep(5);
 		}
 
-		/* Only write pid if we're not just dumping data, for discovery */
-		if (dump_data < 0) {
-			pidfn = xstrdup(buffer);
-			writepid(pidfn);	/* before backgrounding */
-		}
+		pidfn = xstrdup(buffer);
+		writepid(pidfn);	/* before backgrounding */
 	}
 
 	/* clear out callback handler data */
@@ -701,10 +698,7 @@ int main(int argc, char **argv)
 	}
 
 	/* now we can start servicing requests */
-	/* Only write pid if we're not just dumping data, for discovery */
-	if (dump_data < 0) {
-		dstate_init(progname, upsname);
-	}
+	dstate_init(progname, upsname);
 
 	/* The poll_interval may have been changed from the default */
 	dstate_setinfo("driver.parameter.pollinterval", "%d", poll_interval);
