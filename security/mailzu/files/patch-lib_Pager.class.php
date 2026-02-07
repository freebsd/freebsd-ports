--- lib/Pager.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/Pager.class.php
@@ -1,629 +1,629 @@
-<?php
-/**
-* Paging class to iterate through limited recordsets
-* @author Nick Korbel <lqqkout13@users.sourceforge.net>
-* @version 02-02-05
-* @package Pager
-*
-* Copyright (C) 2003 - 2005 phpScheduleIt
-* License: GPL, see LICENSE
-* /
-/**
-* To actually print out page links, call printPages() function
-*
-* In order for this object to work correctly, total records
-*  must be set in either the constructor or by calling
-*  setTotRecords()
-*
-* + Warning - The printPages() function cannot be called
-* 			from within a form
-*
-* === EXAMPLE OF HOW TO USE PAGER ===
-* // Initialize new Pager object with default values
-* $pager = new Pager();
-*
-* // Get total # of pages
-* $query = "SELECT COUNT(*) as num FROM table";
-* $result = $db->query($query);    
-* $rs = $result->fetchRow();
-* $num = $rs['num'];              // # of records
-*
-* $pager->setTotRecords($num);
-* $recordset_offset = $pager->getOffset();
-* $limit = $pager->getLimit();
-*
-* // Execute Query (using $offset and $limit values) //
-*
-* $pager->printPages();
-* ==========================================
-*
-*/
-
-// Should we use the Link class?
-$use_link = true;
-
-if ($use_link) {
-	//include_once('Link.class.php');
-	$link = new Link();
-}
-
-class Pager {
-	// Application set variables
-	var $cur_page;
-	var $query_string;
-	var $tot_pages;
-	var $page_var;
-	var $limit_var;
-	
-	// Application variables with user modify option
-	var $limit;
-	var $tot_records;
-	var $print_limit_select = true;
-	
-	// User modifiable variables
-	var $prev_link = '&laquo;';
-	var $next_link = '&raquo;';
-	var $limits = array(10, 25, 50, 100);
-	var $view_pages = 3;
-	var $table_width = '100%';
-	var $table_align = 'center';
-	var $link_class;
-	var $tb_class;
-	var $tb_style;
-	var $text_class;
-	var $text_style;
-	
-		
-	/**
-	* Pager Constructor
-	* Sets up Pager variables and initializes values
-	*
-	* - All parameters are optional and have default values of:
-	*    $tot_records = 0
-	*    $limit = 25
-	*    $page_var = "page"
-	*    $limit_var = "limit"
-	*
-	* @param int $tot_records optional total number of records
-	* @param int $limit optional limit of recordset
-	* @param string $page_var optional name of var to use in querystring for page value
-	* @param string $limit_var optional name of var to use in querystring for limit value
-	*/
-	function Pager($tot_records=0, $limit=25, $page_var='page', $limit_var='limit') {
-		$this->tot_records = $tot_records;
-		$this->limit = $limit;
-		$this->page_var = $page_var;
-		$this->limit_var = $limit_var;
-		
-		// Call all system setter functions
-		$this->initCurPage();
-		$this->initLimit();
-		$this->initTotPages();
-		$this->initQueryString();
-	}
-	
-	
-	/**
-	* Print out the pages as links
-	* Prints out a table of all the pages as links
-	*  and a jump menu to change the number of records
-	*  per page
-	*
-	* setCurPage() and setTotPages() must be called
-	*  before this function can be called
-	*
-	* @param none
-	* @see printPrev()
-	* @see printLink()
-	* @see printPage()
-	* @see printNext()
-	* @see printTotal()
-	* @see startTable()
-	* @see startPagesCell()
-	* @see endPagesCell()
-	* @see printLimitCell()
-	* @see endTable()
-	*/
-	function printPages() {
-		$p = $this->view_pages;			// How many pages to view
-		$cur_page = $this->cur_page;	// Current page
-		$tot_pages = $this->tot_pages;	// Total pages
-		
-		// Open up the HTML table
-		$this->startTable();
-		// Open up cell for page links
-		$this->startPagesCell();
-		
-		// Page to start printing bulk of links
-		$start = ($cur_page > $p) ? $cur_page - $p : 1;
-		// Page to end printing bulk of links
-		$end = ($cur_page + $p) < $tot_pages ? $cur_page + $p : $tot_pages;
-		
-		// Print 'prev' link
-		$this->printPrev();
-		
-		// Print link to first page, if not already there
-		if ($start != 1) {
-			$this->printPage(1);
-		}
-		
-		// Print '...' if necessary (with link to center page)
-		if ($cur_page > $p+2) {
-			$this->printLink(ceil( ($start+1)/2 ), '...');
-		}
-		
-		// Print links to pages before current page (up to first page)
-		// Print current page
-		// Print links to pages after current page (up to last page)		
-		for ($pg = $start; $pg <= $end; $pg++) {
-			$this->printPage($pg);
-		}
-				
-		// Print '...' if necessary (with link to center page)
-		if ( $cur_page < ($tot_pages - ($p+1)) ) {
-			$this->printLink(ceil( ($tot_pages+$end)/2 ), '...' );
-		}
-		
-		// Print link to last page, if not already there
-		if ($end != $tot_pages) {
-			$this->printPage($tot_pages);
-		}
-		
-		// Print 'next' link
-		$this->printNext();
-		
-		// Print total records
-		$this->printTotal();
-		
-		// Close page links cell
-		$this->endPagesCell();
-		// Print out cell with limit jump menu
-		if ($this->print_limit_select) { $this->printLimitCell(); }
-		// Close table
-		$this->endTable();
-	}
-	
-	//-----------------------------------------
-	// Application setter functions
-	//-----------------------------------------
-	/**
-	* Sets current page variable
-	* @param none
-	*/
-	function initCurPage() {
-		$this->cur_page = isset($_GET[$this->page_var]) ? intval($_GET[$this->page_var]) : 1;
-	}
-	
-	/**
-	* Sets the limit variable if it is passed from querystring
-	* @param none
-	*/
-	function initLimit() {
-		if (isset($_GET[$this->limit_var]))
-			$this->limit = intval($_GET[$this->limit_var]);
-		if (isset($_POST[$this->limit_var]))
-			$this->limit = intval($_POST[$this->limit_var]);
-	}
-	
-	/**
-	* Pull page information from query string and set $query_string
-	*
-	* setLimit() must be called before this function for it to work correctly
-	* @param none
-	*/
-	function initQueryString() {
-	    if (isset($_SERVER['QUERY_STRING'])) {
-			// Remove page from query string and convert all "&" to "&amp;"
-			$this->query_string = str_replace('&', '&amp;', preg_replace("/(&|&amp;)?$this->page_var=\d*/",'',$_SERVER['QUERY_STRING']));
-			
-			// Insert limit into querystring, if it's not there
-			if ( !strstr($this->query_string, "$this->limit_var=") )
-				$this->query_string .= "&amp;$this->limit_var=" . $this->limit;
-		}
-		else {
-			$this->query_string = '';
-		}
-
-	}
-	
-	/**
-	* Sets the tot_pages variable
-	*
-	* tot_records must be set and setLimit() must be called before
-	*  this function can be called
-	*
-	* @param none
-	*/
-	function initTotPages() {
-		$this->tot_pages = ceil($this->tot_records/$this->limit);
-	}
-	//===========================================
-	
-	//-------------------------------------------
-	// Output functions
-	//-------------------------------------------	
-	/**
-	* Print out link to a page
-	* @param int $p page number to print
-	*/
-	function printPage($p) {
-		if ($p == $this->cur_page) {
-			echo " <b>[$p]</b> ";
-		}
-		else {
-			$this->printLink($p, $p);
-		}
-	}
-	
-	/**
-	* Print 'prev' link, if necessary
-	* @param none
-	*/
-	function printPrev() {
-		$cur_page = $this->cur_page;
-		if ($cur_page > 1)
-			$this->printLink($cur_page-1, $this->prev_link);
-	}
-	
-	/**
-	* Print 'next' link, if necessary
-	* @param none
-	*/
-	function printNext() {
-		$cur_page = $this->cur_page;
-		if ($cur_page < $this->tot_pages && $this->tot_records > 0)
-			$this->printLink($cur_page+1, $this->next_link);
-	}
-	
-	/**
-	* Print out link to a certain page
-	* @param int $page page to link to
-	* @param string $text link text
-	*/
-	function printLink($page, $text) {
-		global $link;
-		global $use_link;
-		
-		if ($use_link) {
-			$link->doLink(
-				$_SERVER['PHP_SELF'] . "?$this->page_var=$page&amp;" . $this->query_string . '"',
-				$text,
-				$this->link_class,
-				'',
-				'Page ' . $page
-				);
-		}
-		else {
-			echo ' <a href="' . $_SERVER['PHP_SELF'] . "?$this->page_var=$page&amp;" . $this->query_string . '"'
-				. ' class="$this->class"'
-				. '>'
-				. $text . '</a> ';
-		}
-	}
-	
-	/**
-	* Prints out opening table tag
-	* @param none
-	*/
-	function startTable() {
-		echo "<table align=\"$this->table_align\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"$this->table_width\">\n"
-			. "<tr class=\"$this->text_class\" style=\"$this->text_style\">\n";	
-	}
-	
-	/**
-	* Begins cell containing page links
-	* @param none
-	*/
-	function startPagesCell() {
-		echo '<td>' . translate('Page') . ' ';
-	}
-	
-	/**
-	* Closes cell containing page links
-	* @param none
-	*/
-	function endPagesCell() {
-		echo '</td>';
-	} 
-	
-	/**
-	* Prints out cell containing limit jump menu
-	* @param none
-	*/
-	function printLimitCell() {
-		$limits = $this->limits;
-		echo "<td align=\"right\">\n"
-			. "<form name=\"limit_jump\" id=\"limit_jump\" method=\"post\" action=\"" . $_SERVER['PHP_SELF'] . "?" . preg_replace("/(&|&amp;)?$this->limit_var=\d*/", "", $this->query_string) . "\" style=\"margin: 0px;\">\n"
-			. translate('Per page') . " <select name=\"$this->limit_var\" onchange=\"document.limit_jump.submit();\" class=\"$this->tb_class\" style=\"$this->tb_style\">\n";
-		for ($i = 0; $i < count($limits); $i++) {
-			echo '<option value="' . $limits[$i] . '"';
-			if ($limits[$i] == $this->limit)
-				echo ' selected="selected"';
-			echo '>' . $limits[$i] . "</option>\n";
-		}
-		echo "</select>\n"
-			. "</form>\n"
-			. "</td>\n";
-	}
-	
-	/**
-	* Prints out the closing row and table HTML tags
-	* @param none
-	*/
-	function endTable() {
-		echo "</tr>\n</table>\n";
-	}
-	
-	/**
-	* Prints out total number of records returned
-	* @param none
-	*/
-	function printTotal() {
-		echo '(' . $this->tot_records . ')';
-	}
-	//============================================
-
-	//--------------------------------------------
-	// User-Modified Setter Functions
-	//--------------------------------------------	
-	/**
-	* Sets the total records for this recordset
-	* 
-	* - Default setting is 0 (in constructor)
-	*
-	* @param int $tot total number of records
-	*/
-	function setTotRecords($tot) {
-		$this->tot_records = intval($tot);
-		// Call initTotPages again to reset paging
-		$this->initTotPages();
-	}
-	
-	/**
-	* Sets the default recordset limit
-	* Note: A limit value set in the querystring
-	*  or in a post value will override this
-	*
-	* - Default setting is 25 (in constructor)
-	*
-	* @param int $limit new limit value
-	*/
-	function setLimit($limit) {
-		$this->limit = intval($limit);
-		// Call initLimit() to reinitialzie limit
-		$this->initLimit();
-	}
-	
-	/**
-	* Sets the text for 'prev' link
-	*
-	* - Default setting is "&laquo;"
-	*
-	* @param string $text link text
-	*/
-	function setPrevLink($text) {
-		$this->prev_link = trim($text);
-	}
-	
-	/**
-	* Sets the text for 'next' link
-	*
-	* - Default setting is "&raquo;"
-	*
-	* @param string $text link text
-	*/
-	function setNextLink($text) {
-		$this->next_link = trim($text);
-	}
-		
-	/**
-	* Sets the value of view_pages
-	* How many pages to print on either side of
-	* the currently viewed page number
-	*
-	* - Default setting is 3
-	*
-	* @param int $view_page how many pages to view
-	*/
-	function setViewPages($view_page) {
-		$this->view_pages = intval($view_page);
-	}
-	
-	/**
-	* Sets the array of limits
-	* Pass in an array of ints to use
-	* for the limit pull down menu
-	*
-	* - Default setting is (10, 25, 50, 100)
-	*
-	* @param int $new_limits array of limits
-	*/
-	function setLimits($new_limits) {
-		$this->limits = $new_limits;
-	}
-	
-	/**
-	* Sets the name of the class to be used for the links
-	*
-	* - Default setting is null
-	*
-	* @param string $link_class name of class
-	*/
-	function setLinkClass($link_class) {
-		$this->link_class = $link_class;
-	}
-	
-	/**
-	* Sets the name of the class to be used for the pull down box
-	*
-	* - Default setting is null
-	*
-	* @param string $tb_class name of class
-	*/
-	function setTbClass($tb_class) {
-		$this->tb_class = $tb_class;
-	}
-	
-	/**
-	* Sets the inline style of the limit jump menu
-	* This setting overrides the tb_class value
-	*
-	* - Default setting is null
-	* @param string $tb_style style of limit jump menu box
-	*/
-	function setTbStyle($tb_style) {
-		$this->tb_style = $tb_style;
-	}
-	
-	/**
-	* Sets the name of the class to be used for the text
-	*  ie) "Page:" and "Per page:"
-	* Should be used to modify all paging text font -amily, size, etc
-	*
-	* - Default setting is null
-	*
-	* @param string $text_class name of class
-	*/
-	function setTextClass($text_class) {
-		$this->text_class = $text_class;
-	}
-	
-	/**
-	* Sets the inline style to be used for the text
-	* Should be used to modifiy all paging text font-family, size, etc
-	* This will override the text_class setting
-	*
-	* - Default setting is null
-	*
-	* @param string $text_style style to use for the text
-	*/
-	function setTextStyle($text_style) {
-		$this->text_style = $text_style;
-	}
-	
-	/**
-	* Sets the width of the table bounding the pages/jump box
-	*
-	* - Default setting is "100%"
-	*
-	* @param string $table_width width of table
-	*/
-	function setTableWidth($table_width) {
-		$this->table_width = $table_width;
-	}
-	
-	/**
-	* Sets the horizontial alignment of the table bounding the paging
-	*
-	* - Default setting is "center"
-	*
-	* @param string $table_align alignment value for table align
-	*/
-	function setTableAlign($table_align) {
-		$this->table_align = $table_align;
-	}
-	
-	/**
-	* Sets the page variable name for the querystring
-	* @param string $page_var page variable name
-	*/
-	function setPageVar($page_var) {
-		$this->page_var = $page_var;
-	}
-	
-	/**
-	* Sets the limit variable name for the querystring
-	* @param string $limit_var limit variable name
-	*/
-	function setLimitVar($limit_var) {
-		$this->limit_var = $limit_var;
-	}
-	
-	/**
-	* Sets the print_limit_select variable to decide if we should show the limit select pulldown
-	* @param bool $view_limit_select if we should show the select pulldown or not
-	*/
-	function setViewLimitSelect($view_limit_select) {
-		$this->print_limit_select = $view_limit_select;
-	}
-	//============================================
-	
-	//--------------------------------------------
-	// Getter methods
-	//--------------------------------------------	
-	/**
-	* Returns the recordset offset
-	* @param none
-	* @return integer recorset offset
-	*/
-	function getOffset() {
-		return $this->limit * $this->cur_page - $this->limit;
-	}
-	
-	/**
-	* Returns the total number of pages
-	* @param none
-	* @return integer number of pages total
-	*/
-	function getTotPages() {
-		return $this->tot_pages;
-	}
-	
-	/**
-	* Returns the current page number
-	* @param none
-	* @return integer current page number
-	*/
-	function getPageNum() {
-		return $this->cur_page;
-	}
-	
-	/**
-	* Returns the current recordset limit
-	* @param none
-	* @return integer recordset limit
-	*/
-	function getLimit() {
-		return $this->limit;
-	}
-	
-	/**
-	* Returns value of previous link text
-	* @param none
-	* @return string previous link text
-	*/
-	function getPrevLink() {
-		return $this->prev_link;
-	}
-	
-	/**
-	* Returns value of next link text
-	* @param none
-	* @return string next link text
-	*/
-	function getNextLink() {
-		return $this->next_link;
-	}
-	
-	/**
-	* Returns the name used for the page querystring variable
-	* @param none
-	* @return string page variable name
-	*/
-	function getPageVar() {
-		return $this->page_var;
-	}
-	
-	/**
-	* Returns the name used for the limit querystring variable
-	* @param none
-	* @return string limit variable name
-	*/
-	function getLimitVar() {
-		return $this->limit_var;
-	}
-	//===========================================
-	
-// End class
-}
-?>
\ No newline at end of file
+<?php
+/**
+* Paging class to iterate through limited recordsets
+* @author Nick Korbel <lqqkout13@users.sourceforge.net>
+* @version 02-02-05
+* @package Pager
+*
+* Copyright (C) 2003 - 2005 phpScheduleIt
+* License: GPL, see LICENSE
+* /
+/**
+* To actually print out page links, call printPages() function
+*
+* In order for this object to work correctly, total records
+*  must be set in either the constructor or by calling
+*  setTotRecords()
+*
+* + Warning - The printPages() function cannot be called
+* 			from within a form
+*
+* === EXAMPLE OF HOW TO USE PAGER ===
+* // Initialize new Pager object with default values
+* $pager = new Pager();
+*
+* // Get total # of pages
+* $query = "SELECT COUNT(*) as num FROM table";
+* $result = $db->query($query);    
+* $rs = $result->fetchRow();
+* $num = $rs['num'];              // # of records
+*
+* $pager->setTotRecords($num);
+* $recordset_offset = $pager->getOffset();
+* $limit = $pager->getLimit();
+*
+* // Execute Query (using $offset and $limit values) //
+*
+* $pager->printPages();
+* ==========================================
+*
+*/
+
+// Should we use the Link class?
+$use_link = true;
+
+if ($use_link) {
+	//include_once('Link.class.php');
+	$link = new Link();
+}
+
+class Pager {
+	// Application set variables
+	var $cur_page;
+	var $query_string;
+	var $tot_pages;
+	var $page_var;
+	var $limit_var;
+	
+	// Application variables with user modify option
+	var $limit;
+	var $tot_records;
+	var $print_limit_select = true;
+	
+	// User modifiable variables
+	var $prev_link = '&laquo;';
+	var $next_link = '&raquo;';
+	var $limits = array(10, 25, 50, 100);
+	var $view_pages = 3;
+	var $table_width = '100%';
+	var $table_align = 'center';
+	var $link_class;
+	var $tb_class;
+	var $tb_style;
+	var $text_class;
+	var $text_style;
+	
+		
+	/**
+	* Pager Constructor
+	* Sets up Pager variables and initializes values
+	*
+	* - All parameters are optional and have default values of:
+	*    $tot_records = 0
+	*    $limit = 25
+	*    $page_var = "page"
+	*    $limit_var = "limit"
+	*
+	* @param int $tot_records optional total number of records
+	* @param int $limit optional limit of recordset
+	* @param string $page_var optional name of var to use in querystring for page value
+	* @param string $limit_var optional name of var to use in querystring for limit value
+	*/
+	function __construct($tot_records=0, $limit=25, $page_var='page', $limit_var='limit') {
+		$this->tot_records = $tot_records;
+		$this->limit = $limit;
+		$this->page_var = $page_var;
+		$this->limit_var = $limit_var;
+		
+		// Call all system setter functions
+		$this->initCurPage();
+		$this->initLimit();
+		$this->initTotPages();
+		$this->initQueryString();
+	}
+	
+	
+	/**
+	* Print out the pages as links
+	* Prints out a table of all the pages as links
+	*  and a jump menu to change the number of records
+	*  per page
+	*
+	* setCurPage() and setTotPages() must be called
+	*  before this function can be called
+	*
+	* @param none
+	* @see printPrev()
+	* @see printLink()
+	* @see printPage()
+	* @see printNext()
+	* @see printTotal()
+	* @see startTable()
+	* @see startPagesCell()
+	* @see endPagesCell()
+	* @see printLimitCell()
+	* @see endTable()
+	*/
+	function printPages() {
+		$p = $this->view_pages;			// How many pages to view
+		$cur_page = $this->cur_page;	// Current page
+		$tot_pages = $this->tot_pages;	// Total pages
+		
+		// Open up the HTML table
+		$this->startTable();
+		// Open up cell for page links
+		$this->startPagesCell();
+		
+		// Page to start printing bulk of links
+		$start = ($cur_page > $p) ? $cur_page - $p : 1;
+		// Page to end printing bulk of links
+		$end = ($cur_page + $p) < $tot_pages ? $cur_page + $p : $tot_pages;
+		
+		// Print 'prev' link
+		$this->printPrev();
+		
+		// Print link to first page, if not already there
+		if ($start != 1) {
+			$this->printPage(1);
+		}
+		
+		// Print '...' if necessary (with link to center page)
+		if ($cur_page > $p+2) {
+			$this->printLink(ceil( ($start+1)/2 ), '...');
+		}
+		
+		// Print links to pages before current page (up to first page)
+		// Print current page
+		// Print links to pages after current page (up to last page)		
+		for ($pg = $start; $pg <= $end; $pg++) {
+			$this->printPage($pg);
+		}
+				
+		// Print '...' if necessary (with link to center page)
+		if ( $cur_page < ($tot_pages - ($p+1)) ) {
+			$this->printLink(ceil( ($tot_pages+$end)/2 ), '...' );
+		}
+		
+		// Print link to last page, if not already there
+		if ($end != $tot_pages) {
+			$this->printPage($tot_pages);
+		}
+		
+		// Print 'next' link
+		$this->printNext();
+		
+		// Print total records
+		$this->printTotal();
+		
+		// Close page links cell
+		$this->endPagesCell();
+		// Print out cell with limit jump menu
+		if ($this->print_limit_select) { $this->printLimitCell(); }
+		// Close table
+		$this->endTable();
+	}
+	
+	//-----------------------------------------
+	// Application setter functions
+	//-----------------------------------------
+	/**
+	* Sets current page variable
+	* @param none
+	*/
+	function initCurPage() {
+		$this->cur_page = isset($_GET[$this->page_var]) ? intval($_GET[$this->page_var]) : 1;
+	}
+	
+	/**
+	* Sets the limit variable if it is passed from querystring
+	* @param none
+	*/
+	function initLimit() {
+		if (isset($_GET[$this->limit_var]))
+			$this->limit = intval($_GET[$this->limit_var]);
+		if (isset($_POST[$this->limit_var]))
+			$this->limit = intval($_POST[$this->limit_var]);
+	}
+	
+	/**
+	* Pull page information from query string and set $query_string
+	*
+	* setLimit() must be called before this function for it to work correctly
+	* @param none
+	*/
+	function initQueryString() {
+	    if (isset($_SERVER['QUERY_STRING'])) {
+			// Remove page from query string and convert all "&" to "&amp;"
+			$this->query_string = str_replace('&', '&amp;', preg_replace("/(&|&amp;)?$this->page_var=\d*/",'',$_SERVER['QUERY_STRING']));
+			
+			// Insert limit into querystring, if it's not there
+			if ( !strstr($this->query_string, "$this->limit_var=") )
+				$this->query_string .= "&amp;$this->limit_var=" . $this->limit;
+		}
+		else {
+			$this->query_string = '';
+		}
+
+	}
+	
+	/**
+	* Sets the tot_pages variable
+	*
+	* tot_records must be set and setLimit() must be called before
+	*  this function can be called
+	*
+	* @param none
+	*/
+	function initTotPages() {
+		$this->tot_pages = ceil($this->tot_records/$this->limit);
+	}
+	//===========================================
+	
+	//-------------------------------------------
+	// Output functions
+	//-------------------------------------------	
+	/**
+	* Print out link to a page
+	* @param int $p page number to print
+	*/
+	function printPage($p) {
+		if ($p == $this->cur_page) {
+			echo " <b>[$p]</b> ";
+		}
+		else {
+			$this->printLink($p, $p);
+		}
+	}
+	
+	/**
+	* Print 'prev' link, if necessary
+	* @param none
+	*/
+	function printPrev() {
+		$cur_page = $this->cur_page;
+		if ($cur_page > 1)
+			$this->printLink($cur_page-1, $this->prev_link);
+	}
+	
+	/**
+	* Print 'next' link, if necessary
+	* @param none
+	*/
+	function printNext() {
+		$cur_page = $this->cur_page;
+		if ($cur_page < $this->tot_pages && $this->tot_records > 0)
+			$this->printLink($cur_page+1, $this->next_link);
+	}
+	
+	/**
+	* Print out link to a certain page
+	* @param int $page page to link to
+	* @param string $text link text
+	*/
+	function printLink($page, $text) {
+		global $link;
+		global $use_link;
+		
+		if ($use_link) {
+			$link->doLink(
+				$_SERVER['PHP_SELF'] . "?$this->page_var=$page&amp;" . $this->query_string . '"',
+				$text,
+				$this->link_class,
+				'',
+				'Page ' . $page
+				);
+		}
+		else {
+			echo ' <a href="' . $_SERVER['PHP_SELF'] . "?$this->page_var=$page&amp;" . $this->query_string . '"'
+				. ' class="$this->class"'
+				. '>'
+				. $text . '</a> ';
+		}
+	}
+	
+	/**
+	* Prints out opening table tag
+	* @param none
+	*/
+	function startTable() {
+		echo "<table align=\"$this->table_align\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"$this->table_width\">\n"
+			. "<tr class=\"$this->text_class\" style=\"$this->text_style\">\n";	
+	}
+	
+	/**
+	* Begins cell containing page links
+	* @param none
+	*/
+	function startPagesCell() {
+		echo '<td>' . translate('Page') . ' ';
+	}
+	
+	/**
+	* Closes cell containing page links
+	* @param none
+	*/
+	function endPagesCell() {
+		echo '</td>';
+	} 
+	
+	/**
+	* Prints out cell containing limit jump menu
+	* @param none
+	*/
+	function printLimitCell() {
+		$limits = $this->limits;
+		echo "<td align=\"right\">\n"
+			. "<form name=\"limit_jump\" id=\"limit_jump\" method=\"post\" action=\"" . $_SERVER['PHP_SELF'] . "?" . preg_replace("/(&|&amp;)?$this->limit_var=\d*/", "", $this->query_string) . "\" style=\"margin: 0px;\">\n"
+			. translate('Per page') . " <select name=\"$this->limit_var\" onchange=\"document.limit_jump.submit();\" class=\"$this->tb_class\" style=\"$this->tb_style\">\n";
+		for ($i = 0; $i < count($limits); $i++) {
+			echo '<option value="' . $limits[$i] . '"';
+			if ($limits[$i] == $this->limit)
+				echo ' selected="selected"';
+			echo '>' . $limits[$i] . "</option>\n";
+		}
+		echo "</select>\n"
+			. "</form>\n"
+			. "</td>\n";
+	}
+	
+	/**
+	* Prints out the closing row and table HTML tags
+	* @param none
+	*/
+	function endTable() {
+		echo "</tr>\n</table>\n";
+	}
+	
+	/**
+	* Prints out total number of records returned
+	* @param none
+	*/
+	function printTotal() {
+		echo '(' . $this->tot_records . ')';
+	}
+	//============================================
+
+	//--------------------------------------------
+	// User-Modified Setter Functions
+	//--------------------------------------------	
+	/**
+	* Sets the total records for this recordset
+	* 
+	* - Default setting is 0 (in constructor)
+	*
+	* @param int $tot total number of records
+	*/
+	function setTotRecords($tot) {
+		$this->tot_records = intval($tot);
+		// Call initTotPages again to reset paging
+		$this->initTotPages();
+	}
+	
+	/**
+	* Sets the default recordset limit
+	* Note: A limit value set in the querystring
+	*  or in a post value will override this
+	*
+	* - Default setting is 25 (in constructor)
+	*
+	* @param int $limit new limit value
+	*/
+	function setLimit($limit) {
+		$this->limit = intval($limit);
+		// Call initLimit() to reinitialzie limit
+		$this->initLimit();
+	}
+	
+	/**
+	* Sets the text for 'prev' link
+	*
+	* - Default setting is "&laquo;"
+	*
+	* @param string $text link text
+	*/
+	function setPrevLink($text) {
+		$this->prev_link = trim($text);
+	}
+	
+	/**
+	* Sets the text for 'next' link
+	*
+	* - Default setting is "&raquo;"
+	*
+	* @param string $text link text
+	*/
+	function setNextLink($text) {
+		$this->next_link = trim($text);
+	}
+		
+	/**
+	* Sets the value of view_pages
+	* How many pages to print on either side of
+	* the currently viewed page number
+	*
+	* - Default setting is 3
+	*
+	* @param int $view_page how many pages to view
+	*/
+	function setViewPages($view_page) {
+		$this->view_pages = intval($view_page);
+	}
+	
+	/**
+	* Sets the array of limits
+	* Pass in an array of ints to use
+	* for the limit pull down menu
+	*
+	* - Default setting is (10, 25, 50, 100)
+	*
+	* @param int $new_limits array of limits
+	*/
+	function setLimits($new_limits) {
+		$this->limits = $new_limits;
+	}
+	
+	/**
+	* Sets the name of the class to be used for the links
+	*
+	* - Default setting is null
+	*
+	* @param string $link_class name of class
+	*/
+	function setLinkClass($link_class) {
+		$this->link_class = $link_class;
+	}
+	
+	/**
+	* Sets the name of the class to be used for the pull down box
+	*
+	* - Default setting is null
+	*
+	* @param string $tb_class name of class
+	*/
+	function setTbClass($tb_class) {
+		$this->tb_class = $tb_class;
+	}
+	
+	/**
+	* Sets the inline style of the limit jump menu
+	* This setting overrides the tb_class value
+	*
+	* - Default setting is null
+	* @param string $tb_style style of limit jump menu box
+	*/
+	function setTbStyle($tb_style) {
+		$this->tb_style = $tb_style;
+	}
+	
+	/**
+	* Sets the name of the class to be used for the text
+	*  ie) "Page:" and "Per page:"
+	* Should be used to modify all paging text font -amily, size, etc
+	*
+	* - Default setting is null
+	*
+	* @param string $text_class name of class
+	*/
+	function setTextClass($text_class) {
+		$this->text_class = $text_class;
+	}
+	
+	/**
+	* Sets the inline style to be used for the text
+	* Should be used to modifiy all paging text font-family, size, etc
+	* This will override the text_class setting
+	*
+	* - Default setting is null
+	*
+	* @param string $text_style style to use for the text
+	*/
+	function setTextStyle($text_style) {
+		$this->text_style = $text_style;
+	}
+	
+	/**
+	* Sets the width of the table bounding the pages/jump box
+	*
+	* - Default setting is "100%"
+	*
+	* @param string $table_width width of table
+	*/
+	function setTableWidth($table_width) {
+		$this->table_width = $table_width;
+	}
+	
+	/**
+	* Sets the horizontial alignment of the table bounding the paging
+	*
+	* - Default setting is "center"
+	*
+	* @param string $table_align alignment value for table align
+	*/
+	function setTableAlign($table_align) {
+		$this->table_align = $table_align;
+	}
+	
+	/**
+	* Sets the page variable name for the querystring
+	* @param string $page_var page variable name
+	*/
+	function setPageVar($page_var) {
+		$this->page_var = $page_var;
+	}
+	
+	/**
+	* Sets the limit variable name for the querystring
+	* @param string $limit_var limit variable name
+	*/
+	function setLimitVar($limit_var) {
+		$this->limit_var = $limit_var;
+	}
+	
+	/**
+	* Sets the print_limit_select variable to decide if we should show the limit select pulldown
+	* @param bool $view_limit_select if we should show the select pulldown or not
+	*/
+	function setViewLimitSelect($view_limit_select) {
+		$this->print_limit_select = $view_limit_select;
+	}
+	//============================================
+	
+	//--------------------------------------------
+	// Getter methods
+	//--------------------------------------------	
+	/**
+	* Returns the recordset offset
+	* @param none
+	* @return integer recorset offset
+	*/
+	function getOffset() {
+		return $this->limit * $this->cur_page - $this->limit;
+	}
+	
+	/**
+	* Returns the total number of pages
+	* @param none
+	* @return integer number of pages total
+	*/
+	function getTotPages() {
+		return $this->tot_pages;
+	}
+	
+	/**
+	* Returns the current page number
+	* @param none
+	* @return integer current page number
+	*/
+	function getPageNum() {
+		return $this->cur_page;
+	}
+	
+	/**
+	* Returns the current recordset limit
+	* @param none
+	* @return integer recordset limit
+	*/
+	function getLimit() {
+		return $this->limit;
+	}
+	
+	/**
+	* Returns value of previous link text
+	* @param none
+	* @return string previous link text
+	*/
+	function getPrevLink() {
+		return $this->prev_link;
+	}
+	
+	/**
+	* Returns value of next link text
+	* @param none
+	* @return string next link text
+	*/
+	function getNextLink() {
+		return $this->next_link;
+	}
+	
+	/**
+	* Returns the name used for the page querystring variable
+	* @param none
+	* @return string page variable name
+	*/
+	function getPageVar() {
+		return $this->page_var;
+	}
+	
+	/**
+	* Returns the name used for the limit querystring variable
+	* @param none
+	* @return string limit variable name
+	*/
+	function getLimitVar() {
+		return $this->limit_var;
+	}
+	//===========================================
+	
+// End class
+}
+?>
