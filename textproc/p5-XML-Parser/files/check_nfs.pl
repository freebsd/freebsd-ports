#!/usr/bin/perl
#
# $FreeBSD$

use strict;
use warnings;
use File::Temp qw(tempfile);

my ($fh, $fn) = tempfile("check-XXXXXX", SUFFIX => '.tmp', TMPDIR => 1, UNLINK => 1);
#print "$fn\n";
