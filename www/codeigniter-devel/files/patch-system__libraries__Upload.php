--- ./system/libraries/Upload.php.orig	2009-04-22 10:15:09.000000000 -0400
+++ ./system/libraries/Upload.php	2010-07-12 09:16:30.000000000 -0400
@@ -6,7 +6,7 @@
  *
  * @package		CodeIgniter
  * @author		ExpressionEngine Dev Team
- * @copyright	Copyright (c) 2008 - 2009, EllisLab, Inc.
+ * @copyright	Copyright (c) 2008 - 2010, EllisLab, Inc.
  * @license		http://codeigniter.com/user_guide/license.html
  * @link		http://codeigniter.com
  * @since		Version 1.0
@@ -26,31 +26,33 @@
  */
 class CI_Upload {
 	
-	var $max_size		= 0;
-	var $max_width		= 0;
-	var $max_height		= 0;
-	var $max_filename	= 0;
-	var $allowed_types	= "";
-	var $file_temp		= "";
-	var $file_name		= "";
-	var $orig_name		= "";
-	var $file_type		= "";
-	var $file_size		= "";
-	var $file_ext		= "";
-	var $upload_path	= "";
-	var $overwrite		= FALSE;
-	var $encrypt_name	= FALSE;
-	var $is_image		= FALSE;
-	var $image_width	= '';
-	var $image_height	= '';
-	var $image_type		= '';
-	var $image_size_str	= '';
-	var $error_msg		= array();
-	var $mimes			= array();
-	var $remove_spaces	= TRUE;
-	var $xss_clean		= FALSE;
-	var $temp_prefix	= "temp_file_";
-		
+	var $max_size				= 0;
+	var $max_width				= 0;
+	var $max_height				= 0;
+	var $max_filename			= 0;
+	var $allowed_types			= "";
+	var $file_temp				= "";
+	var $file_name				= "";
+	var $orig_name				= "";
+	var $file_type				= "";
+	var $file_size				= "";
+	var $file_ext				= "";
+	var $upload_path			= "";
+	var $overwrite				= FALSE;
+	var $encrypt_name			= FALSE;
+	var $is_image				= FALSE;
+	var $image_width			= '';
+	var $image_height			= '';
+	var $image_type				= '';
+	var $image_size_str			= '';
+	var $error_msg				= array();
+	var $mimes					= array();
+	var $remove_spaces			= TRUE;
+	var $xss_clean				= FALSE;
+	var $temp_prefix			= "temp_file_";
+	var $client_name			= '';
+	
+	var $_file_name_override	= '';	
 	/**
 	 * Constructor
 	 *
@@ -101,7 +103,8 @@
 							'mimes'				=> array(),
 							'remove_spaces'		=> TRUE,
 							'xss_clean'			=> FALSE,
-							'temp_prefix'		=> "temp_file_"
+							'temp_prefix'		=> "temp_file_",
+							'client_name'		=> ''
 						);	
 	
 	
@@ -124,6 +127,10 @@
 				$this->$key = $val;
 			}
 		}
+		
+		// if a file_name was provided in the config, use it instead of the user input
+		// supplied file name for all uploads until initialized again
+		$this->_file_name_override = $this->file_name;
 	}
 	
 	// --------------------------------------------------------------------
@@ -187,17 +194,12 @@
 
 		// Set the uploaded data as class variables
 		$this->file_temp = $_FILES[$field]['tmp_name'];		
-		$this->file_name = $this->_prep_filename($_FILES[$field]['name']);
-		$this->file_size = $_FILES[$field]['size'];		
+		$this->file_size = $_FILES[$field]['size'];	
 		$this->file_type = preg_replace("/^(.+?);.*$/", "\\1", $_FILES[$field]['type']);
-		$this->file_type = strtolower($this->file_type);
-		$this->file_ext	 = $this->get_extension($_FILES[$field]['name']);
-		
-		// Convert the file size to kilobytes
-		if ($this->file_size > 0)
-		{
-			$this->file_size = round($this->file_size/1024, 2);
-		}
+		$this->file_type = strtolower(trim(stripslashes($this->file_type), '"'));
+		$this->file_name = $this->_prep_filename($_FILES[$field]['name']);
+		$this->file_ext	 = $this->get_extension($this->file_name);
+		$this->client_name = $this->file_name;
 
 		// Is the file type allowed to be uploaded?
 		if ( ! $this->is_allowed_filetype())
@@ -205,6 +207,25 @@
 			$this->set_error('upload_invalid_filetype');
 			return FALSE;
 		}
+				
+		// if we're overriding, let's now make sure the new name and type is allowed
+		if ($this->_file_name_override != '')
+		{
+			$this->file_name = $this->_prep_filename($this->_file_name_override);
+			$this->file_ext  = $this->get_extension($this->file_name);
+
+			if ( ! $this->is_allowed_filetype(TRUE))
+			{
+				$this->set_error('upload_invalid_filetype');
+				return FALSE;				
+			}
+		}
+		
+		// Convert the file size to kilobytes
+		if ($this->file_size > 0)
+		{
+			$this->file_size = round($this->file_size/1024, 2);
+		}
 
 		// Is the file size within the allowed maximum?
 		if ( ! $this->is_allowed_filesize())
@@ -312,6 +333,7 @@
 						'full_path'			=> $this->upload_path.$this->file_name,
 						'raw_name'			=> str_replace($this->file_ext, '', $this->file_name),
 						'orig_name'			=> $this->orig_name,
+						'client_name'		=> $this->client_name,
 						'file_ext'			=> $this->file_ext,
 						'file_size'			=> $this->file_size,
 						'is_image'			=> $this->is_image(),
@@ -549,43 +571,49 @@
 	 * @access	public
 	 * @return	bool
 	 */	
-	function is_allowed_filetype()
+	function is_allowed_filetype($ignore_mime = FALSE)
 	{
 		if (count($this->allowed_types) == 0 OR ! is_array($this->allowed_types))
 		{
 			$this->set_error('upload_no_file_types');
 			return FALSE;
 		}
+		
+		$ext = strtolower(ltrim($this->file_ext, '.'));
+		
+		if ( ! in_array($ext, $this->allowed_types))
+		{
+			return FALSE;
+		}
 
+		// Images get some additional checks
 		$image_types = array('gif', 'jpg', 'jpeg', 'png', 'jpe');
 
-		foreach ($this->allowed_types as $val)
+		if (in_array($ext, $image_types))
 		{
-			$mime = $this->mimes_types(strtolower($val));
-
-			// Images get some additional checks
-			if (in_array($val, $image_types))
+			if (getimagesize($this->file_temp) === FALSE)
 			{
-				if (getimagesize($this->file_temp) === FALSE)
-				{
-					return FALSE;
-				}
-			}
+				return FALSE;
+			}			
+		}
 
-			if (is_array($mime))
-			{
-				if (in_array($this->file_type, $mime, TRUE))
-				{
-					return TRUE;
-				}
-			}
-			else
+		if ($ignore_mime === TRUE)
+		{
+			return TRUE;
+		}
+		
+		$mime = $this->mimes_types($ext);
+				
+		if (is_array($mime))
+		{
+			if (in_array($this->file_type, $mime, TRUE))
 			{
-				if ($mime == $this->file_type)
-				{
-					return TRUE;
-				}	
-			}		
+				return TRUE;
+			}			
+		}
+		elseif ($mime == $this->file_type)
+		{
+				return TRUE;
 		}
 		
 		return FALSE;
@@ -918,7 +946,7 @@
 
 		foreach ($parts as $part)
 		{
-			if ($this->mimes_types(strtolower($part)) === FALSE)
+			if ( ! in_array(strtolower($part), $this->allowed_types) OR $this->mimes_types(strtolower($part)) === FALSE)
 			{
 				$filename .= '.'.$part.'_';
 			}
@@ -928,13 +956,6 @@
 			}
 		}
 
-		// file name override, since the exact name is provided, no need to
-		// run it through a $this->mimes check.
-		if ($this->file_name != '')
-		{
-			$filename = $this->file_name;
-		}
-
 		$filename .= '.'.$ext;
 		
 		return $filename;
