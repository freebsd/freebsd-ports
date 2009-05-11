Index: portstools/tinderbox/webui/templates/paefchen/list_builds.tpl
diff -u portstools/tinderbox/webui/templates/paefchen/list_builds.tpl:1.5.2.3 portstools/tinderbox/webui/templates/paefchen/list_builds.tpl:1.5.2.6
--- portstools/tinderbox/webui/templates/paefchen/list_builds.tpl:1.5.2.3	Wed Feb 11 03:33:12 2009
+++ portstools/tinderbox/webui/templates/paefchen/list_builds.tpl	Wed May  6 16:52:30 2009
@@ -2,7 +2,7 @@
 $topmenu = array(
 	"Current And Latest Builds" 	=> "index.php?action=latest_buildports",
 	"Failed builds in this build"	=> "index.php?action=failed_buildports",
-	"All (really) Build Failures"	=> "index.php?action=bad_buildports"
+	"All Failures"					=> "index.php?action=bad_buildports"
 );
 
 $legend = array(
@@ -15,6 +15,10 @@
 	"T = Total"
 );
 
+if ( empty ( $search_port_name ) ) {
+	$search_port_name = '';
+}
+
 include 'header.inc.tpl';
 ?>
 <!-- $Paefchen: FreeBSD/tinderbox/webui/templates/paefchen/list_builds.tpl,v 1.2 2008/01/07 03:53:59 as Exp $ //-->
@@ -108,21 +112,6 @@
 <?php }?>
 <div class="subcontent">
 	<form method="get" action="index.php">
-	<fieldset>
-		<label>All Build Failures for the maintainer</label>
-	
-			<input type="hidden" name="action" value="failed_buildports" />
-			<select name="maintainer">
-				<option></option>
-<?php foreach($maintainers as $maintainer) {?>
-				<option><?php echo $maintainer?></option>
-<?php }?>
-			</select>
-			<input type="submit" name="Go" value="Go" />
-	</fieldset>
-	</form>
-	<br />
-	<form method="get" action="index.php">
 		<fieldset>
 			<label>Find ports by name</label>
 			<input type="hidden" name="action" value="list_buildports" />
@@ -135,6 +124,42 @@
 			<input type="submit" name="Go" value="Go" />
 		</fieldset>
 	</form>
+	<br />
+	<fieldset>
+		<label>Maintainer</label>
+		<table>
+			<tr>
+				<th>All Build Failures for the maintainer</th>
+				<th>RSS feed for the maintainer</th>
+			</tr>
+			<tr>
+				<td>
+					<form method="get" action="index.php">
+						<input type="hidden" name="action" value="failed_buildports" />
+						<select name="maintainer">
+							<option></option>
+							<?php foreach($maintainers as $maintainer) {?>
+								<option><?php echo $maintainer?></option>
+							<?php }?>
+						</select>
+						<input type="submit" name="Go" value="Go" />
+					</form>
+				</td>
+				<td>
+					<form method="get" action="index.php">
+						<input type="hidden" name="action" value="latest_buildports_rss" />
+						<select name="maintainer">
+							<option></option>
+							<?php foreach($maintainers as $maintainer) {?>
+								<option><?php echo $maintainer?></option>
+							<?php }?>
+						</select>
+						<input type="submit" name="Go" value="Go" />
+					</form>
+				</td>
+			</tr>
+		</table>
+	</fieldset>
 </div>
 <?php 
 $footer_legend = array(
