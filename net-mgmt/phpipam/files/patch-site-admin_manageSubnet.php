--- site/admin/manageSubnet.php.orig	2012-03-01 08:46:57.000000000 -0600
+++ site/admin/manageSubnet.php	2012-06-15 11:16:33.618275630 -0500
@@ -123,7 +123,7 @@
 			
 						print '	<tr class="slaveSubnet subSlaveSubnet">' . "\n";
 		        		print '		<td class="subnet">'. transform2long($subSlave['subnet']) .'/'. $subSlave['mask'] .'</td>' . "\n";
-		       			print '		<td>'. $slave['description'] .'</td>' . "\n";
+		       			print '		<td>'. $subSlave['description'] .'</td>' . "\n";
 						print '		<td class="masterSubnet">'. transform2long($master['subnet']) .'/'. $master['mask'] .'</td>' . "\n";
 		
 						# VLAN
@@ -182,4 +182,4 @@
 		speed  : 'fast'
 	});
 });
-</script>
\ No newline at end of file
+</script>
