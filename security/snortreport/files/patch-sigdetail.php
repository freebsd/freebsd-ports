*** /usr/local/www/snortreport/sigdetail.php	Thu Dec 22 06:07:07 2005
--- ./sigdetail.php	Thu Nov  9 14:28:57 2006
***************
*** 38,44 ****
  assert($beginTime < $endTime);
  
  $URLTimeConstraint = "beginTime=$beginTime&endTime=$endTime";
! $DBTimeConstraint = "(event.timestamp > " . $db->timestamp($beginTime) . " AND event.timestamp < " . $db->timestamp($endTime) . ")";
  
  $sigid = intval($sigid) or die("Invalid signature ID");
  
--- 38,44 ----
  assert($beginTime < $endTime);
  
  $URLTimeConstraint = "beginTime=$beginTime&endTime=$endTime";
! $DBTimeConstraint = "(".$db->timeSinceEpoch("event.timestamp")." > " . $db->timestamp($beginTime) . " AND ".$db->timeSinceEpoch("event.timestamp")." < " . $db->timestamp($endTime) . ")";
  
  $sigid = intval($sigid) or die("Invalid signature ID");
  
***************
*** 101,106 ****
--- 101,108 ----
  	}
  }
  
+ if (!empty($Sources)) {
+ 
  if (PROFILING) elapsedTimer(__FILE__ . ": " . __LINE__);
  // Get the total number of alerts for each source
  
***************
*** 327,332 ****
--- 329,336 ----
  print "<b><a href=\"sigdetail.php?$qs\">$anchor</a></b><br>\n";
  
  if (PROFILING) elapsedTimer(__FILE__ . ": " . __LINE__);
+ 
+ }
  
  require_once("page_bottom.php");
  
