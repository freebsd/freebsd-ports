--- lib389/nss_ssl.py.orig	2026-06-29 18:47:35 UTC
+++ lib389/nss_ssl.py
@@ -198,7 +198,7 @@ only.
 
         # Init the db.
         # 48886; This needs to be sql format ...
-        cmd = ['/usr/bin/certutil', '-N', '-d', self._certdb, '-f', '%s/%s' % (self._certdb, PWD_TXT),  '-@', '%s/%s' % (self._certdb, PWD_TXT)]
+        cmd = ['certutil', '-N', '-d', self._certdb, '-f', '%s/%s' % (self._certdb, PWD_TXT),  '-@', '%s/%s' % (self._certdb, PWD_TXT)]
         self._generate_noise('%s/noise.txt' % self._certdb)
         self.log.debug("nss cmd: %s", format_cmd_list(cmd))
         try:
@@ -255,15 +255,15 @@ only.
             return True
 
         try:
-            openssl_version = check_output(['/usr/bin/openssl', 'version']).decode('utf-8').strip()
+            openssl_version = check_output(['openssl', 'version']).decode('utf-8').strip()
         except subprocess.CalledProcessError as e:
             raise ValueError(e.output.decode('utf-8').rstrip())
         rehash_available = DSVersion(openssl_version.split(' ')[1]) >= DSVersion('1.1.0')
 
         if rehash_available:
-            cmd = ['/usr/bin/openssl', 'rehash', certdir]
+            cmd = ['openssl', 'rehash', certdir]
         else:
-            cmd = ['/usr/bin/c_rehash', certdir]
+            cmd = ['c_rehash', certdir]
         self.log.debug("nss cmd: %s", format_cmd_list(cmd))
         try:
             res = run(cmd, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
@@ -285,7 +285,7 @@ only.
         self._generate_noise('%s/noise.txt' % self._certdb)
         # Now run the command. Can we do this with NSS native?
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-S',
             '-n',
             CA_NAME,
@@ -315,7 +315,7 @@ only.
         # Now extract the CAcert to a well know place.
         # This allows us to point the cacert dir here and it "just works"
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-L',
             '-n',
             CA_NAME,
@@ -339,7 +339,7 @@ only.
         """
 
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-L',
             '-n',
             CA_NAME,
@@ -371,7 +371,7 @@ only.
 
         # Generate a CSR for a new CA cert
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-R',
             '-s',
             ISSUER,
@@ -396,7 +396,7 @@ only.
 
         # Sign the CSR with our old CA
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-C',
             '-d',
             self._certdb,
@@ -423,7 +423,7 @@ only.
 
         # Import the new CA to our DB instead of the old CA
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-A',
             '-n', CA_NAME,
             '-t', "CT,,",
@@ -442,7 +442,7 @@ only.
 
     def _rsa_cert_list(self):
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-L',
             '-d',
             self._certdb,
@@ -475,7 +475,7 @@ only.
 
     def _openssl_get_csr_subject(self, csr_dir, csr_name):
         cmd = [
-            '/usr/bin/openssl',
+            'openssl',
             'req',
             '-subject',
             '-noout',
@@ -498,7 +498,7 @@ only.
 
     def _openssl_get_csr_sub_alt_names(self, csr_dir, csr_name):
         cmd = [
-            '/usr/bin/openssl',
+            'openssl',
             'req',
             '-noout',
             '-text',
@@ -529,7 +529,7 @@ only.
         if name and csr_dir:
             if os.path.exists(csr_dir + "/" + name + ".csr"):
                 cmd = [
-                    "/usr/bin/sed",
+                    "sed",
                     "-n",
                     '/BEGIN NEW/,/END NEW/p',
                     csr_dir + "/" + name + ".csr"
@@ -547,7 +547,7 @@ only.
         csr_dir = self.dirsrv.get_cert_dir()
         # Search for .csr file extensions in instance config dir
         cmd = [
-            '/usr/bin/find',
+            'find',
             csr_dir,
             '-type',
             'f',
@@ -571,7 +571,7 @@ only.
             csr = []
             # Get last modified time stamp
             cmd = [
-                '/usr/bin/date',
+                'date',
                 '-r',
                 '%s/%s'% (csr_dir, csr_file),
                 '+%Y-%m-%d %H:%M:%S',
@@ -596,7 +596,7 @@ only.
     def _rsa_cert_key_exists(self, cert_tuple):
         name = cert_tuple[0]
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-K',
             '-d',
             self._certdb,
@@ -688,7 +688,7 @@ only.
         # Create noise.
         self._generate_noise('%s/noise.txt' % self._certdb)
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-S',
             '-n',
             name,
@@ -741,7 +741,7 @@ only.
         self._generate_noise('%s/noise.txt' % self._certdb)
 
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-R',
             # We want a dual purposes client and server cert
             '--keyUsage',
@@ -781,7 +781,7 @@ only.
         ca_path = '%s/ca.crt' % self._certdb
 
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-C',
             '-d',
             self._certdb,
@@ -819,7 +819,7 @@ only.
             shutil.copyfile(ca, '%s/ca.crt' % self._certdb)
             self.openssl_rehash(self._certdb)
             cmd = [
-                '/usr/bin/certutil',
+                'certutil',
                 '-A',
                 '-n', CA_NAME,
                 '-t', "CT,,",
@@ -840,7 +840,7 @@ only.
                 raise ValueError("The certificate file ({}) does not exist".format(crt))
             self._assert_not_chain(crt)
             cmd = [
-                '/usr/bin/certutil',
+                'certutil',
                 '-A',
                 '-n', name,
                 '-t', ",,",
@@ -856,7 +856,7 @@ only.
             except subprocess.CalledProcessError as e:
                 raise ValueError(e.output.decode('utf-8').rstrip())
             cmd = [
-                '/usr/bin/certutil',
+                'certutil',
                 '-V',
                 '-d', self._certdb,
                 '-n', name,
@@ -881,7 +881,7 @@ only.
         # Wait a second to avoid an NSS bug with serial ids based on time.
         time.sleep(1)
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-S',
             '-n',
             '%s%s' % (USER_PREFIX, name),
@@ -992,7 +992,7 @@ only.
     def list_keys(self, orphan=None):
         key_list = []
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-K',
             '-d',
             self._certdb,
@@ -1019,7 +1019,7 @@ only.
 
     def del_key(self, keyid):
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-F',
             '-d',
             self._certdb,
@@ -1040,7 +1040,7 @@ only.
         """Delete this certificate
         """
         cmd = [
-                '/usr/bin/certutil',
+                'certutil',
                 '-D',
                 '-d', self._certdb,
                 '-n', nickname,
@@ -1072,7 +1072,7 @@ only.
 
         # Modify certificate flags
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-M',
             '-d', self._certdb,
             '-n', nickname,
@@ -1088,7 +1088,7 @@ only.
 
     def display_cert_details(self, nickname):
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-d', self._certdb,
             '-n', nickname,
             '-L',
@@ -1274,7 +1274,7 @@ only.
         trust_flags = "CT,," if ca else ",,"
 
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-A',
             '-d', self._certdb,
             '-n', nickname,
@@ -1511,7 +1511,7 @@ only.
         :raise ValueError: error
         """
         cmd = [
-            '/usr/bin/certutil',
+            'certutil',
             '-L',
             '-d', self._certdb,
             '-n', nickname,
