--- html/torrentspy.php	Sat Oct 15 11:48:01 2005
+++ html/torrentspy.php	Sat Oct 15 12:01:29 2005
@@ -22,12 +22,13 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
-// Original code posted by heddock in the TorrentFlux forums, modified by Qrome
+// Original code posted by heddock in the TorrentFlux forums, modified by Qrome and Kboy
 
 include_once("config.php");
 include_once("functions.php");
 
 $msg = "";
+$thing = "";
 
 // Try to connect
 if (!$fp = @fsockopen ("www.torrentspy.com", 80, $errno, $errstr, 30))
@@ -42,11 +43,15 @@
 	
 	// break the search terms up so they can be handled by the search engine
 	$searchterm=str_replace(" ", "+",$_REQUEST["spysearch"]);
+	if (empty($searchterm))
+	{
+		$searchterm = $_REQUEST["query"];
+	}
 	
 	
-	if ($_REQUEST["genre"] != "")
+	if ($_REQUEST["mainGenre"] != "")
 	{
-		$request = 'GET /directory.asp?mode=sub&id='. $_REQUEST["genre"] . ' HTTP/1.1' ."\r\n".
+		$request = 'GET /directory.asp?mode=main&id='. $_REQUEST["mainGenre"] . ' HTTP/1.1' ."\r\n".
 		           'Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*' ."\r\n".
 		           'Referer: http://www.torrentspy.com/latest.asp' ."\r\n".
 		           'Accept-Language: en-us' ."\r\n".
@@ -57,11 +62,11 @@
 	}
 	else
 	{
-		if ($_REQUEST["LATEST"] != 1)
+		if ($_REQUEST["subGenre"] != "")
 		{
-			$request = 'GET /search.asp?query='. $searchterm . '&submit.x=24&submit.y=10 HTTP/1.1' ."\r\n".
+			$request = 'GET /directory.asp?mode=sub&id='. $_REQUEST["subGenre"] . ' HTTP/1.1' ."\r\n".
 		           'Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*' ."\r\n".
-		           'Referer: http://www.torrentspy.com/' ."\r\n".
+					   'Referer: http://www.torrentspy.com/latest.asp' ."\r\n".
 		           'Accept-Language: en-us' ."\r\n".
 		           'User-Agent: '.$_SERVER['HTTP_USER_AGENT'] ."\r\n".
 		           'Host: www.torrentspy.com' ."\r\n".
@@ -70,7 +75,32 @@
 		}
 		else
 		{
-			$request = 'GET /latest.asp HTTP/1.1' ."\r\n".
+			switch ($_REQUEST["LATEST"])
+			{
+				case "1":
+					$request = 'GET /latest.asp?pg='.$_REQUEST["pg"].' HTTP/1.1' ."\r\n".
+					   'Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*' ."\r\n".
+					   'Referer: http://www.torrentspy.com/' ."\r\n".
+					   'Accept-Language: en-us' ."\r\n".
+					   'User-Agent: '.$_SERVER['HTTP_USER_AGENT'] ."\r\n".
+					   'Host: www.torrentspy.com' ."\r\n".
+					   'Connection: Close' ."\r\n".
+					   'Cookie: ' ."\r\n\r\n";
+				break;
+				
+				case "-1":
+					$request = 'GET /directory.asp?mode='.$_REQUEST["mode"].'&id='.$_REQUEST["id"].'&pg='.$_REQUEST["pg"].'&submit.x=24&submit.y=10 HTTP/1.1' ."\r\n".
+					   'Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*' ."\r\n".
+					   'Referer: http://www.torrentspy.com/' ."\r\n".
+					   'Accept-Language: en-us' ."\r\n".
+					   'User-Agent: '.$_SERVER['HTTP_USER_AGENT'] ."\r\n".
+					   'Host: www.torrentspy.com' ."\r\n".
+					   'Connection: Close' ."\r\n".
+					   'Cookie: ' ."\r\n\r\n";
+				break;
+				
+				default:
+					$request = 'GET /search.asp?query='. $searchterm .'&pg='.$_REQUEST["pg"].'&db='.$_REQUEST["db"].'&submit.x=24&submit.y=10 HTTP/1.1' ."\r\n".
 		           'Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*' ."\r\n".
 		           'Referer: http://www.torrentspy.com/' ."\r\n".
 		           'Accept-Language: en-us' ."\r\n".
@@ -78,6 +108,8 @@
 		           'Host: www.torrentspy.com' ."\r\n".
 		           'Connection: Close' ."\r\n".
 		           'Cookie: ' ."\r\n\r\n";
+				break;
+			}
 		}
 	}
 	
@@ -92,9 +124,9 @@
 	}
 	fclose($fp);
 	
-	$thing = substr($thing,strpos($thing,"\r\n\r\n")+4);
+	//$thing = substr($thing,strpos($thing,"\r\n\r\n")+4);
 	
-	$thing = substr($thing,strpos($thing,"Torrent Name")+12);
+	//$thing = substr($thing,strpos($thing,"Torrent Name")+12);
 }
 
 DisplayHead("TorrentSpy "._SEARCH);
@@ -105,9 +137,21 @@
 echo "<td bgcolor=\"".$cfg["table_header_bg"]."\">";
 echo "<form name=\"form_url\" action=\"torrentspy.php\" method=\"post\">";
 echo _SEARCH." TorrentSpy:<br>";
-echo "<input type=\"text\" name=\"spysearch\" value=\"".$_REQUEST["spysearch"]."\" size=30  maxlength=50>&nbsp;";
+echo "<input type=\"text\" name=\"spysearch\" value=\"".$searchterm."\" size=30  maxlength=50>&nbsp;";
 echo "<input type=\"Submit\" value=\""._SEARCH."\">&nbsp;&nbsp;<a href=\"torrentspy.php?LATEST=1\"><img src=\"images/properties.png\" width=18 height=13 title=\"Show Latest Torrents\" align=\"absmiddle\" border=0>Show Latest Torrents</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Visit: <a href=\"http://www.torrentspy.com/\" target=\"_blank\">TorrentSpy.com</a><br><br>";
-echo "* Click on Torrent Links to add them to the Torrent Download List";
+echo "* Click on Torrent Links to add them to the Torrent Download List<br><br>";
+echo "<div align=center>";
+echo "<a href=\"torrentspy.php?mainGenre=2\">Games</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=4\">Movies</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=5\">TV</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=3\">Music</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=1\">Applications</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=6\">Anime</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=8\">Linux</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=9\">Macintosh</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=10\">Misc</a> | ";
+echo "<a href=\"torrentspy.php?mainGenre=12\">Unsorted/Other</a>";
+echo "</div>";
 echo "</td></tr></form></table>";
 echo "</div>";
 
@@ -120,6 +164,28 @@
 }
 else
 {
+	if ($_REQUEST["mainGenre"] != "")
+	{
+		echo "<br>";
+		echo "<tr bgcolor=\"".$cfg["table_header_bg"]."\">";
+		echo "<td colspan=6><form method=get action=torrentspy.php?>";
+		$thing = substr($thing,strpos($thing,"Torrent Directory:")+strlen("Torrent Directory:"));
+		echo "Category: <b>".substr($thing,0,strpos($thing,"<"))."</a></b> -> ";
+		echo "<select name=subGenre>";
+		while (is_integer(strpos($thing,"directory.asp?mode=sub&id=")))
+		{
+			$thing = substr($thing,strpos($thing,"directory.asp?mode=sub&id=")+strlen("directory.asp?mode=sub&id="));
+			$subid = substr($thing,0,strpos($thing,"&"));
+			$thing = substr($thing,strpos($thing,"&cat=")+strlen("&cat="));
+			$subname = substr($thing,0,strpos($thing,"\""));
+			echo "<option value=".$subid.">".$subname."</option>";
+		}
+		echo "</select> ";
+		echo "<input type=submit value='Show Latest'>";
+		echo "</form>";
+	}
+	else
+	{
 	echo "<br>";
 	echo "<tr bgcolor=\"".$cfg["table_header_bg"]."\">";
 	echo "	<td>&nbsp;</td>";
@@ -130,13 +196,11 @@
 	echo "	<td><strong>Peers</strong></td>";
 	echo "</tr>";
 	// We got a response so display it.
-	while (is_integer(strpos($thing,"<tr bgcolor")))
+		while (is_integer(strpos($thing,"download.asp?id=")))
 	{
-		$thing = substr($thing,strpos($thing,"<tr bgcolor")+3);
-		$thing = substr($thing,strpos($thing,"<td width=")+10);
-		$thing = substr($thing,strpos($thing,"href=")+6);
+			$thing = substr($thing,strpos($thing,"download.asp?id=")+strlen("download.asp?id="));
 		$link = substr($thing,0,strpos($thing,"\""));
-		$link = "http://www.torrentspy.com/" . $link;
+			$link = "http://www.torrentspy.com/download.asp?id=" . $link;
 		
 		$thing = substr($thing,strpos($thing,"title=")+7);
 		$thing = substr($thing,strpos($thing,"title=")+7);
@@ -148,29 +212,65 @@
 			$displayname .= "...";
 		}
 		
-		$thing = substr($thing,strpos($thing,"<td width=")+10);
+			$thing = substr($thing,strpos($thing,"directory.asp?mode=")+strlen("directory.asp?mode="));
+			$modeType = substr($thing,0,strpos($thing,"&"));
+
+
+			// Empty out vars
+			$mainid = "";
+			$subid = "";
+			$mainGenre = "";
+			$subGenre = "";
+
+			if ( $modeType == "main" )
+			{
 		$thing = substr($thing,strpos($thing,"id=")+3);
-		$gid = substr($thing,0,strpos($thing,"\""));
+				$mainid = substr($thing,0,strpos($thing,"\""));
 		
 		$thing = substr($thing,strpos($thing,">")+1);
-		$genre = substr($thing,0,strpos($thing,"<"));
+				$mainGenre = substr($thing,0,strpos($thing,"<"));
+
+				$thing = substr($thing,strpos($thing,"id=")+3);
+				$subid = substr($thing,0,strpos($thing,"\""));
 		
-		$thing = substr($thing,strpos($thing,"<td width=")+10);
 		$thing = substr($thing,strpos($thing,">")+1);
-		$size = substr($thing,0,strpos($thing,"<"));
+				$subGenre = substr($thing,0,strpos($thing,"<"));
+
+			}
+			else
+			{
+				$thing = substr($thing,strpos($thing,"id=")+3);
+				$subid = substr($thing,0,strpos($thing,"\""));
 		
-		$thing = substr($thing,strpos($thing,"<td width=")+10);
 		$thing = substr($thing,strpos($thing,">")+1);
+				$subGenre = substr($thing,0,strpos($thing,"<"));
+			}
+
+
+			$thing = substr($thing,strpos($thing,"<td nowrap>")+11);
+			$size = substr($thing,0,strpos($thing,"<"));
+
+
+			$thing = substr($thing,strpos($thing,"<td nowrap>")+11);
 		$files = substr($thing,0,strpos($thing,"<"));
 		
-		$thing = substr($thing,strpos($thing,"<td width=")+10);
-		$thing = substr($thing,strpos($thing,">")+1);
+
+			$thing = substr($thing,strpos($thing,"<td nowrap>")+11);
 		$seeds = substr($thing,0,strpos($thing,"<"));
 		
-		$thing = substr($thing,strpos($thing,"<td width=")+10);
-		$thing = substr($thing,strpos($thing,">")+1);
+			if ($seeds == "")
+			{
+				$seeds = "NA";
+			}
+
+			$thing = substr($thing,strpos($thing,"<td nowrap>")+11);
 		$peers = substr($thing,0,strpos($thing,"<"));
+			if ($peers == "")
+			{
+				$peers = "NA";
+			}
 	 
+			// See what the bg color is and switch it
 		if ($bg == $cfg["bgLight"])
 		{
 			$bg = $cfg["bgDark"];
@@ -181,17 +281,68 @@
 		}
 		 
 		
+			// Ok hide the rows that don't have seed info
+			//if ($seeds != "NA" )
+			//{
 		echo "<tr>";
-		echo "	<td width=16 bgcolor=\"".$bg."\"><a href=\"index.php?url_upload=".$link."\"><img src=\"images/download_owner.gif\" width=\"16\" height=\"16\" title=\"".$title."\" border=0></a></td>";
+				echo "	<td width=16 bgcolor=\"".$bg."\"><a href=\"index.php?url_upload=".$link."\"><img src=\"images/download_owner.gif\" width=\"16\" height=\"16\" title=\"".$title." - ".$files." "._FILE."\" border=0></a></td>";
 		echo "	<td bgcolor=\"".$bg."\"><a href=\"index.php?url_upload=".$link."\" title=\"".$title."\">".$displayname."</a></td>";
-		echo "	<td bgcolor=\"".$bg."\"><a href=\"torrentspy.php?genre=".$gid."\">". $genre ."</a></td>";
+
+				if (strlen($mainGenre) > 1)
+				{
+					if (strlen($subGenre) > 1)
+					{
+						$mainGenre = "<a href=\"torrentspy.php?mainGenre=".$mainid."\">". $mainGenre ."</a>";
+						$subGenre = "<a href=\"torrentspy.php?subGenre=".$subid."\">". $subGenre ."</a>";
+						$genre = $mainGenre."-".$subGenre;
+					}
+					else
+					{
+						$genre = "<a href=\"torrentspy.php?mainGenre=".$mainid."\">". $mainGenre ."</a>";
+					}
+				}
+				else
+				{
+						$genre = "<a href=\"torrentspy.php?subGenre=".$subid."\">". $subGenre ."</a>";
+				}
+
+				echo "	<td bgcolor=\"".$bg."\">". $genre ."</td>";
+
+				//echo "	<td bgcolor=\"".$bg."\"><a href=\"torrentspy.php?genre=".$gid."\">". $genre ."</a></td>";
+
 		echo "	<td bgcolor=\"".$bg."\" align=right>".$size."</td>";
 		echo "	<td bgcolor=\"".$bg."\" align=center>". $seeds."</td>";
 		echo "	<td bgcolor=\"".$bg."\" align=center>". $peers."</td>";
 		echo "</tr>";
+			//}
+		}
 	}
 }
 echo "</table>";
+
+// is there paging at the bottom?
+if (strpos($thing, "<p class=\"pagenav\">Pages (") !== false)
+{
+	// Yes, then lets grab it and display it!  ;)
+	$thing = substr($thing,strpos($thing,"<p class=\"pagenav\">Pages (")+strlen("<p class=\"pagenav\">"));
+	$pages = substr($thing,0,strpos($thing,"</p>"));
+	$pages = str_replace("<img src=\"gfx/icons/pages.gif\" width=\"10\" height\"12\"> ", "", $pages);
+	if (strpos($pages, "search.asp?"))
+	{
+		$pages = str_replace("search.asp?", "torrentspy.php?LATEST=0&", $pages);
+	}
+	if (strpos($pages, "directory.asp?"))
+	{
+		//http://qrome/torrent/directory.asp?mode=sub&id=12&pg=3
+		$pages = str_replace("directory.asp?", "torrentspy.php?LATEST=-1&", $pages);
+	}
+	if (strpos($pages, "latest.asp?"))
+	{
+		$pages = str_replace("latest.asp?", "torrentspy.php?LATEST=1&", $pages);
+	}
+	
+	echo "<br><div align=center>".$pages."</div><br>";
+}
 
 DisplayFoot();
 ?>
