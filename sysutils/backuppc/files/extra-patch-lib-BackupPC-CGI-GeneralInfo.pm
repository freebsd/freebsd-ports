--- lib/BackupPC/CGI/GeneralInfo.pm.orig	2011-04-25 07:31:55.000000000 +0400
+++ lib/BackupPC/CGI/GeneralInfo.pm	2013-02-17 16:52:16.000000000 +0400
@@ -44,6 +44,47 @@
     GetStatusInfo("info jobs hosts queueLen");
     my $Privileged = CheckPermission();
 
+    #
+    # Generate pool size RRDtool graph image
+    #
+    if ( $In{image} ne "" ) {
+        $In{image} =~ /([0-9]+)/;
+        my $weeks = $1;
+        my $real = $<; ### SUID
+        $< = $>; ### SUID
+
+        my $poolSizeGraph = "$BinDir/rrdtool graph -"
+          . " --start=end-${weeks}w --end=-300"
+          . ' --title="BackupPC Pool Size (' . ${weeks} . ' weeks)"'
+          . ' --vertical-label=""'
+          . ' --width=600 --height=100 --rigid --alt-autoscale-max'
+          . ' --base=1024 --logarithmic --units=si'
+          . ' --color BACK#FFFFFF --slope-mode --imgformat=PNG'
+          . ' --font TITLE:10: --font AXIS:8: --font LEGEND:8: --font UNIT:8:'
+          . ' --font-render-mode mono'
+
+          . ' DEF:ao="'  . "$LogDir" . '/pool.rrd":ckb:AVERAGE'
+          . ' DEF:aob="' . "$LogDir" . '/pool.rrd":tps:AVERAGE'
+          . ' CDEF:a=ao,1024,*'
+          . ' CDEF:b=aob,1024,*'
+
+          . ' AREA:a#95B8DB:"CPool in bytes                  "'
+          . ' GPRINT:a:LAST:"Current\\:%8.2lf %s"'
+          . ' GPRINT:a:AVERAGE:"Average\\:%8.2lf %s"'
+          . ' GPRINT:a:MAX:"Maximum\\:%8.2lf %s\n"'
+
+          . ' LINE1:b#FF0000:"Prior to pooling and compression"'
+          . ' GPRINT:b:LAST:"Current\\:%8.2lf %s"'
+          . ' GPRINT:b:AVERAGE:"Average\\:%8.2lf %s"'
+          . ' GPRINT:b:MAX:"Maximum\\:%8.2lf %s\\n"';
+
+        print "Content-type: image/png\n\n";
+        print `$poolSizeGraph`;
+
+        $< = $real; ### SUID
+        return;
+    }
+
     my($jobStr, $statusStr);
     foreach my $host ( sort(keys(%Jobs)) ) {
         my $startTime = timeStamp2($Jobs{$host}{startTime});
@@ -126,8 +167,20 @@
     } elsif ( $Info{cpoolFileCnt} > 0 ) {
         $poolInfo = $cpoolInfo;
     }
-    my $generalInfo = eval("qq{$Lang->{BackupPC_Server_Status_General_Info}}")
-                                if ( $Privileged );
+
+    my $generalInfo = "";
+    if ( $Privileged ) {
+        $generalInfo  = eval("qq{$Lang->{BackupPC_Server_Status_General_Info}}");
+        $generalInfo .= '
+<ul>
+    <ul>
+        <p><img src="' . $MyURL . '?image=4">
+        <p><img src="' . $MyURL . '?image=52">
+    </ul>
+</ul>'
+                                if ( -r "$LogDir/pool.rrd" );
+    }
+
     my $content = eval("qq{$Lang->{BackupPC_Server_Status}}");
     Header($Lang->{H_BackupPC_Server_Status}, $content);
     Trailer();
