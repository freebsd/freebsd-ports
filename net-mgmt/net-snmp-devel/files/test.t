#!/usr/bin/perl -w
#
# $FreeBSD$

use strict;
use Test::More tests => 1;

my $cmd = 'snmpwalk -c public -v 1 localhost';

# ports/86572
my $output = `$cmd hrSWRunType`;
like($output, qr/operatingSystem/, 'hrSWRunType');
