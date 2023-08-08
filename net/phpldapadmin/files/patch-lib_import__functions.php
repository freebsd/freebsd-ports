--- lib/import_functions.php.orig	2023-04-01 13:46:16 UTC
+++ lib/import_functions.php
@@ -255,7 +255,7 @@ class ImportLDIF extends Import {
 		if (substr($value,0,1) == ':')
 			$value = base64_decode(trim(substr($value,1)));
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
@@ -386,7 +386,7 @@ class ImportLDIF extends Import {
 			$url = trim(substr($value,1));
 
 			if (preg_match('^file://',$url)) {
-				$filename = substr(trim($url),7);
+				$filename = substr(trim((string) $url),7);
 
 				if ($fh = @fopen($filename,'rb')) {
 					if (! $return = @fread($fh,filesize($filename)))
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
 
