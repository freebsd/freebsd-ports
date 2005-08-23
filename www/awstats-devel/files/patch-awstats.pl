--- wwwroot/cgi-bin/awstats.pl.orig	Thu Feb 24 23:02:23 2005
+++ wwwroot/cgi-bin/awstats.pl	Thu Aug 18 08:26:22 2005
@@ -625,8 +625,8 @@
 EOF
 			# Call to plugins' function AddHTMLStyles
 			foreach my $pluginname (keys %{$PluginsLoaded{'AddHTMLStyles'}})  {
-				my $function="AddHTMLStyles_$pluginname()";
-				eval("$function");
+				my $function="AddHTMLStyles_$pluginname";
+				&$function();
 			}
 	
 			if ($BuildReportFormat eq 'xhtml' || $BuildReportFormat eq 'xml') { print ($ENV{'HTTP_USER_AGENT'}=~/Firebird/i?"//-->\n":"]]>\n"); }
@@ -660,8 +660,8 @@
 
     	# Call to plugins' function AddHTMLBodyFooter
     	foreach my $pluginname (keys %{$PluginsLoaded{'AddHTMLBodyFooter'}})  {
-    		my $function="AddHTMLBodyFooter_$pluginname()";
-    		eval("$function");
+			my $function="AddHTMLBodyFooter_$pluginname";
+			&$function();
     	}
 
 		if ($FrameName ne 'index' && $FrameName ne 'mainleft') {
@@ -3254,15 +3254,15 @@
                         # The plugin for this section was loaded
                		    $found=1;
                	        my $issectiontoload=$SectionsToLoad{"plugin_$pluginname"};
-               		    my $function="SectionReadHistory_$pluginname(\$issectiontoload,\$readxml,\$xmleb,\$countlines)";
-               		    eval("$function");
+						my $function="SectionReadHistory_$pluginname";
+						&$function($issectiontoload,$readxml,$xmleb,$countlines);
         				delete $SectionsToLoad{"plugin_$pluginname"};
         				if ($SectionsToSave{"plugin_$pluginname"}) {
         					Save_History("plugin_$pluginname",$year,$month);
         					delete $SectionsToSave{"plugin_$pluginname"};
         					if ($withpurge) {
-                           		my $function="SectionInitHashArray_$pluginname()";
-                           		eval("$function");
+								my $function="SectionInitHashArray_$pluginname";
+								&$function();
         					}
         				}
                         last;
@@ -3977,8 +3977,8 @@
    	if ($AtLeastOneSectionPlugin && $sectiontosave =~ /^plugin_(\w+)$/i)   {
   	    my $pluginname=$1;
   	    if ($PluginsLoaded{'SectionInitHashArray'}{"$pluginname"})  {
-   		    my $function="SectionWriteHistory_$pluginname(\$xml,\$xmlbb,\$xmlbs,\$xmlbe,\$xmlrb,\$xmlrs,\$xmlre,\$xmleb,\$xmlee)";
-  		    eval("$function");
+			my $function="SectionWriteHistory_$pluginname";
+			&$function($xml,$xmlbb,$xmlbs,$xmlbe,$xmlrb,$xmlrs,$xmlre,$xmleb,$xmlee);
         }
     }
 
@@ -4203,8 +4203,8 @@
  		%{'_section_' . $ix . '_l'} = %{'_section_' . $ix . '_p'} = ();
  	}
    	foreach my $pluginname (keys %{$PluginsLoaded{'SectionInitHashArray'}})  {
-   		my $function="SectionInitHashArray_$pluginname()";
-   		eval("$function");
+		my $function="SectionInitHashArray_$pluginname";
+		&$function();
     }
 }
 
@@ -4788,8 +4788,8 @@
 	my $user=shift;
 	# Call to plugins' function ShowInfoUser
 	foreach my $pluginname (sort keys %{$PluginsLoaded{'ShowInfoUser'}})  {
-		my $function="ShowInfoUser_$pluginname('$user')";
-		eval("$function");
+		my $function="ShowInfoUser_$pluginname";
+		&$function($user);
 	}
 }
 
@@ -4804,8 +4804,8 @@
 	my $user=shift;
 	# Call to plugins' function ShowInfoCluster
 	foreach my $pluginname (sort keys %{$PluginsLoaded{'ShowInfoCluster'}})  {
-		my $function="ShowInfoCluster_$pluginname('$user')";
-		eval("$function");
+		my $function="ShowInfoCluster_$pluginname";
+		&$function($user);
 	}
 }
 
@@ -4820,8 +4820,8 @@
 	my $host=shift;
 	# Call to plugins' function ShowInfoHost
 	foreach my $pluginname (sort keys %{$PluginsLoaded{'ShowInfoHost'}})  {
-		my $function="ShowInfoHost_$pluginname('$host')";
-		eval("$function");
+		my $function="ShowInfoHost_$pluginname";
+		&$function($host);
 	}
 }
 
@@ -4838,8 +4838,8 @@
 
 	# Call to plugins' function ShowInfoURL
 	foreach my $pluginname (keys %{$PluginsLoaded{'ShowInfoURL'}})  {
-		my $function="ShowInfoURL_$pluginname('$url')";
-		eval("$function");
+		my $function="ShowInfoURL_$pluginname";
+		&$function($url);
 	}
 
 	if (length($nompage)>$MaxLengthOfShownURL) { $nompage=substr($nompage,0,$MaxLengthOfShownURL)."..."; }
@@ -5154,8 +5154,8 @@
     my $linetitle=0;
 	# Call to plugins' function AddHTMLMenuLink
 	foreach my $pluginname (keys %{$PluginsLoaded{'AddHTMLMenuLink'}})  {
-		my $function="AddHTMLMenuLink_$pluginname('$categ',\$menu,\$menulink,\$menutext)";
-		eval("$function");
+		my $function="AddHTMLMenuLink_$pluginname";
+		&$function($categ,$menu,$menulink,$menutext);
 	}
     foreach my $key (%$menu) { if ($menu->{$key}>0) { $linetitle++; last; } }
 	if (! $linetitle) { return; }
@@ -5723,8 +5723,8 @@
 
 # AWStats output is replaced by a plugin output
 if ($PluginMode) {
-	my $function="BuildFullHTMLOutput_$PluginMode()";
-	eval("$function");
+	my $function="BuildFullHTMLOutput_$PluginMode";
+	&$function();
 	if ($? || $@) { error("$@"); }
 	&html_end(0);
 	exit 0;	
@@ -6623,8 +6623,8 @@
 			elsif ($PluginsLoaded{'GetCountryCodeByAddr'}{'geoip'}) { $Domain=GetCountryCodeByAddr_geoip($HostResolved); }
             if ($AtLeastOneSectionPlugin) {
                	foreach my $pluginname (keys %{$PluginsLoaded{'SectionProcessIp'}})  {
-               		my $function="SectionProcessIp_$pluginname(\$HostResolved)";
-               		eval("$function");
+					my $function="SectionProcessIp_$pluginname";
+					&$function($HostResolved);
                 }
    		    }
 		}
@@ -6638,8 +6638,8 @@
 				elsif ($HostResolved =~ /\.(\w+)$/) { $Domain=$1; }
                 if ($AtLeastOneSectionPlugin) {
                    	foreach my $pluginname (keys %{$PluginsLoaded{'SectionProcessIp'}})  {
-                   		my $function="SectionProcessIp_$pluginname(\$Host)";
-                   		eval("$function");
+						my $function="SectionProcessIp_$pluginname";
+						&$function($Host);
                     }
                 }
 			}
@@ -6649,8 +6649,8 @@
 				elsif ($HostResolved =~ /\.(\w+)$/) { $Domain=$1; }
                 if ($AtLeastOneSectionPlugin) {
                    	foreach my $pluginname (keys %{$PluginsLoaded{'SectionProcessHostname'}})  {
-                   		my $function="SectionProcessHostname_$pluginname(\$HostResolved)";
-                   		eval("$function");
+						my $function="SectionProcessHostname_$pluginname";
+						&$function($HostResolved);
                     }
                 }
 			}
@@ -7319,8 +7319,8 @@
 
 	# Call to plugins' function AddHTMLBodyHeader
 	foreach my $pluginname (keys %{$PluginsLoaded{'AddHTMLBodyHeader'}})  {
-		my $function="AddHTMLBodyHeader_$pluginname()";
-		eval("$function");
+		my $function="AddHTMLBodyHeader_$pluginname";
+		&$function();
 	}
 
     my $WIDTHMENU1=($FrameName eq 'mainleft'?$FRAMEWIDTH:150);
@@ -7462,8 +7462,8 @@
     
 	# Call to plugins' function AddHTMLMenuHeader
 	foreach my $pluginname (keys %{$PluginsLoaded{'AddHTMLMenuHeader'}})  {
-		my $function="AddHTMLMenuHeader_$pluginname()";
-		eval("$function");
+		my $function="AddHTMLMenuHeader_$pluginname";
+		&$function();
 	}
 
 	# MENU
@@ -7572,8 +7572,8 @@
 
 	# Call to plugins' function AddHTMLMenuFooter
 	foreach my $pluginname (keys %{$PluginsLoaded{'AddHTMLMenuFooter'}})  {
-		my $function="AddHTMLMenuFooter_$pluginname()";
-		eval("$function");
+		my $function="AddHTMLMenuFooter_$pluginname";
+		&$function();
 	}
 
 	# Exit if left frame
@@ -7666,8 +7666,8 @@
 
 	# Call to plugins' function AddHTMLContentHeader
 	foreach my $pluginname (keys %{$PluginsLoaded{'AddHTMLContentHeader'}})  {
-		my $function="AddHTMLContentHeader_$pluginname()";
-		eval("$function");
+		my $function="AddHTMLContentHeader_$pluginname";
+		&$function();
 	}
 
 	# Output particular part
@@ -7946,8 +7946,8 @@
     	if ($HTMLOutput{'urldetail'} || $HTMLOutput{'urlentry'} || $HTMLOutput{'urlexit'}) {
     		# Call to plugins' function ShowPagesFilter
     		foreach my $pluginname (keys %{$PluginsLoaded{'ShowPagesFilter'}})  {
-    			my $function="ShowPagesFilter_$pluginname()";
-    			eval("$function");
+				my $function="ShowPagesFilter_$pluginname";
+				&$function();
     		}
     		print "$Center<a name=\"urls\">&nbsp;</a><br />\n";
     		# Show filter form
@@ -7977,8 +7977,8 @@
     		if ($ShowPagesStats =~ /X/i) { print "<th bgcolor=\"#$color_x\" width=\"80\">$Message[116]</th>"; }
     		# Call to plugins' function ShowPagesAddField
     		foreach my $pluginname (keys %{$PluginsLoaded{'ShowPagesAddField'}})  {
-    			my $function="ShowPagesAddField_$pluginname('title')";
-    			eval("$function");
+				my $function="ShowPagesAddField_$pluginname()";
+				&$function('title');
     		}
     		print "<th>&nbsp;</th></tr>\n";
     		$total_p=$total_k=$total_e=$total_x=0;
@@ -8010,8 +8010,8 @@
     			if ($ShowPagesStats =~ /X/i) { print "<td>".($_url_x{$key}?$_url_x{$key}:"&nbsp;")."</td>"; }
     			# Call to plugins' function ShowPagesAddField
     			foreach my $pluginname (keys %{$PluginsLoaded{'ShowPagesAddField'}})  {
-    				my $function="ShowPagesAddField_$pluginname('$key')"; 
-    				eval("$function");
+					my $function="ShowPagesAddField_$pluginname";
+					&$function($key);
     			}
     			print "<td class=\"aws\">";
     			# alt and title are not provided to reduce page size
@@ -8039,8 +8039,8 @@
     			if ($ShowPagesStats =~ /X/i) { print "<td>".($rest_x?$rest_x:"&nbsp;")."</td>"; }
     			# Call to plugins' function ShowPagesAddField
     			foreach my $pluginname (keys %{$PluginsLoaded{'ShowPagesAddField'}})  {
-    				my $function="ShowPagesAddField_$pluginname('')";
-    				eval("$function");
+					my $function="ShowPagesAddField_$pluginname";
+					&$function('');
     			}
     			print "<td>&nbsp;</td></tr>\n";
     		}
@@ -8485,8 +8485,8 @@
     	if ($htmloutput =~ /^plugin_(\w+)$/) {
     		my $pluginname=$1;
     		print "$Center<a name=\"plugin_$pluginname\">&nbsp;</a><br />";
-       		my $function="AddHTMLGraph_$pluginname()";
-       		eval("$function");
+			my $function="AddHTMLGraph_$pluginname";
+			&$function();
     		&html_end(1);
     	}
     }
@@ -9592,8 +9592,8 @@
 			if ($ShowPagesStats =~ /X/i) { print "<th bgcolor=\"#$color_x\" width=\"80\">$Message[116]</th>"; }
 			# Call to plugins' function ShowPagesAddField
 			foreach my $pluginname (keys %{$PluginsLoaded{'ShowPagesAddField'}})  {
-				my $function="ShowPagesAddField_$pluginname('title')";
-				eval("$function");
+				my $function="ShowPagesAddField_$pluginname";
+				&$function('title');
 			}
 			print "<th>&nbsp;</th></tr>\n";
 			$total_p=$total_e=$total_x=$total_k=0;
@@ -9624,8 +9624,8 @@
 				if ($ShowPagesStats =~ /X/i) { print "<td>".($_url_x{$key}?$_url_x{$key}:"&nbsp;")."</td>"; }
 				# Call to plugins' function ShowPagesAddField
 				foreach my $pluginname (keys %{$PluginsLoaded{'ShowPagesAddField'}})  {
-					my $function="ShowPagesAddField_$pluginname('$key')";
-					eval("$function");
+					my $function="ShowPagesAddField_$pluginname";
+					&$function($key);
 				}
 				print "<td class=\"aws\">";
 				if ($ShowPagesStats =~ /P/i && $LogType ne 'F')    { print "<img src=\"$DirIcons\/other\/$BarPng{'hp'}\" width=\"$bredde_p\" height=\"4\"".AltTitle("")." /><br />"; }
@@ -9653,8 +9653,8 @@
 				if ($ShowPagesStats =~ /X/i) { print "<td>".($rest_x?$rest_x:"&nbsp;")."</td>"; }
 				# Call to plugins' function ShowPagesAddField
 				foreach my $pluginname (keys %{$PluginsLoaded{'ShowPagesAddField'}})  {
-					my $function="ShowPagesAddField_$pluginname('')";
-					eval("$function");
+					my $function="ShowPagesAddField_$pluginname";
+					&$function('');
 				}
 				print "<td>&nbsp;</td></tr>\n";
 			}
