--- lib/Crypt/OpenSSL/CA.pm.orig	2017-06-19 18:02:36 UTC
+++ lib/Crypt/OpenSSL/CA.pm
@@ -2064,6 +2064,43 @@ void DESTROY(SV* sv_self) {
 }
 X509_CRL_BASE
 
+
+=head2 parse_CRL ($pem_crl)
+
+Creates and returns an I<Crypt::OpenSSL::CA::X509_CRL> object.
+
+=cut
+
+sub parse_CRL {
+    my ($class, $pemcrl) = @_;
+
+    unless ($pemcrl) {
+        croak("CRL pem must by");
+    }
+    return $class->_parse_CRL($pemcrl);
+}
+
+
+
+use Crypt::OpenSSL::CA::Inline::C <<"_PARSE_CRL";
+static
+SV* _parse_CRL(char *class, const char* pemcrl) {
+    BIO *crlbio;
+    X509_CRL *crl = NULL;
+
+    crlbio = BIO_new_mem_buf((void *) pemcrl, -1);
+    if (crlbio == NULL) {
+        croak("BIO_new_mem_buf failed");
+    }
+    crl = PEM_read_bio_X509_CRL(crlbio, NULL, NULL, NULL);
+    if (crl == NULL) {
+            X509_CRL_free(crl);
+            sslcroak("unable to parse CRL");
+    }
+    return perl_wrap("${\__PACKAGE__}", crl);
+}
+_PARSE_CRL
+
 =head2 new ()
 
 =head2 new ($version)
@@ -2120,10 +2157,47 @@ void set_issuer_DN(SV* sv_self, SV* sv_dn) {
 }
 SET_ISSUER_DN
 
+=head2 get_issuer_DN()
+
+Get DN string of issuer the CRL
+
+=cut
+
+use Crypt::OpenSSL::CA::Inline::C <<"GET_ISSUER";
+
+static
+SV* get_issuer_DN(SV* sv_self) {
+    X509_CRL* self = perl_unwrap("${\__PACKAGE__}", X509_CRL *, sv_self);
+    BIO* mem = BIO_new(BIO_s_mem());
+    ASN1_TIME *next_update;
+    X509_NAME *issuer = NULL;
+
+    if (! mem) {
+        croak("Cannot allocate BIO");
+    }
+
+    issuer = X509_NAME_new();
+
+    if (!(issuer = X509_CRL_get_issuer(self))) {
+        sslcroak("X509_CRL_get_issuer failed");
+    }
+    if (!(X509_NAME_print_ex(mem, issuer, 0, XN_FLAG_ONELINE) && (BIO_write(mem, "\\0", 1) > 0))) {
+            sslcroak("X509_CRL_get_nextUpdate failed");
+    }
+    return BIO_mem_to_SV(mem);
+}
+GET_ISSUER
+
+
 =head2 set_lastUpdate ($enddate)
 
 =head2 set_nextUpdate ($startdate)
 
+=head2 get_nextUpdate ()
+
+=head2 get_lastUpdate ()
+
+
 Sets the validity period of the certificate.  The dates must be in the
 GMT timezone, with the format yyyymmddhhmmssZ (it's a literal Z at the
 end, meaning "Zulu" in case you care).
@@ -2141,6 +2215,24 @@ void set_lastUpdate(SV* sv_self, char* startdate) {
 }
 
 static
+SV* get_lastUpdate(SV* sv_self) {
+    X509_CRL* self = perl_unwrap("${\__PACKAGE__}", X509_CRL *, sv_self);
+    BIO* mem = BIO_new(BIO_s_mem());
+    ASN1_TIME *last_update;
+
+    if (! mem) {
+        croak("Cannot allocate BIO");
+    }
+    if (!(last_update = X509_CRL_get_lastUpdate(self))) {
+        sslcroak("X509_CRL_get_lastUpdate");
+    }
+    if (!(ASN1_TIME_print(mem, last_update) && (BIO_write(mem, "\\0", 1) > 0))) {
+        sslcroak("X509_CRL_get_lastUpdate failed");
+    }
+    return BIO_mem_to_SV(mem);
+}
+
+static
 void set_nextUpdate(SV* sv_self, char* enddate) {
     ASN1_TIME* newtime;
     X509_CRL* self = perl_unwrap("${\__PACKAGE__}", X509_CRL *, sv_self);
@@ -2149,8 +2241,190 @@ void set_nextUpdate(SV* sv_self, char* enddate) {
     X509_CRL_set_nextUpdate(self, time);
     ASN1_TIME_free(time);
 }
+
+
+static
+SV* get_nextUpdate(SV* sv_self) {
+    X509_CRL* self = perl_unwrap("${\__PACKAGE__}", X509_CRL *, sv_self);
+    BIO* mem = BIO_new(BIO_s_mem());
+    ASN1_TIME *next_update;
+
+    if (! mem) {
+        croak("Cannot allocate BIO");
+    }
+    if (!(next_update = X509_CRL_get_nextUpdate(self))) {
+        sslcroak("X509_CRL_get_nextUpdate");
+    }
+    if (!(ASN1_TIME_print(mem, next_update) && (BIO_write(mem, "\\0", 1) > 0))) {
+        sslcroak("ASN1_TIME_print failed");
+    }
+    return BIO_mem_to_SV(mem);
+}
 SET_UPDATES
 
+
+
+=head2 get_entryNumbers()
+
+Get array of revoked serial numbers.
+
+=cut
+
+use Crypt::OpenSSL::CA::Inline::C <<"GET_ENTRY_NUMBERS";
+
+static
+SV* get_entryNumbers(SV* sv_self) {
+    X509_CRL* self = perl_unwrap("${\__PACKAGE__}", X509_CRL *, sv_self);
+    STACK_OF(X509_REVOKED) *rev = NULL;
+    X509_REVOKED *rev_entry = NULL;
+    int revnum, i;
+
+    if (!(rev = X509_CRL_get_REVOKED(self))) {
+        sslcroak("X509_CRL_get_REVOKED failed");
+    }
+    if (!(revnum = sk_X509_REVOKED_num(rev))) {
+        sslcroak("sk_X509_REVOKED_num failed");
+    }
+
+    SV* serial_SV = NULL;
+    SV* revokedate_SV = NULL;
+    HV* hash = NULL;
+    AV* array = newAV();
+
+    char* revokedate_label = "revokedate";
+    char* serial_label = "serial";
+
+    BIO* mem = NULL;
+    for(i = 0; i < revnum; i++) {
+        if (!(hash = newHV())) {
+            croak("Cannot allocate HV");
+        }
+
+        if (!(rev_entry = sk_X509_REVOKED_value(rev, i))) {
+            sslcroak("sk_X509_REVOKED_value failed");
+        }
+
+        if (!(mem = BIO_new(BIO_s_mem()))) {
+            croak("Cannot allocate BIO");
+        }
+        BIO_write(mem, "0x", 2);
+        i2a_ASN1_INTEGER(mem, rev_entry->serialNumber);
+        BIO_write(mem, "\\0", 1);
+        serial_SV = BIO_mem_to_SV(mem);
+        hv_store(hash, serial_label, strlen(serial_label), serial_SV, 0);
+
+        if (!(mem = BIO_new(BIO_s_mem()))) {
+            croak("Cannot allocate BIO");
+        }
+        ASN1_TIME_print(mem, rev_entry->revocationDate);
+        BIO_write(mem, "\\0", 1);
+        revokedate_SV = BIO_mem_to_SV(mem);
+        hv_store(hash, revokedate_label, strlen(revokedate_label), revokedate_SV, 0);
+
+        av_push(array, newRV_noinc((SV*)hash));
+    }
+    return newRV_noinc((SV*)array);
+}
+GET_ENTRY_NUMBERS
+
+=head2 get_entry_count()
+
+Get count of CRL entries.
+
+=cut
+
+use Crypt::OpenSSL::CA::Inline::C <<"GET_ENTRY_COUNT";
+
+int get_entry_count(SV* sv_self) {
+    X509_CRL* self = perl_unwrap("${\__PACKAGE__}", X509_CRL *, sv_self);
+    BIO* mem = BIO_new(BIO_s_mem());
+    STACK_OF(X509_REVOKED) *rev = NULL;
+    int count;
+
+    if (! mem) {
+        croak("Cannot allocate BIO");
+    }
+    if (!(rev = X509_CRL_get_REVOKED(self))) {
+        sslcroak("X509_CRL_get_REVOKED failed");
+    }
+    if (!(count = sk_X509_REVOKED_num(rev))) {
+        sslcroak("sk_X509_REVOKED_num failed");
+    }
+    return count;
+}
+GET_ENTRY_COUNT
+
+
+=head2 get_entry_revoke_date( $num )
+
+Get revoke date of entry in the CRL. Count begin from zero.
+
+=cut
+
+use Crypt::OpenSSL::CA::Inline::C <<"GET_ENTRY_REVOKE_DATE";
+
+static
+SV* get_entry_revoke_date(SV* sv_self, int num) {
+    X509_CRL* self = perl_unwrap("${\__PACKAGE__}", X509_CRL *, sv_self);
+    BIO* mem = BIO_new(BIO_s_mem());
+    ASN1_TIME *next_update;
+    STACK_OF(X509_REVOKED) *rev = NULL;
+    X509_REVOKED *rev_entry = NULL;
+    int revnum, i;
+
+    if (! mem) {
+        croak("Cannot allocate BIO");
+    }
+    if (!(rev = X509_CRL_get_REVOKED(self))) {
+        sslcroak("X509_CRL_get_REVOKED failed");
+    }
+    if (!(rev_entry = sk_X509_REVOKED_value(rev, num))) {
+            sslcroak("sk_X509_REVOKED_value failed");
+    }
+    ASN1_TIME_print(mem, rev_entry->revocationDate);
+    if (!(BIO_write(mem, "\\0", 1) > 0)) {
+        sslcroak("BIO_write failed");
+    }
+    return BIO_mem_to_SV(mem);
+}
+GET_ENTRY_REVOKE_DATE
+
+
+=head2 get_entry_serial( $num )
+
+Get serial number of entry in the CRL.
+
+
+=cut
+
+use Crypt::OpenSSL::CA::Inline::C <<"GET_ENTRY_SERIAL";
+
+static
+SV* get_entry_serial(SV* sv_self, int num) {
+    X509_CRL* self = perl_unwrap("${\__PACKAGE__}", X509_CRL *, sv_self);
+    BIO* mem = BIO_new(BIO_s_mem());
+    STACK_OF(X509_REVOKED) *rev = NULL;
+    X509_REVOKED *rev_entry = NULL;
+
+    if (! mem) {
+        croak("Cannot allocate BIO");
+    }
+    if (!(rev = X509_CRL_get_REVOKED(self))) {
+        sslcroak("X509_CRL_get_REVOKED failed");
+    }
+    BIO_write(mem, "0x", 2); 
+    if (!(rev_entry = sk_X509_REVOKED_value(rev, num))) {
+            sslcroak("sk_X509_REVOKED_value failed");
+    }
+    i2a_ASN1_INTEGER(mem, rev_entry->serialNumber);
+    if (!(BIO_write(mem, "\\0", 1) > 0)) {
+        sslcroak("BIO_write failed");
+    }
+    return BIO_mem_to_SV(mem);
+}
+GET_ENTRY_SERIAL
+
+
 =head2 set_extension ($extname, $value, %options, %more_openssl_config)
 
 =head2 add_extension ($extname, $value, %options, %more_openssl_config)
@@ -2427,6 +2701,9 @@ Returns a textual representation of all the fields ins
 C<X509_CRL_print()>.
 
 =cut
+
+
+
 
 use Crypt::OpenSSL::CA::Inline::C <<"DUMP";
 static
