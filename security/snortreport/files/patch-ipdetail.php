*** /usr/local/www/snortreport/ipdetail.php	Thu Dec 22 06:07:07 2005
--- ./ipdetail.php	Thu Nov  9 14:28:57 2006
***************
*** 40,48 ****
  
  // set up the SQL query
  if ($type == "src") {
! 	$query = "SELECT event.cid, event.sid, event.signature, event.timestamp, iphdr.ip_src, iphdr.ip_dst, iphdr.ip_ver, iphdr.ip_hlen, iphdr.ip_tos, iphdr.ip_len, iphdr.ip_id, iphdr.ip_flags, iphdr.ip_off, iphdr.ip_ttl, iphdr.ip_proto, iphdr.ip_csum, signature.sig_name, signature.sig_id, signature.sig_sid FROM event, iphdr, signature WHERE event.cid = iphdr.cid AND event.sid = iphdr.sid AND event.signature = signature.sig_id AND iphdr.ip_src = ".$ipAddress." AND event.timestamp > ".$db->timestamp($beginTime)." AND event.timestamp < ".$db->timestamp($endTime) or die("Error in query");
  } else {
! 	$query = "SELECT event.cid, event.sid, event.signature, event.timestamp, iphdr.ip_src, iphdr.ip_dst, iphdr.ip_ver, iphdr.ip_hlen, iphdr.ip_tos, iphdr.ip_len, iphdr.ip_id, iphdr.ip_flags, iphdr.ip_off, iphdr.ip_ttl, iphdr.ip_proto, iphdr.ip_csum, signature.sig_name, signature.sig_id, signature.sig_sid FROM event, iphdr, signature WHERE event.cid = iphdr.cid AND event.sid = iphdr.sid AND event.signature = signature.sig_id AND iphdr.ip_dst = ".$ipAddress." AND event.timestamp > ".$db->timestamp($beginTime)." AND event.timestamp < ".$db->timestamp($endTime) or die("Error in query");
  }
  
  // run the query on the database
--- 40,48 ----
  
  // set up the SQL query
  if ($type == "src") {
! 	$query = "SELECT event.cid, event.sid, event.signature, ".$db->timeSinceEpoch('event.timestamp').", iphdr.ip_src, iphdr.ip_dst, iphdr.ip_ver, iphdr.ip_hlen, iphdr.ip_tos, iphdr.ip_len, iphdr.ip_id, iphdr.ip_flags, iphdr.ip_off, iphdr.ip_ttl, iphdr.ip_proto, iphdr.ip_csum, signature.sig_name, signature.sig_id, signature.sig_sid FROM event, iphdr, signature WHERE event.cid = iphdr.cid AND event.sid = iphdr.sid AND event.signature = signature.sig_id AND iphdr.ip_src = ".$ipAddress." AND ".$db->timeSinceEpoch('event.timestamp')." > ".$db->timestamp($beginTime)." AND ".$db->timeSinceEpoch("event.timestamp")." < ".$db->timestamp($endTime) or die("Error in query");
  } else {
! 	$query = "SELECT event.cid, event.sid, event.signature, ".$db->timeSinceEpoch("event.timestamp").", iphdr.ip_src, iphdr.ip_dst, iphdr.ip_ver, iphdr.ip_hlen, iphdr.ip_tos, iphdr.ip_len, iphdr.ip_id, iphdr.ip_flags, iphdr.ip_off, iphdr.ip_ttl, iphdr.ip_proto, iphdr.ip_csum, signature.sig_name, signature.sig_id, signature.sig_sid FROM event, iphdr, signature WHERE event.cid = iphdr.cid AND event.sid = iphdr.sid AND event.signature = signature.sig_id AND iphdr.ip_dst = ".$ipAddress." AND ".$db->timeSinceEpoch("event.timestamp")." > ".$db->timestamp($beginTime)." AND ".$db->timeSinceEpoch("event.timestamp")." < ".$db->timestamp($endTime) or die("Error in query");
  }
  
  // run the query on the database
