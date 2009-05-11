Index: portstools/tinderbox/webui/templates/default/list_builds.tpl
diff -u portstools/tinderbox/webui/templates/default/list_builds.tpl:1.10.2.4 portstools/tinderbox/webui/templates/default/list_builds.tpl:1.10.2.7
--- portstools/tinderbox/webui/templates/default/list_builds.tpl:1.10.2.4	Wed Feb 11 03:33:12 2009
+++ portstools/tinderbox/webui/templates/default/list_builds.tpl	Wed May  6 16:52:29 2009
@@ -12,7 +12,7 @@
 <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
 <html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
 <head>
-<!-- $MCom: portstools/tinderbox/webui/templates/default/list_builds.tpl,v 1.10.2.4 2009/02/11 08:33:12 beat Exp $ //-->
+<!-- $MCom: portstools/tinderbox/webui/templates/default/list_builds.tpl,v 1.10.2.7 2009/05/06 20:52:29 beat Exp $ //-->
 <title><?php echo $tinderbox_name?></title>
 <link href="<?php echo $templatesuri?>/tinderstyle.css" rel="stylesheet" type="text/css" />
 <link rel="alternate" type="application/rss+xml" title="<?php echo $tinderbox_name?> (RSS)" href="index.php?action=latest_buildports_rss" />
@@ -120,7 +120,7 @@
 <p>
 <a href="index.php?action=latest_buildports">Current And Latest Builds</a><br />
 <a href="index.php?action=failed_buildports">All Build Failures</a><br />
-<a href="index.php?action=bad_buildports">All (really) Build Failures</a><br />
+<a href="index.php?action=bad_buildports">All Failures</a><br />
 <input type="hidden" name="action" value="failed_buildports" />
 All Build Failures for the maintainer <select name="maintainer">
 	<option></option>
@@ -140,10 +140,23 @@
 	<option value="<?php echo $row['name']?>"><?php echo $row['name']?></option>
 <?php }?>
 </select>
-<input type="text" name="search_port_name" value="<?php echo $search_port_name?>" />
+<input type="text" name="search_port_name" value="<?php if(isset($search_port_name))echo $search_port_name?>" />
 <input type="submit" name="Go" value="Go" />
 </form>
 </p>
+<p>
+<form method="get" action="index.php">
+RSS feed for the maintainer
+<input type="hidden" name="action" value="latest_buildports_rss" />
+<select name="maintainer">
+<option></option>
+<?php foreach($maintainers as $maintainer) {?>
+	<option><?php echo $maintainer?></option>
+<?php }?>
+</select>
+<input type="submit" name="Go" value="Go" />
+</form>
+<p>
 <br />
 <?php echo $display_login?>
 </body>
