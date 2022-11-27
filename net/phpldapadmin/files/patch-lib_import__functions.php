--- lib/import_functions.php.orig	2021-12-12 02:35:51 UTC
+++ lib/import_functions.php
@@ -86,7 +86,7 @@ abstract class Import {
 		if (get_request('ldif','REQUEST')) {
 			$this->input = explode("\n",get_request('ldif','REQUEST'));
 			$this->source['name'] = 'STDIN';
-			$this->source['size'] = strlen(get_request('ldif','REQUEST'));
+			$this->source['size'] = strlen((string) get_request('ldif','REQUEST'));
 
 		} elseif (isset($_FILES['ldif_file']) && is_array($_FILES['ldif_file']) && ! $_FILES['ldif_file']['error']) {
 			$input = file_get_contents($_FILES['ldif_file']['tmp_name']);
@@ -253,9 +253,9 @@ class ImportLDIF extends Import {
 
 		# Get the DN
 		if (substr($value,0,1) == ':')
-			$value = base64_decode(trim(substr($value,1)));
+			$value = base64_decode(trim((string) substr($value,1)));
 		else
-			$value = trim($value);
+			$value = trim((string) $value);
 
 		return array($attr,$value);
 	}
@@ -271,7 +271,7 @@ class ImportLDIF extends Import {
 
 		if ($this->hasMoreEntries() && ! $this->eof()) {
 			# The first line is the DN one
-			$current[0]= trim($this->_currentLine);
+			$current[0]= trim((string) $this->_currentLine);
 
 			# While we end on a blank line, fetch the attribute lines
 			$count = 0;
@@ -282,11 +282,11 @@ class ImportLDIF extends Import {
 				/* If the next line begin with a space, we append it to the current row
 				 * else we push it into the array (unwrap)*/
 				if ($this->isWrappedLine())
-					$current[$count] .= trim($this->_currentLine);
+					$current[$count] .= trim((string) $this->_currentLine);
 				elseif ($this->isCommentLine()) {}
 				# Do nothing
 				elseif (! $this->isBlankLine())
-					$current[++$count] = trim($this->_currentLine);
+					$current[++$count] = trim((string) $this->_currentLine);
 				else
 					$endEntryFound = true;
 			}
@@ -336,7 +336,7 @@ class ImportLDIF extends Import {
 	 * @return boolean true if it's a comment line,false otherwise
 	 */
 	private function isCommentLine() {
-		return substr(trim($this->_currentLine),0,1) == '#' ? true : false;
+		return substr(trim((string) $this->_currentLine),0,1) == '#' ? true : false;
 	}
 
 	/**
@@ -354,7 +354,7 @@ class ImportLDIF extends Import {
 	 * @return boolean if it is a blank line,false otherwise.
 	 */
 	private function isBlankLine() {
-		return(trim($this->_currentLine) == '') ? true : false;
+		return(trim((string) $this->_currentLine) == '') ? true : false;
 	}
 
 	/**
@@ -383,10 +383,10 @@ class ImportLDIF extends Import {
 		$return = '';
 
 		if (substr($value,0,1) == '<') {
-			$url = trim(substr($value,1));
+			$url = trim((string) substr($value,1));
 
 			if (preg_match('^file://',$url)) {
-				$filename = substr(trim($url),7);
+				$filename = substr(trim((string) $url),7);
 
 				if ($fh = @fopen($filename,'rb')) {
 					if (! $return = @fread($fh,filesize($filename)))
@@ -404,7 +404,7 @@ class ImportLDIF extends Import {
 		} else
 			$return = $value;
 
-		return trim($return);
+		return trim((string) $return);
 	}
 
 	/**
@@ -480,7 +480,7 @@ class ImportLDIF extends Import {
 			# Fetch the attribute for the following line
 			$currentLine = array_shift($lines);
 
-			while ($processline && trim($currentLine) && (trim($currentLine) != '-')) {
+			while ($processline && trim((string) $currentLine) && (trim((string) $currentLine) != '-')) {
 				$processline = false;
 
 				# If there is a valid line
@@ -541,7 +541,7 @@ class ImportLDIF extends Import {
 						array_merge(array($currentLine),$lines));
 
 				$currentLine = array_shift($lines);
-				if (trim($currentLine))
+				if (trim((string) $currentLine))
 					$processline = true;
 			}
 
