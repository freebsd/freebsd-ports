#!/usr/bin/perl -w
#
# Copyright (c) 2004 Oliver Eikemeier. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright notice
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the author nor the names of its contributors may be
#    used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# $FreeBSD$
#
# portaudit to VuXML converter, use with
#  portaudit2vuxml.pl <uuid>
# and edit the entry to suit your needs.
#

require 5.005;
use strict;
use Cwd 'abs_path';

my $portsdir = $ENV{PORTSDIR} ? $ENV{PORTSDIR} : '/usr/ports';

my $portauditdb = "$portsdir/security/portaudit-db/database/portaudit.txt";

my $uuid = $ARGV[0];

$#ARGV == 0 && $uuid =~ /^[0-9a-f]{8}(?:-[0-9a-f]{4}){4}[0-9a-f]{8}$/
  or die "usage: $0 $uuid <uuid>\n";

my $today=`date -u +%Y-%m-%d`;
chomp $today;

my @pkg;
my $url;
my $topic;

open PORTAUDITDB, "<$portauditdb"
  or die "Can't open $portauditdb: $!\n";

while (<PORTAUDITDB>) {
  chomp;
  next if /^(?:#|$)/;
  my @line = split /\|/;
  next if $#line < 3 || $line[3] ne $uuid;
  push @pkg, $line[0];
  $url = $line[1];
  $topic = $line[2];
}

close PORTAUDITDB;

$url =~ s/</&lt;/g;
$url =~ s/>/&gt;/g;
$url =~ s/&/&amp;/g;

$topic =~ s/</&lt;/g;
$topic =~ s/>/&gt;/g;
$topic =~ s/&/&amp;/g;

my %oper = (
  '<'  => 'lt',
  '<=' => 'le',
  '='  => 'eq',
  '>=' => 'ge',
  '>'  => 'gt'
);

if (@pkg) {
  print "  <vuln vid=\"$uuid\">\n";
  print "    <topic>$topic</topic>\n";
  print "    <affects>\n";
  foreach (@pkg) {
    my @vers = split /((?:<|>)=?|=)/;
    my $pkgname = shift @vers;
    print "      <package>\n";
    print "        <name>$pkgname</name>\n";
    if (@vers) {
      print "        <range>";
      while (@vers) {
        my $op = $oper{shift @vers};
        my $v = shift @vers;
           print "<$op>$v</$op>";
      }
      print "</range>\n";
    }
    print "      </package>\n";
  }
  print "    </affects>\n";

  print "    <description>\n";
  print "      <body xmlns=\"http://www.w3.org/1999/xhtml\">\n";
  print "        <p>Please <a href=\"mailto:security\@FreeBSD.org?subject=vid%20$uuid\">contact\n";
  print "           the FreeBSD Security Team</a> for more information.</p>\n";
  print "      </body>\n";
  print "    </description>\n";
  print "    <references>\n";

  foreach (split ' ', $url) {
    if (m'^http://cve\.mitre\.org/cgi-bin/cvename\.cgi\?name=(.+)$') {
      print "      <cvename>$1</cvename>\n"
    }
    elsif (m'^(http://www\.securityfocus\.com/archive/.+)$') {
      print "      <mlist>$1</mlist>\n"
    }
    elsif (m'^http://www\.securityfocus\.com/bid/(.+)$') {
      print "      <bid>$1</bid>\n"
    }
    elsif (m'^(http://(?:article\.gmane\.org|lists\.netsys\.com|marc\.theaimsgroup\.com)/.+)$') {
      print "      <mlist>$1</mlist>\n"
    }
    elsif (m'^http://www\.kb\.cert\.org/vuls/id/(.+)$') {
      print "      <certvu>$1</certvu>\n"
    }
    elsif (m'^http://www\.cert\.org/advisories/(.+)\.html$') {
      print "      <certsa>$1</certsa>\n"
    }
    else {
      print "      <url>$_</url>\n";
    }
  }

  print "    </references>\n";
  print "    <dates>\n";
  print "      <discovery>2000-00-00</discovery>\n";
  print "      <entry>$today</entry>\n";
  print "    </dates>\n";
  print "  </vuln>\n";
}
