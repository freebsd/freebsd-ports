--- ljsm.pl.orig	Mon Oct 23 00:54:39 2006
+++ ljsm.pl	Mon Oct 23 00:54:29 2006
@@ -94,6 +94,7 @@
 use File::Path;
 use File::Basename;
 use File::Find;
+use HTML::Form;
 
 use Compress::Zlib;
 use Digest::MD5 qw(md5_hex);
@@ -102,7 +103,7 @@
 use strict;
 
 my ($ua, $req, $res, $login, @posts, %images, $user, %users, %stat, %memories, %posts, $umask);
-our ($opt_r, $opt_m, $opt_a, $opt_c, $opt_O, $opt_i, $opt_I, $opt_u, $opt_U, $opt_x, $opt_t, $opt_p, $opt_d);
+our ($opt_r, $opt_m, $opt_a, $opt_c, $opt_O, $opt_i, $opt_I, $opt_u, $opt_U, $opt_x, $opt_X, $opt_t, $opt_p, $opt_d);
 
 # open log file (delete it if there were no errors)
 $umask = umask 0077;
@@ -112,7 +113,7 @@
 print LF scalar localtime() . "\n";
 
 # steal options from @ARGV before we go for users
-getopts('rmacxtOIUu:p:d:i:');
+getopts('rmacxtXOIUu:p:d:i:');
 $opt_i = SAVE_PICS if (!$opt_i);
 
 usage() && exit unless (@ARGV);
@@ -153,6 +154,20 @@
 # get cookies
 exit 1 unless (!(LOGIN || $opt_u) || ($login = lj_login()));
 
+
+# get xml files and exit if -X option is set
+if ($opt_X) {
+	if (!$login) {
+		logmsg("only registered user can export her posts as XML files\n");
+		logmsg("please specify -u login:password at the command line\n");
+		exit 128;
+	}
+	($user) = split(':', $opt_u);
+	get_xml($user);
+	exit 0;
+}
+
+
 # get posts and memories
 foreach $user (@ARGV) { # for each user
 	%memories = %posts = %users = ();
@@ -358,6 +373,92 @@
 			}
 		} else {
 			logmsg("error getting $imgsrc\n",0);
+		}
+	}
+}
+
+
+sub get_xml {
+	my ($user) = @_;
+	my ($path, $content, $tmp, $exportform, $month, $emonth, $year, $fname);
+	
+	logmsg("exporting $user\'s posts in XML format...\n",2);
+	$path = LOCAL_DIR . $user . '/export';
+	mkpath($path, DEBUG_LEVEL, 0755) if (!-d $path);
+	my ($start_year, $start_month, $end_year, $end_month) = get_date_range($user, 1);
+
+	# get export form
+	if ($content = get_page(BASE_URL . EXPORT_SCRIPT)) {
+		($tmp, $exportform) = parse HTML::Form($content, BASE_URL);
+		if (defined $exportform) {
+			#$exportform->dump();
+			$exportform->value('format', 'xml');
+			#$exportform->value('encid', 3); # 6 for KOI-8
+			# uncomment next line to skip translation between encodings
+			# $exportform->value('notranslation', 1);
+			
+			$year = $end_year;
+			YEAR:
+			while ($year >= $start_year) {
+				$emonth = ($year == $start_year)? $start_month : 1;
+				for ($month = 12; $month >= $emonth; $month--) {
+					next if (($year == $end_year) && ($month > $end_month));
+					$fname = $path . sprintf("/%4d_%02d.xml", $year, $month);
+					
+					if (-f $fname) {
+						if ($opt_O) {
+							logmsg("!! overwriting $fname\n",2);
+						} elsif ($opt_r) {
+							logmsg("-r: skipping $fname\n", 2);
+							next;
+						} else {
+							last YEAR;
+						}
+					}
+
+					logmsg("<< $year/$month\n",2);
+					$exportform->value('year', $year);
+					$exportform->value('month', $month);
+					
+					#submit export form
+					$req = $exportform->click();
+					$req->header('Accept-Encoding' => 'gzip;q=1.0, *;q=0');
+					
+					foreach (0 .. MAX_TRIES) {
+						$res = $ua->request($req);
+						logmsg("retrying $year/$month...\n") if $_;
+						if ($res->is_success) {
+							$content = ($res->content_encoding && ($res->content_encoding =~ /gzip/))?
+								Compress::Zlib::memGunzip($res->content) : $res->content;
+							# save contents to a file
+							logmsg(">> $fname\n");
+							open (DF, ">$fname") or die "error opening $fname for writing: $!\n";
+							print DF $content;
+							close DF;
+							last;
+							
+						} else {
+							# TODO add logging of failed xml exort
+							my $err = $res->error_as_HTML;
+							$err =~ s/^[^\d].*$//mg;
+							$err =~ s/[\n\r]+//g;
+							logmsg("\n$err\n",0);
+							if ($_ == MAX_TRIES) {
+								logmsg ("failed to get XML file for $year/$month\n");
+								print LF "Failed: xml for $year/$month\n";
+								$stat{'pages_err'}++;
+								return 0 unless $opt_I;
+							}
+							sleep 2;
+						}
+					}
+				}
+				$year--;
+			}
+			
+		} else {
+			logmsg("error getting export form " . BASE_URL . EXPORT_SCRIPT);
+			return 0;
 		}
 	}
 }
