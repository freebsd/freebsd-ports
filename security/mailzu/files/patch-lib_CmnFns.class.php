--- lib/CmnFns.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/CmnFns.class.php
@@ -53,7 +53,7 @@ class CmnFns {
 	* @param double $time time to convert in minutes
 	* @return string time in 12 hour time
 	*/
-	function formatTime($time) {
+	public static function formatTime($time) {
 		global $conf;
 		
 		// Set up time array with $timeArray[0]=hour, $timeArray[1]=minute
@@ -82,7 +82,7 @@ class CmnFns {
 	* @param string $date string (yyyy-mm-dd)
 	* @return int timestamp
 	*/
-	function formatDateISO($date) {
+	public static function formatDateISO($date) {
 
 		$time = strtotime($date);
 		return $time;
@@ -94,7 +94,7 @@ class CmnFns {
 	* @param string $format format to put datestamp into
 	* @return string date as $format or as default format
 	*/
-	function formatDate($date, $format = '') {
+	public static function formatDate($date, $format = '') {
 		global $dates;
 		
 		if (empty($format)) $format = $dates['general_date'];
@@ -108,7 +108,7 @@ class CmnFns {
 	* @param string $format format to put datestamp into
 	* @return string date/time as $format or as default format
 	*/
-	function formatDateTime($ts, $format = '') {
+	public static function formatDateTime($ts, $format = '') {
 		global $conf;
 		global $dates;
 		
@@ -123,7 +123,7 @@ class CmnFns {
 	* @param int $minutes minutes to convert
 	* @return string version of hours and minutes
 	*/
-	function minutes_to_hours($minutes) {
+	public static function minutes_to_hours($minutes) {
 		if ($minutes == 0)
 			return '0 ' . translate('hours');
 			
@@ -137,7 +137,7 @@ class CmnFns {
 	* @param none
 	* @return url url of curent script directory
 	*/
-	function getScriptURL() {
+	public static function getScriptURL() {
 		global $conf;
 		$uri = $conf['app']['weburi'];
 		return (strrpos($uri, '/') === false) ? $uri : substr($uri, 0, strlen($uri));
@@ -150,7 +150,7 @@ class CmnFns {
 	* @param string $style inline CSS style definition to apply to box
 	* @param boolean $die whether to kill the app or not
 	*/
-	function do_error_box($msg, $style='', $die = true) {
+	public static function do_error_box($msg, $style='', $die = true) {
 		global $conf;
 		
 		echo '<table border="0" cellspacing="0" cellpadding="0" align="center" class="alert" style="' . $style . '"><tr><td>' . $msg . '</td></tr></table>';
@@ -171,7 +171,7 @@ class CmnFns {
 	* @param string $msg message to print out
 	* @param string $style inline CSS style definition to apply to box
 	*/
-	function do_message_box($msg, $style='') {
+	public static function do_message_box($msg, $style='') {
 		echo '<table border="0" cellspacing="0" cellpadding="0" align="center" class="message" style="' . $style . '"><tr><td>' . $msg . '</td></tr></table>';
 	}
 	
@@ -181,7 +181,7 @@ class CmnFns {
 	* @param none
 	* @return Link object
 	*/
-	function getNewLink() {
+	public static function getNewLink() {
 		return new Link();
 	}
 	
@@ -191,7 +191,7 @@ class CmnFns {
 	* @param none
 	* @return Pager object
 	*/
-	function getNewPager() {
+	public static function getNewPager() {
 		return new Pager();
 	}
 	
@@ -200,7 +200,7 @@ class CmnFns {
 	* @param none
 	* @return array of cleaned up POST values
 	*/
-	function cleanPostVals() {
+	public static function cleanPostVals() {
 		$return = array();
 		
 		foreach ($_POST as $key => $val)
@@ -214,7 +214,7 @@ class CmnFns {
 	* @param none
 	* @return array of cleaned up data
 	*/
-	function cleanVals($data) {
+	public static function cleanVals($data) {
 		$return = array();
 		
 		foreach ($data as $key => $val)
@@ -228,7 +228,7 @@ class CmnFns {
 	* @param string $vert value of vertical order
 	* @return string vertical order
 	*/
-	function get_vert_order($get_name = 'vert') {
+	public static function get_vert_order($get_name = 'vert') {
 		// If no vertical value is specified, use DESC
 		$vert = isset($_GET[$get_name]) ? $_GET[$get_name] : 'DESC';
 	    
@@ -251,7 +251,7 @@ class CmnFns {
 	* @param array $orders all valid order names
 	* @return string order of recorset
 	*/
-	function get_value_order($orders = array(), $get_name = 'order') {
+	public static function get_value_order($orders = array(), $get_name = 'order') {
 		if (empty($orders))		// Return null if the order array is empty
 			return NULL;
 			
@@ -269,12 +269,12 @@ class CmnFns {
 	
 	
 	/**
-	* Opposite of php's nl2br function.
+	* Opposite of php's nl2br public static function.
 	* Subs in a newline for all brs
 	* @param string $subject line to make subs on
 	* @return reformatted line
 	*/
-	function br2nl($subject) {
+	public static function br2nl($subject) {
 		return str_replace('<br />', "\n", $subject);
 	}
 	
@@ -284,7 +284,7 @@ class CmnFns {
 	* @param string $userid memeber id of user performing the action
 	* @param string $ip ip address of user performing the action
 	*/
-	function write_log($string, $userid = NULL, $ip = NULL) {
+	public static function write_log($string, $userid = NULL, $ip = NULL) {
 		global $conf;
 		$delim = "\t";
 		$file = $conf['app']['logfile'];
@@ -319,7 +319,7 @@ class CmnFns {
 	* @param int $day_of_week day of the week
 	* @param int $type how to return the day name (0 = full, 1 = one letter, 2 = two letter, 3 = three letter)
 	*/
-	function get_day_name($day_of_week, $type = 0) {
+	public static function get_day_name($day_of_week, $type = 0) {
 		global $days_full;
 		global $days_abbr;
 		global $days_letter;
@@ -343,7 +343,7 @@ class CmnFns {
 	* @param string $location new http location
 	* @param int $time time in seconds to wait before redirect
 	*/ 
-	function redirect($location, $time = 0, $die = true) {
+	public static function redirect($location, $time = 0, $die = true) {
 		header("Refresh: $time; URL=$location");
 		if ($die) exit;
 	}
@@ -352,7 +352,7 @@ class CmnFns {
 	* Prints out the HTML to choose a language
 	* @param none
 	*/
-	function print_language_pulldown() {
+	public static function print_language_pulldown() {
 		global $conf;
 		?>
 		<select name="language" class="textbox" onchange="changeLanguage(this);">
@@ -375,7 +375,7 @@ class CmnFns {
 	* @param string $str string to search for links to create
 	* @return string with 'URL-like' text changed into clickable links
 	*/
-	function html_activate_links($str) {
+	public static function html_activate_links($str) {
 		$str = eregi_replace('(((f|ht){1}tp://)[-a-zA-Z0-9@:%_+.~#?&//=]+)', '<a href="\1" target="_blank">\1</a>', $str);
 		$str = eregi_replace('([[:space:]()[{}])(www.[-a-zA-Z0-9@:%_+.~#?&//=]+)', '\1<a href="http://\2" target="_blank">\2</a>', $str);
 		$str = eregi_replace('([_.0-9a-z-]+@([0-9a-z][0-9a-z-]+.)+[a-z]{2,3})','<a href="mailto:\1">\1</a>', $str);
@@ -388,7 +388,7 @@ class CmnFns {
 	* @param integer $page value of current page number
 	* @return integer current page number
 	*/
-	function get_current_page_number($get_name = 'page') {
+	public static function get_current_page_number($get_name = 'page') {
 		// If no page number is specified, use 0
 		$page = ( isset($_GET[$get_name]) && is_numeric($_GET[$get_name]) )  ? $_GET[$get_name] : 0;
 		return $page;
@@ -399,7 +399,7 @@ class CmnFns {
         * @param none
         * @return string mail_id
         */
-        function get_mail_id($get_name = 'mail_id') {
+        public static function get_mail_id($get_name = 'mail_id') {
                 // If there isnt one set, return NULL
                 $mail_id = (isset($_GET[$get_name])) ? $_GET[$get_name] : NULL;
                 return $mail_id;
@@ -413,7 +413,7 @@ class CmnFns {
 	* @param array $exclude_vars to be excluded from the resulting string
 	* @param boolean $url_encode_ampersands
 	*/
-	function array_to_query_string( $array, $exclude_vars=array(), $url_encode_ampersands=true )
+	public static function array_to_query_string( $array, $exclude_vars=array(), $url_encode_ampersands=true )
 	{
 		if( ! is_array( $array ) )
 			return '';
@@ -441,7 +441,7 @@ class CmnFns {
 	* @param integer $sizeLimit maximum number of messages per page
 	* @param integer $count total number of messages
 	*/
-	function genMultiPagesLinks( $page, $sizeLimit, $count) {
+	public static function genMultiPagesLinks( $page, $sizeLimit, $count) {
 		global $link;
 
 		$total_pages = $count / $sizeLimit;
@@ -501,7 +501,7 @@ class CmnFns {
 	* Generate HTML for search engine
 	* @param $content_type: 'B' (attachment) or 'S' (spam)
 	*/
-	function searchEngine($content_type, $submit_page, $full_search = false) {
+	public static function searchEngine($content_type, $submit_page, $full_search = false) {
 		global $conf;
 
 		$fields_array = array("f" => translate('From'), 
@@ -579,7 +579,7 @@ class CmnFns {
         * @param none
         * @return value boolean
         */
-        function didSearch() {
+        public static function didSearch() {
 		$return = false;
 		$strings = array('f_string','s_string','t_string','m_string');
 		foreach ($strings as $string) {
@@ -593,7 +593,7 @@ class CmnFns {
         * @param array of variables to exclude
 	* @return query string
 	*/
-	function querystring_exclude_vars( $excl_array = array() ) {
+	public static function querystring_exclude_vars( $excl_array = array() ) {
 		return CmnFns::array_to_query_string( $_GET, $excl_array );
 	}	
 
@@ -602,7 +602,7 @@ class CmnFns {
         * @param none
         * @return value
         */
-        function get_ctype($get_name = 'ctype') {
+        public static function get_ctype($get_name = 'ctype') {
                 // If there isnt one set, return NULL
                 $result = NULL;
 		if ( isset($_GET[$get_name]) )
@@ -617,7 +617,7 @@ class CmnFns {
         * @param none
         * @return value
         */
-        function get_action($get_name = 'action') {
+        public static function get_action($get_name = 'action') {
                 // If there isnt one set, return NULL
                 $result = (isset($_POST[$get_name])) ? $_POST[$get_name] : NULL;
                 return $result;
@@ -628,7 +628,7 @@ class CmnFns {
         * @param none
         * @return value
         */
-        function get_query_string($get_name = 'query_string') {
+        public static function get_query_string($get_name = 'query_string') {
                 // If there isnt one set, return NULL
                 $result = (isset($_POST[$get_name])) ? $_POST[$get_name] : NULL;
                 return $result;
@@ -656,7 +656,7 @@ class CmnFns {
 	*	INORDER, SESSION, FORM, POST, GET, SERVER
  	* @return value of var
  	*/
-        function getGlobalVar($name, $search = INORDER) {
+        public static function getGlobalVar($name, $search = INORDER) {
 
 		switch ($search) {
 			
@@ -699,7 +699,7 @@ class CmnFns {
 	* Redirect using javascript
 	* @param $location string
 	*/
-	function redirect_js($location) {
+	public static function redirect_js($location) {
 		        echo "<SCRIPT LANGUAGE=\"JavaScript\">";
                        	echo "parent.location.href = '" . $location . "';";
         		echo "</SCRIPT>";
