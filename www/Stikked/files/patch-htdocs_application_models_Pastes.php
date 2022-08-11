--- htdocs/application/models/Pastes.php.orig	2022-06-18 12:47:43 UTC
+++ htdocs/application/models/Pastes.php
@@ -32,8 +32,16 @@ class Pastes extends CI_Model
     {
         $data['created'] = time();
 
-        //this is SO evil… saving the «raw» data with htmlspecialchars :-( (but I have to leave this, because of backwards-compatibility)
-        $data['raw'] = htmlspecialchars($this->_strip_bad_multibyte_chars($this->input->post('code')));
+	if ($this->config->item('true_paste'))
+	{
+		// save the paste as supplied
+		$data['raw'] = $this->input->post('code');
+	}
+	else
+	{
+		//this is SO evil… saving the «raw» data with htmlspecialchars :-( (but I have to leave this, because of backwards-compatibility)
+		$data['raw'] = htmlspecialchars($this->_strip_bad_multibyte_chars($this->input->post('code')));
+	}
         $data['lang'] = htmlspecialchars($this->input->post('lang'));
         $data['replyto'] = ($this->input->post('reply') === null ? '0' : $this->input->post('reply'));
 
