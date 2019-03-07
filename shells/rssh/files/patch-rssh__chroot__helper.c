Workaround for basename(3) that is POSIX compliant since r308264 in FreeBSD 12

Incorporates also a patch to check the command line after chroot. Taken from
Debian ("0010-Check-command-line-after-chroot.patch")

--- rssh_chroot_helper.c.orig	2006-12-21 22:22:35 UTC
+++ rssh_chroot_helper.c
@@ -159,7 +159,7 @@ int main( int argc, char **argv )
 	opts.chroot_path = NULL;
 
 	/* figure out our name, and give it to the log module */
-	progname = strdup(log_make_ident(basename(argv[0])));
+	progname = strdup(log_make_ident(basename(strdup (argv[0]))));
 
 	/* get user's passwd info */
 	if ( (temp = getpwuid(getuid())) ){
@@ -217,6 +217,12 @@ int main( int argc, char **argv )
 	if ( !(argvec = build_arg_vector(argv[2], 0)) )
 		ch_fatal_error("build_arg_vector()", argv[2],
 				"bad expansion");
+
+	/* check the command for safety */
+	if ( !check_command_line(argvec, &opts) ){
+		fprintf(stderr, "\n");
+		exit(1);
+	}
 
 	/* 
 	 * This is the old way to figure out what program to run.  Since we're
