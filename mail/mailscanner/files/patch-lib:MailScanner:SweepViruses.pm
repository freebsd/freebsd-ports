--- ../MailScanner-install-4.32.5.orig/lib/MailScanner/SweepViruses.pm	Mon Aug 16 18:57:47 2004
+++ lib/MailScanner/SweepViruses.pm	Mon Aug 16 18:58:17 2004
@@ -2195,7 +2195,7 @@
     MailScanner::Log::InfoLog("ProcessClamAVOutput: %s", $1);
     return 0;
   }
-  return 0 if /^  /;  # "  inflating", "  deflating.." from --unzip
+  return 0 if /^  |^Extracting|module failure$/;  # "  inflating", "  deflating.." from --unzip
   if ($clamav_archive && /^$clamav_archive:/)
   {
     $clamav_archive = "";
@@ -2206,6 +2206,22 @@
   
   MailScanner::Log::InfoLog("%s", $line);
 
+  #(Real infected archive: /var/spool/MailScanner/incoming/19746/./i75EFmSZ014248/eicar.rar)
+  if (/^\(Real infected archive: (.*)\)$/)
+  {
+     my ($file, $ReportStart);
+     $file = $1;
+     $file =~ s/^(.\/)?$BaseDir\/?//;
+     $file =~ s/^\.\///;
+     my ($id,$part) = split /\//, $file, 2;
+
+     $ReportStart = $part;
+     $ReportStart = $Name . ': ' . $ReportStart if $Name;
+     $infections->{"$id"}{"$part"} .= "$ReportStart contains a virus\n";
+     $types->{"$id"}{"$part"} .= "v";
+     return 1;
+  }
+
   if (/^(\(raw\) )?(.*?): (.*) FOUND$/)
   {
      my ($file, $subfile, $virus, $report, $ReportStart);
@@ -2457,6 +2473,9 @@
   # Sample output:
   #./1B978O-0000g2-Iq/eicar.com  Virus identified  EICAR_Test (+2)
   #./1B978O-0000g2-Iq/eicar.zip:\eicar.com  Virus identified  EICAR_Test (+2)
+
+  # Remove all the duff carriage-returns from the line
+  $line =~ s/[\r\n]//g;
 
   #print STDERR "Line: $line\n";
   return 0 unless $line =~ /Virus identified  (.+)$/;
