--- avelsieve/include/managesieve.lib.php.orig	2016-03-17 16:47:45 UTC
+++ avelsieve/include/managesieve.lib.php
@@ -713,6 +713,20 @@ class sieve {
           return true;
   }
 
+   /**
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
   /**
    * Perform SASL authentication to SIEVE server.
    *
@@ -729,6 +743,7 @@ class sieve {
    
             $this->len=strlen($auth);            
             fputs($this->fp, 'AUTHENTICATE "PLAIN" {' . $this->len . '+}' . "\r\n");
+            $this->ignore_capabilities();
             fputs($this->fp, "$auth\r\n");
 
             $this->line=fgets($this->fp,1024);        
@@ -745,6 +760,7 @@ class sieve {
          // SASL DIGEST-MD5 support works with timsieved 1.1.0
          // follows rfc2831 for generating the $response to $challenge
          fputs($this->fp, "AUTHENTICATE \"DIGEST-MD5\"\r\n");
+         $this->ignore_capabilities();
          // $clen is length of server challenge, we ignore it. 
          $clen = fgets($this->fp, 1024);
          // read for 2048, rfc2831 max length allowed
@@ -796,6 +812,7 @@ class sieve {
          // CRAM-MD5 does not support proxy of $auth by $user
          // requires php mhash extension
          fputs($this->fp, "AUTHENTICATE \"CRAM-MD5\"\r\n");
+         $this->ignore_capabilities();
          // $clen is the length of the challenge line the server gives us
          $clen = fgets($this->fp, 1024);
          // read for 1024, should be long enough?
@@ -821,6 +838,7 @@ class sieve {
           $pass=base64_encode($this->pass);
      
           fputs($this->fp, "AUTHENTICATE \"LOGIN\"\r\n");
+          $this->ignore_capabilities();
           fputs($this->fp, "{".strlen($login)."+}\r\n");
           fputs($this->fp, "$login\r\n");
           fputs($this->fp, "{".strlen($pass)."+}\r\n");
