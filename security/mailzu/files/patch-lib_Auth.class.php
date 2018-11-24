--- lib/Auth.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/Auth.class.php
@@ -43,42 +43,42 @@ class Auth {
 	*  and start the session
 	* @param none
 	*/
-	//function Auth() {
+	//public static function Auth() {
 	//	$this->db = new AuthDB();
 	//}
 
 	/**
 	* Check if user is a super administrator
-	* This function checks to see if the currently
+	* This public static function checks to see if the currently
 	*  logged in user is the administrator, granting
 	*  them special permissions
 	* @param none
 	* @return boolean whether the user is a s_admin
 	*/
-	function isAdmin() {
+	public static function isAdmin() {
 		return isset($_SESSION['sessionAdmin']);
 	}
 
 	/**
         * Check if user is a mail administrator
-        * This function checks to see if the currently
+        * This public static function checks to see if the currently
         *  logged in user is the administrator, granting
         *  them special permissions
         * @param none
         * @return boolean whether the user is a m_admin
         */
-        function isMailAdmin() {
+        public static function isMailAdmin() {
                 return (isset($_SESSION['sessionMailAdmin']) || isset($_SESSION['sessionAdmin']));
         }
 
 	/**
 	* Check user login
-	* This function checks to see if the user has
+	* This public static function checks to see if the user has
 	* a valid session set (if they are logged in)
 	* @param none
 	* @return boolean whether the user is logged in
 	*/
-	function is_logged_in() {
+	public static function is_logged_in() {
 		return isset($_SESSION['sessionID']);
 	}
 	
@@ -87,7 +87,7 @@ class Auth {
 	* @param none
 	* @return the userid, or null if the user is not logged in
 	*/
-	function getCurrentID() {
+	public static function getCurrentID() {
 		return $_SESSION['sessionID'];//isset($_SESSION['sessionID']) ? $_SESSION['sessionID'] : null;
 	}
 
@@ -281,7 +281,7 @@ class Auth {
 		}
 	}
 
-	function isAllowedToLogin( $username ) {
+	public static function isAllowedToLogin( $username ) {
 
 		global $conf;
 
@@ -333,7 +333,7 @@ class Auth {
 	* @param none
 	* @return whether the user is attempting to log in
 	*/
-	function isAttempting() {
+	public static function isAttempting() {
 		return $this->is_attempt;
 	}
 
@@ -341,7 +341,7 @@ class Auth {
 	* Kills app
 	* @param none
 	*/
-	function kill() {
+	public static function kill() {
 		die;
 	}
 
@@ -349,7 +349,7 @@ class Auth {
 	* Destroy any lingering sessions
 	* @param none
 	*/
-	function clean() {
+	public static function clean() {
 		// Destroy all session variables
 		unset($_SESSION['sessionID']);
 		unset($_SESSION['sessionName']);
@@ -359,11 +359,11 @@ class Auth {
 	}
 
 	/**
-	* Wrapper function to call template 'printLoginForm' function
+	* Wrapper public static function to call template 'printLoginForm' function
 	* @param string $msg error messages to display for user
 	* @param string $resume page to resume after a login
 	*/
-	function printLoginForm($msg = '', $resume = '') {
+	public static function printLoginForm($msg = '', $resume = '') {
 		printLoginForm($msg, $resume);
 	}
 
@@ -371,7 +371,7 @@ class Auth {
 	* Prints a message telling the user to log in
 	* @param boolean $kill whether to end the program or not
 	*/
-	function print_login_msg($kill = true) {
+	public static function print_login_msg($kill = true) {
 		CmnFns::redirect(CmnFns::getScriptURL() . '/index.php?auth=no&resume=' . urlencode($_SERVER['PHP_SELF']) . '?' . urlencode($_SERVER['QUERY_STRING']));
 	}
 	
@@ -379,7 +379,7 @@ class Auth {
 	* Prints out the latest success box
 	* @param none
 	*/
-	function print_success_box() {
+	public static function print_success_box() {
 		CmnFns::do_message_box($this->success);
 	}
 }
