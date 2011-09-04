##
##  MAca-bundle.pl -- Regenerate ca-root-nss.crt from the Mozilla certdata.txt
##
##  Rewritten in September 2011 by Matthias Andree to heed untrust
##

##  Copyright (c) 2011, Matthias Andree
##  All rights reserved.
##
##  Redistribution and use in source and binary forms, with or without
##  modification, are permitted provided that the following conditions are
##  met:
##
##  * Redistributions of source code must retain the above copyright
##  notice, this list of conditions and the following disclaimer.
##
##  * Redistributions in binary form must reproduce the above copyright
##  notice, this list of conditions and the following disclaimer in the
##  documentation and/or other materials provided with the distribution.
##
##  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
##  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
##  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
##  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
##  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
##  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
##  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
##  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
##  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
##  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
##  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
##  POSSIBILITY OF SUCH DAMAGE.

use strict;
use MIME::Base64;

my $VERSION = '$FreeBSD$';

#   configuration
print <<EOH;
##
##  ca-root-nss.crt -- Bundle of CA Root Certificates
##
##  This is a bundle of X.509 certificates of public Certificate
##  Authorities (CA). These were automatically extracted from Mozilla's
##  root CA list (the file `certdata.txt').
##
##  Extracted from nss-%%VERSION_NSS%%
##  with $VERSION
##
EOH
my $debug = 1;

my %certs;
my %trusts;

sub printcert_plain($$)
{
    my ($label, $certdata) = @_;
    print "=== $label ===\n" if $label;
    print
	"-----BEGIN CERTIFICATE-----\n",
	MIME::Base64::encode_base64($certdata),
	"-----END CERTIFICATE-----\n\n";
}

sub printcert_info($$)
{
    my (undef, $certdata) = @_;
    return unless $certdata;
    open(OUT, "|openssl x509 -text -inform DER -fingerprint")
            || die "could not pipe to openssl x509";
    print OUT $certdata;
    close(OUT) or die "openssl x509 failed with exit code $?";
}

sub printcert($$) {
    my ($a, $b) = @_;
    printcert_info($a, $b);
}

sub graboct()
{
    my $data;

    while (<>) {
	last if /^END/;
	my (undef,@oct) = split /\\/;
	my @bin = map(chr(oct), @oct);
	$data .= join('', @bin);
    }

    return $data;
}


sub grabcert()
{
    my $certdata;
    my $cka_label;
    my $serial;

    while (<>) {
	chomp;
	last if ($_ eq '');

	if (/^CKA_LABEL UTF8 "([^"]+)"/) {
	    $cka_label = $1;
	}

	if (/^CKA_VALUE MULTILINE_OCTAL/) {
	    $certdata = graboct();
	}

	if (/^CKA_SERIAL_NUMBER MULTILINE_OCTAL/) {
	    $serial = graboct();
	}
    }
    return ($serial, $cka_label, $certdata);
}

sub grabtrust() {
    my $cka_label;
    my $serial;
    my $trust = 1;

    while (<>) {
	chomp;
	last if ($_ eq '');

	if (/^CKA_LABEL UTF8 "([^"]+)"/) {
	    $cka_label = $1;
	}

	if (/^CKA_SERIAL_NUMBER MULTILINE_OCTAL/) {
	    $serial = graboct();
	}

	if (/^CKA_TRUST_.*\s.*_(UN|NOT_)TRUSTED/) {
	    $trust = 0;
	}
    }
    return ($serial, $cka_label, $trust);
}

while (<>) {
    if (/^CKA_CLASS .* CKO_CERTIFICATE/) {
	my ($serial, $label, $certdata) = grabcert();
	if (defined $certs{$serial.$label}) {
	    warn "Certificate $label duplicated!\n";
	}
	$certs{$serial.$label} = $certdata;
    } elsif (/^CKA_CLASS .* CKO_(NSS|NETSCAPE)_TRUST/) {
	my ($serial, $label, $trust) = grabtrust();
	if (defined $trusts{$serial.$label}) {
	    warn "Trust for $label duplicated!\n";
	}
	$trusts{$serial.$label} = $trust;
    } elsif (/^CVS_ID.*Revision: ([^ ]*).*/) {
        print "##  Source: \"certdata.txt\" CVS revision $1\n##\n\n";
    }
}

# weed out untrusted certificates
my $untrusted = 0;
foreach my $it (keys %trusts) {
    if (!$trusts{$it}) {
	if (!exists($certs{$it})) {
	    warn "Found trust for nonexistent certificate\n";
	} else {
	    delete $certs{$it};
	    $untrusted++;
	}
    }
}

print "##  Untrusted certificates omitted from this bundle: $untrusted\n\n";

my $certcount = 0;
foreach my $it (keys %certs) {
    if (!exists($trusts{$it})) {
	die "Found certificate without trust block,\naborting";
    }
    printcert("", $certs{$it});
    print "\n\n\n";
    $certcount++;
}

print "##  Number of certificates: $certcount\n";
print "##  End of file.\n";
