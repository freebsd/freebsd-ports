--- avelsieve/include/managesieve.lib.php.orig	2006-07-24 14:48:27.000000000 +0100
+++ avelsieve/include/managesieve.lib.php	2009-03-26 20:36:33.000000000 +0000
@@ -686,6 +686,20 @@
   }
 
   /**
+   * Neil Darlow - 2009/03/26
+   * Changes to Sieve servers to be compliant with draft-managesieve-09.txt
+   * break authenticate() which cannot handle the capability strings received
+   * after AUTHENTICATE under a TLS encrypted session. We ignore capability
+   * strings for each SASL mechanism.
+   */
+  function ignore_capabilities()
+  {
+    if ($this->capabilities['starttls']) do {
+      $line = fgets($this->fp, 1024);
+    } while (strncmp($line, 'OK', 2));
+  }
+
+  /**
    * Perform SASL authentication to SIEVE server.
    *
    * Attempts to authenticate to SIEVE, using some SASL authentication method
@@ -701,6 +715,7 @@
    
             $this->len=strlen($auth);			
             fputs($this->fp, 'AUTHENTICATE "PLAIN" {' . $this->len . '+}' . "\r\n");
+            $this->ignore_capabilities();
             fputs($this->fp, "$auth\r\n");
 
             $this->line=fgets($this->fp,1024);		
@@ -717,6 +732,7 @@
 	     // SASL DIGEST-MD5 support works with timsieved 1.1.0
 	     // follows rfc2831 for generating the $response to $challenge
 	     fputs($this->fp, "AUTHENTICATE \"DIGEST-MD5\"\r\n");
+ 	     $this->ignore_capabilities();
 	     // $clen is length of server challenge, we ignore it. 
 	     $clen = fgets($this->fp, 1024);
 	     // read for 2048, rfc2831 max length allowed
@@ -768,6 +784,7 @@
 	     // CRAM-MD5 does not support proxy of $auth by $user
 	     // requires php mhash extension
 	     fputs($this->fp, "AUTHENTICATE \"CRAM-MD5\"\r\n");
+	     $this->ignore_capabilities();
 	     // $clen is the length of the challenge line the server gives us
 	     $clen = fgets($this->fp, 1024);
 	     // read for 1024, should be long enough?
@@ -793,6 +810,7 @@
  	     $pass=base64_encode($this->pass);
  	
  	     fputs($this->fp, "AUTHENTICATE \"LOGIN\"\r\n");
+ 	     $this->ignore_capabilities();
  	     fputs($this->fp, "{".strlen($login)."+}\r\n");
  	     fputs($this->fp, "$login\r\n");
  	     fputs($this->fp, "{".strlen($pass)."+}\r\n");
