--- include/Banner.pm.orig	2016-02-13 16:02:14 UTC
+++ include/Banner.pm
@@ -1,8 +1,8 @@
 
 sub usage
 {
-	print( " version $version\nusage: ./cisco-torch.pl <options> <IP,hostname,network>\n\n");
-	print("or: ./cisco-torch.pl <options> -F <hostlist>\n\n");
+	print( " version $version\nusage: cisco-torch <options> <IP,hostname,network>\n\n");
+	print("or: cisco-torch <options> -F <hostlist>\n\n");
 	print("Available options:\n");
 	print("-O <output file>\n");
 	print("-A\t\tAll fingerprint scan types combined\n");
@@ -21,10 +21,10 @@ sub usage
 	print("-c\t\tCisco Webserver with SSL support scan\n");
 	print("-b\t\tPassword dictionary attack (use with -s, -u, -c, -w , -j or -t only)\n");
 	print("-V\t\tPrint tool version and exit\n");
-	print("examples:\t./cisco-torch.pl -A 10.10.0.0\/16\n");
-	print("\t\t./cisco-torch.pl -s -b -F sshtocheck.txt\n");
-        print("\t\t./cisco-torch.pl -w -z 10.10.0.0\/16\n");
-	print("\t\t./cisco-torch.pl -j -b -g -F tftptocheck.txt\n");
+	print("examples:\t cisco-torch -A 10.10.0.0\/16\n");
+	print("\t\t cisco-torch -s -b -F sshtocheck.txt\n");
+        print("\t\t cisco-torch -w -z 10.10.0.0\/16\n");
+	print("\t\t cisco-torch -j -b -g -F tftptocheck.txt\n");
 }
 
 sub banner
