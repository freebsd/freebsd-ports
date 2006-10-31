--- ./makegraph.pl.orig	Sat Jan  3 23:44:21 2004
+++ ./makegraph.pl	Mon Oct  9 13:49:55 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -w
+#!%%PERL%% -w
 #ifGraph 0.4.10 - Network Interface Data to RRD
 #Copyright (C) 2001-2003 Ricardo Sartori
 #
@@ -19,8 +19,6 @@
 #Sugestoes e criticas (sem flames!!) mailto:sartori@ifgraph.lrv.ufsc.br
 #Visite: http://ifgraph.lrv.ufsc.br
 
-use FindBin;
-use lib "$FindBin::Bin/lib";
 use strict;
 use Getopt::Std;
 use Color::Rgb;
@@ -31,14 +29,7 @@
 getopt('ctT');
 getopts('Bbgdh');
 
-# If the perl is older, we have to fetch the older Net::SNMP library
-if ($] < 5.006) { 
-	&debug("Warning: Older perl version $], we will use Net::SNMP 3.65\n");
-	require Net::SNMP_365; 
-} else {
-	&debug("Starting ifgraph 0.4.10 with perl $[, Net::SNMP 4.3\n");
-	require Net::SNMP;
-}
+use Net::SNMP;
 
 # HELP
 if (defined($opt_h)) {
@@ -48,16 +39,16 @@
 
 # Creating a color converter object
 &debug("main(): Creating a RGB converter object from Color::Rgb\n");
-$rgb_converter = new Color::Rgb(rgb_txt=>"$FindBin::Bin/lib/rgb.txt");
+$rgb_converter = new Color::Rgb(rgb_txt=>"%%PREFIX%%/ifgraph/lib/rgb.txt");
 if ($rgb_converter) { &debug("main(): Ok RGB converter object created\n"); }
 
 # Defining the $configile variable
 if (defined($opt_c)) {
   $configfile=$opt_c;
  } else {
-  print("Warning: searching /usr/local/etc/, /etc and ./ for an ifgraph.conf file\n");
-  if (-r "/usr/local/etc/ifgraph.conf") {
-	  $configfile="/usr/local/etc/ifgraph.conf";
+  print("Warning: searching %%PREFIX%%/etc/, /etc and ./ for an ifgraph.conf file\n");
+  if (-r "%%PREFIX%%/etc/ifgraph.conf") {
+	  $configfile="%%PREFIX%%/etc/ifgraph.conf";
   } elsif (-r "/etc/ifgraph.conf") { # used from the patch of Iain Lea <iain@bricbrac.de>
           $configfile="/etc/ifgraph.conf";
   } elsif (-r "./ifgraph.conf") {
@@ -683,7 +674,7 @@
   &debug("criaGraficoBytes(): Colors are $color_back, $color_canvas, $color_shadea, $color_shadeb, $color_grid, $color_mgrid, $color_font, $color_frame, $color_arrow, $color_in, $color_out\ncriaGraficoBytes(): Options are $$targets[$targetindex][6]->[0] $$targets[$targetindex][6]->[1] $$targets[$targetindex][6]->[2] $$targets[$targetindex][6]->[3] $$targets[$targetindex][6]->[4] $$targets[$targetindex][6]->[5]\ncriaGraficoBytes(): Dimensions are $$targets[$targetindex][7]->[0] x $$targets[$targetindex][7]->[1]\n");
   my($start);
   while ($start=shift(@period)) {
-	  print(RRDTOOL "graph $global->[3]/$targets->[$targetindex][0]$start.$opt_imgformat -a $$global[5] -b 1000 $opt_rigid -s $start -e -$targets->[$targetindex][19] $opt_legend $opt_nominor -w $dim_width -h $dim_height -c BACK$color_back -c CANVAS$color_canvas -c SHADEA$color_shadea -c SHADEB$color_shadeb -c GRID$color_grid -c MGRID$color_mgrid -c FONT$color_font -c FRAME$color_frame -c ARROW$color_arrow -v \" $$targets[$targetindex][9] \" -t \"$$targets[$targetindex][10]\" $opt_inout_def CDEF:deltain=totalin,errin,-,0,LT,0,totalin,errin,-,IF CDEF:in=deltain,0,LT,0,deltain,IF,$bwidth_in,GT,$bwidth_in,deltain,IF CDEF:deltaout=totalout,errout,-,0,LT,0,totalout,errout,-,IF CDEF:out=deltaout,0,LT,0,deltaout,IF,$bwidth_out,GT,$bwidth_out,deltaout,IF CDEF:kbin=in,1000,\/ CDEF:kbout=out,1000,\/ CDEF:percbin=in,100,*,$bwidth_in,\/ CDEF:percbout=out,100,*,$bwidth_out,\/ AREA:in$color_in:\"$$targets[$targetindex][11]->[0]\" LINE2:out$color_out:\"$$targets[$targetindex][11]->[1]\\l\" GPRINT:kbin:LAST:\'$$targets[$targetindex][11]->[0] - Now\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:LAST:\' (%.1lf%%)\' GPRINT:kbin:AVERAGE:\'Avg\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:AVERAGE:\' (%.1lf%%)\' GPRINT:kbin:MAX:\'Max\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:MAX:\' (%.1lf%%)\\l\' GPRINT:kbout:LAST:\'$$targets[$targetindex][11]->[1] - Now\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:LAST:\' (%.1lf%%)\' GPRINT:kbout:AVERAGE:\'Avg\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:AVERAGE:\' (%.1lf%%)\' GPRINT:kbout:MAX:\'Max\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:MAX:\' (%.1lf%%)\\l\' COMMENT:\'Max bytes for target $targets->[$targetindex][0]\: $bwidth_in - $bwidth_out bytes/sec\\l\' $opt_error\n")|| die("criaGraficoBytes() Fatal: Could not print to filehandle RRDTOOL: $!\n");
+	  print(RRDTOOL "graph $global->[3]/$targets->[$targetindex][0]$start.$opt_imgformat -a $$global[5] -b 1000 $opt_rigid -s $start -e -$targets->[$targetindex][19] $opt_legend $opt_nominor -w $dim_width -h $dim_height -c BACK$color_back -c CANVAS$color_canvas -c SHADEA$color_shadea -c SHADEB$color_shadeb -c GRID$color_grid -c MGRID$color_mgrid -c FONT$color_font -c FRAME$color_frame -c ARROW$color_arrow -v \" $$targets[$targetindex][9] \" -t \"$$targets[$targetindex][10]\" $opt_inout_def CDEF:deltain=totalin,errin,-,0,LT,0,totalin,errin,-,IF CDEF:in=deltain,0,LT,0,deltain,IF,$bwidth_in,GT,$bwidth_in,deltain,IF CDEF:deltaout=totalout,errout,-,0,LT,0,totalout,errout,-,IF CDEF:out=deltaout,0,LT,0,deltaout,IF,$bwidth_out,GT,$bwidth_out,deltaout,IF CDEF:kbin=in,1000,\/ CDEF:kbout=out,1000,\/ CDEF:percbin=in,100,*,$bwidth_in,\/ CDEF:percbout=out,100,*,$bwidth_out,\/ AREA:in$color_in:\"$$targets[$targetindex][11]->[0]\" LINE2:out$color_out:\"$$targets[$targetindex][11]->[1]\\l\" GPRINT:kbin:LAST:\'$$targets[$targetindex][11]->[0] - Now\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:LAST:\' (%.1lf%%)\' GPRINT:kbin:AVERAGE:\'Avg\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:AVERAGE:\' (%.1lf%%)\' GPRINT:kbin:MAX:\'Max\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:MAX:\' (%.1lf%%)\\l\' GPRINT:kbout:LAST:\'$$targets[$targetindex][11]->[1] - Now\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:LAST:\' (%.1lf%%)\' GPRINT:kbout:AVERAGE:\'Avg\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:AVERAGE:\' (%.1lf%%)\' GPRINT:kbout:MAX:\'Max\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:MAX:\' (%.1lf%%)\\l\' COMMENT:\'Max bytes for target $targets->[$targetindex][0]\\: $bwidth_in - $bwidth_out bytes/sec\\l\' $opt_error\n")|| die("criaGraficoBytes() Fatal: Could not print to filehandle RRDTOOL: $!\n");
   }
 }
 
@@ -737,7 +728,7 @@
   &debug("criaGraficoBits(): Colors are $color_back, $color_canvas, $color_shadea, $color_shadeb, $color_grid, $color_mgrid, $color_font, $color_frame, $color_arrow, $color_in, $color_out\ncriaGraficoBits(): Options are $$targets[$targetindex][6]->[0] $$targets[$targetindex][6]->[1] $$targets[$targetindex][6]->[2] $$targets[$targetindex][6]->[3] $$targets[$targetindex][6]->[4] $$targets[$targetindex][6]->[5]\ncriaGraficoBits(): Dimensions are $$targets[$targetindex][7]->[0] x $$targets[$targetindex][7]->[1]\n");
   my($start);
   while ($start=shift(@period)) {
-	  print(RRDTOOL "graph $global->[3]/$targets->[$targetindex][0]$start.$opt_imgformat -a $$global[5] -b 1000 $opt_rigid -s $start -e -$targets->[$targetindex][19] $opt_legend $opt_nominor -w $dim_width -h $dim_height -c BACK$color_back -c CANVAS$color_canvas -c SHADEA$color_shadea -c SHADEB$color_shadeb -c GRID$color_grid -c MGRID$color_mgrid -c FONT$color_font -c FRAME$color_frame -c ARROW$color_arrow -v \"$$targets[$targetindex][9]\" -t \"$$targets[$targetindex][10]\" $opt_inout_def  CDEF:deltain=totalin,errin,-,0,LT,0,totalin,errin,-,IF CDEF:in=deltain,0,LT,0,deltain,IF,$bytes_bwidth_in,GT,$bytes_bwidth_in,deltain,IF CDEF:deltaout=totalout,errout,-,0,LT,0,totalout,errout,-,IF CDEF:out=deltaout,0,LT,0,deltaout,IF,$bytes_bwidth_out,GT,$bytes_bwidth_out,deltaout,IF CDEF:bitsin=in,8,* CDEF:bitsout=out,8,* CDEF:kbitsin=bitsin,1000,\/ CDEF:kbitsout=bitsout,1000,\/ CDEF:percbin=bitsin,100,*,$bwidth_in,\/ CDEF:percbout=bitsout,100,*,$bwidth_out,\/ CDEF:berrin=errin,8,\/ CDEF:berrout=errout,8,\/ AREA:bitsin$color_in:\"$$targets[$targetindex][11]->[0]\" LINE2:bitsout$color_out:\"$$targets[$targetindex][11]->[1]\\l\" GPRINT:kbitsin:LAST:\'$$targets[$targetindex][11]->[0] - Now\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:LAST:\' (%.1lf%%)\' GPRINT:kbitsin:AVERAGE:\'Avg\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:AVERAGE:\' (%.1lf%%)\' GPRINT:kbitsin:MAX:\'Max\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:MAX:\' (%.1lf%%)\\l\' GPRINT:kbitsout:LAST:\'$$targets[$targetindex][11]->[1] - Now\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:LAST:\' (%.1lf%%)\' GPRINT:kbitsout:AVERAGE:\'Avg\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:AVERAGE:\' (%.1lf%%)\' GPRINT:kbitsout:MAX:\'Max\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:MAX:\' (%.1lf%%)\\l\' COMMENT:\'Max bits for target $targets->[$targetindex][0]\: $bwidth_in - $bwidth_out bits/sec \\l\' $opt_error\n") || die("criaGraficoBits() Fatal: Could not print to filehandle RRDTOOL: $!\n");
+	  print(RRDTOOL "graph $global->[3]/$targets->[$targetindex][0]$start.$opt_imgformat -a $$global[5] -b 1000 $opt_rigid -s $start -e -$targets->[$targetindex][19] $opt_legend $opt_nominor -w $dim_width -h $dim_height -c BACK$color_back -c CANVAS$color_canvas -c SHADEA$color_shadea -c SHADEB$color_shadeb -c GRID$color_grid -c MGRID$color_mgrid -c FONT$color_font -c FRAME$color_frame -c ARROW$color_arrow -v \"$$targets[$targetindex][9]\" -t \"$$targets[$targetindex][10]\" $opt_inout_def  CDEF:deltain=totalin,errin,-,0,LT,0,totalin,errin,-,IF CDEF:in=deltain,0,LT,0,deltain,IF,$bytes_bwidth_in,GT,$bytes_bwidth_in,deltain,IF CDEF:deltaout=totalout,errout,-,0,LT,0,totalout,errout,-,IF CDEF:out=deltaout,0,LT,0,deltaout,IF,$bytes_bwidth_out,GT,$bytes_bwidth_out,deltaout,IF CDEF:bitsin=in,8,* CDEF:bitsout=out,8,* CDEF:kbitsin=bitsin,1000,\/ CDEF:kbitsout=bitsout,1000,\/ CDEF:percbin=bitsin,100,*,$bwidth_in,\/ CDEF:percbout=bitsout,100,*,$bwidth_out,\/ CDEF:berrin=errin,8,\/ CDEF:berrout=errout,8,\/ AREA:bitsin$color_in:\"$$targets[$targetindex][11]->[0]\" LINE2:bitsout$color_out:\"$$targets[$targetindex][11]->[1]\\l\" GPRINT:kbitsin:LAST:\'$$targets[$targetindex][11]->[0] - Now\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:LAST:\' (%.1lf%%)\' GPRINT:kbitsin:AVERAGE:\'Avg\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:AVERAGE:\' (%.1lf%%)\' GPRINT:kbitsin:MAX:\'Max\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbin:MAX:\' (%.1lf%%)\\l\' GPRINT:kbitsout:LAST:\'$$targets[$targetindex][11]->[1] - Now\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:LAST:\' (%.1lf%%)\' GPRINT:kbitsout:AVERAGE:\'Avg\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:AVERAGE:\' (%.1lf%%)\' GPRINT:kbitsout:MAX:\'Max\\: %.$targets->[$targetindex][20]lf $$targets[$targetindex][13]\\g\' GPRINT:percbout:MAX:\' (%.1lf%%)\\l\' COMMENT:\'Max bits for target $targets->[$targetindex][0]\\: $bwidth_in - $bwidth_out bits/sec \\l\' $opt_error\n") || die("criaGraficoBits() Fatal: Could not print to filehandle RRDTOOL: $!\n");
   }
 }
 
@@ -832,7 +823,7 @@
  # Setting targets defaults
  my(@default)=("name","1G","localhost","public",161,0,"","460x150","back#FFFFFF","","","","1000","",1,10,"-1day,-1week,-1month,-1year",0,"",600,2);
  # Setting global defaults
- @global[1,2,3,4,5]=("/usr/local/bin/rrdtool","/usr/local/rrdfiles/","/usr/local/htdocs/","$FindBin::Bin/templates/en/","PNG");
+ @global[1,2,3,4,5]=("%%LOCALBASE%%/bin/rrdtool","%%LOCALBASE%%/rrdfiles/","%%PERFIX%%/htdocs/","%%PREFIX%%/ifgraph/templates/en/","PNG");
  my($accept_new_target)=1;
  my($index)=-1; # target targetindex
  open(CONF,"$configfile") || die("readconf() Fatal: Could not read configuration file $configfile ($!)\n"); 
