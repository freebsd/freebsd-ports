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
# MAINTAINER=   eik@FreeBSD.org
#

require 5.005;
use strict;

my $dbdir  = $ENV{RANKDIR}  ? $ENV{RANKDIR}  : '/var/db/distrank';

my $fping  = $ENV{FPING}    ? $ENV{FPING}    : '/usr/local/sbin/fping';

-x $fping
    or die "fping required\n";

-d $dbdir || mkdir $dbdir, 0777
    or die "Can't create $dbdir\n";

my $rankfile = "$dbdir/ranks-fping";

my $now = time;

my %distance;

if (-r $rankfile) {
    open RANKS, "<$rankfile";
    while (<RANKS>) {
        chomp;
        my ($host, $d, $e) = split;
        $distance{$host} = [$d, $e]
            if defined $e && $e >= $now;
    }
    close RANKS;
}

my %mastersites;
my %newdistance;

my $distgood    = 0;
my $distdefault = 5000;
my $distbad     = 10000;

my $expgood     = $now + 14 * 86400;
my $expdefault  = $now + 7 * 86400;

my $hostcount = 0;

while (<>) {
    chomp;
    next
        if exists $mastersites{$_};
    if (m'^(?:ftp|https?)://(?:[^/]*@)?([^/:]+\.[^/:]+)(?::\d+)?(?:/|$)'i) {
        my $host = lc $1;
        $mastersites{$_} = $host;
        if (!defined $distance{$host}) {
            $distance{$host} = [$distdefault, $expdefault];
            $newdistance{$host} = undef
        }
        $hostcount++;
    } elsif (m'^file:'i) {
        $mastersites{$_} = 'FILE';
    } else {
        $mastersites{$_} = 'UNKNOWN';
    }
}

if (%newdistance && $hostcount > 1) {
    if (!open FPING, '-|') {
        if (!open FPINGIN, '|-') {
            open STDERR, '>&STDOUT';
            exec $fping, '-q', '-C', '3';
            die
        }
        foreach (keys %newdistance) {
            print FPINGIN $_, "\n";
        }
        close FPINGIN;
        exit;
    }

    while(<FPING>) {
        /([^\s:]+)\s*:\s*([\s\d.-]*)/ or next;
        my $sum = 0.0;
        my $num = 0;
        foreach my $val (split ' ', $2) {
            $val ne '-' || next;
            $sum += $val;
            $num++;
        }
        if ($num > 0) {
            $distance{$1} = [$sum/$num, $expgood];
        }
    }
    close FPING;

    open RANKS, ">$rankfile";
    while (my ($host, $val) = each %distance) {
        printf RANKS "%s\t%.2f\t%d\n", $host, $val->[0], $val->[1]
            if defined $val;
    }
    close RANKS;
}

$distance{FILE} = [$distgood, 0];
$distance{UNKNOWN} = [$distbad, 0];

foreach (sort {$distance{$mastersites{$a}}->[0] <=> $distance{$mastersites{$b}}->[0]} keys %mastersites) {
    print $_, "\n";
}
